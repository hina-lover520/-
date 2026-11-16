#include "stm32f10x.h"                  // Device header   //电机
#include "PWM.h"  

void  Motor_Init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;  //设置为推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_Pin_3); // STBY=高，使能驱动
	
	PWM_Init ();   //开启定时器
	
}


void MotorL1_SetSpeed(int8_t Speed)    //设置电机1速度  //其实这里的Speed就是compare
{                                              //compare就是要写入的CCR的值，进而改变占空比
	if(Speed >=0)                              //占空比=CCR/(ARR+1)
	{	
		
		
		GPIO_SetBits(GPIOA ,GPIO_Pin_4);   //高电平PA4
		GPIO_ResetBits(GPIOA ,GPIO_Pin_5);  //低电平PA5
		PWM_SetCompare2(Speed);      //设置速度
		
	}
	
	else   //Speed<0
	{
		GPIO_ResetBits(GPIOA ,GPIO_Pin_4);   //低电平PA4
		GPIO_SetBits(GPIOA ,GPIO_Pin_5);  //高电平PA5
		PWM_SetCompare2(-Speed);      //设置速度 //因为PWM的输出结果为正数，所以当速度为负数时要加负号
		
		
		
	}
	
	
	
}

void MotorL2_SetSpeed(int8_t Speed)    //设置电机2速度
{
	if(Speed >=0)
	{	
		
		
		GPIO_ResetBits(GPIOA ,GPIO_Pin_6);   //高电平PA4
		GPIO_SetBits(GPIOA ,GPIO_Pin_7);  //低电平PA5
		PWM_SetCompare3(Speed);      //设置速度
		
	}
	
	else   //Speed<0
	{
		GPIO_SetBits(GPIOA ,GPIO_Pin_6);   //低电平PA4
		GPIO_ResetBits(GPIOA ,GPIO_Pin_7);  //高电平PA5
		PWM_SetCompare3(-Speed);      //设置速度 //因为PWM的输出结果为正数，所以当速度为负数时要加负号
		
		
		
	}
	
	
	
}



