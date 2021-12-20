#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "g4ntransmission.h"

TransmissionSettings GetTransmissionSettings(char* command) {

	TransmissionSettings transmissionSettings;

	char* transmissionStr = substring(command, 7, indexOf(command, "//"));
	int resultLong = parseInt(transmissionStr, 16);
	free(transmissionStr);


	if (command[4] == 'H') {
		transmissionSettings.network = HOME;
	} else {
		transmissionSettings.network = ROAMING;
	}

	transmissionSettings.enabled = (resultLong & 0x80000000) == 0;

	transmissionSettings.intervalA = (resultLong & 0x40000000) != 0;
	transmissionSettings.intervalAWhenContactOn = (resultLong & 0x20000000) != 0;
	transmissionSettings.intervalAWhenContactOff = (resultLong & 0x10000000) != 0;
	transmissionSettings.intervalAWhenAlarmsSet = (resultLong & 0x08000000) != 0;

	transmissionSettings.intervalB = (resultLong & 0x04000000) != 0;
	transmissionSettings.intervalBWhenContactOn = (resultLong & 0x02000000) != 0;
	transmissionSettings.intervalBWhenContactOff = (resultLong & 0x01000000) != 0;
	transmissionSettings.intervalBWhenAlarmsSet = (resultLong & 0x00800000) != 0;

	transmissionSettings.alarm = (resultLong & 0x00400000) != 0;
	transmissionSettings.accumulatedData = (resultLong & 0x00200000) != 0;
	transmissionSettings.contact = (resultLong & 0x00100000) != 0;
	transmissionSettings.hourMatch = (resultLong & 0x00080000) != 0;
	transmissionSettings.iButtonGroup = (resultLong & 0x00040000) != 0;
	transmissionSettings.dailyTraficLimit = (resultLong & 0x00020000) != 0;
	transmissionSettings.monthlyTraficLimit = (resultLong & 0x00010000) != 0;

	transmissionSettings.gpsValid = (resultLong & 0x00008000) != 0;

	transmissionSettings.powerOn = (resultLong & 0x00004000) != 0;
	transmissionSettings.delay = (resultLong & 0x00002000) != 0;
	transmissionSettings.clear = (resultLong & 0x00001000) != 0;
	transmissionSettings.changeWorkPrivate = (resultLong & 0x00000800) != 0;
	transmissionSettings.epochIntervalAcontactOn = (resultLong & 0x00000400) != 0;
	transmissionSettings.epochIntervalAcontactOff = (resultLong & 0x00000200) != 0;
	transmissionSettings.epochIntervalBcontactOn = (resultLong & 0x00000100) != 0;
	transmissionSettings.epochIntervalBcontactOff = (resultLong & 0x00000080) != 0;



	transmissionSettings.cumulativeDistance = (resultLong & 0x00000040) != 0;
	transmissionSettings.allowTransGenAcqEngine = (resultLong & 0x00000020) != 0;
	transmissionSettings.transmitRTC = (resultLong & 0x00000010) != 0;
	transmissionSettings.transmitCANRequests = (resultLong & 0x00000008) != 0;

	return transmissionSettings;
}

void GetCmdTransmissionSettings(char* command, TransmissionSettings transmission) {
	command[0] = '\0';

	unsigned long mask = 0;

	mask = mask | (transmission.enabled ? 0 : 0x80000000);

	mask = mask | (transmission.intervalA ? 0x40000000 : 0);
	mask = mask | (transmission.intervalAWhenContactOn ? 0x20000000 : 0);
	mask = mask | (transmission.intervalAWhenContactOff ? 0x10000000 : 0);
	mask = mask | (transmission.intervalAWhenAlarmsSet ? 0x08000000 : 0);

	mask = mask | (transmission.intervalB ? 0x04000000 : 0);
	mask = mask | (transmission.intervalBWhenContactOff ? 0x02000000 : 0);
	mask = mask | (transmission.intervalBWhenContactOn ? 0x01000000 : 0);
	mask = mask | (transmission.intervalBWhenAlarmsSet ? 0x00800000 : 0);

	mask = mask | (transmission.alarm ? 0x00400000 : 0);
	mask = mask | (transmission.accumulatedData ? 0x00200000 : 0);
	mask = mask | (transmission.contact ? 0x00100000 : 0);
	mask = mask | (transmission.hourMatch ? 0x00080000 : 0);
	mask = mask | (transmission.iButtonGroup ? 0x00040000 : 0);
	mask = mask | (transmission.dailyTraficLimit ? 0x00020000 : 0);
	mask = mask | (transmission.monthlyTraficLimit ? 0x00010000 : 0);

	mask = mask | (transmission.gpsValid ? 0x00008000 : 0);
	mask = mask | (transmission.powerOn ? 0x00004000 : 0);
	mask = mask | (transmission.delay ? 0x00002000 : 0);
	mask = mask | (transmission.clear ? 0x00001000 : 0);
	mask = mask | (transmission.changeWorkPrivate ? 0x00000800 : 0);
	mask = mask | (transmission.epochIntervalAcontactOn ? 0x00000400 : 0);
	mask = mask | (transmission.epochIntervalAcontactOff ? 0x00000200 : 0);
	mask = mask | (transmission.epochIntervalBcontactOn ? 0x00000100 : 0);
	mask = mask | (transmission.epochIntervalBcontactOff ? 0x00000080 : 0);
	mask = mask | (transmission.cumulativeDistance ? 0x00000040 : 0);
	mask = mask | (transmission.allowTransGenAcqEngine ? 0x00000020 : 0);
	mask = mask | (transmission.transmitRTC ? 0x00000010 : 0);
	mask = mask | (transmission.transmitCANRequests ? 0x00000008 : 0);

	char hexaStr[9] = "";
	toHexaString(hexaStr, mask, 8);

	if (transmission.network == HOME) {
		strcat(command, "PTRSHST");
	} else {
		strcat(command, "PTRSRST");
	}
	strcat(command, hexaStr);
	strcat(command, "//");
	return;
}

/**
 * Builds the command to enable the given transmission parameter.
 * STRSHST/STRSRST
 */
void GetCmdEnableTransmissionParameter(char* command, TransmissionParameters param, Network network) {
	command[0] = '\0';

	if (network == HOME) {
		strcat(command, "STRSHST");
	} else {
		strcat(command, "STRSRST");
	}

	switch(param) {
		case ENABLED:                     strcat(command, "80000000"); break;
		case INTERVAL_A:                  strcat(command, "40000000"); break;
		case INTERVAL_A_WHEN_CONTACT_ON:  strcat(command, "20000000"); break;
		case INTERVAL_A_WHEN_CONTACT_OFF: strcat(command, "10000000"); break;
		case INTERVAL_A_WHEN_ALARMS_SET:  strcat(command, "08000000"); break;
		case INTERVAL_B:                  strcat(command, "04000000"); break;
		case INTERVAL_B_WHEN_CONTACT_ON:  strcat(command, "02000000"); break;
		case INTERVAL_B_WHEN_CONTACT_OFF: strcat(command, "01000000"); break;
		case INTERVAL_B_WHEN_ALARMS_SET:  strcat(command, "00800000"); break;
		case ALARMS:                      strcat(command, "00400000"); break;
		case ACCUMULATED_DATA:            strcat(command, "00200000"); break;
		case CONTACT:                     strcat(command, "00200000"); break;
		case MATCHING_HOURS:              strcat(command, "00080000"); break;
		case IBUTTON_GROUP:               strcat(command, "00040000"); break;
		case DAILY_TRAFFIC_LIMIT:         strcat(command, "00020000"); break;
		case MONTHLY_TRAFFIC_LIMIT:       strcat(command, "00010000"); break;
		case GPS_VALID:                   strcat(command, "00008000"); break;
		case POWER_ON:                    strcat(command, "00004000"); break;
		case DELAY:                       strcat(command, "00002000"); break;
		case CLEAR:                       strcat(command, "00001000"); break;
		case CHANGE_WORK_PRIVATE:         strcat(command, "00000800"); break;
		case EPOCH_INTERVAL_A_CONTACT_ON: strcat(command, "00000400"); break;
		case EPOCH_INTERVAL_A_CONTACT_OFF:strcat(command, "00000200"); break;
		case EPOCH_INTERVAL_B_CONTACT_ON: strcat(command, "00000100"); break;
		case EPOCH_INTERVAL_B_CONTACT_OFF:strcat(command, "00000080"); break;
		case CUMULATIVE_DISTANCE:         strcat(command, "00000040"); break;
		case ALLOW_TRANS_GEN_ACQ_ENGINE:  strcat(command, "00000020"); break;
		case TRANSMIT_RTC:                strcat(command, "00000010"); break;
		case TRANSMIT_CAN_REQUESTS:       strcat(command, "00000080"); break;
	}

	strcat(command, "//");
	return;

}

/**
 * Builds the command to enable the given transmission parameter.
 * RTRSHST/RTRSRST
 */
void GetCmdDisableTransmissionParameter(char* command, TransmissionParameters param, Network network) {
	command[0] = '\0';

	if (network == HOME) {
		strcat(command, "RTRSHST");
	} else {
		strcat(command, "RTRSRST");
	}

	switch(param) {
		case ENABLED:                     strcat(command, "80000000"); break;
		case INTERVAL_A:                  strcat(command, "40000000"); break;
		case INTERVAL_A_WHEN_CONTACT_ON:  strcat(command, "20000000"); break;
		case INTERVAL_A_WHEN_CONTACT_OFF: strcat(command, "10000000"); break;
		case INTERVAL_A_WHEN_ALARMS_SET:  strcat(command, "08000000"); break;
		case INTERVAL_B:                  strcat(command, "04000000"); break;
		case INTERVAL_B_WHEN_CONTACT_ON:  strcat(command, "02000000"); break;
		case INTERVAL_B_WHEN_CONTACT_OFF: strcat(command, "01000000"); break;
		case INTERVAL_B_WHEN_ALARMS_SET:  strcat(command, "00800000"); break;
		case ALARMS:                      strcat(command, "00400000"); break;
		case ACCUMULATED_DATA:            strcat(command, "00200000"); break;
		case CONTACT:                     strcat(command, "00200000"); break;
		case MATCHING_HOURS:              strcat(command, "00080000"); break;
		case IBUTTON_GROUP:               strcat(command, "00040000"); break;
		case DAILY_TRAFFIC_LIMIT:         strcat(command, "00020000"); break;
		case MONTHLY_TRAFFIC_LIMIT:       strcat(command, "00010000"); break;
		case GPS_VALID:                   strcat(command, "00008000"); break;
		case POWER_ON:                    strcat(command, "00004000"); break;
		case DELAY:                       strcat(command, "00002000"); break;
		case CLEAR:                       strcat(command, "00001000"); break;
		case CHANGE_WORK_PRIVATE:         strcat(command, "00000800"); break;
		case EPOCH_INTERVAL_A_CONTACT_ON: strcat(command, "00000400"); break;
		case EPOCH_INTERVAL_A_CONTACT_OFF:strcat(command, "00000200"); break;
		case EPOCH_INTERVAL_B_CONTACT_ON: strcat(command, "00000100"); break;
		case EPOCH_INTERVAL_B_CONTACT_OFF:strcat(command, "00000080"); break;
		case CUMULATIVE_DISTANCE:         strcat(command, "00000040"); break;
		case ALLOW_TRANS_GEN_ACQ_ENGINE:  strcat(command, "00000020"); break;
		case TRANSMIT_RTC:                strcat(command, "00000010"); break;
		case TRANSMIT_CAN_REQUESTS:       strcat(command, "00000080"); break;
	}

	strcat(command, "//");
	return;
}

int GetTransmissionAccumulatedData(char* command) {

	if (indexOf(command, "QTRSHAD") != 0 && indexOf(command, "QTRSRAD") != 0) {
		return -1;
	}

	char* accumulatedDataStr = substring(command, 7, 11);
	int resultInt = parseInt(accumulatedDataStr, 16);
	free(accumulatedDataStr);

	return resultInt;
}

void GetCmdTransmissionAccumulatedData(char* command, int accumulatedData, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HAD");
	} else {
		strcat(command, "RAD");
	}
	char hexa[5] = "";
	toHexaString(hexa, accumulatedData, 4);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

int GetTransmissionIntervalA(char* command) {

	if (indexOf(command, "QTRSHIA") != 0 && indexOf(command, "QTRSRIA") != 0) {
		return -1;
	}

	char* intervalAStr = substring(command, 7, 11);
	int resultInt = parseInt(intervalAStr, 16);
	free(intervalAStr);

	return (resultInt & 0xffff);
}

void GetCmdTransmissionIntervalA(char* command, int intervalA, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HIA");
	} else {
		strcat(command, "RIA");
	}
	char hexa[5] = "";
	toHexaString(hexa, intervalA, 4);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

int GetTransmissionIntervalB(char* command) {

	if (indexOf(command, "QTRSHIB") != 0 && indexOf(command, "QTRSRIB") != 0) {
		return -1;
	}

	char* intervalBStr = substring(command, 7, 11);
	int resultInt = parseInt(intervalBStr, 16);
	free(intervalBStr);

	return (resultInt & 0xffff);
}

void GetCmdTransmissionIntervalB(char* command, int intervalB, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HIB");
	} else {
		strcat(command, "RIB");
	}
	char hexa[5] = "";
	toHexaString(hexa, intervalB, 4);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

MatchingHours GetTransmissionMatchingHours(char* command) {
	MatchingHours matchingHours;
	matchingHours.hour1[0] = '\0';
	matchingHours.hour2[0] = '\0';
	matchingHours.hour3[0] = '\0';
	matchingHours.hour4[0] = '\0';
	matchingHours.hour5[0] = '\0';
	matchingHours.hour6[0] = '\0';
	matchingHours.hour7[0] = '\0';
	matchingHours.hour8[0] = '\0';

	if (indexOf(command, "QTRSHMT") != 0 && indexOf(command, "QTRSRMT") != 0) {
		return matchingHours;
	}

	char* matchingHoursStr = substring(command, 7, indexOf(command, "//"));

  char* nothing = "9999\0";

	char* str = substring(matchingHoursStr, 0, 4);
  if(strcmp(str,nothing)){
   char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour1, hour);
  
  }else {
    strcat(matchingHours.hour1, "--:--");

  }
free(str);


	str = substring(matchingHoursStr, 6, 10);
  if(strcmp(str,nothing)){
  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour2, hour);
  }   else {
  strcat(matchingHours.hour2, "--:--");

  }
	free(str);

	str = substring(matchingHoursStr, 12, 16);
  if(strcmp(str,nothing)){
  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour3, hour);
  }   else {
  strcat(matchingHours.hour3, "--:--");

  }
	free(str);

	str = substring(matchingHoursStr, 18, 22);
  if(strcmp(str,nothing)){
	  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour4, hour);
  }   else {
  strcat(matchingHours.hour4, "--:--");

  }
	free(str);


	str = substring(matchingHoursStr, 24, 28);
  if(strcmp(str,nothing)){
  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour5, hour);
  }   else {
  strcat(matchingHours.hour5, "--:--");

  }
	free(str);

	str = substring(matchingHoursStr, 30, 34);
  if(strcmp(str,nothing)){
  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour6, hour);
  }   else {
  strcat(matchingHours.hour6, "--:--");

  }
	free(str);

	str = substring(matchingHoursStr, 36, 40);
  if (strcmp(str,nothing)){
  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour7, hour);
  }   else {
  strcat(matchingHours.hour7, "--:--");

  }
	free(str);

	str = substring(matchingHoursStr, 42, 46);
  if(strcmp(str,nothing)){
  char* part1 = substring(str,0,2);
  char* part2 = substring(str,2,4);
 
  char* hour = strcat(part1,":");
  hour = strcat(hour,part2);
  strcat(matchingHours.hour8, hour);
  }   else {
  strcat(matchingHours.hour8, "--:--");

  }
	free(str);

	return matchingHours;
}

void GetCmdTransmissionMatchingHours(char* command, MatchingHours matchingHours, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HMT");
	} else {
		strcat(command, "RMT");
	}

	strcat(command, matchingHours.hour1);
	strcat(command, strcmp(matchingHours.hour1, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour2);
	strcat(command, strcmp(matchingHours.hour2, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour3);
	strcat(command, strcmp(matchingHours.hour3, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour4);
	strcat(command, strcmp(matchingHours.hour4, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour5);
	strcat(command, strcmp(matchingHours.hour5, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour6);
	strcat(command, strcmp(matchingHours.hour6, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour7);
	strcat(command, strcmp(matchingHours.hour7, "9999") == 0 ? "99" : "00");
	strcat(command, matchingHours.hour8);
	strcat(command, strcmp(matchingHours.hour8, "9999") == 0 ? "99" : "00");
	strcat(command, "//");
	return;
}

/**
 * Get daily traffic limit internal SIM (KB) from the command result given as parameter command.
 * QTRSHDC / QTRSRDC
 */
int GetDailyTrafficInternalSIM(char* command) {
	if (indexOf(command, "QTRSHDC") != 0 && indexOf(command, "QTRSRDC") != 0) {
		return -1;
	}

	char* dailyTrafficStr = substring(command, 7, 15);
	unsigned int resultInt = parseInt(dailyTrafficStr, 16);
	free(dailyTrafficStr);

	return (resultInt / 1024);

}

/**
 * Builds the command to set daiyly traffic. Built command assigned to command parameter.
 */
void GetCmdDailyTrafficInternalSIM(char* command, int dailyTraffic, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HDC");
	} else {
		strcat(command, "RDC");
	}
	char hexa[9] = "";
	toHexaString(hexa, dailyTraffic * 1024, 8);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

/**
 * Get daily traffic limit external SIM (KB) from the command result given as parameter command.
 * QTRSHDL / QTRSRDL
 */
int GetDailyTrafficExternalSIM(char* command) {
	if (indexOf(command, "QTRSHDL") != 0 && indexOf(command, "QTRSRDL") != 0) {
		return -1;
	}

	char* dailyTrafficStr = substring(command, 7, 15);
	unsigned int resultInt = parseInt(dailyTrafficStr, 16);
	free(dailyTrafficStr);

	return (resultInt / 1024);
}

/**
 * Builds the command to set daiyly traffic. Built command assigned to command parameter.
 */
void GetCmdDailyTrafficExternalSIM(char* command, int dailyTraffic, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HDL");
	} else {
		strcat(command, "RDL");
	}
	char hexa[9] = "";
	toHexaString(hexa, dailyTraffic * 1024, 8);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

/**
 * Get monthly traffic limit internal SIM (MB) from the command result given as parameter command.
 * QTRSHMC / QTRSRMC
 */
int GetMonthlyTrafficInternalSIM(char* command) {
	if (indexOf(command, "QTRSHMC") != 0 && indexOf(command, "QTRSRMC") != 0) {
		return -1;
	}

	char* monthlyTrafficStr = substring(command, 7, 15);
	unsigned int resultInt = parseInt(monthlyTrafficStr, 16);
	free(monthlyTrafficStr);

	return (resultInt / 1048576);
}

/**
 * Builds the command to set daiyly traffic. Built command assigned to command parameter.
 */
void GetCmdMonthlyTrafficInternalSIM(char* command, int monthlyTraffic, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HMC");
	} else {
		strcat(command, "RMC");
	}
	char hexa[9] = "";
	toHexaString(hexa, monthlyTraffic * 1048576, 8);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

/**
 * Get monthly traffic limit external SIM (MB) from the command result given as parameter command.
 * QTRSHML / QTRSRML
 */
int GetMonthlyTrafficExternalSIM(char* command) {
	if (indexOf(command, "QTRSHML") != 0 && indexOf(command, "QTRSRML") != 0) {
		return -1;
	}

	char* monthlyTrafficStr = substring(command, 7, 15);
	unsigned int resultInt = parseInt(monthlyTrafficStr, 16);
	free(monthlyTrafficStr);

	return (resultInt / 1048576);
}

/**
 * Builds the command to set daiyly traffic. Built command assigned to command parameter.
 */
void GetCmdMonthlyTrafficExternalSIM(char* command, int monthlyTraffic, Network network) {
	command[0] = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HML");
	} else {
		strcat(command, "RML");
	}
	char hexa[9] = "";
	toHexaString(hexa, monthlyTraffic * 1048576, 8);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

/**
 * Get day of month traffic reset from the command result given as parameter.
 * QTRSTDR
 */
int GetDayOfMonthTrafficReset(char* command) {
	if (indexOf(command, "QTRSTDR") != 0) {
		return -1;
	}

	char* dayOfMonthStr = substring(command, 7, 9);
	unsigned int resultInt = parseInt(dayOfMonthStr, 16);
	free(dayOfMonthStr);

	return resultInt;
}

/**
 * Builds the command to set the day of month traffic reset. Built command assigned to command parameter.
 */
void GetCmdDayOfMonthTrafficReset(char* command, int day) {
	command[0] = '\0';
	strcat(command, "PTRSTDR");
	char hexa[9] = "";
	toHexaString(hexa, day, 2);
	strcat(command, hexa);
	strcat(command, "//");
	return;
}

/**
 * Get delay transmission (seconds) from the command result given as parameter.
 * QTRSHDT / QTRSRDT
 */
int GetDelayTransmission(char* command) {
	if (indexOf(command, "QTRSHDT") != 0 && indexOf(command, "QTRSRDT") != 0) {
		return -1;
	}

	char* delayStr = substring(command, 7, 11);
	unsigned int resultInt = parseInt(delayStr, 10);
	free(delayStr);

	return resultInt;
}

/**
 * Builds the command to set the delay transmission (seconds). Built command assigned to command parameter.
 */
char* GetCmdDelayTransmission(int delay, Network network) {
	
	char* command = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HTD");
	} else {
		strcat(command, "RTD");
	}

	char dec[5] = "";
	sprintf(dec, "%04d", delay);
	strcat(command, dec);
	strcat(command, "//");
	return command;
}

/**
 * Get distance transmission (meters) from the command result given as parameter.
 * QTRSHDT / QTRSRDT
 */
unsigned long GetDistanceTransmission(char* command) {
	if (indexOf(command, "QTRSHTD") != 0 && indexOf(command, "QTRSRTD") != 0) {
		return 0xffffffff;
	}

	char* distanceStr = substring(command, 7, 15);
	unsigned long resultlong = parseLong(distanceStr, 16);
	free(distanceStr);

	return resultlong;
}

/**
 * Builds the command to set the distance transmission (meters). Built command assigned to command parameter.
 */
char* GetCmdDistanceTransmission(unsigned long distanceTransmission, Network network) {
	char* command = '\0';
	strcat(command, "PTRS");
	if (network == HOME) {
		strcat(command, "HTD");
	} else {
		strcat(command, "RTD");
	}
	char hexa[9] = "";
	toHexaString(hexa, distanceTransmission, 8);
	strcat(command, hexa);
	strcat(command, "//");
	return command;
}

/**
 * Builds the command that triggers the transmission now.
 * CTRSREQ
 */
char* GetCmdTransmitNow(char* command) {
	command = '\0';
	strcat(command, "CTRSREQ//");
	return command;
}
