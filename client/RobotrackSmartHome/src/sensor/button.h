#ifndef ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H
#define ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorButton : internal::model::DigitalSensor {
public:
  SensorButton(uint8_t SensorId, char SensorName[17] = "Button",
               SensorPort sensorPort)
      : internal::model::DigitalSensor(
            SensorId, SensorName, SensorType_SENSOR_TYPE_BUTTON, sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H
