/* 
 * AH_AT24C_ Library to read and write to/from Atmel(s) EEPROM(s) AT24C32/64
 * 
 * Author: Marcelo Soffredi
 * Website: http://www.arduinohobby.com
 * 
 * Created on July 5, 2017, 11:59 AM
 */

#ifndef AH_AT24C__H
#define AH_AT24C__H

#include <Arduino.h>
#include "Wire.h"

#define AT24CX_DEF_ADDR 0x57

// Status where 0 = OK because 0 is what we get from Wire.endTransaction()
// when connection was successful.
#define AT24CX_STATUS_OK 0

class AT24CX {
    
public:
    AT24CX();
    AT24CX(uint8_t i2cAddress);
    
    uint8_t status();

    // Reads multiple bytes into buffer
    void read(uint16_t address, uint8_t size, uint8_t *buffer);
    
    // Reads one byte and returns the byte read
    uint8_t readByte(uint16_t address);

    // Writes multiple bytes from buffer
    void write(uint16_t address, uint8_t size, uint8_t *buffer);
    
private:
    uint8_t _address;
    uint8_t _status;
    
    // Init Wire.h library
    void init();

};

#endif /* AH_AT24C__H */

