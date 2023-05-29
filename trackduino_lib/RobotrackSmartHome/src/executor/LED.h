#ifndef ROBOTRACK_SMARTHOME_EXECUTOR_LED_H
#define ROBOTRACK_SMARTHOME_EXECUTOR_LED_H

#include "internal/model/executor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorLED : internal::model::Executor {
public:
  ExecutorLED(uint8_t executorId, char executorName[17] = "LED",
               ExecutorPort executorPort)
      : internal::model::Executor(
            executorID, executorName, ExecutorType_EXECUTOR_TYPE_LED, executorPort, ExecutorCommandType_EXECUTOR_TYPE_OFF) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H
