
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  timer_config.c
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Nov 26, 2022
 * @brief   		:
 *
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "timer_config.h"

/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
// void timer_config(uint8_t TimerGroup, uint8_t TimerIdx, uint8_t Interrupt_Level)
//{
//	timer_config_t config;
//	config.alarm_en = TIMER_ALARM_EN;				//Alarm is the value that the timer will count to before rolling over
//	config.counter_dir = TIMER_COUNT_UP;
//	config.auto_reload = TIMER_AUTORELOAD_EN;		//When the timer counts to the alarm value then reloads the value given in this function
//	config.counter_en = TIMER_PAUSE;				//timer_set_counter_value
//	config.intr_type = TIMER_INTR_LEVEL;
//	config.divider = TIMER_DIVIDER;
//	timer_init(TimerGroup, TimerIdx, &config);
//	timer_set_counter_value(TimerGroup, TimerIdx, 0x00000000ULL);
//	timer_set_alarm_value(TimerGroup, TimerIdx, TIMER_PERIODE);
//	timer_enable_intr(TimerGroup, TimerIdx);		//timer_group0_isr is the interrupt function that is executed when an interrupt occurs
//    timer_isr_register(TimerGroup, TimerIdx, timer_group0_isr,
//        (void *) TimerIdx, Interrupt_Level, NULL);
////	timer_start(TimerGroup, TimerIdx);
//}


/**************************  Useful Electronics  ****************END OF FILE***/
