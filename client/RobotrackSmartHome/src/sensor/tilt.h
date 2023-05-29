#ifndef ROBOTRACK_SMARTHOME_SENSOR_TILT_H
#define ROBOTRACK_SMARTHOME_SENSOR_TILT_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorTilt : internal::model::AnalogSensor {
public:
  SensorTilt(uint8_t SensorId, char SensorName[17] = "Tilt",
             SensorPort sensorPort)
      : internal::model::AnalogSensor(SensorId, SensorName, SensorType_SENSOR_TYPE_IR,
                                      sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_TILT_H
