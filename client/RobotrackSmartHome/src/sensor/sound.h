#ifndef ROBOTRACK_SMARTHOME_SENSOR_SOUND_H
#define ROBOTRACK_SMARTHOME_SENSOR_SOUND_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorSound : internal::model::AnalogSensor {
public:
  SensorSound(uint8_t SensorId, char SensorName[17] = "Sound",
              SensorPort sensorPort)
      : internal::model::AnalogSensor(SensorId, SensorName, SensorType_SENSOR_TYPE_SOUND,
                                      sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_SOUND_H
