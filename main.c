/* 
 * File:   main.c
 * Author: Int-Mosfet
 *
 * Created on April 8, 2017, 11:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "pin_manager.h"

#define SET_BIT(var, pos) (var |= (1 << pos))
 
#define CLEAR_BIT(var, pos) (var &= (~(1 << pos)))

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    //turn on LED
    IO_RB6_SetHigh();
    //turn off PWM
    //1 is off, 0 is on (PWM)
    TRISCbits.TRISC6 = 1;
    
    // Value loaded effects volume output
    //PWM3_LoadDutyValue(0xF0);
    
    //TRISCbits.TRISC6 = 0;
    //__delay_ms(500);
    //TRISCbits.TRISC6 = 1;
    //RC6_SetLow();
    
    uint8_t count = 0;
    uint8_t i = 0;
    //control char of 254 (0xFE)
    //must be sent before a command)
    uint8_t cntr = 254;
    uint8_t clear_cmd = 1;
    
    volatile uint32_t ir_code;
    uint16_t address;
    uint8_t command, inv_command;
    //Clear screen
    //EUSART1_Write(cntr);
    //EUSART1_Write(clear_cmd);
    //set cursor to beginning
    //EUSART1_Write(cntr);
    //EUSART1_Write(128);
    __delay_ms(2000);
    printf("ECE471 IR Decode");
    printf("NEC Proto, Begin");
    while (true)
    {
        //delay until RC7 goes low
        while(IO_RC7_GetValue() == 1);
        //9ms high
        while((IO_RC7_GetValue() == 0) && (count < 200))
        {
            count++;
            __delay_us(50);
        }
        
        //if(count > 200 || count < 160)
        //    printf("FALSE ACTIVATION");
        
        //reset counter
        count = 0;
        //4.5ms low
        while((IO_RC7_GetValue()) && (count < 100))
        {
            count++;
            __delay_us(50);
        }
        
        //if(count > 100 || count < 80)
        //    printf("FALSE ACTIVATION");
        
        // Read IR code, 32 bits
        for(i = 0; i < 32; i++)
        {
            count = 0;
            while((IO_RC7_GetValue() == 0) && (count < 14))
            {
                count++;
                __delay_us(50);
            }
                            
            count = 0;
            while((IO_RC7_GetValue()) && (count < 40))
            {
                count++;
                __delay_us(50);
            }
                               
            if( count > 20)
                SET_BIT(ir_code, (31 - i));
            else // If space width < 1ms
                CLEAR_BIT(ir_code, (31 - i));
        }
        address = ir_code << 16;
        command = ir_code >> 4;
        
        //clear screen
        EUSART1_Write(cntr);
        EUSART1_Write(clear_cmd);
        
        printf("    NEC PROTOCOL");
        
        //printf("      CMD: ");
        //printf("%x", command);
        //printf("     ");
       
        
        EUSART1_Write(cntr);
        EUSART1_Write(192);
        printf("FULL CODE: ");
        printf("%x", ir_code);
        printf("     ");
        TRISCbits.TRISC6 = 0;
        __delay_ms(200);
        TRISCbits.TRISC6 = 1;
        
    }
}

