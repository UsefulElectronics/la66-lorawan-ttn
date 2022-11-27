
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  main1.c
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Aug 20, 2022
 * @brief   		:
 *
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/

#include "temp_config.h"

#include "main.h"

#include "uart_config.h"

/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
hMain_t hMain;
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/


static void main_creatSysteTasks				(void);

const char *TAG = "Main";
/* FUNCTION PROTOTYPES -------------------------------------------------------*/


static void main_creatSysteTasks(void)
{
	xTaskCreatePinnedToCore(uart_event_task, "uart event", 10000, NULL, 4, NULL, 1);
}




/**
 * @brief Program starts from here
 *
 */
void app_main(void)
{

    uart_config();

    main_creatSysteTasks();

    tempSensor_init();

    while (1) {
        vTaskDelay(1000 / portTICK_RATE_MS);

        ESP_LOGI(TAG, "Temperature out celsius %.02f°C", tempSensor_read());
    }
}
/**************************  Useful Electronics  ****************END OF FILE***/
