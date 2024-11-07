#switch and led

#include <reg51.h> 
sbit LED = P1^0; 
sbit SW=P1^1; 
void Delay(const unsigned int x) //Function to provide delay 
{ 
unsigned int L1=0; 
unsigned int L2=0; 
for(; L1 < x; L1++) 
{ 
for(L2=0; L2 <6553; L2++) 
{} 
} 
} 
int main() 
{ 
SW=1;  
LED=0; //configuring as output pin 
while(1) 
{ 
if((SW ==0)) 
{   
LED=1; //Make pin high 
Delay(1); 
} 
else 
{ 
LED=0; // Make pin low 
Delay(1); 
} 
} 
} 