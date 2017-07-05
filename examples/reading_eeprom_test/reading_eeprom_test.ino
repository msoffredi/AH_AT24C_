// Arduino Wire.h is required for ah_at24c_.h
#include "Wire.h"

// AT24C32/64 EEPROM Library 
#include "ah_at24c_.h"

// AT24CX memObj = new AT24CX(0x57);
AT24CX memObj;
        
void setup() {
    byte buffer[16];
    
    Serial.begin(9600);
    Serial.println("Accessing EEPROM AT24Cxx ...");
    
    memObj.read(0, 16, buffer);
    
    for (int x=0; x<16; x++) {
        if (buffer[x] < 0x10) {
          Serial.print("0");
        }

        Serial.print(buffer[x], HEX);
        Serial.print(" ");
    }
    
    Serial.println("");

    // Testing writing to EEPROM (the if is to ensure we don't write on each execution)
    /*
    if (buffer[0] != 9) {
        buffer[0] = 9;
        memObj.write(0, 1, buffer);
    }
    */
}

void loop() {
}
