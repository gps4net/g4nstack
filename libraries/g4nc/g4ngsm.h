#ifndef G4NGSM_H
#define G4NGSM_H

typedef struct {
	int defaultSIM;       /* 1 - SIM1, 2 - SIM2 */
	int currentStatus;    /* modem status (i.e. stopped, searching for network, etc.) */
	int requestedStatus;  		
} GSMInfo;

typedef struct {
	int sim1Network;         /* 1 - HOME, 2 - ROAMING */
	int sim2Network;         /* 1 - HOME, 2 - ROAMING */
	int sim1Signal;          /* 0 - No signal, 1-3 - POOR, 4-10 - GOOD, 11-14 VERY GOOD, 15 - EXCELENT */
	int sim2Signal;          /* 0 - No signal, 1-3 - POOR, 4-10 - GOOD, 11-14 VERY GOOD, 15 - EXCELENT */
	char sim1MCC[10];           /* MCC code SIM 1 */
	char sim2MCC[10];           /* MCC code SIM 2 */
	char sim1MNC[10];           /* MNC code SIM 1 */
	char sim2MNC[10];           /* MNC code SIM 2 */
	char sim1IMSI[20];
	char sim2IMSI[20];
	char sim1ICCID[30];
	char sim2ICCID[30];
	char sim1DataMode[5];      /* i.e. 2G, 5G */
	char sim2DataMode[5];      /* i.e. 2G, 5G */
} GSMInfoExtended;

typedef enum {
	USER,
	ALERT,
	VOICE,
	CSD
} PhoneNumberType;

typedef struct {
	char phoneNumber[15];
	int position;
	PhoneNumberType type;
} AuthorizedNumber;

/**
 * Reads the GSM Info.
 * QGSMINF
 */
GSMInfo GetGSMInfo(char* command);

/**
 * Reads the extended GSM info.
 * QGSMDSI
 */
GSMInfoExtended GetGSMInfoExtended(char* command);

/**
 * Reads the authorized number from the command result.
 *
 * QGSMAXX where XX is the position (i.e. 04 is the 4th position in the list of authorized numbers), type is USER, max 12 positions
 * QGSMALX where X is the position (i.e. 5 is the 5th position in the list of authorized numbers), type is ALERT, max 8 positions
 * QGSMVDX where X is the position (i.e. 2 is the 2nd position in the list of authorized numbers), type is VOICE, max 6 positions
 * QGSMCSX where X is the position (i.e. 2 is the 2nd position in the list of authorized numbers), type is VOICE, max 2 positions
 */
AuthorizedNumber GetAuthorizedNumber(char* command);

/**
 * Returns the command to authorize a phone number. Return value in command parameter.
 */
void SetAuthorizedNumber(char* command, char* number, int position, PhoneNumberType type);

#endif
