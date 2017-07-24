//
//  FILE: KilnController.ccp
//  AUTHOR: Lars Flikkeid
//  DATE: 24-07-2017
//
//
#include "KilnController.h"

void controlLED (uint8_t value, boolean onOff)
{
  static uint8_t currentValue = SET_ALL_LEDS;
  if (onOff == true) {
     currentValue|= value;
  }
  else {
     currentValue &= value;
     currentValue = ~currentValue;
  } 
  
  Wire.beginTransmission(I2C_ADDRESS_HEC);  //Begin the transmission to PCF8574
  Wire.write(currentValue);          	//Send the data to PCF8574
  Wire. endTransmission();            	//End the Transmission
}

void testFunction (KilnData *kilnData)
{ 
  static bool onOff = ON;
  if (onOff == ON) 
  {
  controlLED (LED1 | LED2 | LED3, ON);
  kilnData->setIndicatorHE1 (ON);
  kilnData->setIndicatorHE2 (ON);
  kilnData->setIndicatorHE3 (ON);
  kilnData->setIndicatorHE4 (OFF);
  controlLED (LED4, OFF);
  onOff = OFF;  
  }
  else
  {
  controlLED (LED1 | LED2 | LED3, OFF);    
  kilnData->setIndicatorHE1 (OFF);
  kilnData->setIndicatorHE2 (OFF);
  kilnData->setIndicatorHE3 (OFF);
  kilnData->setIndicatorHE4 (ON);
  controlLED (LED4, ON);
  onOff = ON;  
  }
}

void drawOLEDInit (U8GLIB_SSD1306_128X64 *u8g, KilnData *kilnData)
{ 
  u8g->firstPage();
  do {
    // Draw Display Header
    u8g->setFont ( u8g_font_fub14 );
    drawString (u8g, 0, 16, MODE_TITLE_INIT);
  } while ( u8g->nextPage() );
}

void drawOLEDDebug (U8GLIB_SSD1306_128X64 *u8g, KilnData *kilnData)
{ 
  u8g->firstPage();
  do {
    // Draw Display Header
    u8g->setFont ( u8g_font_fub14 );
    drawString (u8g, 25, 16, MODE_TITLE_DEBUG);
    drawString (u8g, 25, 45, kilnData->getDebugValue());  
  } while ( u8g->nextPage() );
}

void drawOLEDRunning (U8GLIB_SSD1306_128X64 *u8g, KilnData *kilnData)
{  
  static char* tempString5 = "00000";
  static float tempVar;

  u8g->firstPage();
  do {  
    // Draw Display Header
    u8g->setFont ( u8g_font_fub14 );
    //kilnData->setProgramTitle ("0987654321");
    drawString (u8g, 0, 16, kilnData->getProgramTitle());

    if (kilnData->getTemperatureUnit() == CELSIUS)
      drawString (u8g, 115, 16, "C");
    else  
      drawString (u8g, 115,16, "F");

    // Display Content    
    u8g->drawFrame ( 0, 16, 95, 32);

    u8g->setFont ( u8g_font_7x14 );
    sprintf (tempString5, "%i/%i\n", kilnData->getSegmentNumber(), kilnData->getNumberOfSegments());
    drawString(u8g, 5, 30, tempString5);

    drawString(u8g, 2, 45, kilnData->getSegmentRampTime());
    drawString(u8g, 2, 60, kilnData->getActualRampTime());

    //drawString(u8g, 34, 30, "CLOCK");
  
    drawString(u8g, 34, 45, kilnData->getSegmentTemperature());
    drawString(u8g, 34, 60, kilnData->getActualTemperature());

    drawString(u8g, 65, 30, " ");
    drawString(u8g, 65, 45, kilnData->getSegmentHoldTime());
    drawString(u8g, 65, 60, kilnData->getActualHoldTime());

    // Draw Thermocouples temperature
    u8g->setFont ( u8g_font_6x13 );
    drawString(u8g, 98, 30, kilnData->getTemperatureTC1());
    drawString(u8g, 98, 45, kilnData->getTemperatureTC2());
    drawString(u8g, 98, 60, kilnData->getTemperatureTC3()); 

    // Draw Segment Progress
    u8g->drawFrame ( 2, 63, 28, 1);
    tempVar= 28 * kilnData->getSegmentRampProgress () / 100 ;  
    u8g->drawBox   ( 2, 61, ((uint16_t ) lround ( tempVar)), 3);    
    u8g->drawFrame ( 33, 63, 28, 1);
    u8g->drawBox   ( 33, 61, ( 28 * kilnData->getSegmentTemperatureProgress () / 100 ), 3);
    u8g->drawFrame ( 65, 63, 28, 1);
    u8g->drawBox   ( 65, 61, ( 28 * kilnData->getSegmentHoldProgress () / 100 ), 3);
    
    // Draw Heat Element indicators
    if (kilnData->getIndicatorHE1 () == ON) u8g->drawBox ( 124, 16, 4, 10); else u8g->drawFrame ( 127, 16, 1, 10); 
    if (kilnData->getIndicatorHE2 () == ON) u8g->drawBox ( 124, 28, 4, 10); else u8g->drawFrame ( 127, 28, 1, 10);
    if (kilnData->getIndicatorHE3 () == ON) u8g->drawBox ( 124, 40, 4, 10); else u8g->drawFrame ( 127, 40, 1, 10);
    if (kilnData->getIndicatorHE4 () == ON) u8g->drawBox ( 124, 52, 4, 10); else u8g->drawFrame ( 127, 52, 1, 10); 
    
  } while ( u8g->nextPage() );
}

void drawOLEDProgramming (U8GLIB_SSD1306_128X64 *u8g, KilnData *kilnData)
{
  u8g->firstPage();
  do {
    // Draw Display Header
    u8g->setFont ( u8g_font_fub14 );
    drawString (u8g, 0, 16, MODE_TITLE_PROGRAMMING);
  } while ( u8g->nextPage() );
}



void drawValueChar(U8GLIB_SSD1306_128X64 *u8g, char c) {
}

void drawValueInt(U8GLIB_SSD1306_128X64 *u8g, uint16_t i) {}
void drawValueString(U8GLIB_SSD1306_128X64 *u8g, char* string) {}


void drawString(U8GLIB_SSD1306_128X64* u8g,u8g_uint_t x, u8g_uint_t y, const char *s){
  u8g->drawStr( x, y, s);
}

void drawString(U8GLIB_SSD1306_128X64* u8g, u8g_uint_t x, u8g_uint_t y, uint16_t n)
{
  static  char* tempString5 = "00000";
  if (n < 10)         sprintf (tempString5, "   %i\n", n);
  else if (n < 100)   sprintf (tempString5, "  %i\n", n);
  else if (n < 1000)  sprintf (tempString5, " %i\n", n);
  else                sprintf (tempString5, "%i\n", n);
  u8g->drawStr( x, y, tempString5);
}

void readThermocouplerI2C (KilnData* kilnData)
{
  char 		c = 'X';
  uint16_t	i = 0;
  char charBuffer [6];
  uint16_t * intBuffer;
  
  // Read the thermo couplers from I2C

  Wire.requestFrom (I2C_ADDRESS_TCC, 6);    // request 6 bytes from slave device #8

  while (Wire.available()) 
    charBuffer[i++] = Wire.read();

  intBuffer = (uint16_t *) charBuffer;

  kilnData->setTemperatureTC1 (intBuffer[0]);  
  kilnData->setTemperatureTC2 (intBuffer[1]);  
  kilnData->setTemperatureTC3 (intBuffer[2]);  

  kilnData->setDebugValue ((uint16_t )intBuffer [0]);
}


//
// END OF FILE
//


