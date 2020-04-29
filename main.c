#include "stm32f10x.h"

void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

int main(void) {
	
	RCC->APB2ENR = 0x18;
	
	GPIOC->CRH = 0x30000000;
	GPIOB->CRH = 0x3;

	while(1) {
		if (GPIOC->IDR & 0x8000) {
			GPIOB->ODR = 0x2000;     // for B13
			delay(1000);
			GPIOB->ODR = 0x00000000;
			delay(1000);
		} else {
			GPIOB->ODR = 0x00000000;
		}
	}
}
