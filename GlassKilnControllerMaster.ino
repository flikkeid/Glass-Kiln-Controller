
//
//  FILE: GlassKilnControllerMaster.ino
//  AUTHOR: Lars Flikkeid
//  DATE: 24-07-2017
//
//

#include "KilnController.h"

// OLED declarations and definitions
  U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

// ARDUINO KilnController
  KilnData kilnData;

void setup()
{
  // Init Serial communication
  Serial.begin (BAUDRATE); 
  
  // InitI2C
  Wire.begin (); // StartI2C, Address optional for Master
  
  // InitOLED   
  u8g.setColorIndex (1); // Instructs the display to draw with a pixel on. 

  // TEST setup
  controlLED (SET_ALL_LEDS, LED_OFF);
    
  kilnData.setMode (KILN_INIT);
}

void loop()
{
  switch (kilnData.getMode()) {
  case KILN_INIT:        drawOLEDInit (&u8g, &kilnData); break;
  case KILN_RUNNING:     drawOLEDRunning (&u8g, &kilnData); break;
  case KILN_PROGRAMMING: drawOLEDProgramming (&u8g, &kilnData); break;
  case KILN_DEBUG:       drawOLEDDebug (&u8g, &kilnData); break;
  }

  kilnData.setMode  (KILN_RUNNING);  
  testFunction      (&kilnData);

  readThermocouplerI2C (&kilnData);
 
  delay (1000);  
}

//
// END OF FILE
//


