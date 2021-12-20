#ifndef G4NGPS_H
#define G4NGPS_H

typedef struct {
	int valid;      /* 0 - invalid navigation, 1 - valid navigation */
	int precision;	/** 0 or 1 - IDEAL precision
					 *  2 - EXCELENT precision
					 *  3 to 5 - GOOD precision
					 *  6 to 10 - MODERATE precision
					 *  11 to 20 - FAIR precision
					 *  21 or bigger - POOR precision 
					 */
} Navigation;

typedef struct {
	char time[30];        /* string formated as hhmmssddmmyyyy, can be formated i.e. hh:mm:ss dd/mm/yyyy */
	float latitude;       /* degrees */
	float longitude;      /* degrees */
	float altitude;       /* meters */
	float sog;            /* km/h */
	float cog;            /* degrees */
	int navstat;
	int sattelites;       /* number of sattelites */
	unsigned int pdop;
	unsigned int hdop;
	unsigned int vdop;
	float distance;
	float tripDistance;
	Navigation navigation;
} GPSInfo;

/**
 * Reads the device GPS info
 * QGPSINF
 */
GPSInfo GetGPSInfo(char* command);



#endif
