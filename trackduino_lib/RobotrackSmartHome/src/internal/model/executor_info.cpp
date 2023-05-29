#include "executor_info.h"

#include "pb_encode.h"

#include "executor.nanopb.h"


namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

SmartHomeExecutorInfo::SmartHomeExecutorInfo(uint32_t executorId,
                                         char executorName[17],
                                         ExecutorType executorType,
                                         ExecutorPort executorPort,
                                         ExecutorCommandType commandType) {
  this->setExecutorInfo(executorId, executorName);
  this->setExecutorType(executorType);
  this->setExecutorPort(executorPort);
  this->setExecutorCommandType(commandType);
}

ExecutorInfo SmartHomeExecutorInfo::getExecutorInfo() { return this->_executorInfo; }

void SmartHomeExecutorInfo::setExecutorInfo(ExecutorId, ExecutorName){
  this->_executorInfo.info = {executorId, executorName};
}

ExecutorType SmartHomeExecutorInfo::getExecutorType() {
  return this->_executorInfo.type;
}

void SmartHomeExecutorInfo::setExecutorType(ExecutorType executorType) {
  this->_executorInfo.type = executorType;
}

ExecutorPort SmartHomeExecutorInfo::getExecutorPort() {
  return this->_executorInfo.port;
}

void SmartHomeExecutorInfo::setExecutorPort(ExecutorPort executorPort) {
  this->_executorInfo.port = executorPort;
}

ExecutorCommandType SmartHomeExecutorInfo::getExecutorCommandType() {
  return this->_executorInfo.commandType;
}

void SmartHomeExecutorInfo::setExecutorCommandType(ExecutorCommandType commandType) {
  this->_executorInfo.commandType = commandType;
}

bool SmartHomeExecutorInfo::send(pb_ostream_s *stream) {
  return pb_encode(stream, ExecutorInfo_fields, &(this->_executorInfo));
}

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack
