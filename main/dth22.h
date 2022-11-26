
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  dth22.h
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Nov 26, 2022
 * @brief   		:
 *
 ******************************************************************************/

#ifndef MAIN_DTH22_H_
#define MAIN_DTH22_H_


/* INCLUDES ------------------------------------------------------------------*/
#include "stdlib.h"
#include "string.h"
/* MACROS --------------------------------------------------------------------*/

/* ENUMORATIONS --------------------------------------------------------------*/
enum
{
	INPUT = 0,
	OUTPUT = 1
};

typedef enum
{
	DHT22_IDLE,
	DHT22_RX_START,
	DHT22_RX_ONGOING,
	DHT22_RX_TERMINATED,

}dth22_operationMode_e;
/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/



#endif /* MAIN_DTH22_H_ */

/**************************  Useful Electronics  ****************END OF FILE***/
