

 #include <xc.h>
 #include "pwm3.h"

 void PWM3_Initialize(void)
 {
     // PWM3POL active_hi; PWM3EN enabled; 
     PWM3CON = 0x80;
     
     // DC 127; 
     PWM3DCH = 0x7F;
     
     // DC 1; 
     PWM3DCL = 0x40;
     
     // Select timer
     CCPTMRSbits.P3TSEL = 0x1;
 }

 void PWM3_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM3DCH = (dutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM3DCL = (dutyValue & 0x0003)<<6;
 }
 /**
  End of File
 */
