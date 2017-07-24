//
//  FILE: KilnData.ccp
//  AUTHOR: Lars Flikkeid
//  DATE: 24-07-2017
//
//
#include <KilnData.h>

void KilnData::setProgramTitle (const char * s)	{ _ProgramTitle = s; }
const char * KilnData::getProgramTitle ()	{ return _ProgramTitle; }

void KilnData::resetProgramTitle ()		{ _ProgramTitle = "PROGRAM"; }
void KilnData::setDebugValue (const char * s)	{ _DebugValue = s; }

void KilnData::setDebugValue (char c)	{
  static  char* tempString5 = "00000";
  sprintf (tempString5, "%u\n", c);
  _DebugValue = tempString5; 
}

void KilnData::setDebugValue (uint16_t i)	{
  static  char* tempString5 = "00000";
  uint16_t n;
  n=i;
 // sprintf (tempString5, "%i\n", n);
   sprintf (tempString5, "%" PRIu16 "\n", n);
  _DebugValue = tempString5; 
}



const char * KilnData::getDebugValue () 	{ return _DebugValue; }

void KilnData::setTemperatureUnit (bool u)	{ _TemperatureUnit = u; }
bool KilnData::getTemperatureUnit ()		{ return _TemperatureUnit; }

void KilnData::setSegmentNumber (uint16_t n)		{ _SegmentNumber = n; }
void KilnData::setNumberOfSegments (uint16_t n)	{ _NumberOfSegments = n; }

void KilnData::setSegmentRampTime (uint16_t n)	{ _SegmentRampTime = n; }
void KilnData::setSegmentTemperature (uint16_t n)	{ _SegmentTemperature = n; }
void KilnData::setSegmentHoldTime (uint16_t n)	{ _SegmentHoldTime = n; }
void KilnData::setActualRampTime (uint16_t n)	{ _ActualRampTime = n; }
void KilnData::setActualTemperature (uint16_t n)	{ _ActualTemperature = n; }
void KilnData::setActualHoldTime (uint16_t n)	{ _ActualHoldTime = n; }

uint16_t KilnData::getSegmentNumber ()	{ return _SegmentNumber; }
uint16_t KilnData::getNumberOfSegments ()	{ return _NumberOfSegments; }
uint16_t KilnData::getSegmentRampTime ()	{ return _SegmentRampTime; }
uint16_t KilnData::getSegmentTemperature ()	{ return _SegmentTemperature; }
uint16_t KilnData::getSegmentHoldTime ()	{ return _SegmentHoldTime; }
float KilnData::getActualRampTime ()	{ return _ActualRampTime; }
float KilnData::getActualTemperature ()	{ return _ActualTemperature; }
float KilnData::getActualHoldTime ()	{ return _ActualHoldTime; }

float KilnData::getSegmentRampProgress () {
 return (_ActualRampTime / _SegmentRampTime ) * 100; }
float KilnData::getSegmentTemperatureProgress () {
 return (_ActualTemperature / _SegmentTemperature ) * 100; }
float KilnData::getSegmentHoldProgress () {
 return (_ActualHoldTime / _SegmentHoldTime ) * 100; }

void KilnData::setTemperatureTC1 (uint16_t n) { _TemperatureTC1 = n; }
void KilnData::setTemperatureTC2 (uint16_t n) { _TemperatureTC2 = n; }
void KilnData::setTemperatureTC3 (uint16_t n) { _TemperatureTC3 = n; }
uint16_t KilnData::getTemperatureTC1 () { return _TemperatureTC1; }
uint16_t KilnData::getTemperatureTC2 () { return _TemperatureTC2; }
uint16_t KilnData::getTemperatureTC3 () { return _TemperatureTC3; }

char* KilnData::getTC () { return (char *)_T; }

void KilnData::setIndicatorHE1 (bool onOff) { _IndicatorHE1 = onOff; }
void KilnData::setIndicatorHE2 (bool onOff) { _IndicatorHE2 = onOff; }
void KilnData::setIndicatorHE3 (bool onOff) { _IndicatorHE3 = onOff; }
void KilnData::setIndicatorHE4 (bool onOff) { _IndicatorHE4 = onOff; }
bool KilnData::getIndicatorHE1 () { return _IndicatorHE1; }
bool KilnData::getIndicatorHE2 () { return _IndicatorHE2; }
bool KilnData::getIndicatorHE3 () { return _IndicatorHE3; }
bool KilnData::getIndicatorHE4 () { return _IndicatorHE4; }

uint16_t KilnData::getCursorRow ()            { return _CursorRow; }
uint16_t KilnData::getCursorColumn ()         { return _CursorColumn; }
uint16_t KilnData::getSelectedRow ()          { return _SelectedRow; }
uint16_t KilnData::getSelectedColumn ()       { return _SelectedColumn; }
void KilnData::setCursorRow (uint16_t y)      { _CursorRow = y; }
void KilnData::setCursorColumn (uint16_t x)   { _CursorColumn = x; }
void KilnData::setSelectedRow (uint16_t y)    { _SelectedRow = y; }
void KilnData::setSelectedColumn (uint16_t x) { _SelectedColumn = x; }

uint16_t KilnData::getMode ()          { return _Mode; }
void KilnData::setMode (uint16_t mode) { _Mode = mode; }

//
// END OF FILE
//


