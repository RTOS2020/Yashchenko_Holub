#include "stm32f10x.h"

void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

void main(){
	GPIO_InitTypeDef GPIO_InitStructure;
	
  /* Initialize LED which connected to PC15 and PC8 */

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	/* Configure the GPIO_LED pin */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	 //GPIO_SetBits(GPIOC, GPIO_Pin_8); // Set C8 to High level ("1")
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	
	while (1) {
 
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) != 0) {
        /* Toggle LED which connected to PC8*/
        GPIOC->ODR ^= GPIO_Pin_8; // Invert C8
 
        /* delay */
		delay(1000);
        /* Toggle LED which connected to PC13*/
        GPIOC->ODR ^= GPIO_Pin_8;
 
        /* delay */
		delay(1000);  }
    else {        GPIO_SetBits(GPIOC, GPIO_Pin_8);   }

		GPIO_SetBits(GPIOC, GPIO_Pin_8);   
		delay(1000);
		GPIO_ResetBits(GPIOC, GPIO_Pin_8); 
		delay(1000);
		GPIOC->ODR&=~GPIO_Pin_8;
		delay(1000);
		GPIOC->ODR|=GPIO_Pin_8;
		delay(1000);

  }

}
