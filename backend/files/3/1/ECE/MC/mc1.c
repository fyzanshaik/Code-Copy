Source mode 
##include <reg51.h>
##void main(void) 
#{ 
      unsigned int i; 
for(i=0;i<5000;i++); 
for(i=0;i<5000;i++); 
P1=0x01; 
} 
Sink mode 
##include <reg51.h> 
void main(void) 
{ 
unsigned int i; 
for(i=0;i<5000;i++); 
for(i=0;i<5000;i++); 
P1=0x0fe; 
} 