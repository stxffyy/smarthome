#ifndef ROBOTRACK_SMARTHOME_MODEL_ANALOG_SENSOR_H
#define ROBOTRACK_SMARTHOME_MODEL_ANALOG_SENSOR_H

#include "Arduino.h"

#include "sensor_info.h"

namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

typedef enum {
  IR = SensorType_SENSOR_TYPE_IR,
  BUTTON = SensorType_SENSOR_TYPE_BUTTON,
  SOUND = SensorType_SENSOR_TYPE_SOUND,
  DISTANCE = SensorType_SENSOR_TYPE_DISTANCE,
  TILT = SensorType_SENSOR_TYPE_TILT, 
  FLAME = SensorType_SENSOR_TYPE_FLAME,
  MAGNETIC_FIELD = SensorType_SENSOR_TYPE_MAGNETIC_FIELD
} SmartHomeSensorType;

typedef enum {
  ANALOG = SensorMode_SENSOR_MODE_ANALOG,
  DIGITAL = SensorMode_SENSOR_MODE_DIGITAL
} SmartHomeSensorMode;

class AnalogSensor : SmartHomeSensorInfo {
public:
  AnalogSensor(uint8_t SensorId, char SensorName[17], SensorType sensorType,
               SensorPort sensorPort)
      : SmartHomeSensorInfo(SensorId, SensorName, sensorType,
                            SensorMode_SENSOR_MODE_ANALOG, sensorPort) {}
};

class DigitalSensor : SmartHomeSensorInfo {
public:
  DigitalSensor(uint8_t SensorId, char SensorName[17], SensorType sensorType,
               SensorPort sensorPort)
      : SmartHomeSensorInfo(SensorId, SensorName, sensorType,
                            SensorMode_SENSOR_MODE_DIGITAL, sensorPort) {}
};

uint8_t matchSensorPortToInputPort(SensorPort sensorPort) {
  switch (sensorPort) {
  case SensorPort_SENSOR_PORT_IN1:
    return IN1;
  case SensorPort_SENSOR_PORT_IN2:
    return IN2;
  case SensorPort_SENSOR_PORT_IN3:
    return IN3;
  case SensorPort_SENSOR_PORT_IN4:
    return IN4;
  case SensorPort_SENSOR_PORT_IN5:
    return IN5;
  case SensorPort_SENSOR_PORT_IN6:
    return IN6;
  case SensorPort_SENSOR_PORT_IN7:
    return IN7;
  case SensorPort_SENSOR_PORT_IN8:
    return IN8;
  default:
    return 0;
  }
}

SensorPort matchInputPortToSensorPort(uint8_t inputPort) {
  switch (inputPort) {
  case IN1:
    return SensorPort_SENSOR_PORT_IN1;
  case IN2:
    return SensorPort_SENSOR_PORT_IN2;
  case IN3:
    return SensorPort_SENSOR_PORT_IN3;
  case IN4:
    return SensorPort_SENSOR_PORT_IN4;
  case IN5:
    return SensorPort_SENSOR_PORT_IN5;
  case IN6:
    return SensorPort_SENSOR_PORT_IN6;
  case IN7:
    return SensorPort_SENSOR_PORT_IN7;
  case IN8:
    return SensorPort_SENSOR_PORT_IN8;
  default:
    return SensorPort_SENSOR_PORT_UNSPECIFIED;
  }
}

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_MODEL_ANALOG_SENSOR_H
