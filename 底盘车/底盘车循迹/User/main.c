//#include "stm32f10x.h"                  // Device header
//#include "Delay.h"
//#include "OLED.h"
//#include "LED.h"
//#include "Timer.h"
//#include "Key.h"
//#include "MPU6050.h"
//#include "BlueSerial.h"
//#include "math.h"
//#include "Motor.h"
//#include "PWM.h"
//#include "Encoder.h"
//#include "Serial.h"
//#include "MyI2C.h"
//#include "PID.h"
//#include "string.h"
//#include "stdlib.h"
//#include "Tracker.h"

///*MPU6050测试*/
////int16_t AX, AY, AZ, GX, GY, GZ;
////uint8_t TimerErrorFlag;
////uint16_t TimerCount;

////float AngleAcc;
////float  AngleGyro;
////float Angle;
//////float Alpha;
////uint8_t KeyNum ,Runflag;  //Runflag 是运行标志位，1是运行 0是停止
////int16_t LeftPWM ,RightPWM;
////int16_t AvePWM  ,DifPWM;
////float LeftSpeed , RightSpeed;
////float AveSpeed ,DifSpeed;  

////uint8_t Count=0;
//////PID  参数


////PID_t SpeedPID = {
////	
////	.Kp =0 ,    //2
////	.Ki =0 ,         //0.05
////	.Kd =0 ,
////	
////	.OutMax =20 ,
////	.OutMin =-20
////	
////	
////	
////};















//int main(void)
//{
//	//OLED_Init();
//	//MPU6050_Init();
//	//Key_Init();
//	//Timer_Init();
//	//BlueSerial_Init();
//	Motor_Init();
//	PWM_Init();
//	//Serial_Init();
//	//Encoder_Init();
//	LED_Init();
//	Tracker_Init();
//	

////	Motor_SetSpeed(1,10);
////	Motor_SetSpeed(2,10);
//	
////				MotorL1_SetSpeed(50);
////				MotorL2_SetSpeed(50); 
//	while (1)
//	{

//		if(//GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1 &&          
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 0 &&
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 0 )// &&      //向前走 // 4 5 //6//7 //8
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_7) == 0 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_8) == 0)
//		{
//				MotorL1_SetSpeed(50);
//				MotorL2_SetSpeed(50);
//				LED_ON();
//		}
//		if(//GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1 &&          
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 1 &&             //灭是1
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 1 )// &&      //向前走 // 4 5 //6//7 //8
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_7) == 0 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_8) == 0)
//		{
//				MotorL1_SetSpeed(0);
//				MotorL2_SetSpeed(0);
//				LED_OFF();
//		}
//		
//		if(//GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1 &&          
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 0 &&             
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 1 )// &&      //左转
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_7) == 0 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_8) == 0)
//		{
//				MotorL1_SetSpeed(80);
//				MotorL2_SetSpeed(0);
//				Delay_ms(50);
//		}
//		
//		if(//GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1 &&          
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 1 &&             
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 0 )// &&      //右转
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_7) == 0 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_8) == 0)
//		{
//				MotorL1_SetSpeed(0);
//				MotorL2_SetSpeed(80);
//				Delay_ms(50);

//		}
////		
////		if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_8) == 1 &&          //全白无黑线 
////			GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_9) == 0 &&
////			GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_10) == 0 &&      //向前走
////			GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_11) == 0 &&
////			GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_12) == 0)
////		{
////			Motor_SetSpeed(1 ,0);
////			Motor_SetSpeed(2 ,0);
////			Delay_s(20);
////			Motor_SetSpeed(1,0);
////			Motor_SetSpeed(2,50 + SpeedPID.Out);
////			Count =Count +1;
////		}
//		
//	}
//}





////中断
////void TIM1_UP_IRQHandler(void)
////{

////	static int Count1;
////	
////	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
////	{
////		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
////		

//////		Key_Tick();
////		if(Count ==4)
////		{
////			Count=0;
////			Buzzer_ON();       //蜂鸣器
////		}
////		else 
////		{
////			Buzzer_OFF();
////		}
////		
////		Count1 ++;
////		if(Count1 >=50)   //50ms一次  //速度环PID控制
////		{
////			Count1 =0;
////			
////			LeftSpeed =Encoder_Get(1) /52.0 /0.05 /34 ;//四频脉冲//中断时间//减速比
////			RightSpeed =Encoder_Get(2) /52.0 /0.05 /34 ;
////			
////			AveSpeed =(LeftSpeed +RightSpeed) / 2.0 ;
////			DifSpeed =(LeftSpeed - RightSpeed );
////			
////			
////			//PID 运算
////			SpeedPID.Actual =DifSpeed ;  //差分速度
////			SpeedPID.Target = 0 ;
////			PID_Update(&SpeedPID);  //运算
//////			Motor_SetSpeed(1,50 + SpeedPID.Out);
//////			Motor_SetSpeed(2,50 + SpeedPID.Out);
////				
////				
////			
////			
////		}
////		
////		
////		
////		
////		if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
////		{
////			TimerErrorFlag = 1;
////			TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
////		}
////		TimerCount = TIM_GetCounter(TIM1);
////	}
////}



//#include "stm32f10x.h"                  // Device header
//#include "Delay.h"
//#include "OLED.h"
//#include "LED.h"
//#include "Key.h"
//#include "Timer.h"
//#include "MPU6050.h"
//#include "BlueSerial.h"
//#include "math.h"
//#include "Motor.h"
//#include "PWM.h"
//#include "Encoder.h"
//#include "Serial.h"
//#include "MyI2C.h"
//#include "PID.h"
//#include "string.h"
//#include "stdlib.h"
//#include "Tracker.h"

//// ====================== 四路循迹传感器引脚定义 ======================
//// 红外顺序：1  →  4  →  5  →  10
//#define TRACKER_PIN1   GPIO_Pin_1    // 左1
//#define TRACKER_PIN4   GPIO_Pin_4    // 左2
//#define TRACKER_PIN5   GPIO_Pin_5    // 右2
//#define TRACKER_PIN10  GPIO_Pin_10   // 右1
//#define TRACKER_PORT   GPIOB

//// ====================== 传感器状态枚举（switch专用） ======================
//typedef enum {
//    // 状态值 = 二进制(左1,左2,右2,右1)
//    TRACK_STOP          = 0x0F,  // 1111  全白/停止
//    TRACK_FORWARD       = 0x00,  // 0000  中间两个检测到 → 直行
//    TRACK_SMALL_LEFT    = 0x04,  // 0100  左2检测到 → 小左转
//    TRACK_SMALL_RIGHT   = 0x02,  // 0010  右2检测到 → 小右转
//    TRACK_BIG_LEFT      = 0x08,  // 1000  左1检测到 → 大左转
//    TRACK_BIG_RIGHT     = 0x01,  // 0001  右1检测到 → 大右转
//    TRACK_LEFT_MIX      = 0x0C,  // 1100  左侧两个 → 大左转
//    TRACK_RIGHT_MIX     = 0x03,  // 0011  右侧两个 → 大右转
//} Tracker_State;

//// 记录最后方向（全白时补正）
//static Tracker_State last_track_state = TRACK_FORWARD;



////TRACK_STOP          = 0x0F,  // 1111  全白/停止
////    TRACK_FORWARD       = 0x06,  // 0110  中间两个检测到 → 直行
////    TRACK_SMALL_LEFT    = 0x04,  // 0100  左2检测到 → 小左转
////    TRACK_SMALL_RIGHT   = 0x02,  // 0010  右2检测到 → 小右转
////    TRACK_BIG_LEFT      = 0x08,  // 1000  左1检测到 → 大左转
////    TRACK_BIG_RIGHT     = 0x01,  // 0001  右1检测到 → 大右转
////    TRACK_LEFT_MIX      = 0x0C,  // 1100  左侧两个 → 大左转
////    TRACK_RIGHT_MIX     = 0x03,  // 0011  右侧两个 → 大右转
//int main(void)
//{
//	// 外设初始化
//	Motor_Init();
//	PWM_Init();
//	LED_Init();
//	Tracker_Init();
//	
//	while (1)
//	{
//		
//		if(//GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1 &&          
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 0 &&             
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 0  &&      //右转
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_12) == 0 &&
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_13) == 0 &&
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_14) == 0 &&             
//			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_14) == 0  &&      //右转
//			GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_9) == 0 &&
//			GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_8) == 0)
//		
//		{
//				LED_ON();

//		}
//		
////			if(//GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1 &&          
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 1 &&             
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 1  &&      //右转
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_9) == 1 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_8) == 1 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_7) == 1 &&             
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_6) == 1  &&      //右转
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_5) == 1 &&
////			GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_4) == 1)
//		else
//		{
//			LED_OFF();

//		}
////		// ====================== 读取四路传感器状态（按你指定顺序） ======================
////		uint8_t tracker_state = 0;
////		tracker_state |= GPIO_ReadInputDataBit(TRACKER_PORT, TRACKER_PIN1)  << 3;  // 左1 → 位3
////		tracker_state |= GPIO_ReadInputDataBit(TRACKER_PORT, TRACKER_PIN4)  << 2;  // 左2 → 位2
////		tracker_state |= GPIO_ReadInputDataBit(TRACKER_PORT, TRACKER_PIN5)  << 1;  // 右2 → 位1
////		tracker_state |= GPIO_ReadInputDataBit(TRACKER_PORT, TRACKER_PIN10) << 0;  // 右1 → 位0

////		Delay_ms(4);  // 防抖
////		
////		// ====================== switch 统一控制 ======================
////		switch(tracker_state)
////		{
////			// ---------------------- 直行 ----------------------
////			case TRACK_FORWARD:
////				last_track_state = TRACK_FORWARD;
////				MotorL1_SetSpeed(-20);
////				MotorL2_SetSpeed(-20);
////				LED_ON();
////				break;
////			
////			// ---------------------- 小左转 ----------------------
////			case TRACK_SMALL_LEFT:
////				last_track_state = TRACK_SMALL_LEFT;
////				MotorL1_SetSpeed(-60);
////				MotorL2_SetSpeed(0);
////				break;
////			
////			// ---------------------- 小右转 ----------------------
////			case TRACK_SMALL_RIGHT:
////				last_track_state = TRACK_SMALL_RIGHT;
////				MotorL1_SetSpeed(0);
////				MotorL2_SetSpeed(-60);
////				break;
////			
////			// ---------------------- 大左转 ----------------------
////			case TRACK_BIG_LEFT:
////			
////				MotorL1_SetSpeed(0);
////				MotorL2_SetSpeed(-100);
////				Delay_ms(100);
////				break;
////			case TRACK_LEFT_MIX:
////				last_track_state = TRACK_BIG_LEFT;
////				MotorL1_SetSpeed(0);
////				MotorL2_SetSpeed(-100);
////				Delay_ms(100);
////				break;
////			
////			// ---------------------- 大右转 ----------------------
////			case TRACK_BIG_RIGHT:

////				MotorL1_SetSpeed(-100);
////				MotorL2_SetSpeed(0);
////				Delay_ms(100);
////				break;
////			case TRACK_RIGHT_MIX:
////				last_track_state = TRACK_BIG_RIGHT;
////				MotorL1_SetSpeed(-100);
////				MotorL2_SetSpeed(0);
////				Delay_ms(100);
////				break;
////			
////			// ---------------------- 全白停止 ----------------------
////			case TRACK_STOP:
////				MotorL1_SetSpeed(0);
////				MotorL2_SetSpeed(0);				
////				LED_OFF();
////				break;
////			
////			// ---------------------- 默认直行 ----------------------
////			default:
////				MotorL1_SetSpeed(-20);
////				MotorL2_SetSpeed(-20);
////				LED_ON();
////				break;
////		}
//	}
//}
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Key.h"
#include "Timer.h"
#include "MPU6050.h"
#include "BlueSerial.h"
#include "math.h"
#include "Motor.h"
#include "PWM.h"
#include "Encoder.h"
#include "Serial.h"
#include "MyI2C.h"
#include "PID.h"
#include "string.h"
#include "stdlib.h"
#include "Tracker.h"

// 8路循迹传感器 从左到右顺序：A9 A8 B15 B14 B13 B12 B1 B10
#define T1_PIN     GPIO_Pin_9    // 左1
#define T2_PIN     GPIO_Pin_8    // 左2
#define T3_PIN     GPIO_Pin_15   // 左3
#define T4_PIN     GPIO_Pin_14   // 左4
#define T5_PIN     GPIO_Pin_13   // 右4
#define T6_PIN     GPIO_Pin_12   // 右3
#define T7_PIN     GPIO_Pin_1    // 右2
#define T8_PIN     GPIO_Pin_10   // 右1

#define T_PORT_A   GPIOA
#define T_PORT_B   GPIOB

typedef enum {
    TRACK_STOP = 0,
    TRACK_FORWARD,
    TRACK_SMALL_LEFT,
    TRACK_SMALL_RIGHT,
    TRACK_BIG_LEFT,
    TRACK_BIG_RIGHT,
    TRACK_TURN_LEFT90,    // 正方形左转90°
    TRACK_TURN_RIGHT90    // 正方形右转90°
} Track_State;

int main(void)
{
    Motor_Init();
    PWM_Init();
    LED_Init();
    Tracker_Init();
//	Key_Init();
//	OLED_Init();
	
    Track_State now_state;
    uint8_t turn_flag = 0;  // 防止连续多次转弯
//	uint16_t KeyNum =0;
	uint16_t Count =0;
//	OLED_ShowString(1 ,1 ,"Count:" );
//	OLED_ShowString(2 ,1 ,"KEY:" );
    while (1)
    {
//		Buzzer_OFF();
//		Delay_ms(1000);
//		Buzzer_ON();
//		Delay_ms(1000);
//		KeyNum = Key_GetNum();

//		if(KeyNum == 1)
//		{
			// 读取8路传感器（0=黑线，1=白底）
			uint8_t t1 = GPIO_ReadInputDataBit(T_PORT_A, T1_PIN);
			uint8_t t2 = GPIO_ReadInputDataBit(T_PORT_A, T2_PIN);
			uint8_t t3 = GPIO_ReadInputDataBit(T_PORT_B, T3_PIN);
			uint8_t t4 = GPIO_ReadInputDataBit(T_PORT_B, T4_PIN);
			uint8_t t5 = GPIO_ReadInputDataBit(T_PORT_B, T5_PIN);
			uint8_t t6 = GPIO_ReadInputDataBit(T_PORT_B, T6_PIN);
			uint8_t t7 = GPIO_ReadInputDataBit(T_PORT_B, T7_PIN);
			uint8_t t8 = GPIO_ReadInputDataBit(T_PORT_B, T8_PIN);

			// ===================== 状态判断 =====================
			// 中间4路在黑线 → 直行
			if (t4 == 0 && t5 == 0)
			{
				now_state = TRACK_FORWARD;
				turn_flag = 0;
			}
			// 偏左 → 小右转
			else if (t3 == 0 || t2 == 0)
			{
				now_state = TRACK_SMALL_RIGHT;
			}
			// 偏右 → 小左转
			else if (t6 == 0 || t7 == 0)
			{
				now_state = TRACK_SMALL_LEFT;
			}
			// 正方形直角：只有最外侧检测到黑线 → 转90度
			else if ((t1 == 0 && t2 == 1 && t3 == 1 && t4 == 1) && !turn_flag)
			{
				now_state = TRACK_TURN_LEFT90;
				turn_flag = 1;
			}
			else if ((t8 == 0 && t7 == 1 && t6 == 1 && t5 == 1) && !turn_flag)
			{
				now_state = TRACK_TURN_RIGHT90;
				turn_flag = 1;
			}
			// 全白 → 停止
			else if (t1 && t2 && t3 && t4 && t5 && t6 && t7 && t8)
			{
				now_state = TRACK_STOP;
			}
			else
			{
				now_state = TRACK_FORWARD;
			}

			// ===================== 电机控制 =====================
			switch (now_state)
			{
				case TRACK_FORWARD:
					MotorL1_SetSpeed(-25);
					MotorL2_SetSpeed(-25);
					//LED_ON();
					break;

				case TRACK_SMALL_LEFT:
	//                MotorL1_SetSpeed(0);
	//                MotorL2_SetSpeed(-30);
					MotorL1_SetSpeed(-25);
					MotorL2_SetSpeed(0);
					break;

				case TRACK_SMALL_RIGHT:
	//                MotorL1_SetSpeed(-30);
	//                MotorL2_SetSpeed(0);
					MotorL1_SetSpeed(0);
					MotorL2_SetSpeed(-25);
					break;

				case TRACK_TURN_LEFT90:
					// 原地左转90度
					MotorL1_SetSpeed(0);
					MotorL2_SetSpeed(0);
					Delay_s(10);
				
					MotorL1_SetSpeed(0);
					MotorL2_SetSpeed(-38);
					Delay_ms(700);  // 根据实际调整
					Count++;
				
				    if (Count % 4 == 0) {
								Buzzer_ON();
								Delay_ms(500);   // 短鸣200ms
								Buzzer_OFF();
							}
					
					break;

				case TRACK_TURN_RIGHT90:
					// 原地右转90度
				
					MotorL1_SetSpeed(0);
					MotorL2_SetSpeed(0);
					Delay_s(10);					
					MotorL1_SetSpeed(-38);
					MotorL2_SetSpeed(0);
					Delay_ms(700);
					Count++;
				
				    if (Count % 4 == 0) {
								Buzzer_ON();
								Delay_ms(500);   // 短鸣200ms
								Buzzer_OFF();
							}
				
					break;

				case TRACK_STOP:
					MotorL1_SetSpeed(-25);
					MotorL2_SetSpeed(-25);
					//LED_OFF();
					break;

				default:
					MotorL1_SetSpeed(-25);
					MotorL2_SetSpeed(-25);
					
				

			}
	

	
					
			Delay_ms(5);

  }
}
