#include "g4nardualarm.h"

int QALMOVS() {
	Serial2.write("QALMOVS//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int speedThreshold = getSpeedThreshold(s);  
	return speedThreshold;
}


int QALMMOV() {
	Serial2.write("QALMMOV//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int alarmMovement = getAlarmMovement(s);  
	return alarmMovement;
}

int QALMSTN() {
	Serial2.write("QALMMOV//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int stationaryContantON = getStationaryContactOnThreshold(s);  
	return stationaryContantON;
}

int QALMSTF() {
	Serial2.write("QALMSTF//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int stationaryContantOFF = getStationaryContactOffThreshold(s);  
	return stationaryContantOFF;	
};

int QALMSSN(){
	Serial2.write("QALMSSN//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int speedContactOnThreshohld = getSpeedContactOnThreshold(s);  
	return speedContactOnThreshohld;	
};

int QALMSSF(){
	Serial2.write("QALMSSF//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int speedContactOffThreshohld = getSpeedContactOffThreshold(s);  
	return speedContactOffThreshohld;	
};

int QALMGTM(){
	Serial2.write("QALMGTM//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int gpsMissingTimeThreshold = getGpsMissingTime(s);  
	return gpsMissingTimeThreshold;	
};

int QALMATD(){
	Serial2.write("QALMATD//");

	delay(100);

	String commandResult = Serial2.readString();  
	Serial.println(commandResult);
	char s[commandResult.length()];
	commandResult.toCharArray(s, commandResult.length());
	int delayAccelerometerMovement = getDelayAccelerometerMovement(s);  
	return delayAccelerometerMovement;	
};

 Alarm QALMHST() {
  Serial2.write("QALMHST//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);


  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  Alarm alarms = GetAlarm(s);

  return alarms ;    
};


Alarm QALMRST() {
  Serial2.write("QALMRST//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);

  // char s[commandResult.length() + 1];
    char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);
  // char* s=commandResult;

  return GetAlarm(s);    
};