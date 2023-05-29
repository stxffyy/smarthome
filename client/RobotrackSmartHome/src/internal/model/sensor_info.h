#pragma once

#include "pb.h"

#include "sensor.nanopb.h"


namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

class SmartHomeSensorInfo {
public:
  SmartHomeSensorInfo(uint32_t SensorId,char SensorName[17], SensorType sensorType,
                      SensorMode sensorMode, SensorPort sensorPort);

  SensorInfo getSensorInfo();

  void setSensorInfo(uint32_t SensorId, char SensorName[17]);

  SensorType getSensorType();

  void setSensorType(SensorType sensorType);

  SensorMode getSensorMode();
  void setSensorMode(SensorMode sensorMode);

  SensorPort getSensorPort();
  void setSensorPort(SensorPort sensorPort);

  bool send(pb_ostream_s *stream);

private:
  SensorInfo _sensorInfo;
};

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack

// ROBOTRACK_SMARTHOME_MODEL_SENSOR_INFO_H
