#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, 11, 12); //sets up a transciever object with reciever on d11, transmitter on d12

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    else{
        Serial.println("init successful");
    }
}

void loop()
{
    const char *msg = "a";
    driver.send((uint8_t *)msg, strlen(msg)); //sends the message and its length
    driver.waitPacketSent(); //waits till the packet is sent
    Serial.println("transmission sent");
    delay(1000);
}