#include<p18f4520.h>
#define data_line PORTD
#define RS PORTCbits.RC1
#define RW PORTCbits.RC0
#define EN PORTCbits.RC2

void lcd_4bit_init(void);
void lcd_4bit_cmd(unsigned char);
void lcd_cmd(unsigned char);
void lcd_4bit_data(unsigned char);
void delay(void);

void main()
{
lcd_4bit_init();
lcd_4bit_data('H');
lcd_4bit_data('E');
lcd_4bit_data('L');
lcd_4bit_data('L');
lcd_4bit_data('O');
while(1);
}
void lcd_4bit_init(void)
{
TRISC=0X00;
TRISD=0X00;
lcd_cmd(0X20);
lcd_4bit_cmd(0X28);
lcd_4bit_cmd(0X01);
lcd_4bit_cmd(0X80);
lcd_4bit_cmd(0X0F);
}
void lcd_4bit_cmd(unsigned char C)
{
unsigned char C1=C;
RS=0;
RW=0;
C=C&0XF0;
data_line=C;
EN=1;
delay();
EN=0;
C1=C1&0X0F;
C1=C1<<4;
data_line=C1;
EN=1;
delay();
EN=0;
}
void lcd_4bit_data(unsigned char C)
{
unsigned char C1=C;
RS=1;
RW=0;
C=C&0XF0;
data_line=C;
EN=1;
delay();
EN=0;
C1=C1&0X0F;
C1=C1<<4;
data_line=C1;
EN=1;
delay();
EN=0;
}
void lcd_cmd(unsigned char C)
{
data_line=C;
RS=0;
RW=0;
EN=1;
delay();
EN=0;
}
void delay(void)
{
int i,j;
for(i=0;i<200;i++)
{
for(j=0;j<200;j++)
{
}
}
}




