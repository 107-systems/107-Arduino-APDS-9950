/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-APDS-9950/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "107-Arduino-APDS-9950.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace APDS_9950;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoAPDS_9950::ArduinoAPDS_9950(APDS_9950::I2cWriteFunc write,
                               APDS_9950::I2cReadFunc read,
 //                              APDS_9950::DelayFunc delay,
                               uint8_t const i2c_slave_addr)
: _error{APDS_9950::Error::None}
, _io{write, read, i2c_slave_addr}
{
}


/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

bool ArduinoAPDS_9950::begin(bool const use_extended)
{
  /* Check the CHIP ID if it matches the expected value.
   */
  if (_io.read(APDS_9950::Register::APDS_9950_ReadCommandRegister) != APDS_9950::ID_EXPECTED_ID) {
    _error = APDS_9950::Error::ChipId;
    return false;
  }

  if(use_extended == true) _io.write(APDS_9950::Register::APDS_9950_WriteCommandExtendedRange);
  else _io.write(APDS_9950::Register::APDS_9950_WriteCommandStandardRange);

  return true;
}


float ArduinoAPDS_9950::get_lux()
{
  float r=0, light_level=0;

  return light_level;
}

APDS_9950::Error ArduinoAPDS_9950::error()
{
  return _error;
}
