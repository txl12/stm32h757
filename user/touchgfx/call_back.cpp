#include <gui/screen1_screen/Screen1View.hpp>
extern "C"{
	#include "stdio.h"
	#include "string.h"
	#define BUF_SIZE  256
	static uint16_t * text_p;
		static uint16_t * text_p_base_add;
struct print_info{
uint32_t cur_offset;
	uint32_t total_size;
	
};
static struct print_info info;
int my_put(const char *txt,uint32_t length){
	if(info.total_size - info.cur_offset >length){
		for(int i=0;i<length;++i){
		*text_p++ = txt[i];
		}
//	memcpy(&text_p[info.cur_offset],txt,length);
	info.cur_offset +=length;
		*text_p=0;
	}else{ 
		info.cur_offset=0;
		text_p = text_p_base_add;
		my_put(txt,length);
	}
}
int my_printf(const char *fmt, ...){
   va_list args;
    uint32_t length;
    static char rt_log_buf[BUF_SIZE];

    va_start(args, fmt);
    /* the return value of vsnprintf is the number of bytes that would be
     * written to buffer had if the size of the buffer been sufficiently
     * large excluding the terminating null byte. If the output string
     * would be larger than the rt_log_buf, we have to adjust the output
     * length. */
    length = vsnprintf(rt_log_buf, sizeof(rt_log_buf) - 1, fmt, args);
    if (length > BUF_SIZE - 1)
        length = BUF_SIZE - 1;
    my_put(rt_log_buf,length);
    va_end(args);

    return length;
}
};
Screen1View::Screen1View()
{
	
text_p =     (uint16_t*)&textArea1Buffer;
	text_p_base_add = text_p;
	info.cur_offset =0;
	info.total_size = TEXTAREA1_SIZE/2;
}

void Screen1View::terminal_print()
{
my_printf("123");
//Unicode::snprintf(textArea1Buffer, 9, "New Text");
//	textArea1Buffer[0]='a';
//	textArea1Buffer[1]=0;
	textArea1.setWideTextAction(WIDE_TEXT_CHARWRAP);
	textArea1.invalidate();
}