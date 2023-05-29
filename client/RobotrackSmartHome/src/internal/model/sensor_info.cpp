#include "sensor_info.h"

#include "pb_encode.h"

#include "sensor.nanopb.h"


namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

SmartHomeSensorInfo::SmartHomeSensorInfo(uint32_t sensorId,
                                         char sensorName[17],
                                         SensorType sensorType,
                                         SensorMode sensorMode,
                                         SensorPort sensorPort) {
  this->setSensorInfo(sensorId, sensorName);
  this->setSensorType(sensorType);
  this->setSensorMode(sensorMode);
  this->setSensorPort(sensorPort);
}

SensorInfo SmartHomeSensorInfo::getSensorInfo() { return this->_sensorInfo; }

void SmartHomeSensorInfo::setSensorInfo(SensorId, SensorName){
  this->_sensorInfo.info = {SensorId, SensorName};
}

SensorType SmartHomeSensorInfo::getSensorType() {
  return this->_sensorInfo.type;
}

void SmartHomeSensorInfo::setSensorType(SensorType sensorType) {
  this->_sensorInfo.type = sensorType;
}

SensorMode SmartHomeSensorInfo::getSensorMode() {
  return this->_sensorInfo.mode;
}

void SmartHomeSensorInfo::setSensorMode(SensorMode sensorMode) {
  this->_sensorInfo.mode = sensorMode;
}

SensorPort SmartHomeSensorInfo::getSensorPort() {
  return this->_sensorInfo.port;
}

void SmartHomeSensorInfo::setSensorPort(SensorPort sensorPort) {
  this->_sensorInfo.port = sensorPort;
}

bool SmartHomeSensorInfo::send(pb_ostream_s *stream) {
  return pb_encode(stream, SensorInfo_fields, &(this->_sensorInfo));
}

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack
