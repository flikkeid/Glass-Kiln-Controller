//
//  FILE: KilnData.h
//  AUTHOR: Lars Flikkeid
//  DATE: 24-07-2017
//
//

#ifndef _KILNDATA_H
#define _KILNDATA_H
#include "Arduino.h"
#include <inttypes.h>

#define PROGRAM_TITLE  "PROGRAM"
#define CELSIUS true
#define FAHRENHEIT false
#define TEMPERATURE_UNIT CELSIUS
#define ON true
#define OFF false

// Display modes
#define KILN_INIT        0
#define KILN_RUNNING     1
#define KILN_PROGRAMMING 2
#define KILN_DEBUG	 3
#define DEBUG_STRING 	 "---TEST---"



class KilnData {
private:
  const char* 	_ProgramTitle = PROGRAM_TITLE;
  bool 		_TemperatureUnit = TEMPERATURE_UNIT;

  uint16_t	_SegmentProgress = 0;
  char*		_SegmentProgressString;
  uint16_t	_SegmentNumber = 9;
  uint16_t	_NumberOfSegments = 12;

  uint16_t	_SegmentRampTime = 60;
  uint16_t	_SegmentTemperature = 250;
  uint16_t	_SegmentHoldTime = 50;

  float	_ActualRampTime = 40;
  float	_ActualTemperature = 130;
  float _ActualHoldTime = 50;
  
  uint16_t	_RampProgress = 0;
  uint16_t	_TemperatureProgress = 0;
  uint16_t	_HoldProgress = 0;

  uint16_t 	_TemperatureTC1 = 816;
  uint16_t 	_TemperatureTC2 = 810;
  uint16_t 	_TemperatureTC3 = 805 ;

  uint16_t  _T[3] = {600, 200, 100};

  bool  _IndicatorHE1 = OFF;
  bool  _IndicatorHE2 = OFF;
  bool  _IndicatorHE3 = OFF;
  bool  _IndicatorHE4 = OFF;

  uint16_t	_CursorColumn = 0;
  uint16_t	_CursorRow = 0;
  uint16_t	_SelectedColumn = 0;
  uint16_t	_SelectedRow = 0;
  
  uint16_t _Mode = KILN_DEBUG;
  const char* _DebugValue = DEBUG_STRING;

public:

  void 		setProgramTitle (const char* s);
  const char * 	getProgramTitle ();

  void 		resetProgramTitle ();
  void 		setDebugValue (const char* s);
  void 		setDebugValue (char c);
  // void 	setDebugValue (int i);
  void 		setDebugValue (uint16_t i);
  const char * 	getDebugValue();

  void setTemperatureUnit (bool u);
  bool getTemperatureUnit ();

  void drawString(uint16_t x, uint16_t y, const char *s);

  void setSegmentNumber (uint16_t n);
  void setNumberOfSegments (uint16_t n);
  void setSegmentRampTime (uint16_t n);
  void setSegmentTemperature (uint16_t n);
  void setSegmentHoldTime (uint16_t n);
  void setActualRampTime (uint16_t n);
  void setActualTemperature (uint16_t n);
  void setActualHoldTime (uint16_t n);

  uint16_t getSegmentNumber ();
  uint16_t getNumberOfSegments ();
  uint16_t getSegmentRampTime ();
  uint16_t getSegmentTemperature ();
  uint16_t getSegmentHoldTime ();
  float getActualRampTime ();
  float getActualTemperature ();
  float getActualHoldTime ();

  float getSegmentRampProgress ();
  float getSegmentTemperatureProgress ();
  float getSegmentHoldProgress ();

  void setTemperatureTC1 (uint16_t n);
  void setTemperatureTC2 (uint16_t n);
  void setTemperatureTC3 (uint16_t n);
  uint16_t getTemperatureTC1 ();
  uint16_t getTemperatureTC2 ();
  uint16_t getTemperatureTC3 ();

  char* getTC ();

/*
  void drawSegmentProgress  (uint16_t n);
*/

  void setIndicatorHE1 (bool onOff);
  void setIndicatorHE2 (bool onOff);
  void setIndicatorHE3 (bool onOff);
  void setIndicatorHE4 (bool onOff);
  bool getIndicatorHE1 ();
  bool getIndicatorHE2 ();
  bool getIndicatorHE3 ();
  bool getIndicatorHE4 ();

  uint16_t getCursorRow ();          
  uint16_t getCursorColumn ();       
  uint16_t getSelectedRow ();        
  uint16_t getSelectedColumn ();     
  void setCursorRow (uint16_t);      
  void setCursorColumn (uint16_t);   
  void setSelectedRow (uint16_t);    
  void setSelectedColumn (uint16_t);


  uint16_t getMode ();
  void setMode (uint16_t);
};



#endif

