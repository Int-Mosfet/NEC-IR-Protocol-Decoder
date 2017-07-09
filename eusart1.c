

#include "eusart1.h"

void EUSART1_Initialize(void)
{
    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUD1CON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN disabled; ADDEN disabled; SREN disabled; 
    RC1STA = 0x80;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TX1STA = 0x24;

    // Baud Rate = 9600; SP1BRGL 103; 
    SP1BRGL = 0x67;

    // Baud Rate = 9600; SP1BRGH 0; 
    SP1BRGH = 0x00;

}


uint8_t EUSART1_Read(void)
{

    RC1STAbits.CREN = 1;	
    while(!PIR3bits.RC1IF)
    {
    }

    
    if(1 == RC1STAbits.OERR)
    {
        // EUSART1 error - restart

        RC1STAbits.CREN = 0; 
        RC1STAbits.CREN = 1; 
    }

    return RC1REG;
}

void EUSART1_Write(uint8_t txData)
{
    while(0 == PIR3bits.TX1IF)
    {
    }

    TX1REG = txData;    // Write the data byte to the USART.
}

char getch(void)
{
    return EUSART1_Read();
}

void putch(char txData)
{
    EUSART1_Write(txData);
}
/**
  End of File
*/
