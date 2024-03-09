#include <stm32l053xx.h>

uint32_t tick = 0;

void SysTick_Handler(void)
{
	tick++;
}

void delay(uint32_t time)
{
	tick = 0;
	while (tick < time)
	{
		;
	}
}

int main(void)
{
	SysTick_Config(SystemCoreClock / 8 / 1000);
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE5;
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	while (1)
	{
		GPIOA->BSRR |= GPIO_BSRR_BS_5;
		delay(1000);
		GPIOA->BSRR |= GPIO_BSRR_BR_5;
		delay(1000);
	}
	return 0;
}
