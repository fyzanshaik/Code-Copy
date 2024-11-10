// 7. LCD DISPLAY INTERFACING

#include <reg51.h>
sfr ldata = 0x0a0; // P2=LCD data pins
sbit rs = P3 ^ 7;
sbit rw = P3 ^ 6;
sbit en = P3 ^ 5;
unsigned char str1[16] = "VardhamanCollege";
unsigned char str2[15] = " of Engineering";
void MSDelay(unsigned int itime)
{
    unsigned int i, j;
    for (i = 0; i < itime; i++)
        for (j = 0; j < 1275; j++)
            ;
}
void lcdcmd(unsigned int value)
{
    ldata = value;
    rs = 0;
    rw = 0;
    en = 1;
    MSDelay(1);
    en = 0;
    return;
}
// put the value on the pins
// strobe the enable pin
void lcddata(unsigned char value)
{
    ldata = value
        rs = 1;
    rw = 0;
    en = 1;
    MSDelay(5);
    en = 0;
    return;
}
void main()
{
    unsigned int x;
    lcdcmd(0x38);
    lcdcmd(0x0E);
    lcdcmd(0x01);
    lcdcmd(0x06);
    ;
    // put the value on the pins
    // strobe the enable pin
    lcdcmd(0x80); // line 1, position 6
    for (x = 0; x < 16; x++)
    {
        lcddata(str1[x]);
        MSDelay(25);
    }
    lcdcmd(0xc0);
    for (x = 0; x < 15; x++)
    {
        lcddata(str2[x]);
        MSDelay(25);
    }
    while (1)
        ;
}