#ifndef G4NARDUTRANSMISSION_H
#define G4NARDUTRANSMISSION_H

#include "Arduino.h"
extern "C" {
#include <g4nutil.h>
#include <g4ntransmission.h>
}

TransmissionSettings QTRSHST();
TransmissionSettings QTRSRST();
void PTRSHST(TransmissionSettings transmissionSettings);
void PTRSRST(TransmissionSettings transmissionSettings);
void EnableTransmissionParameter(TransmissionParameters param, Network network);
void DisableTransmissionParameter(TransmissionParameters param, Network network);


int QTRSHAD();
int QTRSRAD();
void PTRSHAD(int accumulateddData);
void PTRSRAD(int accumulateddData);

int QTRSHIA();
int QTRSRIA();
void PTRSHIA(int intervalA);
void PTRSRIA(int intervalA);

int QTRSHIB();
int QTRSRIB();
void PTRSHIB(int intervalB);
void PTRSRIB(int intervalB);

MatchingHours QTRSHMT();
MatchingHours QTRSRMT();
void PTRSHMT(MatchingHours matchingHours);
void PTRSRMT(MatchingHours matchingHours);

int QTRSHDC();
int QTRSRDC();
void PTRSHDC(int dailyTrafficLimit);
void PTRSRDC(int dailyTrafficLimit);

int QTRSHDL();
int QTRSRDL();
void PTRSHDL(int dailyTrafficLimit);
void PTRSRDL(int dailyTrafficLimit);

int QTRSHMC();
int QTRSRMC();
void PTRSHMC(int dailyTrafficLimit);
void PTRSRMC(int dailyTrafficLimit);

int QTRSHML();
int QTRSRML();
void PTRSHML(int dailyTrafficLimit);
void PTRSRML(int dailyTrafficLimit);

int QTRSTDR();
void PTRSTDR(int dayOfMonth);

int QTRSHDT();
int QTRSRDT();
void PTRSHDT(int delayTransmission);
void PTRSRDT(int delayTransmission);

unsigned long QTRSHTD();
unsigned long QTRSRTD();
void PTRSHTD(unsigned long distanceTransmission); 
void PTRSRTD(unsigned long distanceTransmission); 

void CTRSREQ();

#endif
