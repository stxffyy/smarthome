#ifndef ROBOTRACK_SMARTHOME_MODEL_EXECUTOR_H
#define ROBOTRACK_SMARTHOME_MODEL_EXECUTOR_H

#include "Arduino.h"

#include "executor_info.h"

namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

typedef enum {
  LED = ExecutorType_EXECUTOR_TYPE_LED,
  LEDPWM = ExecutorType_EXECUTOR_TYPE_LEDPWM,
  MOTOR = ExecutorType_EXECUTOR_TYPE_MOTOR,
  SERVO = ExecutorType_EXECUTOR_TYPE_SERVO,
  SMALLSERVO = ExecutorType_EXECUTOR_TYPE_SMALLSERVO, 
  ZOOMER = ExecutorType_EXECUTOR_TYPE_ZOOMER
} SmartHomeExecutorType;



class Executor : SmartHomeExecutorInfo {
public:
  Executor(uint8_t ExecutorId, char ExecutorName[17], ExecutorType executorType,
               ExecutorPort executorPort)
      : SmartHomeExecutorInfo(executorId, executorName, sensorType,
                            executorPort, ExecutorCommandType_EXECUTOR_TYPE_ON) {}
};

uint8_t matchExecutorPortToOutputPort(ExecutorPort executorPort) {
  switch (executorPort) {
  case ExecutorPort_EXECUTOR_PORT_OUT1:
    return OUT1;
  case ExecutorPort_EXECUTOR_PORT_OUT2:
    return OUT2;
  case ExecutorPort_EXECUTOR_PORT_OUT3:
    return OUT3;
  case ExecutorPort_EXECUTOR_PORT_OUT4:
    return OUT4;
  case ExecutorPort_EXECUTOR_PORT_OUT5:
    return OUT5;
  case ExecutorPort_EXECUTOR_PORT_OUT6:
    return OUT6;
  case ExecutorPort_EXECUTOR_PORT_OUT7:
    return OUT7;
  case ExecutorPort_EXECUTOR_PORT_OUT8:
    return OUT8;
  default:
    return 0;
  }
}

SensorPort matchOutputPortToExecutorPort(uint8_t outputPort) {
  switch (outputPort) {
  case OUT1:
    return ExecutorPort_EXECUTOR_PORT_OUT1;
  case OUT2:
    return ExecutorPort_EXECUTOR_PORT_OUT2;
  case OUT3:
    return ExecutorPort_EXECUTOR_PORT_OUT3;
  case OUT4:
    return ExecutorPort_EXECUTOR_PORT_OUT4;
  case OUT5:
    return ExecutorPort_EXECUTOR_PORT_OUT5;
  case OUT6:
    return ExecutorPort_EXECUTOR_PORT_OUT6;
  case OUT7:
    return ExecutorPort_EXECUTOR_PORT_OUT7;
  case OUT8:
    return ExecutorPort_EXECUTOR_PORT_OUT8;
  default:
    return ExecutorPort_EXECUTOR_PORT_UNSPECIFIED;
  }
}

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_MODEL_ANALOG_SENSOR_H
