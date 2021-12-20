#ifndef G4NARDUALARM_H
#define G4NARDUALARM_H


#include "Arduino.h"
extern "C" {
#include <g4nutil.h>
#include <g4nalarm.h>
}


Alarm QALMHST();
Alarm QALMRST();


int QALMOVS();
int QALMMOV();


int QALMSTN();
int QALMSTF();


int QALMSSN();
int QALMSSF();


int QALMGTM();
int QALMATD();


#endif