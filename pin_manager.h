

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <xc.h>
//#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include "pwm3.h"
#include "tmr2.h"
#include "eusart1.h"

// GPIO and peripheral I/O initialization
void PIN_MANAGER_Initialize (void);

// Interrupt on change handling routine
void PIN_MANAGER_IOC(void);

#define _XTAL_FREQ  4000000

// Initialize system
void SYSTEM_Initialize(void);

// Initialize clocks
void OSCILLATOR_Initialize(void);

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISBbits.TRISB6
#define IO_RB6_LAT                LATBbits.LATB6
#define IO_RB6_PORT               PORTBbits.RB6
#define IO_RB6_WPU                WPUBbits.WPUB6
#define IO_RB6_OD                ODCONBbits.ODCB6
#define IO_RB6_ANS                ANSELBbits.ANSELB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()    do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetOpenDrain()   do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetAnalogMode()  do { ANSELBbits.ANSELB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode() do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()     do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()   do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode() do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()     do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()   do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()     do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()   do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define IO_RC7_TRIS               TRISCbits.TRISC7
#define IO_RC7_LAT                LATCbits.LATC7
#define IO_RC7_PORT               PORTCbits.RC7
#define IO_RC7_WPU                WPUCbits.WPUC7
#define IO_RC7_OD                ODCONCbits.ODCC7
#define IO_RC7_ANS                ANSELCbits.ANSELC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()      do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_RC7_ResetPullup()    do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_RC7_SetPushPull()    do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_RC7_SetOpenDrain()   do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_RC7_SetAnalogMode()  do { ANSELCbits.ANSELC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode() do { ANSELCbits.ANSELC7 = 0; } while(0)

#endif // PIN_MANAGER_H
/**
 End of File
*/