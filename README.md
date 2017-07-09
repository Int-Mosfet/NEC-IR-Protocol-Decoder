# NEC-IR-Protocol-Decoder
C implementation of a NEC protocol decoder with a PIC18F27K40

Very simple code, no interrupts.  I use the __delay_us() function for timing, which is included in compiler header files.  IR remotes that follow the NEC protocol (8-bit) will be decoded and the command will be displayed to the screen.  I was having some problems with the address for some reason, but the command is what matters most.  On each activation is a small beep (using pulse-width modulation on a speaker) and I send the code via the EUSART to an LCD display (that has a Serial-LCD decoder on it, I save a lot of pins doing that).  Tons of room for expansion here (I may make a media controller out of it, or light controller).

There is a bug I haven't fixed, I believe the LED I'm using is causing false activations (based off some of my work with infrared devices, they can be "ambient light" detectors as well).  Or the LED is emitting IR light.  All that's needed to trigger an activation is to go high for 9ms, then it will return a code of 0xFF since no bits are being sent, just holding high.  I bet if it required low then high, that this would be filtered out.

Another interesting thing, I encountered a hardware erratum in the PIC18 core (pretty terrible bug).  My professor didn't believe me when I told him my code wasn't wrong :( .  This was causing the EUSART to not function properly.  According to here:  "TBLRD requires NVMREG value to point to appropriate memory".  The workaround for htis bug is the "powerup.as" file.  Pretty cool that a piece of assembly code can patch a hardware erratum.</br>

View of project:</br>
![ir_pic1](https://3.bp.blogspot.com/-eg8vL1p6M54/WToIhfaFF5I/AAAAAAAAARI/HxekjkFPpT8uHzSME4nR09Se-hcwE9wVQCEw/s1600/ir4.jpg)</br>

The NEC protocol:</br>
![ir_pic2](https://4.bp.blogspot.com/-RYDoB7P2o9E/WToIVgoITlI/AAAAAAAAARA/HgqiunGzexopnkGgUD7HmT9jYrhCelGJgCEw/s1600/ir3.png)</br>

Software flow chart:</br>
![ir_pic3](https://3.bp.blogspot.com/-sum6eQ0AmUQ/WToIWGVjjxI/AAAAAAAAARE/wYUXv1PWQgUN-bUxCGem5G5pQ5j7vz-yACEw/s1600/ir2.png)</br>

Hardware layout (almost a schematic):</br>
![ir_pic4](https://1.bp.blogspot.com/-JbZ1POF5HFM/WToIVxssaGI/AAAAAAAAAQ8/MxBYWY_d-T0NHIbLMjmRnYmPEZOrhGWjwCLcB/s1600/ir1.png)</br>
