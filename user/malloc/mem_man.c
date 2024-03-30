#include "mem_man.h"

#define MEM_GET_VALUE_SIZE_ALIGN(x, align)  (((x)/(align))*(align)+(!!((x)%(align)))* (align))
static inline struct mem_list_t* list_init(size_t * base_addr) {
	struct mem_list_t* list = (struct mem_list_t*)(*base_addr);
	*base_addr += MEM_GET_VALUE_SIZE_ALIGN(sizeof(struct mem_list_t), sizeof(void*));
	if(list)
	{
		list->addr_start = NULL;
		list->len = 0;
		list->next_p = NULL;
	}
	return list;
}
static inline void list_insert(struct mem_list_t* list1, struct mem_list_t* list2) {
	if(list1!=NULL&&list2!=NULL)
	{
		list2->next_p = list1->next_p;
		list1->next_p = list2;
	}
}
static inline struct mem_list_t* list_out(struct mem_list_t* list) {
	struct mem_list_t* temp = list->next_p;
	
	if (temp) {
		list->next_p = list->next_p->next_p;
		temp->addr_start = NULL;
		temp->next_p = NULL;
	}
	return temp;
}
void mem_init(struct mem_man_t *obj,const struct mem_init_t* mem) {
	//obj->empty_list = NULL;
	size_t base_addr = (size_t)mem->ext_mem;
	obj->free_list = NULL;
	obj->max_nblk_cnt = mem->max_nblk_cnt;
	obj->MemMaxUsedSize = 0;
	obj->MemNMaxUsedBlks = 0;
	obj->used_list = list_init(&base_addr);
	obj->MemNUsedBlks = 0;
	obj->free_list = list_init(&base_addr);
	obj->Used_Size = 0;
	for (size_t i = 0; i < mem->max_nblk_cnt-1; ++i) {
		struct mem_list_t* list = list_init(&base_addr);
		list_insert(obj->free_list,list);
	}
	obj->free_list->addr_start = (void*)base_addr;
	obj->start_addr = (void*)base_addr;
	obj->max_size = (mem->mem_len - (size_t)(base_addr - (size_t)mem->ext_mem));
}
void* get_mem(struct mem_man_t *mem_obj,size_t size) {
	void* res = NULL;
	struct mem_list_t*  list = list_out(mem_obj->free_list);
	if (list) {
		struct mem_list_t* used_list = mem_obj->used_list->next_p;
		if(used_list != NULL)//list head == null ,list is empty
		{
			if (used_list->addr_start > mem_obj->start_addr) {
				size_t len = (size_t)(used_list->addr_start) - (size_t)(mem_obj->start_addr) ;
				if (len >= VALUE_SIZE(size)) {
					list->next_p = used_list;
					mem_obj->used_list->next_p = list;
					list->addr_start = mem_obj->start_addr;
					list->len = VALUE_SIZE(size);
					mem_obj->Used_Size += list->len;
					if (mem_obj->MemMaxUsedSize < mem_obj->Used_Size) {
						mem_obj->MemMaxUsedSize = mem_obj->Used_Size;
					}
					mem_obj->MemNUsedBlks++;
					if (mem_obj->MemNMaxUsedBlks < mem_obj->MemNUsedBlks) {
						mem_obj->MemNMaxUsedBlks = mem_obj->MemNUsedBlks;
					}
					res = list->addr_start;
				}
			}
			else
			{
				while (used_list != NULL) {//轮询全部使用的list,used list为有序链表
					if (used_list->next_p != NULL) {
						size_t len = (size_t)(used_list->next_p->addr_start) - (size_t)(used_list->addr_start) - used_list->len;
						if (len >= VALUE_SIZE(size)) {//当前两个空闲链表之间的size大于需要申请的空间，从空间中取出长度。
							list->addr_start = (void*)(((size_t)(used_list->addr_start)) + used_list->len);//addr为当前长度加上len,
							list->len = VALUE_SIZE(size);
							list_insert(used_list, list);
							mem_obj->Used_Size += list->len;
							if (mem_obj->MemMaxUsedSize < mem_obj->Used_Size) {
								mem_obj->MemMaxUsedSize = mem_obj->Used_Size;
							}
							mem_obj->MemNUsedBlks++;
							if (mem_obj->MemNMaxUsedBlks < mem_obj->MemNUsedBlks) {
								mem_obj->MemNMaxUsedBlks = mem_obj->MemNUsedBlks;
							}
							res = list->addr_start;
							break;
						}
					}//next 指针空
					else {
						size_t rest_size = (((size_t)mem_obj->start_addr) + mem_obj->max_size) - (((size_t)(used_list->addr_start) + used_list->len));
						if (rest_size >= size) {//size 足够，可以分配
							list->addr_start = (void*)((size_t)(used_list->addr_start) + used_list->len);//addr为当前长度加上len,
							list->len = VALUE_SIZE(size);
							list_insert(used_list, list);
							mem_obj->Used_Size += list->len;
							if (mem_obj->MemMaxUsedSize < mem_obj->Used_Size) {
								mem_obj->MemMaxUsedSize = mem_obj->Used_Size;
							}
							mem_obj->MemNUsedBlks++;
							if (mem_obj->MemNMaxUsedBlks < mem_obj->MemNUsedBlks) {
								mem_obj->MemNMaxUsedBlks = mem_obj->MemNUsedBlks;
							}
							res = list->addr_start;
							break;
						}
					}
					used_list = used_list->next_p;
				}
			}
		}
		else if(mem_obj->MemNUsedBlks == 0){// list empty 
			if (mem_obj->max_size >= size) {//size 足够，可以分配
				list->addr_start = mem_obj->start_addr;//addr为当前长度加上len,
				list->len = VALUE_SIZE(size);
				list_insert(used_list, list);
				mem_obj->Used_Size += list->len;
				if (mem_obj->MemMaxUsedSize < mem_obj->Used_Size) {
					mem_obj->MemMaxUsedSize = mem_obj->Used_Size;
				}
				mem_obj->MemNUsedBlks++;
				if (mem_obj->MemNMaxUsedBlks < mem_obj->MemNUsedBlks) {
					mem_obj->MemNMaxUsedBlks = mem_obj->MemNUsedBlks;
				}
				res = list->addr_start;
				mem_obj->used_list->next_p = list;
			}
		}
	}
	return res;
}
void release_mem(struct mem_man_t* mem_obj,void* mem_blk) {
	if(mem_blk)
	{
		struct mem_list_t* used_list = mem_obj->used_list->next_p;
		if (used_list != NULL)//list head == null ,list is empty
		{
			struct mem_list_t* used_list_last = NULL;
			while (used_list != NULL) {
				if (used_list->addr_start == mem_blk) {//找到mem地址
					struct mem_list_t* list = used_list;  //取出链表，将数据放到空闲链表中
					if (used_list_last)
					{
						used_list_last->next_p = used_list->next_p;
					}
					else {
						mem_obj->used_list->next_p = used_list->next_p;
					}
					used_list = used_list->next_p;
					mem_obj->MemNUsedBlks--;
					mem_obj->Used_Size -= list->len;
					list->len = 0;
					list->addr_start = NULL;
					list->next_p = NULL;
					list_insert(mem_obj->free_list, list);
					break;
				}
				used_list_last = used_list;
				used_list = used_list->next_p;
			}
		}
	}
}