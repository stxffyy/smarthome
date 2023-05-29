#include "SensorsAndExecutorsSH.h"

WemosCommunicator::WemosCommunicator(int port) {
  _port = port;
  switch (_port) {
    case 1: //UART1
      _serial = &Serial1;
      break;
    case 2: //UART2
      _serial = &Serial2;
      break;
    case 3: //UART3
      _serial = &Serial3;
  }
}

void WemosCommunicator::begin() {
   _serial->begin(_bauds);
}

void WemosCommunicator::storeSensor(DeviceType type, int port, String value) {
  _sensors_t += type;
  _sensors_t += ", ";
  _sensors_p += port;
  _sensors_p += ", ";  
  
  String storedSensor;
  storedSensor += "{\"type\": \""; 
  storedSensor += type;
  storedSensor += "\", \"port\": \"";
  storedSensor += port;
  storedSensor += "\", \"value\": \"" ;
  storedSensor += "[{\"arg\": \"";
  storedSensor += type;
  storedSensor += "\", \"values\": [\"";
  storedSensor += value;
  storedSensor += "\"]}], ";
  _sent_data += storedSensor;
}

void WemosCommunicator::storeSensorWithArg(DeviceType type, int port, String value, String arg) {  
  String storedSensor;
  storedSensor += "{\"type\": \""; 
  storedSensor += type;
  storedSensor += "\", \"port\": \"";
  storedSensor += port;
  storedSensor += "\", \"value\": \"" ;
  storedSensor += "[{\"arg\": \"";
  storedSensor += arg;
  storedSensor += "\", \"values\": [\"";
  storedSensor += value;
  storedSensor += "\"]}], ";
  _sent_data += storedSensor;
}

void WemosCommunicator::autoStoreAllSensors() {
  _sensors_t = _sensors_t.substring(0, _sensors_t.length() - 3); //???
  char ch_t[_sensors_t.length() + 1]; 
  _sensors_t.toCharArray(ch_t, _sensors_t.length() + 1);
  
  _sensors_p = _sensors_p.substring(0, _sensors_p.length() - 3); //???
  char ch_p[_sensors_p.length() + 1]; 
  _sensors_p.toCharArray(ch_p, _sensors_p.length() + 1);
  
  char *ptr_t; char *ptr_p;
  DeviceType type_s; int port_s = 0;

  ptr_t = strtok(ch_t, ", ");
  ptr_p = strtok(ch_p, ", ");

  while (ptr_t != NULL || ptr_p != NULL) {
    type_s = static_cast<DeviceType>(atoi(ptr_t));
    port_s = atoi(ptr_p);

    for (int i = 0; i < 10; i++) {
      int s_g[9];
      int flag_g = 0;
      for (int j = 0; j < 9; j++) {
        if (groups[i][j] == type_s) {flag_g = 1;}
        else {s_g[j] = groups[i][j];};    
      }

      if (flag_g) {
        for (int j = 0; j < 9; j++) {
          if (groups[i][j] == -1) {break;}
          else {
            String val = "";
            String arg = String(type_s);
            switch (type_s) {
              case IR: {
                val = String(irAnalog(port_s)); 
                break; 
              }
              case IR_White: {
                val = String(irWhite(port_s, 511));
                break;
              }
              case IR_Black: {
                val = String(irBlack(port_s, 511));
                break;
              } 
              case Light: {
                val = String(cdsAnalog(port_s)); 
                break;
              }
              case Light_Light: {
                val = String(cdsLight(port_s, 511));
                break; 
              }
              case Light_Black: {
                val = String(cdsDark(port_s, 511));
                break;
              }
              case LightI2C: {
                break;
              }
              case Button: {
                val = String(int(buttonRead(port_s)));
                break;
              }
              case IR_RC: {
                String arg = "";
                int n_btn = 0;
                if (RC(UP_KEY)) {
                  arg = "UP";
                  val = "1";
                }
                if (RC(DOWN_KEY)) {
                  arg = "DOWN";
                  val = "1";
                }
                if (RC(LEFT_KEY)) {
                  arg = "LEFT";
                  val = "1";
                }
                if (RC(RIGHT_KEY)) {
                  arg = "RIGHT";
                  val = "1";
                }
                if (RC(UP_AND_LEFT_KEY)) {
                  arg = "UP_AND_LEFT";
                  val = "1";
                }
                if (RC(UP_AND_RIGHT_KEY)) {
                  arg = "UP_AND_RIGHT";
                  val = "1";
                }
                if (RC(DOWN_AND_RIGHT_KEY)) {
                  arg = "DOWN_AND_RIGHT";
                  val = "1";
                }
                if (RC(DOWN_AND_RIGHT_KEY)) {
                  arg = "DOWN_AND_RIGHT";
                  val = "1";
                }
                if (RC(F1_KEY)) {
                  arg = "F1";
                  val = "1";
                }
                if (RC(F2_KEY)) {
                  arg = "F2";
                  val = "1";
                }
                if (RC(F3_KEY)) {
                  arg = "F3";
                  val = "1";
                }
                if (RC(F4_KEY)) {
                  arg = "F4";
                  val = "1";
                }
                if (RC(F5_KEY)) {
                  arg = "F5";
                  val = "1";
                }
                if (RC(F6_KEY)) {
                  arg = "F6";
                  val = "1";
                }
                break;
              }
              case Touch_perc: {
                break;
              }
              case Touch_mm: {
                break;
              }
              case Touch_n: {
                break;
              }
              case Angle: {
                break;
              }
              case Tilt: {
                val = String(int(shock(port_s)));  
                break;
              }
              case Vibration:  {
                break;
              }
              case Magnetic_field: {
                break;
              }
              case Orientation_x_gyro: {
                val = String(readAccelAngle('x', RAW_GYRO));  
                break;
              }
              case Orientation_x_accel: {
                val = String(readAccelAngle('x', RAW_ACCEL));  
                break;
              }
              case Orientation_x_filtered: {
                val = String(readAccelAngle('x', FILTERED)); 
                break;
              }
              case Orientation_y_gyro: {
                val = String(readAccelAngle('y', RAW_GYRO)); 
                break;
              }
              case Orientation_y_accel: {
                val = String(readAccelAngle('y', RAW_ACCEL)); 
                break;
              }
              case Orientation_y_filtered: {
                val = String(readAccelAngle('y', FILTERED)); 
                break;
              }
              case Orientation_z_gyro: {
                val = String(readAccelAngle('z', RAW_GYRO)); 
                break;
              }
              case Orientation_z_accel: { 
                val = String(readAccelAngle('z', RAW_ACCEL)); 
                break;
              }
              case Orientation_z_filtered: {
                val = String(readAccelAngle('z', FILTERED)); 
                break;
              }
              case Distance: {
                val = String(distanceCM(port_s)); 
                break;
              }
              case DistanceI2C: { 
                break;
              }
              case Microphone: {
                val = String(micAnalog(port_s)); 
                break;
              }
              case Flame: {
                val = String(flame(port_s)); 
                break;
              }
              case Color: {
                val = String(getColor());
                break;
              }
              case RedI2C: {
                break;
              }
              case GreenI2C: {
                break;
              }
              case BlueI2C: {
                 break;
              }
              case GeneralI2C: {
                break;
              }
              case HueI2C: {
                break;
              }
              case SaturationI2C: {
                break;
              }
              case BrightnessI2C: {
                break;
              }
              case ColorI2C: {
                break;
              }
              case Day: {
                break;
              }
              case Month: {
                break;
              }
              case Year: {
                break;
              }
              case Hour: {
                break;
              }
              case Minute: {
                break;
              }
              case Second: {
                break;
              }
              case Soil_moisture: {
                break;
              }
              case Temperature: {
                break;
              }
              case Humidity: {
                break;
              }
              case Pressure_kPa: {
                break;
              }
              case Pressure_mm:  { 
                break;
              }
            }
            storeSensorWithArg(type_s, port_s, val, arg);
          }
        }
      }
      ptr_t = strtok(NULL, ", ");
      ptr_p = strtok(NULL, ", ");
    }
  }
}

void WemosCommunicator::send() {
  autoStoreAllSensors();
  _sent_data = "[";
  _sent_data += _sent_data.substring(0, _sent_data.length() - 2);
  _sent_data += "]"; 
  if (_serial->available() == 0) {
    _serial->println(_sent_data);
    _sent_data = "";
    _sensors_t = "";
    _sensors_p = "";
  }
}

void WemosCommunicator::send(String data) {
  _sent_data = data; 
  if (_serial->available() == 0) {
    _serial->println(_sent_data);
    _sent_data = "";
    _sensors_t = "";
    _sensors_p = "";
  }
}

void WemosCommunicator::receive() {
  if (_serial->available() > 0) {
    _received_data = _serial->readString();
  }
}

String WemosCommunicator::receiveAndGet() {
  if (_serial->available() > 0) {
    _received_data = _serial->readString();
  }
  return _received_data;
}

void WemosCommunicator::stringToInts(String s) {
  char ch[s.length() + 1]; 
  s.toCharArray(ch, 
    s.length() + 1);
  char *ptr;
  int index = 0;

  ptr = strtok(ch, ", ");

  while (ptr != NULL) {
    vals[index] = atoi(ptr);
    index++;
    ptr = strtok(NULL, ", ");
  }
}

String getStringValues(DeviceType type_l, int port_l, String str_l) {
  int i_p;
  int i_vs;
  int i_s;
  int i_e;
  String p1;
  p1 += "\"port\": \""; 
  p1 += port_l; 
  p1 += "\"";
  String p2;
  p2 += "\"port\":\""; 
  p2 += port_l; 
  p2 += "\"";
  i_p = str_l.indexOf(p1);
  if (i_p == -1) {
    i_p = str_l.indexOf(p2);
  }
  i_vs = str_l.indexOf("\"values\":", i_p);
  i_s = str_l.indexOf("[\"", i_vs);
  i_e = str_l.indexOf("]}", i_s);
  String r = str_l.substring(i_s + 1, i_e);
  r.replace("\"", "");
  return r;
}

String WemosCommunicator::loadExecutor(DeviceType type, int port) {
  String r = getStringValues(type, port, _received_data);
  switch (type) {
    case BIG_SM:
    case SMALL_SM:
    case Motor:
      return r;
    case Motor_stop:
    case Motor_stopHard:
      return "1";
    case LED:
    case LED_PWM: 
    case Buzzer:
    case Buzzer_timer:
      return r;
    case Buzzer_off:
      return "1";
    case Set_time:
    case Set_date:
    case Set_LED_TIME:
    case Set_LED_COLOR:
      return r;
  }
  return r;
}

void WemosCommunicator::autoLoadExecutor(DeviceType type, int port) {
  String r = getStringValues(type, port, _received_data);
//  For every case get value and for spec device(f.e. dispay) get spec value
  switch (type) {
    case BIG_SM:
    case SMALL_SM:
    case Motor: {
      startMotor(port, r.toInt());
      break; 
    }
    case Motor_stop: {
      if (r.toInt() == 1) {
        stopMotor(port);
      }
      break; 
    }
    case Motor_stopHard: {
      if (r.toInt() == 1) {
        stopMotorHard(port);
      }
      break;
    }
    case LED: {
      led(port, r.toInt());
      break; 
    }
    case LED_PWM: { 
      ledPWM(port, r.toInt()); 
      break;
    }
    case Buzzer: { 
      tone(port, r.toInt());
      break; 
    }
    case Buzzer_timer: { 
      stringToInts(r);
      tone(port, vals[0], vals[1]); 
      break;
    }
    case Buzzer_off: {
      if (r.toInt() == 1) {
        noTone(port);
      }
      break; 
    }
    case Display: {
      String arg = "";
//      for (JsonObject fig : val)
        stringToInts(r);
        if (arg == "clear") {
          fidfidmfo.clear();
        }
        if (arg == "line") {
          fidfidmfo.line(vals[0], vals[1], 
                        vals[2], vals[3], 
                        vals[4]);         
        } 
        if (arg == "rectangle") {
          fidfidmfo.rectangle(vals[0], vals[1], 
                             vals[2], vals[3], 
                             vals[4]);     
        }
        if (arg == "fill") {
          fidfidmfo.fill(vals[0], vals[1], 
                        vals[2], vals[3], 
                        vals[4]);
        }
        if (arg == "circle") {
          fidfidmfo.circle(vals[0], vals[1], 
                          vals[2], 
                          vals[3]);
        }
        if (arg == "brightness") {
          fidfidmfo.brightness(vals[0]);
        }
        if (arg == "text") {
          String text;
          char ch_r[r.length() + 1]; 
          r.toCharArray(ch_r, 
            r.length() + 1);
          char *ptr;
          int index = 0;

          ptr = strtok(ch_r, ", ");

          while (ptr != NULL) {
            index++;
            if (index == 5) {
              text = String(ptr);
            }
            ptr = strtok(NULL, ", ");
          }
          fidfidmfo.text(vals[0], vals[1],
                        vals[2], vals[3],
                        text);
         }
         break;
    }
    case MP3: {
      String arg = "";
//      for (JsonObject com : val)  
        stringToInts(r);
        if (arg == "track") {
          _mp3.SpecifyMusicPlay(vals[0]);
        }
        if (arg == "folder") {
          _mp3.SpecifyfolderPlay(vals[0], vals[1]);
        }
        if (arg == "pause") {
          _mp3.PlayPause();
        } 
        if (arg == "resume") {
          _mp3.PlayResume();
        }
        if (arg == "next") {
          _mp3.PlayNext();
        }
        if (arg == "previous") {
          _mp3.PlayPrevious();
        }
        if (arg == "loop") {
          _mp3.PlayLoop();
        }
        if (arg == "increase") {
          _mp3.IncreaseVolume();
        }   
        if (arg == "decrease") {
          _mp3.DecreaseVolume();
        }
        if (arg == "volume") {
          _mp3.SetVolume(vals[0]);
        } 
        break;
    }
    case Set_time: {
      break;
    }
    case Set_date: {
      break;
    }
    case Set_LED_TIME: {
      break;
    }
    case Set_LED_COLOR: {
      break;
    }
  }   
}
