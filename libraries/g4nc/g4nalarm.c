#include <stdlib.h>
#include "g4nalarm.h"
#include "g4nutil.h"
#include <string.h>

Alarm GetAlarm(char* command) {
		Alarm alarms;
	
	// if (indexOf(command, "QALMHST") != 0 || indexOf(command, "QALMRST") != 0) {
	// 	return alarms;
	// }
	char* alarmStr = substring(command, 7, 23);
	char* theStringForResultLong =(substring(alarmStr,0,8));
	long resultLong = parseLong(theStringForResultLong, 16);
	// int resultLong = parseInt(alarmStr, 16);
	// printf("***Resultlong is: %u/n", resultLong);
	// free(alarmStr);
	// free(theStringForResultLong);
	

	
	if (command[4]=='H')  {
		alarms.network = HOME;
	} else {
		alarms.network = ROAMING;
	}
	alarms.alarms = ((resultLong & 0x80000000) == 0);
	alarms.overspeed = ((resultLong & 0x40000000) != 0)? true:false;
	// alarms.overspeed = true;
	alarms.ignition = (resultLong & 0x20000000) != 0;
	alarms.panicButton = ((resultLong & 0x10000000) != 0);
	alarms.relay = (resultLong & 0x08000000) != 0;
	alarms.inputPowerUndervoltage = (resultLong & 0x04000000) != 0;
	alarms.inputPowerOvervoltage = (resultLong & 0x02000000) != 0;
	alarms.accVoltageUnderThreshold = (resultLong & 0x01000000) != 0;
	alarms.accError = (resultLong & 0x00800000) != 0;
	alarms.relayDisconnected = (resultLong & 0x00400000) != 0;
	alarms.iButtonDisconnected = (resultLong & 0x00200000) != 0;
	alarms.dataLimit = (resultLong & 0x00040000) != 0;
	alarms.dailyTrafficExceeded = (resultLong & 0x00020000) != 0;
	alarms.monthlyTrafficExceeded = (resultLong & 0x00010000) != 0;
	alarms.gpsMissing = (resultLong & 0x00008000) != 0;
	alarms.stationaryContactOn = (resultLong & 0x00004000) != 0;
	alarms.stationaryContactOff = (resultLong & 0x00002000) != 0;
	alarms.speedExceededContactOffThreshold = (resultLong & 0x00001000) != 0;
	alarms.motionSensorMovement = (resultLong & 0x00000400) != 0;
	alarms.privateAlarm = (resultLong & 0x00000100) != 0;
	alarms.gpsJamming = (resultLong & 0x00000040) != 0;
	alarms.gsmJamming = (resultLong & 0x00000020) != 0;
	alarms.accelerometerAntitheftAlarm = (resultLong & 0x00000008) != 0;

	free(alarmStr);
	free(theStringForResultLong);
	return alarms;
	
}

int getSpeedThreshold(char* command){
	if (indexOf(command, "QALMOVS") != 0 ) {
		return -1;
	}
	
	char* speedTresholdStr = substring(command, 7, 11);
	unsigned int resultInt = parseInt(speedTresholdStr, 16);
	free(speedTresholdStr);

	return ((resultInt & 0xffff) / 10); 
	
}

int getAlarmMovement(char* command){
	if (indexOf(command, "QALMMOV") != 0 ) {
		return -1;
	}

	char* speedAlarmMov = substring(command, 7, 11);
	unsigned int resultInt = parseInt(speedAlarmMov, 16);
	free(speedAlarmMov);

	return ((resultInt & 0xffff) / 10);  
}

int getStationaryContactOnThreshold(char* command){
	
	if (indexOf(command, "QALMSTN") != 0 ) {
		return -1;
	}

	char* stationaryContactOnThresh = substring(command, 7, 11);
	unsigned int resultInt = parseInt(stationaryContactOnThresh, 16);
	free(stationaryContactOnThresh);

	return (resultInt & 0xffff);  
	
}

int getStationaryContactOffThreshold(char* command){
	
	if (indexOf(command, "QALMSTF") != 0 ) {
		return -1;
	}

	char* stationaryContactOffThresh = substring(command, 7, 11);
	unsigned int resultInt = parseInt(stationaryContactOffThresh, 16);
	free(stationaryContactOffThresh);

	return (resultInt & 0xffff);  
	
}

int getSpeedContactOnThreshold(char* command){
	
	if (indexOf(command, "QALMSSN") != 0 ) {
		return -1;
	}

	char* speedContactOnThresh = substring(command, 7, 11);
	unsigned int resultInt = parseInt(speedContactOnThresh, 16);
	free(speedContactOnThresh);

	return ((resultInt & 0xffff) / 10);  
	
}

int getSpeedContactOffThreshold(char* command){
	
	if (indexOf(command, "QALMSSF") != 0 ) {
		return -1;
	}

	char* speedContactOffTresh = substring(command, 7, 11);
	unsigned int resultInt = parseInt(speedContactOffTresh, 16);
	free(speedContactOffTresh);

	return ((resultInt & 0xffff) / 11);  
	
}

int getGpsMissingTime(char* command){
	
	if (indexOf(command, "QALMGTM") != 0 ) {
		return -1;
	}

	char* gpsMissingTimeTresh = substring(command, 7, 11);
	unsigned int resultInt = parseInt(gpsMissingTimeTresh, 16);
	free(gpsMissingTimeTresh);

	return (resultInt & 0xffff);
	
}

int getDelayAccelerometerMovement (char* command){
	
	if (indexOf(command, "QALMATD") != 0 ) {
		return -1;
	}

	char* delayAccelerometerMovement = substring(command, 7, 11);
	unsigned int resultInt = parseInt(delayAccelerometerMovement, 16);
	free(delayAccelerometerMovement);

	return (resultInt & 0xffff);
	
}








