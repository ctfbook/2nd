#include <stdint.h>
#include <stdio.h>

struct x {
	uint32_t u32;
	uint8_t u8arr[0x12];
	uint64_t u64;
};

int main(void){
	double lv_double = 0.1;
	uint8_t lv_u8arr_1[0x10] = "AAAAAAAABBBBBBBB";
	void *lv_ptr = main;
	uint16_t lv_u16arr[20] = {0};
	struct x lv_st = {
		.u32 = 0x11111111,
		.u8arr = "XXXXXXXXYYYYYYYYZZ",
		.u64 = 0x2222222222222222,
	};
	uint32_t lv_u32 = 0x33333333;
	uint8_t lv_u8arr_2[0x24] = 
		"aaaaaaaabbbbbbbbccccccccddddddddeeee";
	uint32_t lv_u32arr[2] = {0xdeadbeef, 0xcafebabe};
	uint64_t lv_u64 = 0x4444444444444444;

	puts("Done");
}
