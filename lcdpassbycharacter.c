#include<p18f4520.h>
#define data_line PORTD
#define RS PORTCbits.RC1
#define RW PORTCbits.RC0
#define EN PORTCbits.RC2

void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(void);

void main()
{
lcd_init();
lcd_data('H');
lcd_data('E');
lcd_data('L');
lcd_data('L');
lcd_data('O');
while(1);
}
void lcd_init(void)
{
TRISD=0X00;
TRISC=0X00;
lcd_cmd(0X30);
lcd_cmd(0X38);
lcd_cmd(0X01);
lcd_cmd(0X80);
lcd_cmd(0X0C);
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
void lcd_data(unsigned char C)
{
data_line=C;
RS=1;
RW=0;
EN=1;
delay();
EN=0;
}
void delay(void)
{
int i,j;
for(i=0;i<100;i++)
{
for(j=0;j<100;j++)
{
}
}
}




