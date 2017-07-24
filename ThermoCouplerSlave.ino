
//
//  FILE: ThermoCouplerSlave.ino
//  AUTHOR: Lars Flikkeid
//  DATE: 24-07-2017
//
//

#include "KilnController.h"

// Thermocoupler declartionsn
  MAX6675 ktc1(KTCCLK1, KTCCS1, KTCSO1);
  MAX6675 ktc2(KTCCLK2, KTCCS2, KTCSO2);
  MAX6675 ktc3(KTCCLK3, KTCCS3, KTCSO3);

  static  uint16_t temperatureBuffer [3];

void setup()
{ 
  // InitI2C
  Wire.begin (I2C_ADDRESS_TCC);                // join i2c bus with address #8
  Wire.onRequest (requestEvent); // register event
}

void loop()
{
  temperatureBuffer[0] = (uint16_t) ktc1.readCelsius ();
  //  delay (500); 
  temperatureBuffer[1] = (uint16_t) ktc2.readCelsius ();
  //  delay (500); 
  temperatureBuffer[2] = (uint16_t) ktc3.readCelsius ();
  delay (500); 
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  char* charBuffer;
  charBuffer = (char*) temperatureBuffer;  

  // respond with the Temperature buffer of 6 bytes
  //   as expected by master
  
  for (int i=0; i<6; i++) Wire.write( charBuffer[i] ); 
}

//
// END OF FILE
//



