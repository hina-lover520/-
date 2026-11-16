#include "stm32f10x.h"                  // Device header  //PWM初始化

void PWM_Init(void)
{
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 ,ENABLE );
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);        //打开AFIO时钟
//	
//	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);            	//GPIO引脚重映射//将PIn_0引脚映射为Pin_15
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);                //解除调试端口
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP ;  //设置为复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;  //GPIO_Pin_2
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
    TIM_InternalClockConfig(TIM2);
	//TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSbC_OFF,TIM_ExtTRGPolarity_NonInverted,0x0F);
    
    
    //配置时基单元
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision =  TIM_CKD_DIV1 ;
    TIM_TimeBaseInitStructure.TIM_CounterMode =   TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 100-1;                     //ARR自动重装器的值 //周期 //ARR
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72-1;					//PSC预分频器的值   //PSC
	
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;            //重复寄存器的值
    
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
        /////////输出比较单元
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_OCStructInit (&TIM_OCInitStructure);   //给结构体赋初始值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ; //极性选择
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable ;  //输出状态，输出使能。
	TIM_OCInitStructure.TIM_Pulse =0;                              //用来设置CCR寄存器的值  //CCR
	
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);       //PWM OC1通道
    TIM_OC2Init(TIM2,&TIM_OCInitStructure);     //驱动第二个电机用的另一个通道
	TIM_OC3Init(TIM2,&TIM_OCInitStructure);
	
    TIM_Cmd(TIM2 , ENABLE );   //启动定时器
    
    
}

//Compare 要写入的CCR的值，范围：0~100
//动态改变CCR值从而改变占空比
void PWM_SetCompare1(uint16_t Compare)    //电机1
{
	TIM_SetCompare1(TIM2, Compare);
	
}

void PWM_SetCompare2(uint16_t Compare)   //电机2
{
	TIM_SetCompare2(TIM2, Compare);
	
}

void PWM_SetCompare3(uint16_t Compare)   //电机2
{
	TIM_SetCompare3(TIM2, Compare);
	
}
