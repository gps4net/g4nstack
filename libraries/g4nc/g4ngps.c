#include <stdlib.h>
#include <string.h>
#include "g4ngps.h"
#include "g4nutil.h"

GPSInfo GetGPSInfo(char* command) {

	GPSInfo gpsInfo;
	Navigation navigation;

	char* navstatStr = substring(command, 45, 47);
	int navstat = parseInt(navstatStr, 16);
	free(navstatStr);

	gpsInfo.navstat = navstat;

	char* str = substring(command, 7, 21);
	gpsInfo.time[0] = '\0';
	strcat(gpsInfo.time, str);
	free(str);

	char* latStr = substring(command, 21, 29);
	char* latMinStrBeforeComma = substring(latStr, 2, 4);
	char* latMinStrAfterComma = substring(latStr, 4, 8);
	char* latDegreesStr = substring(latStr, 0, 2);
	char s[] = "";
	strcat(s, latMinStrBeforeComma);
	strcat(s, ".");
	strcat(s, latMinStrAfterComma);
	float latMinites = atof(s);
	float latDegrees = atof(latDegreesStr);
	float lat = latDegrees + (latMinites / 60);

	free(latStr);
	free(latMinStrBeforeComma);
	free(latMinStrAfterComma);
	free(latDegreesStr);

	if ((navstat & 0x40) != 0) {
		lat = -lat;
	}
	gpsInfo.latitude = lat;

	char* lonStr = substring(command, 29, 39);
	char* lonMinStrBeforeComma = substring(lonStr, 4, 6);
	char* lonMinStrAfterComma = substring(lonStr, 6, 10);
	char* lonDegreesStr = substring(lonStr, 0, 4);
	char slon[] = "";
	strcat(slon, lonMinStrBeforeComma);
	strcat(slon, ".");
	strcat(slon, lonMinStrAfterComma);
	float lonMinites = atof(slon);
	float lonDegrees = atof(lonDegreesStr);
	float lon = lonDegrees + (lonMinites / 60);

	free(lonStr);
	free(lonMinStrBeforeComma);
	free(lonMinStrAfterComma);
	free(lonDegreesStr);

	if ((navstat & 0x20) != 0) {
		lon = -lon;
	}
	gpsInfo.longitude = lon;

	char* altStr = substring(command, 39, 45);
	char* altStrBeforeComma = substring(altStr, 0, 4);
	char* altStrAfterComma = substring(altStr, 4, 6);
	if(altStrAfterComma[0] == '0') {
		altStrAfterComma = substring(altStr, 5, 6);
	}
	char alts[] = "";
	strcat(alts, altStrBeforeComma);
	strcat(alts, ".");
	strcat(alts, altStrAfterComma);
	float alt = atof(alts);

	free(altStrBeforeComma);
	free(altStrAfterComma);
	free(altStr);

	if ((navstat & 0x80) != 0) {
		alt = -alt;
	}
	gpsInfo.altitude = alt;


	char* sogStr = substring(command, 47, 53);
	char* sogStrBeforeComma = substring(sogStr, 0, 4);
	char* sogStrAfterComma = substring(sogStr, 4, 6);
	if(sogStrAfterComma[0] == '0') {
		sogStrAfterComma = substring(sogStr, 5, 6);
	}

	char sogs[] = "";
	strcat(sogs, sogStrBeforeComma);
	strcat(sogs, ".");
	strcat(sogs, sogStrAfterComma);

	float sog = atof(sogs);

	free(sogStrAfterComma);
	free(sogStrBeforeComma);
	free(sogStr);

	gpsInfo.sog = sog;

	char* cogStr = substring(command, 53, 59);
	char* cogStrBeforeComma = substring(cogStr, 0, 4);
	char* cogStrAfterComma = substring(cogStr, 4, 6);
	if(cogStrAfterComma[0] == '0') {
		cogStrAfterComma = substring(cogStr, 5, 6);
	}

	char cogs[] = "";
	strcat(cogs, cogStrBeforeComma);
	strcat(cogs, ".");
	strcat(cogs, cogStrAfterComma);

	float cog = atof(cogs);

	free(cogStrAfterComma);
	free(cogStrBeforeComma);
	free(cogStr);

	gpsInfo.cog = cog;


	char* nosvgpsStr = substring(command, 59, 61);
	gpsInfo.sattelites = parseInt(nosvgpsStr, 10);
	free(nosvgpsStr);


	char *pdopStr = substring(command, 61, 65);
	gpsInfo.pdop = parseInt(pdopStr, 16);

	char *precisionStr = substring(pdopStr, 0, 2);
	navigation.precision = parseInt(precisionStr, 16);

	free(pdopStr);
	free(precisionStr);

	if ((navstat & 0x10) == 0) {
		navigation.valid = 0;
	}

	gpsInfo.navigation = navigation;

	char* hdopStr = substring(command, 65, 69);
	gpsInfo.hdop = parseInt(hdopStr, 16);
	free(hdopStr);

	char* vdopStr = substring(command, 69, 73);
	gpsInfo.vdop = parseInt(vdopStr, 16);
	free(vdopStr);

	char* distanceStr = substring(command, 73, 81);
	float distance = parseLong(distanceStr, 16);
	gpsInfo.distance = distance / 1000;
	free(distanceStr);

	char* tripDistanceStr = substring(command, 81, 89);
	float tripDistance = parseLong(tripDistanceStr, 16);
	gpsInfo.tripDistance = tripDistance / 1000;
	free(tripDistanceStr);

	return gpsInfo;
}
