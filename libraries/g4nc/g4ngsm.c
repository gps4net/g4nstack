#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "g4ngsm.h"
#include "g4nutil.h"

/**
 * QGSMINF AABBBBBBCCCCCCDDDDDDDDDDDDDDDEEFF//
 * A-XR_GSM_STAT, B-XR_GSM_MCCMNC, C-XR_GSM_EXTSIMMCCMNC, D-SIMCHIP IMSI
 * E-XR_GSMAUT_CURRENTSTAT, F-XR_GSMAUT_REQUESTSTAT
 *
 * XR_GSM_STAT
 * 		BIT0 - GSM REGISTRATION STATUS, 0 UNREGISTERED, 1 REGISTERED IN A GSM NETWORK
 * 		BIT1 - GSM NETWORK TYPE, IF REGISTERED, 0 FOR HOME NETWORK, 1 FOR ROAMING NETWORK
 * 		BIT2 - GSM ROAMING NETWORK, IF REGISTERED IN ROAMING: 0 FOR PREFERRED NETWORK, 1 FOR NON PREFERRED NETWORK
 * 		BIT3 - GPRS STATUS, 0 DETACHED FROM GPRS CONTEXT, 1 ATTACHED TO GPRS CONTEXT
 * 		BIT4 - SIM SELECTOR, 0 EXTERNAL SIM IS USED, 1-INTERNAL SIM CHIP IS USED
 * 		BIT5 TO 7 - GSM SIGNAL STRENGTH, MEASURED WITH CSQ
 *
 * QGSMINF
 */
GSMInfo GetGSMInfo(char* command) {

	GSMInfo gsm;

	char* gsmStatusStr = substring(command, 7, 9);
	int gsmStatus = parseInt(gsmStatusStr, 16);
	gsm.defaultSIM = 1;
	if ((gsmStatus & 0x10) != 0) {
		gsm.defaultSIM = 2;
	}
	free(gsmStatusStr);

	char* currentStatusStr = substring(command, 36, 38);
	gsm.currentStatus = parseInt(currentStatusStr, 16);
	free(currentStatusStr);

	char* requestedStatusStr = substring(command, 38, 40);
	gsm.requestedStatus = parseInt(requestedStatusStr, 16);
	free(requestedStatusStr);

	return gsm;
}

/** QGSMDSI */
GSMInfoExtended GetGSMInfoExtended(char* command) {

	GSMInfoExtended gsm;

	char* gsmStatusSim1Str = substring(command, 7, 9);
	int gsmStatusSim1 = parseInt(gsmStatusSim1Str, 16);
	if ((gsmStatusSim1 & 0x01) != 0 && ((gsmStatusSim1 & 0x02) == 0)) {
		gsm.sim1Network = 1; /* HOME */
	}
	if ((gsmStatusSim1 & 0x01) != 0 && ((gsmStatusSim1 & 0x02) == 0)) {
		gsm.sim1Network = 2; /* ROAMING */
	}
	char* gsmStatusSim2Str = substring(command, 7, 9);
	int gsmStatusSim2 = parseInt(gsmStatusSim2Str, 16);
	if ((gsmStatusSim2 & 0x01) != 0 && ((gsmStatusSim2 & 0x02) == 0)) {
		gsm.sim2Network = 1; /* HOME */
	}
	if ((gsmStatusSim2 & 0x01) != 0 && ((gsmStatusSim2 & 0x02) == 0)) {
		gsm.sim2Network = 2; /* ROAMING */
	}

	free(gsmStatusSim1Str);
	free(gsmStatusSim2Str);

	gsm.sim1Signal = (gsmStatusSim1 & 0xE0) >> 5;
	gsm.sim2Signal = (gsmStatusSim2 & 0xE0) >> 5;

	char* sim1IMSI = substring(command, 11, 27);

	char* str = substring(sim1IMSI, 0, 3);
	gsm.sim1MCC[0] = '\0';
	strcat(gsm.sim1MCC, str);
	free(str);

	str = substring(sim1IMSI, 3, 6);
	gsm.sim1MNC[0] = '\0';
	strcat(gsm.sim1MNC, str);
	free(str);

	str = substring(command, 11, 27);
	gsm.sim1IMSI[0] = '\0';
	strcat(gsm.sim1IMSI, str);
	free(str);

	free(sim1IMSI);

	char* sim2IMSI = substring(command, 49, 65);

	str = substring(sim2IMSI, 0, 3);
	gsm.sim2MCC[0] = '\0';
	strcat(gsm.sim2MCC, str);
	free(str);

	str = substring(sim2IMSI, 3, 6);
	gsm.sim2MNC[0] = '\0';
	strcat(gsm.sim2MNC, str);
	free(str);

	str = substring(command, 49, 65);
	gsm.sim2IMSI[0] = '\0';
	strcat(gsm.sim2IMSI, str);
	free(str);

	free(sim2IMSI);

	str = substring(command, 27, 49);
	gsm.sim1ICCID[0] = '\0';
	strcat(gsm.sim1ICCID, str);
	free(str);

	str = substring(command, 65, 87);
	gsm.sim2ICCID[0] = '\0';
	strcat(gsm.sim2ICCID, str);
	free(str);

	if ((gsmStatusSim1 & 0x02) == 0) {
		gsm.sim1DataMode[0] = '\0';
		strcat(gsm.sim1DataMode, "2G");
	} else {
		gsm.sim1DataMode[0] = '\0';
		strcat(gsm.sim1DataMode, "5G");
	}

	if ((gsmStatusSim2 & 0x02) == 0) {
		gsm.sim2DataMode[0] = '\0';
		strcat(gsm.sim2DataMode, "2G");
	} else {
		gsm.sim2DataMode[0] = '\0';
		strcat(gsm.sim2DataMode, "5G");
	}

	return gsm;
}

AuthorizedNumber GetAuthorizedNumber(char* command) {
	AuthorizedNumber authNumber;
	char* positionStr;
	char* str;
	PhoneNumberType type;
	switch (command[4]) {
		case 'A':
			if (command[5] == 'L') {
				authNumber.type = ALERT;
				positionStr = substring(command, 6, 7);
				authNumber.position = parseInt(positionStr, 10);
				free(positionStr);
			} else {
				authNumber.type = USER;
				positionStr = substring(command, 5, 7);
				authNumber.position = parseInt(positionStr, 10);
				free(positionStr);
			}
			str = substring(command, 7, indexOf(command, "//"));
			authNumber.phoneNumber[0] = '\0';
			strcat(authNumber.phoneNumber, str);
			free(str);
			break;
		case 'V':
			authNumber.type = VOICE;
			positionStr = substring(command, 6, 7);
			authNumber.position = parseInt(positionStr, 10);
			free(positionStr);

			str = substring(command, 7, indexOf(command, "//"));
			authNumber.phoneNumber[0] = '\0';
			strcat(authNumber.phoneNumber, str);
			free(str);
			break;
		case 'C':
			authNumber.type = CSD;
			positionStr = substring(command, 6, 7);
			authNumber.position = parseInt(positionStr, 10);
			free(positionStr);

			str = substring(command, 7, indexOf(command, "//"));
			authNumber.phoneNumber[0] = '\0';
			strcat(authNumber.phoneNumber, str);
			free(str);
			break;
	}
	return authNumber;
}

void SetAuthorizedNumber(char* command, char* number, int position, PhoneNumberType type) {
	command[0] = '\0';
	strcat(command, "PGSM");
	switch (type) {
		case USER:
			strcat(command, "A");
			char positionStrU[12] = "";
			sprintf(positionStrU, "%02d", position);
			strcat(command, positionStrU);
			strcat(command, number);
			strcat(command, "//");
			break;
		case ALERT:
			strcat(command, "AL");
			char positionStrA[12] = "";
			sprintf(positionStrA, "%1d", position);
			strcat(command, positionStrA);
			strcat(command, number);
			strcat(command, "//");
			break;
		case VOICE:
			strcat(command, "VD");
			char positionStrV[12] = "";
			sprintf(positionStrV, "%1d", position);
			strcat(command, positionStrV);
			strcat(command, number);
			strcat(command, "//");
			break;
		case CSD:
			strcat(command, "CS");
			char positionStrC[12] = "";
			sprintf(positionStrC, "%d", position);
			strcat(command, positionStrC);
			strcat(command, number);
			strcat(command, "//");
			break;
	}
}
