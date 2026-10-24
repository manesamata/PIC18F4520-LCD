#include<p18f4520.h>

#define data_line PORTD
#define RS PORTCbits.RC1
#define RW PORTCbits.RC0
#define EN PORTCbits.RC2

#define r0 PORTBbits.RB5
#define r1 PORTBbits.RB6
#define r2 PORTBbits.RB7
#define c0 PORTBbits.RB1
#define c1 PORTBbits.RB2
#define c2 PORTBbits.RB3
#define c3 PORTBbits.RB4
#define led PORTBbits.RB0

void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(void);
void lcd_string(unsigned char*);

void main()
{
unsigned int pass[4],i;
unsigned char a[16]="Enter Pass";
unsigned char b[16]="Pass correct";
unsigned char c[16]="access granted";
unsigned char d[16]="pass incorrect";
unsigned char e[16]="access denied";

TRISB=0X1E;
ADCON1=0X0F;
INTCON2bits.RBPU=0;
lcd_init();
lcd_string(a);
lcd_cmd(0XC0);
led=0;
while(1)
{
i=0;
while(i<4)
{
r0=0;
r1=r2=1;
if(c0==0)
{
pass[i]=1;
lcd_data('1');
i++;
}
r1=0;
r1=r0=1;
if(c0==0)
{
pass[i]=2;
lcd_data('2');
i++;
}
r2=0;
r1=r0=1;
if(c0==0)
{
pass[i]=3;
lcd_data('3');
i++;
}
r0=0;
r1=r2=1;
if(c1==0)
{
pass[i]=4;
lcd_data('4');
i++;
}
r1=0;
r0=r2=1;
if(c1==0)
{
pass[i]=5;
lcd_data('5');
i++;
}
r2=0;
r0=r2=1;
if(c1==0)
{
pass[i]=6;
lcd_data('6');
i++;
}
r0=0;
r1=r2=1;
if(c2==0)
{
pass[i]=7;
lcd_data('7');
i++;
}
r1=0;
r0=r2=1;
if(c2==0)
{
pass[i]=8;
lcd_data('8');
i++;
}
r2=0;
r1=r0=1;
if(c2==0)
{
pass[i]=9;
lcd_data('9');
i++;
}
delay();
}
if((pass[0]==1)&&(pass[1]==1)&&(pass[2]==1)&&(pass[3]==1))
{
lcd_cmd(0X01);
lcd_cmd(0X80);
lcd_string(b);
lcd_cmd(0XC0);
lcd_string(c);
led=1;
}
else
{
lcd_cmd(0X01);
lcd_cmd(0X80);
lcd_string(d);
lcd_cmd(0XC0);
lcd_string(e);
led=1;
}
}
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
void lcd_string(unsigned char *p)
{
while(*p!='\0')
{
lcd_data(*p);
p++;
}
}
void delay(void)
{
int i,j;
for(i=0;i<300;i++)
{
for(j=0;j<200;j++)
{
}
}
}
