
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
/**
 * @brief This task is used to form AT command that contains the packet to be sent to TTN
 *
 * @note :
 *   Sending a stringing is not a good practice with LoRaWAN or any IOT, encode data in order not to wast battery life and air time. Air time is a commodity used by everyone
 *   Please implement FUP (Fair usage policy) you are allowed 30 seconds uplink time a day and max 10 downlinks.
 *
 *
 */
static void la66_packetTx_task(void *param)
{
//	static char TempBuffer[30] = {0};

	float TempBuffer = tempSensor_read();

	uartHandler_t hUart;

	memset(&hUart, 0, sizeof(uartHandler_t));

	while(1)
	{
		if(la66_packetJoinStatus())
		{
//			sprintf(TempBuffer,"%.02f",  tempSensor_read());

//			hUart.uart_txPacketSize = la66_sendStringPacket(TempBuffer,  (char*)hUart.uart_txBuffer);

			hUart.uart_txPacketSize = la66_sendDataPacket(&TempBuffer, (char*)hUart.uart_txBuffer, sizeof(float));


			xQueueSendToBack(uartTx_queue, &hUart, portMAX_DELAY);

			memset(&hUart, 0, sizeof(uartHandler_t));
		}

		vTaskDelay(600000 / portTICK_PERIOD_MS);
	}
}

static void main_creatSysteTasks(void)
{
	xTaskCreatePinnedToCore(uart_event_task, "uart event", 10000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(peripheral_handler_task, "peripheral handler", 10000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(la66_packetTx_task, "peripheral handler", 10000, NULL, 4, NULL, 1);

	xTaskCreatePinnedToCore(uart_transmission_task, "USART TX handling task", 10000, NULL, 4, NULL, 1);



}





/**
 * @brief Program starts from here
 *
 */
void app_main(void)
{

    uart_config();

    tempSensor_init();

    main_creatSysteTasks();



}
/**************************  Useful Electronics  ****************END OF FILE***/
