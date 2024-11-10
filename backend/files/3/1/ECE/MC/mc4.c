
// 1. Count no.  0f pulses without interrupts using counter 0
ORG 0000H MOV TMOD, #05h SETB P3 .4 MOV TL0, #00H MOV TH0, #00H SETB TR0 BACK : MOV A, TL0 MOV P1, A MOV A, TH0 MOV P2, A SJMP BACK END

#include <reg51.h>
                                                                                                                            sbit t1 = P3 ^ 5;
void main(void)
{
    t1 = 1;
    TMOD = 0x60;
    TH1 = 0;
    while (1)
    {
        do
        {
            TR1 = 1;
            P1 = TL1;
        } while (TF1 == 0);
        TR1 = 0;
        TF1 = 0;
    }
}

// 2. Count no.  0f pulses with interrupts using counter 1
ORG 0000H LJMP MAIN
    ORG 001BH MOV P1,
    #55H MOV TL1, #0FAH MOV TH1, #0FFH RETI ORG 30H MAIN : MOV TMOD, #50h SETB P3 .5 MOV TL1, #0FAH MOV TH1, #0FFH MOV IE, #88H SETB TR1 HERE : MOV P1, #0AAH SJMP HERE END

#include <reg51.h>
                                                                                                                                                            sbit WAVE = P2 ^ 1;
void timer0() interrupt 1
{
    WAVE = ~WAVE; // toggle pin
    TH0 = 0xff;
    TL0 = 0xf5;
}
void main()
{
    TMOD = 0x05;
    TH0 = 0xff;
    TL0 = 0xf5;
    IE = 0x82; // enable interrupts
    TR0 = 1;   // start timer 0
    while (1)
        ; // wait until interrupted