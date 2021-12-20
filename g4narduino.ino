#include "g4nardu.h"
#include "g4nardutransmission.h"
#include "g4nalarm.h"
#include "g4nardualarm.h"
#include "g4nio.h"
#include "g4nIOO.h"

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 16, 17);

  Serial.printf("UART0 initialized\n");
  Serial.printf("UART2 initialized\n");

  Serial2.setTimeout(500);
}

void loop() {

  SystemInfo systemInfo = QSYSINF();
  Serial.printf("System Info\n");
  Serial.printf("...Uptime: %lu\n", systemInfo.upTime);
  Serial.printf("...Clock: %s\n", systemInfo.internalClock);
  Serial.printf("...Syncage: %lu\n", systemInfo.syncage);
  Serial.printf("...PSN: %s\n", systemInfo.PSN);
  Serial.printf("...Platform code: %d\n", systemInfo.platformHardwareCode);
  Serial.printf("...Bootloader: %d\n", systemInfo.bootloaderVersion);
  Serial.printf("...Firmware version: %s\n", systemInfo.firmwareVersion);
  Serial.printf("...Build number: %d\n", systemInfo.firmwareBuildNo);

  GSMInfo gsmInfo = QGSMINF();
  Serial.printf("===================================\n");
  Serial.printf("GSM Info\n");
  Serial.printf("...Default SIM: %d\n", gsmInfo.defaultSIM);
  Serial.printf("...Current status: %d\n", gsmInfo.currentStatus);
  Serial.printf("...Requested status: %d\n", gsmInfo.requestedStatus);

  GSMInfoExtended gsmInfoExtended = QGSMDSI();
  Serial.printf("GSM Info\n");
  Serial.printf("...SIM1 network: %d\n", gsmInfoExtended.sim1Network);
  Serial.printf("...SIM2 network: %d\n", gsmInfoExtended.sim2Network);
  Serial.printf("...SIM1 signal: %d\n", gsmInfoExtended.sim1Signal);
  Serial.printf("...SIM2 signal: %d\n", gsmInfoExtended.sim2Signal);
  Serial.printf("...SIM1 MCC: %s\n", gsmInfoExtended.sim1MCC);
  Serial.printf("...SIM2 MCC: %s\n", gsmInfoExtended.sim2MCC);
  Serial.printf("...SIM1 MNC: %s\n", gsmInfoExtended.sim1MNC);
  Serial.printf("...SIM2 MNC: %s\n", gsmInfoExtended.sim2MNC);
  Serial.printf("...SIM1 IMSI: %s\n", gsmInfoExtended.sim1IMSI);
  Serial.printf("...SIM2 IMSI: %s\n", gsmInfoExtended.sim2IMSI);
  Serial.printf("...SIM1 ICCID: %s\n", gsmInfoExtended.sim1ICCID);
  Serial.printf("...SIM2 ICCID: %s\n", gsmInfoExtended.sim2ICCID);
  Serial.printf("...SIM1 Data Mode: %s\n", gsmInfoExtended.sim1DataMode);
  Serial.printf("...SIM2 Data Mode: %s\n", gsmInfoExtended.sim2DataMode);

  GPSInfo gpsInfo = QGPSINF();
  Serial.printf("===================================\n");
  Serial.printf("GPS Info\n");
  Serial.printf("...Time: %s\n", gpsInfo.time);
  Serial.printf("...Latitude: %f\n", gpsInfo.latitude);
  Serial.printf("...Longitude: %f\n", gpsInfo.longitude);
  Serial.printf("...Altitude: %f\n", gpsInfo.altitude);
  Serial.printf("...SOG: %f\n", gpsInfo.sog);
  Serial.printf("...COG: %f\n", gpsInfo.cog);
  Serial.printf("...Navstat: %d\n", gpsInfo.navstat);
  Serial.printf("...PDOP: %d\n", gpsInfo.pdop);
  Serial.printf("...HDOP: %d\n", gpsInfo.hdop);
  Serial.printf("...VDOP: %d\n", gpsInfo.vdop);
  Serial.printf("...Distance: %f\n", gpsInfo.distance);
  Serial.printf("...Trip distance: %f\n", gpsInfo.tripDistance);
  Serial.printf("...Navigation valid: %d\n", gpsInfo.navigation.valid);
  Serial.printf("...Navigation precision: %d\n\n", gpsInfo.navigation.precision);
  Serial.printf("\n");

  

  TransmissionSettings transmissions; 
  transmissions= QTRSHST();
  Serial.printf("===================================\n");
  Serial.printf("Transmission settings\n");
  Serial.printf("Interval Enabled = %u\n", transmissions.enabled);
  Serial.printf("IntervalA = %u\n", transmissions.intervalA);
  Serial.printf("IntervalA When Contact ON = %u\n", transmissions.intervalAWhenContactOn);
  Serial.printf("IntervalA interval AWhen Contact Off = %u\n", transmissions.intervalAWhenContactOff);
  Serial.printf("IntervalA = %u\n", transmissions.intervalA);
  Serial.printf("IntervalA Contact On = %u\n", transmissions.epochIntervalAcontactOn);
  Serial.printf("IntervalA Contact Off = %u\n", transmissions.intervalBWhenContactOff);
  Serial.printf("IntervalB = %u\n", transmissions.intervalB);
  Serial.printf("Contact = %u\n", transmissions.contact);
  Serial.printf("Monthly traffic limit = %u\n", transmissions.monthlyTraficLimit);
  Serial.printf("IntervalB = %u\n", transmissions.intervalB);
  Serial.printf("Deny transmission @ invalid position = %u\n", transmissions.gpsValid);
  Serial.printf("Hour Match Transmission = %u\n", transmissions.hourMatch);
  Serial.printf("Power On = %u\n", transmissions.powerOn);
  Serial.printf("Transmit at work/private change = %u\n", transmissions.changeWorkPrivate);  
  Serial.printf("\n");

if(transmissions.hourMatch==1){
  Serial.printf("===================================\n");
  Serial.printf("Transmission hours are: \n");
  MatchingHours matchingHours;
  matchingHours = QTRSHMT();
  Serial.printf("MatchingHour1 = %s\n", matchingHours.hour1);
  Serial.printf("MatchingHour2 = %s\n", matchingHours.hour2);
  Serial.printf("MatchingHour3 = %s\n", matchingHours.hour3);
  Serial.printf("MatchingHour4 = %s\n", matchingHours.hour4);
  Serial.printf("MatchingHour5 = %s\n", matchingHours.hour5);
  Serial.printf("MatchingHour6 = %s\n", matchingHours.hour6);
  Serial.printf("MatchingHour7 = %s\n", matchingHours.hour7);
  Serial.printf("MatchingHour8 = %s\n", matchingHours.hour8);
}else {
  Serial.printf("No hours to display \n");
};


IOInfo ioinfo;
ioinfo = GETIO();

Serial.printf("===================================\n");
Serial.printf("IO info\n");
Serial.printf("...AIN1: %f\n", ioinfo.ain1);
Serial.printf("...AIN2: %f\n", ioinfo.ain2);
Serial.printf("...AIN3: %f\n", ioinfo.ain3);
Serial.printf("...DIN1: %d\n", ioinfo.din1);
Serial.printf("...DIN2: %d\n", ioinfo.din2);
Serial.printf("...DIN3: %d\n", ioinfo.din3);
Serial.printf("...inputVoltage: %f\n", ioinfo.inputVoltage);
Serial.printf("...contact: %d\n", ioinfo.contact);
Serial.printf("...infoRelay: %d\n", ioinfo.relay);
Serial.printf("...panicButton: %d\n", ioinfo.panicButton);
Serial.printf("...temperature: %u\n", ioinfo.temperature);


  Alarm alarm;
  alarm = QALMHST();
  //  Serial.printf("alarm %s\n",QALMHST());

  Serial.printf("===================================\n");
  Serial.printf("...Alarm Nework: %d\n", alarm.network);
  Serial.printf("...OverspeedAlarm: %d\n", alarm.overspeed);
  Serial.printf("...OverspeedIgnition: %d\n", alarm.ignition);
  Serial.printf("...PanicButton: %d\n", alarm.panicButton);
  Serial.printf("...Relay Alarm: %d\n", alarm.relay);
  Serial.printf("...Input Under voltage: %d\n", alarm.inputPowerUndervoltage);
  Serial.printf("...Input Over voltage: %d\n", alarm.inputPowerOvervoltage);
  Serial.printf("...Input gpsJamming: %d\n", alarm.gpsJamming);
  Serial.printf("...Input gsmJamming: %d\n", alarm.gsmJamming);
  Serial.printf("...AccelerometerAntitheftAlarm: %d\n", alarm.accelerometerAntitheftAlarm);





  //  int alarmMovement = QALMMOV();
  //  Serial.printf("...Get Alarm Movement: %d\n", alarmMovement);

  int accumulatedData = QTRSHAD();
  Serial.printf("Transmission\n");
  Serial.printf("... Accumulated data home: %d\n", accumulatedData);

  TransmissionSettings transmission = QTRSHST();
  Serial.printf("... Accumulated data param home: %d\n", transmission.accumulatedData);

  DisableTransmissionParameter(ACCUMULATED_DATA, HOME);
  transmission = QTRSHST();
  Serial.printf("... Accumulated data param home: %d\n", transmission.accumulatedData);

  EnableTransmissionParameter(ACCUMULATED_DATA, HOME);
  transmission = QTRSHST();
  Serial.printf("... Accumulated data param home: %d\n", transmission.accumulatedData);

  int alarmOverspeedVelocity = QALMOVS();
  Serial.printf("...TESTING THE QALMOVS - Movement Speed Treshold READ: %d\n", alarmOverspeedVelocity);

  int qalmmov = QALMMOV();
  Serial.printf("...TESTING THE QALMMOV-Movement Treshold READ: %u\n", qalmmov);

  int qalmstf = QALMSTF();
  Serial.printf("...TESTING THE QALMSTNF-Stationary Contact Off Treshold READ: %u\n", qalmstf);

  int qalmssn = QALMSSN();
  Serial.printf("...TESTING THE QALMSSN-Speed Contact On Threshhold READ: %u\n", qalmssn);

  int qalmssf = QALMSSF();
  Serial.printf("...TESTING THE QALMSSN-Speed Contact Off Threshhold READ: %u\n", qalmssf);

  int qalmgtm = QALMGTM();
  Serial.printf("...TESTING THE QALMGTM-Gps Missing Threshhold READ: %u\n", qalmgtm);

  int qalmatd = QALMATD();
  Serial.printf("...TESTING THE QALMGTM-Delay Accelerometer Movent: %u\n", qalmatd);



  delay(5000);
}
