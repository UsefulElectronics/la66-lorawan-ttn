
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  temp_config.c
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Nov 26, 2022
 * @brief   		:
 *
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "temp_config.h"
#include "driver/temp_sensor.h"
#include "stdlib.h"
/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
void tempSensor_init(void)
{
    temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();

    temp_sensor_get_config(&temp_sensor);

    temp_sensor.dac_offset = TSENS_DAC_DEFAULT; // DEFAULT: range:-10℃ ~  80℃, error < 1℃.

    temp_sensor_set_config(temp_sensor);

    temp_sensor_start();
}

float tempSensor_read(void)
{
	float ReadVal;

	temp_sensor_read_celsius(&ReadVal);

	return ReadVal;
}

/**************************  Useful Electronics  ****************END OF FILE***/
