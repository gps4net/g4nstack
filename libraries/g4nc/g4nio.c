#include <stdlib.h>
#include "g4nio.h"
#include "g4nutil.h"

IOInfo GetIOInfo(char* command) {

	IOInfo ioInfo;

	char* ioStatusStr = substring(command, 163, 165);
	long ioStatus = parseLong(ioStatusStr, 16);
	free(ioStatusStr);

	char* ioStatus2Str = substring(command, 165, 167);
	long ioStatus2 = parseLong(ioStatus2Str, 16);
	free(ioStatus2Str);

	char* ain1Str = substring(command, 167, 171);
	long ain1 = parseLong(ain1Str, 16);
	free(ain1Str);
	ioInfo.ain1 = 0.0071838f * ain1;

	char* ain2Str = substring(command, 171, 175);
	long ain2 = parseLong(ain2Str, 16);
	free(ain2Str);
	ioInfo.ain2 = 0.0071838f * ain2;

	char* ain3Str = substring(command, 175, 179);
	long ain3 = parseLong(ain3Str, 16);
	free(ain3Str);
	ioInfo.ain3 = 0.0071838f * ain3;

	if ((ioStatus2 & 0x04) != 0) {
		ioInfo.din1 = 1;
	} else {
		ioInfo.din1 = 0;
	}

	if ((ioStatus2 & 0x08) != 0) {
		ioInfo.din2 = 1;
	} else {
		ioInfo.din2 = 0;
	}

	if ((ioStatus2 & 0x10) != 0) {
		ioInfo.din3 = 1;
	} else {
		ioInfo.din3 = 0;
	}

	char* powerInVoltageStr = substring(command, 191, 195);
	long powerInVoltage = parseLong(powerInVoltageStr, 16);
	free(powerInVoltageStr);
	ioInfo.inputVoltage = 0.0071838f * powerInVoltage;

	char* temperatureStr = substring(command, 199, 203);
	long temperature = parseLong(temperatureStr, 16);
	free(temperatureStr);
	ioInfo.temperature = ((0.0005493164 * temperature) - 0.856) / 0.00333;

	if ((ioStatus & 0x01) == 0x01) {
		ioInfo.contact = 1;
	} else {
		ioInfo.contact = 0;
	}

	if ((ioStatus & 0x02) == 0x02) {
		ioInfo.relay = 1;
	} else {
		ioInfo.relay = 0;
	}

	if ((ioStatus & 0x04) == 0x04) {
		ioInfo.panicButton = 1;
	} else {
		ioInfo.panicButton = 0;
	}

	return ioInfo;
}
