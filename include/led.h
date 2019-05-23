#ifndef _LED_H_
#define _LED_H_

#define LED_PORT    GPIOB
#define LED_PIN     GPIO_PIN_8


void led_init(void);
void led_trigger(void);
void led_on(void);
void led_off(void);

#endif // !_LED_H_