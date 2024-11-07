//5. SERIAL COMMUNICATION
Transmit Data 
ORG 0000H 
MOV TMOD,#20H 
MOV TH1,#0FDH 
MOV SCON,#50H 
SETB TR1 
AGAIN: MOV SBUF,#'A' 
HERE: JNB TI, HERE 
CLR TI 
SJMP AGAIN 
END 

include<reg51.h>  
void main( ) 
{  
TMOD = 0x20 ; //use Timer 1, mode 2  
TH1= 0xFD 
; //9600 baud rate 
SCON = 0x50 ;//configure SCON  
TR1 = 1 ; // start the timer 1 
while (1) 
{ 
SBUF = 'A'; //place value in buffer  
while (TI == 0); 
TI = 0; 
} 
} 



SERIAL RECEIVE 
ORG 0000H 
MOV TMOD,#20H 
MOV TH1,#0FDH 
MOV SCON,#50H 
SETB TR1 
HERE: JNB RI,HERE 
MOV A,SBUF 
MOV P1,A 
CLR RI 
SJMP HERE 
END 

#include <reg51.h> 
void main() 
{ 
unsigned char mybyte; 
SCON=0X50; 
TMOD=0X20; 
TH1=0XFA;      //4800 
TR1=1; 
while(1) 
{ 
while(RI==0);         
mybyte=SBUF; 
P1=mybyte; 
RI=0; 
} 
}