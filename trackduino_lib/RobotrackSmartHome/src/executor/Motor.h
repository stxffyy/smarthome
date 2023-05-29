#ifndef ROBOTRACK_SMARTHOME_EXECUTOR_MOTOR_H
#define ROBOTRACK_SMARTHOME_EXECUTOR_MOTOR_H

#include "internal/model/executor.h"

namespace robotrack {
namespace smarthome {
namespace sensor {

class SensorLED : internal::model::Executor {
public:
  ExecutorMotor(uint8_t executorId, char executorName[17] = "Motor",
               ExecutorPort executorPort)
      : internal::model::Executor(
            executorID, executorName, ExecutorType_EXECUTOR_TYPE_DC_MOTOR, executorPort, ExecutorCommandType_EXECUTOR_SET_VALUE) {}
};

} // namespace sensor
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_SENSOR_BUTTON_H
