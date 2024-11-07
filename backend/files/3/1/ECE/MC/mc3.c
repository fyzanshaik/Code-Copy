//1. Toggling of p1.5 with the delay of 5ms without interrupts using timer 1 
//#include<reg51.h> 
    sbit mybit=P1^5; 
    void todelay(); 
    void main(void) 
    { 
    while(1) 
    { 
    mybit=0; 
    todelay(); 
    mybit=1; 
    todelay(); 
    } 
    } 
    void todelay() 
    { 
    TMOD=0x01; 
    TL0=0x00; 
    TH0=0xee; 
    TR0=1; 
    while(TF0==0); 
    TR0=0; 
    TF0=0; 
    }


ORG 0000H 
MOV TMOD, #10h  
AGAIN: MOV TL1, #00H  
MOV TH1, #0EEH  
CPL P1.5 
SETB TR1  
BACK: JNB TF1, BACK  
CLR TR1  
CLR TF1  
SJMP AGAIN  
END










//#include <reg51.h> 
sbit SW =P1^7; 
sbit LED =P1^0; 
sbit WAVE =P2^5; 
void timer0(void) interrupt 1 
{ 
WAVE=~WAVE;   //toggle pin TF0=0; 
} 
void main() 
{ 
SW=1; //make switch input 
TMOD=0x01; 
TH0=0xed; // 
TL0=0xff; 
IE=0x82; //enable interrupt for timer 0 
TR0=1; 
while (1) 
{ 
LED=SW; //send switch to LED 
} 
}

//2. Toggling of p1.2 with the delay of 5ms with interrupts using timer 0 
ORG 000 
LJMP MAIN 
ORG 000BH; ISR for Timer 0 
CPL P1.2 
MOV TL0, #00H 
MOV TH0, #0EEH 
RETI 
ORG 30H 
MAIN: MOV TMOD, #01h; Timer 0, Mode 1 
MOV TL0, #00 
MOV TH0, #0DCH 
MOV IE, #82H; enable Timer 0 interrupt 
SETB TR0 
HERE:   SJMP HERE 
END



