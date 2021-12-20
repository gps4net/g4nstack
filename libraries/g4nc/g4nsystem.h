#ifndef G4NSYSTEM_H
#define G4NSYSTEM_H

typedef struct {
	unsigned long upTime;  /* seconds */
	char internalClock[20];   /* string formated as hhmmssddmmyyyy, just need to insert the separators i.e. hh:mm:ss dd/mm/yyyy */
	unsigned long syncage; /* seconds */
	char PSN[10];
	int platformHardwareCode;
	int bootloaderVersion;
	char firmwareVersion[10]; /* firmware version, hexa string */
	int firmwareBuildNo;	
} SystemInfo;

typedef struct {
	long records;
	unsigned long totalRecords;
} MemoryInfo;


/**
 * Reads the device system info
 * QSYSINF
 */
SystemInfo GetSystemInfo(char* command);

/**
 * Reads the device memory info
 * QDLFINF
 */
MemoryInfo GetMemoryInfo(char* command);

/**
 * Returns reset command. Return value in the command parameter.
 */
void Reset(char* command);

#endif
