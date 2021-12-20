#include <Preferences.h>

#include "g4nardu.h"


SystemInfo QSYSINF() {

  Serial2.write("QSYSINF//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);

  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);
  
  return GetSystemInfo(s);
};

GSMInfo QGSMINF() {

  Serial2.write("QGSMINF//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);

  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  return GetGSMInfo(s);
};

GSMInfoExtended QGSMDSI() {

  Serial2.write("QGSMDSI//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);

  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  return GetGSMInfoExtended(s);
};

GPSInfo QGPSINF() {

  Serial2.write("QGPSINF//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);

  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  return GetGPSInfo(s);  
};

MemoryInfo QDLFINF() {
  Serial2.write("QDLFINF//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);

  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  return GetMemoryInfo(s);
};



void cSYSRST() {
  Serial2.write("cSYSRST//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  
  return;      
};
