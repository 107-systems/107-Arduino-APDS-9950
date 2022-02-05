/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-APDS-9950/graphs/contributors.
 */

#ifndef _107_ARDUINO_APDS_9950_H_
#define _107_ARDUINO_APDS_9950_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "APDS-9950/APDS-9950_Io.h"
#include "Arduino.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoAPDS_9950
{

public:

  ArduinoAPDS_9950(APDS_9950::I2cWriteFunc write,
                 APDS_9950::I2cReadFunc read,
 //                APDS_9950::DelayFunc delay,
                 uint8_t const i2c_slave_addr);

  bool begin(bool const use_extended);
  float get_lux();

  APDS_9950::Error error();

private:

  APDS_9950::Error _error;
  APDS_9950::APDS_9950_Io _io;

};

#endif /* _107_ARDUINO_APDS_9950_H_ */
