#ifndef DHT_U_H
#define DHT_U_H

#include <Arduino_Sensor.h>
#include <DHT.h>

#define DHT_SENSOR_VERSION 1 /**< Sensor Version */

/*!
 *  @brief  Class that stores state and functions for interacting with
 * DHT_Unified.
 */
class DHT_Unified {
public:
  DHT_Unified(uint8_t pin, uint8_t type, uint8_t count = 6,
              int32_t tempSensorId = -1, int32_t humiditySensorId = -1);
  void begin();

  /*!
   *  @brief  Class that stores state and functions about Temperature
   */
  class Temperature : public Arduino_Sensor {
  public:
    Temperature(DHT_Unified *parent, int32_t id);
    bool getEvent(sensors_event_t *event);
    void getSensor(sensor_t *sensor);

  private:
    DHT_Unified *_parent;
    int32_t _id;
  };

  /*!
   *  @brief  Class that stores state and functions about Humidity
   */
  class Humidity : public Arduino_Sensor {
  public:
    Humidity(DHT_Unified *parent, int32_t id);
    bool getEvent(sensors_event_t *event);
    void getSensor(sensor_t *sensor);

  private:
    DHT_Unified *_parent;
    int32_t _id;
  };

	/*!
   *  @brief  Returns temperature stored in _temp
   *  @return Temperature value
   */
  Temperature temperature() { return _temp; }

	/*!
   *  @brief  Returns humidity stored in _humidity
   *  @return Humidity value
   */
  Humidity humidity() { return _humidity; }

private:
  DHT _dht;
  uint8_t _type;
  Temperature _temp;
  Humidity _humidity;

  void setName(sensor_t *sensor);
  void setMinDelay(sensor_t *sensor);
};

#endif
