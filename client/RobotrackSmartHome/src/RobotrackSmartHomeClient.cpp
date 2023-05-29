#include "RobotrackSmartHomeClient.h"

#include <Arduino.h>

#include "internal/connector/trackduino.h"

#include "internal/model/sensor.h"

#include "internal/model/executor.h"

namespace robotrack {
namespace smarthome {

SmartHomeClient::SmartHomeClient() {
  this->_sensors.setStorage(this->_sensor_array);
}

SmartHomeClient::begin(Print &serial) {
  serial.begin(internal::connector::BAUD_RATE);
}


SmartHomeClient::registerSensor(internal::model::SmartHomeSensorInfo sensor) {
  this->_sensors.push_back(sensor);
}


SmartHomeClient::sendSensorInfo(internal::model::SmartHomeSensorInfo sensor){
  switch(sensor.getSensorType){
    case 1:
      serial.print(irWhite(matchSensorPortToInputPort(sensor.getSensorPort()), 700));
      break;
    case 2:
      serial.print(buttonRead(matchSensorPortToInputPort(sensor.getSensorPort())));
      break;
    case 3:
      serial.print(mic(matchSensorPortToInputPort(sensor.getSensorPort())));
      break;
    case 4:
      serial.print(distanceCM(matchSensorPortToInputPort(sensor.getSensorPort())));
      break;
    case 5:
      serial.print(tilt(matchSensorPortToInputPort(sensor.getSensorPort())));
      break;
    case 6:
      serial.print(flame(matchSensorPortToInputPort(sensor.getSensorPort())));
      break;
    case 7:
      sensor.send(Serial);
      break;
  }
}

SmartHomeClient::getCommands(){
  String req = TrackduinoConnector::receiveAndGet();


}

SmartHomeClient::registerExecutor(internal::model::SmartHomeExecutorInfo executor){
  this->_executors.push_back(executor);
}
} // namespace smarthome
} // namespace robotrack
