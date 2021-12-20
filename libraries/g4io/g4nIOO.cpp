#include "g4nIOO.h"


IOInfo GETIO() {

    Serial2.write("QDIOINF//"); 
    delay(100);
    String commandResult = Serial2.readString();  
    Serial.println(commandResult);
    char s[commandResult.length() + 1];
    commandResult.toCharArray(s, commandResult.length() + 1);
    return GetIOInfo(s);
}