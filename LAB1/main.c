#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

int main(void) {
	char mor[] = {'.', '.','.', '_','_','_', ' ', '.','.','.', '_','_','_', ' ', '.', '_'};

	int length = sizeof(mor) / sizeof(char);
	int *GPIO_C_CRH = (int*)(0x00100000);
	int *GPIO_C_ODR = (int*)(0x00002000);
	int *apb2enr = (int*)0x40021018;
	int i = 0;

	*apb2enr |= 0x0001C;
	*GPIO_C_CRH = 0x00300000;

	while(1) {

		char elem = mor[i % length];
		if(elem == '.') {
			*GPIO_C_ODR=0x00000100;
			delay(150);
		} else if(elem == '_') {
			*GPIO_C_ODR=0x00000100;
			delay(300);
		} else if(elem == ' ') {
			*GPIO_C_ODR=0x0000000;
			delay(600);
		}
		
		i++;

		if(i % length == length - 1) {
			delay(3000);
			i = 0;
		};
	}
}