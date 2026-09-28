#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(2000, 11, 12); //sets up a transciever object with reciever on d11, transmitter on d12

void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init()){
         Serial.println("init failed");
    }
    else{
    Serial.println("started recieving");
    }
}

void loop()
{
    uint8_t buf[1]; //expected length of message to be recieved
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.println((char*)buf);         
    }
}