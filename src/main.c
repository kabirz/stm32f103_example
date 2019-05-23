#include <config.h>
#include <led.h>

int main()
{
	HAL_Init();
	led_demo();
	return 0;
}