#include "stm32f1xx_hal.h"
#include "led.h"

void led_init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitType;
    GPIO_InitType.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitType.Pin = LED_PIN;
    GPIO_InitType.Pull = GPIO_PULLUP;
    GPIO_InitType.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(LED_PORT, &GPIO_InitType);

}

void led_on(void)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
}

void led_off(void)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
}

void led_trigger(void)
{
    HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
    HAL_Delay(100);
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}
