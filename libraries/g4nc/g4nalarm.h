#ifndef G4NALARM_H
#define G4NALARM_H
#include <stdbool.h>
#include "g4nutil.h"

typedef struct {
Network network;
// bool network1;  	               		/* Indicates the network.True if local/home, false if roaming */ 
bool alarms; 	               			/* Indicates if the alarms are allowed for the selected network. */
bool overspeed;                			/* Indicates if the overspeed alarm is on/off. */
bool ignition;	               			/* Indicates if the ignition alarm is on/off. */	
bool panicButton;              			/* Indicates if the panic button alarm is on/off. */
bool relay;                    			/* Indicates if relay alarm is on/off. */  
bool inputPowerUndervoltage;   			/* Inficates if input power undervoltage alarm is on/off. */
bool inputPowerOvervoltage;    			/* Indicates if input power overvoltage alarm is on/off. */
bool accVoltageUnderThreshold; 			/* Indicates if accumulator voltage is under voltage alarm is on/off. */   
bool accError;                 			/* Indicates if accumulator installed and charger indicates error alarm is on/off. */
bool relayDisconnected;		   			/* Indicates if relay disconnected alarm is on/off. */
bool iButtonDisconnected;	   			/* Indicates if iButton disconnected alarm is on/off. */
bool dailyTrafficExceeded;     			/* Indicates if daily traffic exceeded alarm is on/off. */
bool monthlyTrafficExceeded;   			/* Indicates if monthly traffic exceeded alarm is on/off. */
bool gpsMissing;			   			/* Indicates if GPS signal is missing more than programmed time alarm is on/off.	*/
bool stationaryContactOn;	   			/* Indicates if vehicle with contact on is not moving more than threshold alarm is on/off. */
bool stationaryContactOff;	   			/* Indicates if vehicle with contact off is not moving more than threshold alarm is on/off. */
bool speedExceededContactOffThreshold;  /* Indicates if vehicle is moving with contact off and speed exceeds threshold alarm is on/off. */
bool motionSensorMovement;     			/* Indicates if motion sensor indicates movement. */
bool gpsJamming; 			   			/* Indicates if GPS jamming alarm is on/off. */
bool gsmJamming;			   			/* Indicates if GSM jamming alarm is on/off.. */
bool dataLimit;				   			/* Indicates if data limit alarm is on/off. */
bool privateAlarm; 			   			/* Alarm is on as long as private mode is on.*/
bool accelerometerAntitheftAlarm; 		/* Accelerometer antitheft alarm.*/
int speedThreshold; 		  		    /* Speed threshold for overspeed alarm (in Km/h * 10). Default is 90 Km/h. */
int movementThreshold;       		    /* Movement speed threshold for movement alarm (in Km/h * 10). Default is 20 Km/h. */
int stationaryContactOnThreshold;       /* Time threshold of stationary alarm contact on (seconds). */ 
int stationaryContactOffThreshold;      /* Time threshold of stationary alarm contact on (seconds). */  
int speedContactOnThreshold; 		    /* Speed threshold of stationary alarm contact on (in Km/h * 10). */
int speedContactOffThreshold;   	    /* Speed threshold of stationary alarm contact off (in Km/h * 10). */
int gpsMissingThreshold;     		    /* Threshold for missing GPS signal (seconds). */ 
int dataflashLimit1;    			    /* Theshold for data flash limit alarm (bytes). */   
int delayAccelerometerMovement;         /* Delay from accelerometer movement detection to movement alarm on. */

} Alarm;

/**
 * Reads device ALARM info
 * if Invalid command return NULL
 * QALMHST for home 
 * QALMRST for roaming
 */
Alarm GetAlarm(char* command);

int getSpeedThreshold(char* command);

int getAlarmMovement(char* command);

int getStationaryContactOnThreshold(char* command);

int getStationaryContactOffThreshold(char* command);

int getSpeedContactOnThreshold(char* command);

int getSpeedContactOffThreshold(char* command);

int getGpsMissingTime(char* command);

int getDelayAccelerometerMovement (char* command);





#endif
