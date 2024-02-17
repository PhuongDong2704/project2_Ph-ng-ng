#include "button.h"
#include "stm32f1xx_hal.h"
uint8_t button_current = 1;
uint8_t button_later = 1;
uint8_t state_button = 1;
uint8_t button_filter = 1;
uint8_t debouncing;
uint8_t time_interference;
uint8_t test;
uint8_t count =0;

void button_press()
{
	HAL_GPIO_TogglePin (GPIOC,GPIO_PIN_13);
	count++;
}
void button_handle ()
{
	// -------------------------LOC NHIEU-------------------------------------
	state_button = HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0);
	if (button_filter != state_button )
	{
		button_filter = state_button ;
		debouncing = 1;
		time_interference = HAL_GetTick();
	}
	// -------------------------XAC LAP TRANG THAI----------------------------
	if (debouncing && (HAL_GetTick() - time_interference >= 20))
	{
		button_current = button_filter ;
		debouncing = 0;	
	}
	// -------------------------XU LI TIN HIEU--------------------------------
	if (button_current != button_later )
	{
		if (button_current == 0)
		{
			button_press();
		}
		else
		{	
		}
		button_later = button_current;
	}
}