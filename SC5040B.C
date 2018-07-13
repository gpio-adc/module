 /****************************************************
;www.stchip.com
;OTP 语音芯片串行二线模式测试程序
;主芯片:MPC82L52(1T)
;工作频率:12MHz
;适用型号:SC5020 SC5040 Sc5060 Sc5080...
;亿矽特科技
****************************************************/

#include <reg52.h>
void delay_us(unsigned int count);
void delay_ms(unsigned int count) ;	  
void SC_WBusy(void);
void SC_WBusyL(void);
void SC5040_SDA(unsigned char sdata);

/**************端口定义*****************/

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
;控制地址段放音
;入口参数:cnt;
;出口参数:无
**************************************/



void SC5040_SDA(unsigned char sdata)
{    
     unsigned char i;

     DATA=0;
     delay1ms(3);							   //拉低3MS	  最小大于2.5MS
     for(i=0;i<8;i++)
     {  
       
        if(sdata&0x01)
        {
           DATA=1; 
           delay20us(60);  					  //1200US		 最小600US
           DATA=0;
           delay20us(20);  					 //400US		 最小200US
        }
        else
        { 
           DATA=1; 
           delay20us(20);  				   //400US			 最小200US
           DATA=0;
           delay20us(60);  				  //1200US			 最小600US
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
 
  /*************主程序****************/

main (void)
{


while(1)
{  
     SC5040_SDA(0x01);		   //第1段
	 SC_WBusy();				//等待BUSY脚信号
	 delay1ms(50);
 	 SC5040_SDA(0x02);		   //第2段
	 SC_WBusy();			   //等待BUSY脚信号
	 delay1ms(50);
         SC5040_SDA(0x03);		   //第3段
	 SC_WBusy();			  //等待BUSY脚信号
	 delay1ms(50);
 	 SC5040_SDA(0x04);		 //第4段
	 SC_WBusy();			 //等待BUSY脚信号
	 delay1ms(50);
	 SC5040_SDA(0x05);		   //第5段
	 SC_WBusy();			  //等待BUSY脚信号
	 delay1ms(50);
 	 
 
}}
  