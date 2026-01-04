// Where is the LED connected?
// Port: A
// Pin: 6
// AHB - Advanced High performance Bus
// APB - Advanced Peripheral Bus
//

#include "stm32f4xx.h"

#define GPIO_AEN (1UL << 0)
#define LED_PIN_0 (1U<<6)

int main(void) {
	RCC->AHB1ENR |= GPIO_AEN;

	GPIOA->MODER |= (1U << 12);
	GPIOA->MODER &= ~(1U << 13);

	while(1) {
		GPIOA->ODR ^= LED_PIN_0;
		for(int i = 0; i < 500000; ++i);
	}

	return 0;
}
