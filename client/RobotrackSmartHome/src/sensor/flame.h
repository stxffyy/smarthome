#ifndef ROBOTRACK_SMARTHOME_SENSOR_FLAME_H
#define ROBOTRACK_SMARTHOME_SENSOR_FLAME_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorFlame : internal::model::AnalogSensor {
public:
  SensorFlame(uint8_t SensorId, char SensorName[17] = "Distance",
              SensorPort sensorPort)
      : internal::model::AnalogSensor(SensorId, SensorName, SensorType_SENSOR_TYPE_FLAME,
                                      sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_FLAME_H
