 /****************************************************
;www.stchip.com
;OTP ����оƬ���ж���ģʽ���Գ���
;��оƬ:MPC82L52(1T)
;����Ƶ��:12MHz
;�����ͺ�:SC5020 SC5040 Sc5060 Sc5080...
;�����ؿƼ�
****************************************************/

#include <reg52.h>
void delay_us(unsigned int count);
void delay_ms(unsigned int count) ;	  
void SC_WBusy(void);
void SC_WBusyL(void);
void SC5040_SDA(unsigned char sdata);

/**************�˿ڶ���*****************/

sbit BUSY =P2^5; 
sbit DATA=P1^3; 

/**************************************/

void delay20us(unsigned int count)
{
 unsigned int i,j;
 for(i=0;i<count;i++)
 {
    for(j=0;j<0;j++);
 }
}

	void delay1ms(unsigned int count)
{
unsigned int i,j;
for(i=0;i<count;i++)
{ for(j=0;j<110;j++);
}
}



/**************************************
;���Ƶ�ַ�η���
;��ڲ���:cnt;
;���ڲ���:��
**************************************/



void SC5040_SDA(unsigned char sdata)
{    
     unsigned char i;

     DATA=0;
     delay1ms(3);							   //����3MS	  ��С����2.5MS
     for(i=0;i<8;i++)
     {  
       
        if(sdata&0x01)
        {
           DATA=1; 
           delay20us(60);  					  //1200US		 ��С600US
           DATA=0;
           delay20us(20);  					 //400US		 ��С200US
        }
        else
        { 
           DATA=1; 
           delay20us(20);  				   //400US			 ��С200US
           DATA=0;
           delay20us(60);  				  //1200US			 ��С600US
        } 
        sdata>>=1;
     } 
      DATA=1;  						  //200US
      delay20us(10); 
} 


void SC_WBusy(void)
{
unsigned int times;
 for(times=0;times<100;times++)
 {
 delay1ms(50);
 if(BUSY==1) break;
  
 }
}
 
  /*************������****************/

main (void)
{


while(1)
{  
     SC5040_SDA(0x01);		   //��1��
	 SC_WBusy();				//�ȴ�BUSY���ź�
	 delay1ms(50);
 	 SC5040_SDA(0x02);		   //��2��
	 SC_WBusy();			   //�ȴ�BUSY���ź�
	 delay1ms(50);
         SC5040_SDA(0x03);		   //��3��
	 SC_WBusy();			  //�ȴ�BUSY���ź�
	 delay1ms(50);
 	 SC5040_SDA(0x04);		 //��4��
	 SC_WBusy();			 //�ȴ�BUSY���ź�
	 delay1ms(50);
	 SC5040_SDA(0x05);		   //��5��
	 SC_WBusy();			  //�ȴ�BUSY���ź�
	 delay1ms(50);
 	 
 
}}
  