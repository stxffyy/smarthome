#ifndef ROBOTRACK_SMARTHOME_SENSOR_MAGNETIC_FIELD_H
#define ROBOTRACK_SMARTHOME_SENSOR_MAGNETIC_FIELD_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorMagneticField : internal::model::AnalogSensor {
public:
  SensorMagneticField(uint8_t SensorId, char SensorName[17] = "Magnetic Field",
                      SensorPort sensorPort)
      : internal::model::AnalogSensor(
            SensorId, SensorName, SensorType_SENSOR_TYPE_MAGNETIC_FIELD, sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_MAGNETIC_FIELD_H
