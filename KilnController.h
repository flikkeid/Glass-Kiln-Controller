//
//  FILE: KilnController
//  AUTHOR: Lars Flikkeid
//  DATE: 24-07-2017
//
//

#ifndef _KILNCONTROLLER_H
#define _KILNCONTROLLER_H

//#include "Arduino.h"

#include <Wire.h>
#include "U8glib.h"
#include "PCF8574.h"
#include <UnoWiFiDevEd.h>
#include "max6675.h"
#include "KilnData.h"

// Test declarations and definitions
  #define LED1 B00000001 
  #define LED2 B00000010
  #define LED3 B00000100
  #define LED4 B00001000
  #define SET_ALL_LEDS B0001111
  #define LED_ON true
  #define LED_OFF false

// Thermocoupler declarations
  #define KTCSO1 8
  #define KTCSO2 6
  #define KTCSO3 4
  #define KTCCS1 9
  #define KTCCS2 7
  #define KTCCS3 5
  #define KTCCLK1 10	//10
  #define KTCCLK2 3	//3
  #define KTCCLK3 2	//2

// MENU defines
  #define MENU_ROWS 3
  #define MENU_COLUMNS 3
  #define MENU_TITLE "Menu"
  #define MENU_ROW1 "Select Schedule"
  #define MENU_ROW2 "Schedule"
  #define MENU_ROW31 "START"
  #define MENU_ROW32 "STOP"

  #define MODE_TITLE_INIT "INIT"
  #define MODE_TITLE_RUNNING "RUNNING"
  #define MODE_TITLE_PROGRAMMING "PROGRAMMING"
  #define MODE_TITLE_DEBUG "DEBUG"

// I2C decarations and definitions
  #define I2C_ADDRESS_HEC 56    // Heat Element Controller, PCF8574AN address
  #define I2C_ADDRESS_TCC 8     // Thermo Couple Conroller, Arduino Mini address
  #define I2C_ADDRESS_OLED 56  // Color OLED address

// Serial definitions
  #define BAUDRATE 9600

// Color OLED delarations and definitions
void controlLED (uint8_t, boolean );
void drawOLEDInit 	(U8GLIB_SSD1306_128X64 *, KilnData*);
void drawOLEDRunning 	(U8GLIB_SSD1306_128X64 *, KilnData*);
void drawOLEDProgramming (U8GLIB_SSD1306_128X64 *, KilnData*);
void drawOLEDDebug 	(U8GLIB_SSD1306_128X64 *, KilnData*);
void drawMENU 		(U8GLIB_SSD1306_128X64 *, KilnData*);
void testFunction (KilnData*);
void readThermocouplerI2C (KilnData*);
void drawString		(U8GLIB_SSD1306_128X64 *, u8g_uint_t , u8g_uint_t, const char*);
void drawString		(U8GLIB_SSD1306_128X64 *, u8g_uint_t , u8g_uint_t, uint16_t );
void drawWEB (WifiData *);
void drawValueChar	(U8GLIB_SSD1306_128X64 *, char);
void drawValueInt	(U8GLIB_SSD1306_128X64 *, int);
void drawValueString	(U8GLIB_SSD1306_128X64 *, char*);


class KilnController {
private:


public:


};

//extern SoftwareWire myWire;

#endif

