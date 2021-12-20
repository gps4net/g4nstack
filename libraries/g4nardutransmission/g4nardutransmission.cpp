#include "g4nardutransmission.h"

TransmissionSettings QTRSHST() {
  Serial2.write("QTRSHST//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println("Transmission command response : " + commandResult);
  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  TransmissionSettings transmissions = GetTransmissionSettings(s);
    
  return transmissions;  
}

TransmissionSettings QTRSRST() {
  Serial2.write("QTRSRST//");

  delay(100);

  String commandResult = Serial2.readString();  

  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  TransmissionSettings transmissions = GetTransmissionSettings(s);
    
  
  return transmissions;  
}

void PTRSHST(TransmissionSettings transmissionSettings) {
  char command[100] = "";
  transmissionSettings.network = HOME;
  GetCmdTransmissionSettings(command, transmissionSettings);
  Serial.printf("Command sent: %s\n", command);
  Serial2.write(command);

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  
  return;
}

void PTRSRST(TransmissionSettings transmissionSettings) {
  char command[20] = "";
  transmissionSettings.network = ROAMING;
  GetCmdTransmissionSettings(command, transmissionSettings);
  Serial.printf("Command sent: %s\n", command);
  Serial2.write(command);

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  
  return;  
}

void EnableTransmissionParameter(TransmissionParameters param, Network network) {
  char command[20] = "";
  GetCmdEnableTransmissionParameter(command, param, network);
  Serial.printf("Command sent: %s\n", command);
  Serial2.write(command);

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  
  return;    
}

void DisableTransmissionParameter(TransmissionParameters param, Network network) {
  char command[100] = "";
  GetCmdDisableTransmissionParameter(command, param, network);
  Serial.printf("Command sent: %s\n", command);
  Serial2.write(command);

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  
  return;  

}

int QTRSHAD() {
  Serial2.write("QTRSHAD//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  char s[commandResult.length()];
  commandResult.toCharArray(s, commandResult.length());
  int accumulatedData = GetTransmissionAccumulatedData(s);

  return accumulatedData;
}

int QTRSRAD() {
  Serial2.write("QTRSRAD//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  char s[commandResult.length()];
  commandResult.toCharArray(s, commandResult.length());
  int accumulatedData = GetTransmissionAccumulatedData(s);  
  return accumulatedData;
}

void PTRSHAD(int accumulatedData) {
  char command[20] = "";
  GetCmdTransmissionAccumulatedData(command, accumulatedData, HOME);
  Serial.printf("Command sent: %s\n", command);
  Serial2.write(command);

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);
  
  return;    
}

void PTRSRAD(int accumulateddData) {
  
}

int QTRSHIA() {
  return 0;
}

int QTRSRIA() {
  return 0;
}

void PTRSHIA(int intervalA) {
  
}

void PTRSRIA(int intervalA) {
  
}

int QTRSHIB() {
  return 0;
}

int QTRSRIB() {
  return 0;
}

void PTRSHIB(int intervalB) {
  
}

void PTRSRIB(int intervalB) {
  
}

MatchingHours QTRSHMT() {
  MatchingHours matchingHours;
  Serial2.write("QTRSHMT//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);


  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  matchingHours = GetTransmissionMatchingHours(s);

  return matchingHours;
}

MatchingHours QTRSRMT() {
 MatchingHours matchingHours;
  Serial2.write("QTRSRMT//");

  delay(100);

  String commandResult = Serial2.readString();  
  Serial.println(commandResult);


  char s[commandResult.length() + 1];
  commandResult.toCharArray(s, commandResult.length() + 1);

  matchingHours = GetTransmissionMatchingHours(s);
  return matchingHours;  
}

void PTRSHMT(MatchingHours matchingHours) {
  
}

void PTRSRMT(MatchingHours matchingHours) {
  
}

int QTRSHDC() {
  return 0;
}

int QTRSRDC() {
  return 0;
}

void PTRSHDC(int dailyTrafficLimit) {
  
  
}

void PTRSRDC(int dailyTrafficLimit) {
  
}

int QTRSHDL() {
  return 0;
}

int QTRSRDL() {
  return 0;
}

void PTRSHDL(int dailyTrafficLimit) {
  
}

void PTRSRDL(int dailyTrafficLimit) {
  
}

int QTRSHMC() {
  return 0;
}

int QTRSRMC() {
  return 0;
}

void PTRSHMC(int dailyTrafficLimit) {
  
}

void PTRSRMC(int dailyTrafficLimit) {
  
}

int QTRSHML() {
  return 0;
}

int QTRSRML() {
  return 0;
}

void PTRSHML(int dailyTrafficLimit) {
  
}

void PTRSRML(int dailyTrafficLimit) {
  
}

int QTRSTDR() {
  return 0;
}

void PTRSTDR(int dayOfMonth) {
  
}

int QTRSHDT() {
  return 0;
}

int QTRSRDT() {
  return 0;
}

void PTRSHDT(int delayTransmission) {


// Serial2.write(commandResult);

}

void PTRSRDT(int delayTransmission) {

}

unsigned long QTRSHTD() {
  return 0;
}

unsigned long QTRSRTD() {
  return 0;
}

void PTRSHTD(unsigned long distanceTransmission) {
  
}

void PTRSRTD(unsigned long distanceTransmission) {
  
}

void CTRSREQ() {
  
}
