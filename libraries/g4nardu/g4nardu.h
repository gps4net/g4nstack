#ifndef G4NARDU_H
#define G4NARDU_H

#include "Arduino.h"
extern "C" {
#include <g4ngps.h>
#include <g4ngsm.h>
#include <g4nsystem.h>
#include <g4nutil.h>
#include <g4nalarm.h>
#include <g4nio.h>
// #include "../g4nardualarm/g4nardualarm.h"
// #include "../g4nardutransmission/g4nardutransmission.h"

}


SystemInfo QSYSINF();

GSMInfo QGSMINF();

GSMInfoExtended QGSMDSI();

GPSInfo QGPSINF();

MemoryInfo QDLFINF();

// Alarm QALMHST();

// Alarm QALMRST();

void cSYSRST();



#endif
