#include "main.h"
#define SHARE_MEM_ADDR 0x38000000
#define SHARE_MEM_SIZE 32*1024
struct share_mem{
const uint32_t share_mem_add;
const uint32_t share_mem_size;
const uint32_t end_offset;
};
