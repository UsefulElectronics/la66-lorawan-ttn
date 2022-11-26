
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  dth22.c
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Nov 26, 2022
 * @brief   		:
 *
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "dth22.h"

/* PRIVATE STRUCTRES ---------------------------------------------------------*/
typedef struct
{
	uint8_t 				pinNumber;
	dth22_operationMode_e	mode;
	void* 					timerStart;
	union
	{
		uint8_t all;
		struct
		{
			uint8_t reserved	:7,
					pageChange	:1;
		}flags;
	}main_status;

}dth22_handler_t;
/* VARIABLES -----------------------------------------------------------------*/
dth22_handler_t hDth22_sensor;
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
void dth22_init(void* timerStart)
{
	memset(&hDth22_sensor, 0, sizeof(dth22_handler_t));
	hDth22_sensor.timerStart = timerStart;
}

void dth22_directionSet(uint8_t mode)
{
	switch (mode)
	{
		case INPUT:

			break;
		case OUTPUT:

			break;

	}

}
void dth22_negEdgeTrigger(uint8_t mode)
{
	//
}

/**************************  Useful Electronics  ****************END OF FILE***/
