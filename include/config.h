#if defined(STM32H743xx)
#include <stm32h7xx_hal.h>
#define LED_RED         GPIO_PIN_14
#define LED_BLUE        GPIO_PIN_7
#define LED_YELLOW      GPIO_PIN_0
#define DELAY_TIME 200
#elif defined(STM32F103xB)
#include <stm32f1xx_hal.h>
#define LED_RED     GPIO_PIN_8
#define DELAY_TIME 100
#endif

// command
#define LED_PORT    GPIOB
