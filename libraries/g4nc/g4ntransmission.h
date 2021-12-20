#ifndef G4NTRANSMISSION_H
#define G4NTRANSMISSION_H

#include "g4nutil.h"
#include <stdbool.h>

typedef struct {
	Network network;
	bool enabled;
	bool intervalA;
	bool intervalAWhenContactOn;
	bool intervalAWhenContactOff;
	bool intervalAWhenAlarmsSet;
	bool intervalB;
	bool intervalBWhenContactOn;
	bool intervalBWhenContactOff;
	bool intervalBWhenAlarmsSet;
	bool alarm;
	bool accumulatedData;
	bool contact;
	bool hourMatch;
	bool iButtonGroup;
	bool dailyTraficLimit;
	bool monthlyTraficLimit;
	bool gpsValid;
	bool powerOn;
	bool delay;
	bool clear;
	bool changeWorkPrivate;
	bool epochIntervalAcontactOn;
	bool epochIntervalAcontactOff;
	bool epochIntervalBcontactOn;
	bool epochIntervalBcontactOff;
	bool cumulativeDistance;
	bool allowTransGenAcqEngine;
	bool transmitRTC;
	bool transmitCANRequests;
} TransmissionSettings;

typedef struct {
	char* hour1[6];
	char* hour2[6];
	char* hour3[6];
	char* hour4[6];
	char* hour5[6];
	char* hour6[6];
	char* hour7[6];
	char* hour8[6];
} MatchingHours;

typedef enum {
	ENABLED,
	INTERVAL_A,
	INTERVAL_A_WHEN_CONTACT_ON,
	INTERVAL_A_WHEN_CONTACT_OFF,
	INTERVAL_A_WHEN_ALARMS_SET,
	INTERVAL_B,
	INTERVAL_B_WHEN_CONTACT_ON,
	INTERVAL_B_WHEN_CONTACT_OFF,
	INTERVAL_B_WHEN_ALARMS_SET,
	ALARMS,
	ACCUMULATED_DATA,
	CONTACT,
	MATCHING_HOURS,
	IBUTTON_GROUP,
	DAILY_TRAFFIC_LIMIT,
	MONTHLY_TRAFFIC_LIMIT,
	GPS_VALID,
	POWER_ON,
	DELAY,
	CLEAR,
	CHANGE_WORK_PRIVATE,
	EPOCH_INTERVAL_A_CONTACT_ON,
	EPOCH_INTERVAL_A_CONTACT_OFF,
	EPOCH_INTERVAL_B_CONTACT_ON,
	EPOCH_INTERVAL_B_CONTACT_OFF,
	CUMULATIVE_DISTANCE,
	ALLOW_TRANS_GEN_ACQ_ENGINE,
	TRANSMIT_RTC,
	TRANSMIT_CAN_REQUESTS
} TransmissionParameters;

/**
 * Get transmission settings from command result given as parameter.
 * QTRSHST / QTRSRST
 */
TransmissionSettings GetTransmissionSettings(char* command);

/**
 * Builds the command to set the transmission settings. Built command assigned to command parameter.
 */
void GetCmdTransmissionSettings(char* command, TransmissionSettings transmission);

/**
 * Builds the command to enable the given parameter.
 * STRSHST
 */
void GetCmdEnableTransmissionParameter(char* command, TransmissionParameters param, Network network);

/**
 * Builds the command to enable the given parameter.
 * RTRSHST
 */
void GetCmdDisableTransmissionParameter(char* command, TransmissionParameters param, Network network);

/**
 * Get the transmission accumulated data (no of KB) from the command result given as parameter.
 * QTRSHAD / QTRSRAD
 */
int GetTransmissionAccumulatedData(char* command);

/**
 * Builds the command to set the transmission accumulated data. Built command assigned to command parameter.
 */
void GetCmdTransmissionAccumulatedData(char* command, int accumulatedData, Network network);

/**
 * Get interval A transmission (seconds) from the command result given as parameter.
 * QTRSHIA / QTRSRIA
 */
int GetTransmissionIntervalA(char* command);

/**
 * Builds the command to set Interval A transmission. Built command assigned to command parameter.
 */
void GetCmdTransmissionIntervalA(char* command, int intervalA, Network network);

/**
 * Get interval B transmission (seconds) from the command result given as parameter.
 * QTRSHIB / QTRSRIB
 */
int GetTransmissionIntervalB(char* command);

/**
 * Builds the command to set Interval B transmission. Built command assigned to command parameter.
 */
void GetCmdTransmissionIntervalB(char* command, int intervalB, Network network);

/**
 * Get matching hours transmission from the command result given as parameter. There are 6 matching hours.
 * QTRSHMT / QTRSRMT
 */
MatchingHours GetTransmissionMatchingHours(char* command);

/**
 * Builds the command to set the matching hours transmission. Built command assigned to command parameter.
 */
void GetCmdTransmissionMatchingHours(char* command, MatchingHours matchingHours, Network network);

/**
 * Get daily traffic limit internal SIM (KB) from the command result given as parameter.
 * QTRSHDC / QTRSRDC
 */
int GetDailyTrafficInternalSIM(char* command);

/**
 * Builds the command to set daily traffic. Built command assigned to command parameter.
 */
void GetCmdDailyTrafficInternalSIM(char* command, int dailyTraffic, Network network);

/**
 * Get daily traffic limit external SIM (KB) from the command result given as parameter.
 * QTRSHDL / QTRSRDL
 */
int GetDailyTrafficExternalSIM(char* command);

/**
 * Builds the command to set monthly traffic. Built command assigned to command parameter.
 */
void GetCmdDailyTrafficExternalSIM(char* command, int dailyTraffic, Network network);

/**
 * Get monthly traffic limit internal SIM (MB) from the command result given as parameter.
 * QTRSHMC / QTRSRMC
 */
int GetMonthlyTrafficInternalSIM(char* command);

/**
 * Builds the command to set monthly traffic. Built command assigned to command parameter.
 */
void GetCmdMonthlyTrafficInternalSIM(char* command, int monthlyTraffic, Network network);

/**
 * Get monthly traffic limit external SIM (MB) from the command result given as parameter.
 * QTRSHML / QTRSRML
 */
int GetMonthlyTrafficExternalSIM(char* command);

/**
 * Builds the command to set monthly traffic. Built command assigned to command parameter.
 */
void GetCmdMonthlyTrafficExternalSIM(char* command, int monthlyTraffic, Network network);

/**
 * Get day of month traffic reset from the command result given as parameter.
 * QTRSTDR
 */
int GetDayOfMonthTrafficReset(char* command);

/**
 * Builds the command to set the day of month traffic reset. Built command assigned to command parameter.
 */
void GetCmdDayOfMonthTrafficReset(char* command, int day);

/**
 * Get delay transmission (seconds) from the command result given as parameter.
 * QTRSHDT / QTRSRDT
 */
int GetDelayTransmission(char* command);

/**
 * Builds the command to set the delay transmission (seconds). Built command assigned to command parameter.
 */
char* GetCmdDelayTransmission( int delay, Network network);

/**
 * Get distance transmission (meters) from the command result given as parameter.
 * QTRSHTD / QTRSRTD
 */
unsigned long GetDistanceTransmission(char* command);

/**
 * Builds the command to set the distance transmission (meters). Built command assigned to command parameter.
 */
char* GetCmdDistanceTransmission( unsigned long distanceTransmission, Network network);

/**
 * Builds the command that triggers the transmission now.
 * CTRSREQ
 */
char* GetCmdTransmitNow();

#endif
