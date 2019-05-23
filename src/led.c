
#include <config.h>

static uint16_t leds[] = {
#ifdef LED_RED
	LED_RED,
#endif
#ifdef LED_BLUE
	LED_BLUE,
#endif
#ifdef LED_YELLOW
	LED_YELLOW,
#endif
};

void led_init(uint16_t pin)
{
	GPIO_InitTypeDef GPIO_InitType;

	GPIO_InitType.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitType.Pin = pin;
	GPIO_InitType.Pull = GPIO_PULLUP;
	GPIO_InitType.Speed = GPIO_SPEED_FREQ_HIGH;

	__HAL_RCC_GPIOB_CLK_ENABLE();
	HAL_GPIO_Init(LED_PORT, &GPIO_InitType);
}

void led_on(uint16_t pin)
{
	HAL_GPIO_WritePin(LED_PORT, pin, GPIO_PIN_SET);
}

void led_off(uint16_t pin)
{
	HAL_GPIO_WritePin(LED_PORT, pin, GPIO_PIN_RESET);
}

void led_trigger(uint16_t pin)
{
	HAL_GPIO_TogglePin(LED_PORT, pin);
	HAL_Delay(DELAY_TIME);
}

void led_demo(void)
{
	for (size_t i = 0; i < sizeof(leds) / sizeof(leds[0]); i++) {
		led_init(leds[i]);
	}
	while (1) {
		for (size_t i = 0; i < sizeof(leds) / sizeof(leds[0]); i++) {
			led_on(leds[i]);
			HAL_Delay(DELAY_TIME);
			led_off(leds[i]);
			HAL_Delay(DELAY_TIME);
		}
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
