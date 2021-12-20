#include <stdlib.h>
#include <string.h>
#include "g4nsystem.h"
#include "g4nutil.h"

SystemInfo GetSystemInfo(char* command) {

	SystemInfo sysInfo;

	/**
	 * REPLY: QSYSINF AAAAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCDDDDDDDDEEFFGGHH//
	 * A: SYSTEM UPTIME, BINARY FORMAT, 10 MS STEP, LITTLE ENDIAN ORDER
	 * B: REAL TIME CLOCK, HOUR,MINUTE,SEC,TENS SEC,DAY,MONTH,YEAR
	 * C: SYNCAGE, IN SECONDS, BINARY FORMAT, LITTLE ENDIAN ORDER
	 * D: PSN, E:PLATFORM HARDWARE CODE, F:BOOTLOADER VERSION
	 * G: FIRMWARE VERSION, E: FIRMWARE BUILD NO.
	 */
	char* upTimeStr = substring(command, 7, 15);
	sysInfo.upTime = parseLong(upTimeStr, 16);
	free(upTimeStr);

	sysInfo.internalClock[0] = '\0';
	char* str = substring(command, 15, 31);
	strcat(sysInfo.internalClock, str);
	free(str);

	char* syncageStrRev = Reverse(substring(command, 31, 39));
	sysInfo.syncage = parseLong(syncageStrRev, 16);
	free(syncageStrRev);

	sysInfo.PSN[0] = '\0';
	str = substring(command, 39, 47);
	strcat(sysInfo.PSN, str);
	free(str);

	char *platformCodeStr = substring(command, 47, 49);
	sysInfo.platformHardwareCode = parseInt(platformCodeStr, 16);
	free(platformCodeStr);

	char * bootloaderVersionStr = substring(command, 49, 51);
	sysInfo.bootloaderVersion = parseInt(bootloaderVersionStr, 16);
	free(bootloaderVersionStr);

	sysInfo.firmwareVersion[0] = '\0';
	str = substring(command, 51, 53);
	strcat(sysInfo.firmwareVersion, str);
	free(str);

	char* buildStr = substring(command, 53, 55);
	sysInfo.firmwareBuildNo = parseInt(buildStr, 16);
	free(buildStr);

	return sysInfo;
}

MemoryInfo GetMemoryInfo(char* command) {

	MemoryInfo memory;

	char* recordsStr = substring(command, 7, 13);
	long records = parseLong(recordsStr, 16);
	memory.records = records;
	free(recordsStr);

	char* totalRecordsStr = substring(command, 13, 19);
	long totalRecords = parseLong(totalRecordsStr, 16);
	memory.totalRecords = totalRecords;
	free(totalRecordsStr);

	return memory;
}

void Reset(char* command) {
	strcat(command, "cSYSRST//");
}
