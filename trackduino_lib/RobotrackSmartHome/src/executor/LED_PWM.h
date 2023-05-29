#ifndef ROBOTRACK_SMARTHOME_EXECUTOR_LED_PWM_H
#define ROBOTRACK_SMARTHOME_EXECUTOR_LED_PWM_H

#include "internal/model/executor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorLED : internal::model::Executor {
public:
  ExecutorPWM(uint8_t executorId, char executorName[17] = "LED PWM",
               ExecutorPort executorPort)
      : internal::model::Executor(
            executorID, executorName, ExecutorType_EXECUTOR_TYPE_LED_PWM, executorPort, ExecutorCommandType_EXECUTOR_TYPE_SET_VALUE) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H
