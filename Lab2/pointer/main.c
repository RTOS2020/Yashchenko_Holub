#include "stm32f10x.h"

void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

int main(void) {
	
	int *GPIO_B_CRH = (int*) (0x40010c04);
	int *GPIO_B_ODR = (int*) (0x40010C0C);
	int *GPIO_C_CRH = (int*) (0x40011004);
	int *GPIO_C_IDR = (int*) (0x40011008);
	
	int *apb2enr = (int*) 0x40021018;
	*apb2enr = 0x00018;
	
	*GPIO_C_CRH = 0x30000000; 
	*GPIO_B_CRH = 0x00000033;

	while(1) {
		if (*GPIO_C_IDR & 0x8000) {
			*GPIO_B_ODR = 0x2000;     // for B13
			delay(1000);
			*GPIO_B_ODR = 0x00000000;
			delay(1000);
		} else {
			*GPIO_B_ODR = 0x00000000;
		}
	}
}
