#pragma once
#include "pb.h"

#include "executor.nanopb.h"


namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

class SmartHomeExecutorInfo {
public:
  SmartHomeExecutorInfo(uint32_t executorId,char executorName[17], ExecutorType executorType,
                       ExecutorPort executorPort, ExecutorCommandType commandType);

  ExecutorInfo getExecutorInfo();

  void setExecutorInfo(uint32_t executorId, char executorName[17]);

  ExecutorType getExecutorType();

  void setExecutorType(ExecutorType executorType);

  ExecutorPort getExecutorPort();
  void setExecutorPort(ExecutorPort executorPort);

  ExecutorCommandType getExecutorCommandType();

  void setExecutorCommandType(ExecutorCommandType commandType);

  bool send(pb_ostream_s *stream);

private:
  ExecutorInfo _executorInfo;
};

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack

// ROBOTRACK_SMARTHOME_MODEL_SENSOR_INFO_H
