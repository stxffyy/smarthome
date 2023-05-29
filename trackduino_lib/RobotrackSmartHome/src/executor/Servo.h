#ifndef ROBOTRACK_SMARTHOME_EXECUTOR_SERVO_H
#define ROBOTRACK_SMARTHOME_EXECUTOR_SERVO_H

#include "internal/model/executor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorLED : internal::model::Executor {
public:
  ExecutorServo(uint8_t executorId, char executorName[17] = "Servo",
               ExecutorPort executorPort)
      : internal::model::Executor(
            executorId, executorName, ExecutorType_EXECUTOR_TYPE_SERVO, executorPort, ExecutorCommandType_EXECUTOR_SET_VALUE) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H
