//stepper motor
//CLOCKWISE

#include <REG51XD2.H> 
void delay(unsigned int x) 
{ 
for(;x>0;x--); 
} 
void main() 
{ 
unsigned char val,i; 
P0=0x88; 
while (1) 
{ 
val=0x88; 
for (i=0;i<4;i++) 
{ 
P0=val; 
val=val>>1; 
delay(575); 
} 
} 
} 

//COUNTER CLOCKWISE 

#include <REG51XD2.H> 
void delay(unsigned int x) 
{ 
for(;x>0;x--); 
} 
void main() 
{ 
unsigned char val,i; 
P0=0x11; 
8. STEPPER MOTOR 
while (1) 
{ 
val=0x11; 
for (i=0;i<4;i++) 
{ 
P0=val; 
val=val<<1; 
delay(575); 
} 
} 
}