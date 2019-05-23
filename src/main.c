#include "stm32f1xx_hal.h"
#include "led.h"

int main()
{
    HAL_Init();
    led_init();

    while (1)
    {
        led_trigger();
    }

    return 0;
}