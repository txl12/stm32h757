#include <stdio.h>
#include <stdint.h>
#define VALUE_SIZE(x)  (((x)/sizeof(void*))*sizeof(void*)+(!!((x)%sizeof(void*)))* sizeof(void*))

struct mem_init_t
{
	size_t mem_len;
	size_t max_nblk_cnt;
	uint8_t* ext_mem;
};
struct mem_list_t {
	struct mem_list_t* next_p;
	void* addr_start;
	size_t len;
};
struct mem_man_t {
	size_t max_nblk_cnt;
	size_t MemNUsedBlks;
	size_t MemNMaxUsedBlks;
	size_t MemMaxUsedSize;
	struct mem_list_t* free_list;
	struct mem_list_t* used_list;
	//struct mem_list_t* empty_list;
	size_t max_size;
	size_t Used_Size;
	void* start_addr;
};
void mem_init(struct mem_man_t* obj,const struct mem_init_t* mem);
void* get_mem(struct mem_man_t* mem_obj, size_t size);
void release_mem(struct mem_man_t* mem_obj, void* mem_blk);
