#ifndef _AM2320_H
#define _AM2320_H

#define AM2320_SENSOR_VERSION 1 ///< the sensor version
#define AM2320_CMD_READREG    0x03 ///< read register command
#define AM2320_REG_TEMP_H     0x02 ///< temp register address
#define AM2320_REG_HUM_H      0x00 ///< humidity register address

#include <Arduino_Sensor.h>
#include <Wire.h>

/**************************************************************************/
/*! 
    @brief  Class that stores state and functions for interacting with AM2320 Temperature & Humidity Unified Sensor
*/
/**************************************************************************/
class AM2320 {
public:
  AM2320(TwoWire *theI2C = &Wire, int32_t tempSensorId=-1, int32_t humiditySensorId=-1);
  bool begin();

  float readTemperature();
  float readHumidity();
  uint16_t readRegister16(uint8_t reg);
  uint16_t crc16(uint8_t *buffer, uint8_t nbytes);

  /**************************************************************************/
  /*! 
      @brief  temperature sensor class
  */
  /**************************************************************************/
  class Temperature : public Arduino_Sensor {
  public:
    Temperature(AM2320* parent, int32_t id);
    bool getEvent(sensors_event_t* event);
    void getSensor(sensor_t* sensor);

  private:
    AM2320* _parent; ///< the parent sensor object
    int32_t _id; ///< the sensor id
  };

  /**************************************************************************/
  /*! 
      @brief  humidity sensor class
  */
  /**************************************************************************/
  class Humidity : public Arduino_Sensor {
  public:
    Humidity(AM2320* parent, int32_t id);
    bool getEvent(sensors_event_t* event);
    void getSensor(sensor_t* sensor);

  private:
     AM2320* _parent; ///< the parent sensor object
    int32_t _id; ///< the sensor id

  };

  /**************************************************************************/
  /*! 
      @brief  get the temperature sensor object belonging to this class
      @return the temperature sensor object
  */
  /**************************************************************************/
  Temperature temperature() {
    return _temp;
  }

  /**************************************************************************/
  /*! 
      @brief  get the humidity sensor object belonging to this class
      @return the humidity sensor object
  */
  /**************************************************************************/
  Humidity humidity() {
    return _humidity;
  }

private:
  Temperature _temp; ///< the temperature sensor object
  Humidity _humidity; ///< the humidity sensor object
  TwoWire *_i2c; ///< the TwoWire object used for I2C connumication
  uint8_t _i2caddr; ///< the i2c address the device can be found on

  void setName(sensor_t* sensor);
  void setMinDelay(sensor_t* sensor);
};

#endif
