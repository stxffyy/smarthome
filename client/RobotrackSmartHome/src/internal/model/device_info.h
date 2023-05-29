#ifndef ROBOTRACK_SMARTHOME_MODEL_DEVICE_INFO_H
#define ROBOTRACK_SMARTHOME_MODEL_DEVICE_INFO_H

#include "Arduino.h"

#include "pb.h"


namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

class SmartHomeDeviceInfo {
public:
  SmartHomeDeviceInfo(uint32_t id, char *name);

  DeviceInfo getDeviceInfo();

  uint32_t getId();
  void setId(uint32_t id);

  char *getName();
  void setName(char *name);

  bool send(pb_ostream_s *stream);

private:
  DeviceInfo _deviceInfo = DeviceInfo DeviceInfo_init_default;
};

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack

#endif // ROBOTRACK_SMARTHOME_MODEL_DEVICE_INFO_H
