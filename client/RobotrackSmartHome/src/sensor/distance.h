#ifndef ROBOTRACK_SMARTHOME_SENSOR_DISTANCE_H
#define ROBOTRACK_SMARTHOME_SENSOR_DISTANCE_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorDistance : internal::model::AnalogSensor {
public:
  SensorDistance(uint8_t SensorId, char SensorName[17] = "Distance",
                 SensorPort sensorPort)
      : internal::model::AnalogSensor(
            SensorId, SensorName, SensorType_SENSOR_TYPE_DISTANCE, sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_DISTANCE_H
