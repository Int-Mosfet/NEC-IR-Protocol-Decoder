

 #ifndef _PWM3_H
 #define _PWM3_H

 #include <xc.h>
 #include <stdint.h>

 #ifdef __cplusplus  // Provide C++ Compatibility

     extern "C" {

 #endif

 #define PWM3_INITIALIZE_DUTY_VALUE    509

// This routine initializes the EPWM3_Initialize
// This routine must be called before any other PWM3 routine is called.
// This routine should only be called once during system initialization.
 void PWM3_Initialize(void);

// This routine loads the 16 bit duty cycle value.
 void PWM3_LoadDutyValue(uint16_t dutyValue);
 
 #ifdef __cplusplus  // Provide C++ Compatibility

     }

 #endif

 #endif	//PWM3_H
 /**
  End of File
 */