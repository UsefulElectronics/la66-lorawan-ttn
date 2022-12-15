
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  la66.c
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Sep 30, 2022
 * @brief   		:
 *
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "la66.h"

/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
la66_handler_t hLa66;

static char *TAG = "LA66";
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/


/**
 * @brief
 *
 */
void la66_config(void)
{
	memset(&hLa66, 0, sizeof(la66_handler_t));
}

/**
 * @brief
 *
 * @param packet
 */
void la66_packetParser(char* packet, uint16_t packetSize)
{
	if(false == hLa66.joinStatus)
	{
		uint8_t offset = packetSize - ( 2 + strlen(AT_NETWORK_JOINED));

		if(00 == memcmp(&packet[offset], AT_NETWORK_JOINED, strlen(AT_NETWORK_JOINED)))
		{
			hLa66.joinStatus = true;
			ESP_LOGI(TAG, "LoRaWAN network has been joined.");
		}
	}
}
/**
 * @brief AT+SEND=01,01,5,HELLO
 *
 * @param packet
 * @param packetSize
 */
uint16_t la66_sendStringPacket(char* stringPacket, char* targetPacketBuffer)
{
	uint8_t fPort = 1;

	uint16_t packetLength =  strlen(stringPacket);

	//TODO LA66 module problem in handling '.' character within a string
	stringPacket[15] = ':';

	sprintf(targetPacketBuffer, "%s1,%d,%d,%s%s",
			AT_SEND_ASCII_STRING,
			fPort,
			packetLength,
			stringPacket,
			AT_TERMINATOR);

	packetLength = strlen(targetPacketBuffer);


	return packetLength;
}

/**
 * @brief AT+SENDB=01,01,8,08820802581ea0a5
 *
 * @param packet
 * @param packetSize
 */
uint16_t la66_sendDataPacket(void* dataPacket, char* targetPacketBuffer, uint8_t packetSize)
{
	uint8_t fPort = 1;

	uint16_t packetLength =  packetSize;

	sprintf(targetPacketBuffer, "%s1,%d,%d,",
			AT_SEND_HEX_STRING,
			fPort,
			packetLength);

	packetLength = strlen(targetPacketBuffer);

	memcpy(&targetPacketBuffer[packetLength], dataPacket, packetSize);

	packetLength += packetSize;

	memcpy(&targetPacketBuffer[packetLength], ",\r\n", 3);


	return packetLength;
}
/**
 * @brief
 *
 * @return
 */
bool la66_packetJoinStatus(void)
{
	return hLa66.joinStatus;
}

/**************************  Useful Electronics  ****************END OF FILE***/
