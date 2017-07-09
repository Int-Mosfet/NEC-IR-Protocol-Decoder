

#ifndef _EUSART1_H
#define _EUSART1_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


#define EUSART1_DataReady  (PIR3bits.RC1IF)

// This routine initializes the EUSART1 driver.
// This routine must be called before any other EUSART1 routine is called.
void EUSART1_Initialize(void);

// This routine reads a byte of data from the EUSART1.
uint8_t EUSART1_Read(void);

// This routine writes a byte of data to the EUSART1.
void EUSART1_Write(uint8_t txData);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // _EUSART1_H
/**
 End of File
*/
