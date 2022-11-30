
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
#include "la66.h"
#include "uart_config.h"

/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
hMain_t hMain;
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

static void peripheral_handler_task				(void *param);
static void main_creatSysteTasks				(void);

const char *TAG = "Main";
/* FUNCTION PROTOTYPES -------------------------------------------------------*/

static void peripheral_handler_task(void *param)
{
	uartHandler_t la66Packet;
//	uint8_t la66Packet[200] = {0};
//	uint16_t packetSize	= 0;
	while(1)
	{
		if(xQueueReceive(uartRxStore_queue, (void *)&la66Packet, portMAX_DELAY))
//		if(xSemaphoreTake(UART_RXsem, portMAX_DELAY) == pdTRUE)
		{
//			memset(&la66Packet, 0, sizeof(uartHandler_t));

//			packetSize = uartGetRxBuffer(la66Packet);
			ESP_LOGI(TAG, "received packet: %s",(char*)la66Packet.uart_rxBuffer);

			la66_packetParser((char*)la66Packet.uart_rxBuffer, la66Packet.uart_rxPacketSize);
			memset(&la66Packet, 0, sizeof(uartHandler_t));
		}
	}
}


static void main_creatSysteTasks(void)
{
	xTaskCreatePinnedToCore(uart_event_task, "uart event", 10000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(peripheral_handler_task, "peripheral handler", 10000, NULL, 4, NULL, 1);
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
