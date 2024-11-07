//6. SEVEN SEGMENT DISPLAY 

#include <reg51.h> 
#define DATA P2 
void delay(unsigned int );        
 
int main() //main starting 
{ 
 while(1) 
 { 
  DATA=0xc0; 
  delay(500); 
   
  DATA=0xf9; 
  delay(500); 
   
  DATA=0xa4; 
  delay(500); 
   
  DATA=0xb0; 
  delay(500); 
   
  DATA=0x99; 
  delay(500); 
   
  DATA=0x92; 
  delay(500); 
   
  DATA=0x82; 
  delay(500); 
   
  DATA=0xf8; 
  delay(500); 
   
  DATA=0x80; 
  delay(500); 
   
  DATA=0x90; 
  delay(500); 
 } 
 
} 
 
void delay(unsigned int t) //delay    t*25msec 
{ 
unsigned int i,j; 
for(i=0; i<t; i++) 
for(j=0; j<1275; j++); 
} 
 
