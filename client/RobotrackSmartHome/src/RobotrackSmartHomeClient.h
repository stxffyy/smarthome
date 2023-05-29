#ifndef ROBOTRACK_SMARTHOME_CLIENT_H
#define ROBOTRACK_SMARTHOME_CLIENT_H

#include <Arduino.h>

#include <Vector.h>

#include "internal/connector/trackduino.h"
#include "internal/connector/const.h"
#include "internal/model/sensor.h"
#include "internal/model/executor.h"

namespace robotrack {
namespace smarthome {

namespace {
const size_t MAX_SENSORS_COUNT = 8;

typedef Vector<internal::model::SmartHomeSensorInfo> Sensors;
} // namespace

class SmartHomeClient {
public:
  SmartHomeClient();

  void begin(Print &serial);

  void registerSensor(internal::model::SmartHomeSensorInfo sensor);
  
  void registerExecutor(internal::model::SmartHomeExecutorInfo executor);

private:
  internal::model::SmartHomeSensorInfo _sensor_array[MAX_SENSORS_COUNT];
  Sensors _sensors;
};

} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_CLIENT_H
