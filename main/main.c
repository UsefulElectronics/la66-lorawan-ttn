
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
static void la66_packetTx_task					(void *param);
static void main_creatSysteTasks				(void);

const char *TAG = "Main";
/* FUNCTION PROTOTYPES -------------------------------------------------------*/


static void peripheral_handler_task(void *param)
{
	uartHandler_t la66Packet;

	while(1)
	{
		if(xQueueReceive(uartRxStore_queue, (void *)&la66Packet, portMAX_DELAY))
		{

			ESP_LOGI(TAG, "received packet: %s",(char*)la66Packet.uart_rxBuffer);

			la66_packetParser((char*)la66Packet.uart_rxBuffer, la66Packet.uart_rxPacketSize);
			memset(&la66Packet, 0, sizeof(uartHandler_t));
		}
	}
}

static void la66_packetTx_task(void *param)
{
	static char TempBuffer[30] = {0};

	uartHandler_t hUart;

	memset(&hUart, 0, sizeof(uartHandler_t));

	while(1)
	{
		if(la66_packetJoinStatus())
		{
			sprintf(TempBuffer,"Temperature: %.02f",  tempSensor_read());

			hUart.uart_txPacketSize = la66_sendStringPacket(TempBuffer,  (char*)hUart.uart_txBuffer);

			xQueueSendToBack(uartTx_queue, &hUart, portMAX_DELAY);

			memset(TempBuffer, 0, sizeof(TempBuffer));

			memset(&hUart, 0, sizeof(uartHandler_t));
		}

		vTaskDelay(60000 / portTICK_PERIOD_MS);
	}
}

static void main_creatSysteTasks(void)
{
	xTaskCreatePinnedToCore(uart_event_task, "uart event", 10000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(peripheral_handler_task, "peripheral handler", 10000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(la66_packetTx_task, "peripheral handler", 5000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(uart_transmission_task, "USART TX handling task", 10000, NULL, 4, NULL, 1);

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

}
/**************************  Useful Electronics  ****************END OF FILE***/
