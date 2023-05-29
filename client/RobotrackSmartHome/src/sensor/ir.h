#ifndef ROBOTRACK_SMARTHOME_SENSOR_IR_H
#define ROBOTRACK_SMARTHOME_SENSOR_IR_H

#include "internal/model/sensor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorIRAnalog : internal::model::AnalogSensor {
public:
  SensorIRAnalog(uint8_t SensorId, char SensorName[17] = "IR_Analog",
                 SensorPort sensorPort)
      : internal::model::AnalogSensor(SensorId, SensorName, SensorType_SENSOR_TYPE_IR,
                                      sensorPort) {}
};

class SensorIRDigital : internal::model::DigitalSensor {
public:
  SensorIRDigital(uint8_t SensorId, char SensorName[17] = "IR_Digital",
                  SensorPort sensorPort)
      : internal::model::DigitalSensor(SensorId, SensorName, SensorType_SENSOR_TYPE_IR,
                                       sensorPort) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_IR_H
