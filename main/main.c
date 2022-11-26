
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

#include "driver/temp_sensor.h"

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

    ESP_LOGI(TAG, "Initializing Temperature sensor");
    float tsens_out;
    temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();
    temp_sensor_get_config(&temp_sensor);
    ESP_LOGI(TAG, "default dac %d, clk_div %d", temp_sensor.dac_offset, temp_sensor.clk_div);
    temp_sensor.dac_offset = TSENS_DAC_DEFAULT; // DEFAULT: range:-10℃ ~  80℃, error < 1℃.
    temp_sensor_set_config(temp_sensor);
    temp_sensor_start();
    ESP_LOGI(TAG, "Temperature sensor started");
    while (1) {
        vTaskDelay(1000 / portTICK_RATE_MS);
        temp_sensor_read_celsius(&tsens_out);
        ESP_LOGI(TAG, "Temperature out celsius %.02f°C", tsens_out);
    }
}
/**************************  Useful Electronics  ****************END OF FILE***/
