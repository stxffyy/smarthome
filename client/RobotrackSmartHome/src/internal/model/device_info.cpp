#include "device_info.h"

#include "Arduino.h"

#include "pb.h"
#include "pb_encode.h"


namespace robotrack {
namespace smarthome {
namespace internal {
namespace model {

SmartHomeDeviceInfo::SmartHomeDeviceInfo(uint32_t id, char *name) {
  this->setId(id);
  this->setName(name);
}

DeviceInfo SmartHomeDeviceInfo::getDeviceInfo() { return this->_deviceInfo; }

uint32_t SmartHomeDeviceInfo::getId() { return this->_deviceInfo.id; }

void SmartHomeDeviceInfo::setId(uint32_t id) { this->_deviceInfo.id = id; }

char *SmartHomeDeviceInfo::getName() { return this->_deviceInfo.name; }

void SmartHomeDeviceInfo::setName(char *name) {
  strcpy(this->_deviceInfo.name, name);
}

bool SmartHomeDeviceInfo::send(pb_ostream_s *stream) {
  return pb_encode(stream, DeviceInfo_fields, &(this->_deviceInfo));
}

} // namespace model
} // namespace internal
} // namespace smarthome
} // namespace robotrack
