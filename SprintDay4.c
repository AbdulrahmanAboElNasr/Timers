/*
 * SprintDay4.c
 *
 * Created: 2019-12-03 1:35:26 PM
 *  Author: Abdo Sayed
 */ 
#include "led.h"
#include "softwareDelay.h"
#include "gpio.h"
#include "pushButton.h"
#include "timers.h"
#include "avr/delay.h"



#define Go			0
#define Stop		1
#define	GetReady	2


int main(void)
{
	static uint8 statex = Go;
	static uint8 flag = 0;
	uint8 count = 0;
	pushButton_Init(BTN_0);
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_POLLING);
	timer1Init(T1_NORMAL_MODE,T1_OC1_DIS,T1_PRESCALER_64,0,0,0,0,T1_POLLING);
	
    while(1)
    {
		//TODO:: Please write your application code 
		
		switch (statex)
		{
			case Go:
			Led_On(LED_0);
			
			Led_Off(LED_1);
			
			Led_Off(LED_2);
			//SwDelay_ms(1000);
			//_delay_ms(1000);
			//timer0Delay_ms(2000);
			timer1Delay_ms(2000);
			statex = Stop;
			break;
			
			case Stop:
			Led_Off(LED_0);

			Led_On(LED_1);

			Led_Off(LED_2);
			//SwDelay_ms(1000);
			//_delay_ms(1000);
			//timer0Delay_ms(1000);
			timer1Delay_ms(2000);
			statex = GetReady;
			break;
			
			case GetReady:
			Led_Off(LED_0);

			Led_Off(LED_1);

			Led_On(LED_2);
			//SwDelay_ms(1000);
			//_delay_ms(1000);
			//timer0Delay_ms(1000);
			timer1Delay_ms(2000);
			statex = Go;
			break;
			
			default:
			// Your code here
			break;
		}

    }
}


/* 


*/

/**

/////////////////////////////
Led_On(LED_0);
Led_Off(LED_1);
Led_Off(LED_2);
_delay_ms(1000);

Led_Off(LED_0);
Led_On(LED_1);
Led_Off(LED_2);
_delay_ms(1000);

Led_Off(LED_0);
Led_Off(LED_1);
Led_On(LED_2);
_delay_ms(1000);

*/