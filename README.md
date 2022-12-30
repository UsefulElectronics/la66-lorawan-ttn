[![Build Status](https://img.shields.io/badge/USEFUL%20ELECTRONICS-YOUTUBE-red)](https://www.youtube.com/user/wardzx1)

# Sponsors

### PCBWay
Tutorial Series Sponsor PCBWay Website. You can get extra free coupons using the link below:
[<img src="https://github.com/UsefulElectronics/esp32s3_la66_lorawan/blob/main/repo%20cover/banner320x100.gif">](https://www.pcbway.com/setinvite.aspx?inviteid=582640)

***
### Dragino
LA66 LoRaWAN Dragino Arduino shield module:
https://www.dragino.com/products/lora/item/231-la66-lorawan-shield.html
Store Link:
https://shop.dragino.com/
***

# ESP32S3 LoRaWAN Communication with TTN Using LA66 Module
***
### [Tutorial Link](https://youtu.be/i_y3ftt9oOs) On [![Build Status](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/wardzx1) 

In this tutorial, I am demonstrating 'CONNECT' Board that I have designed that has ESP32S3 and LA66 LoRaWAN module that communicates with LPS8v2 Gateway. 

The ESP32S3 reads the internal temperature sensor and sends the read data over UART in form of AT Command to the LA66 module that sends the temperature data over LoRaWAN to the LPS8v2 gateway, which sends the obtained data to the TTN.

Some features of the TTN network are also presented and shown as a real life example in the tutorial. Then, it is compared with Helium network in terms of map coverage and usage pricing. 

LPS8v2 gateway also features built in Node-Red server that allows IOT data management and offers UI. This feature is used to get the temperature  data from the TTN application MQTT broker to make it available to the connected IOT device.

##TTN Application Payload Formatter code
```
function decodeUplink(input) 
{
  return {
    data: {
      bytes: String.fromCharCode.apply(null, input.bytes)
    },
    warnings: [],
    errors: []
  };
}
```

![Circuit Diagram](https://github.com/UsefulElectronics/la66-lorawan-ttn/blob/main/repo%20cover/repo%20cover.png)

## CONNECT Board Pin-out Diagram
![Circuit Diagram](https://github.com/UsefulElectronics/la66-lorawan-ttn/blob/main/repo%20cover/ConnectPinout.png)
