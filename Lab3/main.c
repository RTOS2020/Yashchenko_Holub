#include "stm32f10x.h"

enum states{
	GPIO_PORT_ON = 800,
	GPIO_PORT_OFF = 0
};


void led_on();
void led_off();

int main(void)
{
  int timestamp = 0;
	
	// initilize
	RCC->APB2ENR = 0b1100; //B, A
	GPIOB->CRH = 0x300; //B8, B9
	GPIOA->CRL = 0x6; //A1, A2
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);
	
	while(1){
		switch(timestamp % 1000){
		case GPIO_PORT_ON:
			led_on();
			timestamp -= 1000;
			break;
		case GPIO_PORT_OFF:
			led_off();
			break;
		}
	}
}


void led_on(){
	GPIOA->ODR = 0b1000000;
}
void led_off(){
	GPIOA->ODR = 0;
}