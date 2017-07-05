#include "ah_at24c_.h"

AT24CX::AT24CX() {
    this->_address = AT24CX_DEF_ADDR;
    Wire.begin();
}

AT24CX::AT24CX(uint8_t i2cAddress) {
    this->_address = i2cAddress;
    Wire.begin();
}

void AT24CX::read(uint16_t address, uint8_t size, uint8_t *buffer) {
    if (size) {
        Wire.beginTransmission(this->_address);
        Wire.write((uint8_t)(address >> 8));
        Wire.write((uint8_t)(address));
        Wire.endTransmission();

        Wire.requestFrom(this->_address, size);

        for (int x=0; x<size; x++) {
            if (Wire.available()) {
                *(buffer+x) = Wire.read();
            }
        }
    }
}

uint8_t AT24CX::readByte(uint16_t address) {
    uint8_t buffer[1];
    this->read(address, 1, buffer);
    return buffer[0];
}

void AT24CX::write(uint16_t address, uint8_t size, uint8_t *buffer) {
    if (size) {
        Wire.beginTransmission(this->_address);
        Wire.write((uint8_t)(address >> 8));
        Wire.write((uint8_t)(address));

        for (int x=0; x<size; x++) {
            Wire.write(*(buffer+x));
        }
        
        Wire.endTransmission();
    }
}
