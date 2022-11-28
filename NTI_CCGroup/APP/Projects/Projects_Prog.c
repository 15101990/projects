/*
 * Projects_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#define EEPROM_PAGE_NUMBER     2

#include "Projects_Interface.h"

void A_Timer0Excution(void);

void A_Projects_EEPROMApplication(void);

int main()
{
	M_GIE_Void_GlobalInterruptEnable();
	M_Timer_Void_SetCallBack(A_Timer0Excution);
	M_Timer_Void_TimerInit();
	M_Timer_Void_TimerSetTime(1000);
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);

	return 0;
}


void A_Timer0Excution(void)
{

}

void A_Projects_EEPROMApplication(void)
{
	H_Lcd_Void_LCDInit();
	H_EEPROM_Void_EEPROMInit();
	u8 x = H_EEPROM_U8_EEPROMRead(EEPROM_PAGE_NUMBER,0);
	while(1)
	{
		H_Lcd_Void_LCDWriteNumber(x);
		_delay_ms(600);
		x++;
		H_EEPROM_Void_EEPROMWrite(EEPROM_PAGE_NUMBER,0,x);
		H_Lcd_Void_LCDClear();
	}
}
