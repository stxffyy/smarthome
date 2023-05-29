#include "WebSH.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>

TrackduinoCommunicator::TrackduinoCommunicator() {
  _serial = &Serial;
}

void TrackduinoCommunicator::begin() {
   _serial->begin(_bauds);
}

void TrackduinoCommunicator::send() {
  _sent_data = "[" + _sent_data.substring(0, _sent_data.length() - 1) + "]"; 
  if (_serial->available() == 0) {
    _serial->println(_sent_data);
    _sent_data = "";
  }
}

void TrackduinoCommunicator::send(String data) {
  _sent_data = data; 
  if (_serial->available() == 0) {
    _serial->println(_sent_data);
    _sent_data = "";
  }
}

void TrackduinoCommunicator::receive() {
  if (_serial->available() > 0) {
    _received_data = _serial->readString();
  }
}

String TrackduinoCommunicator::receiveAndGet() {
  if (_serial->available() > 0) {
    _received_data = _serial->readString();
  }
  return _received_data;
}

WebCommunicator::WebCommunicator() {
  _ip = WiFi.localIP().toString();
}

void WebCommunicator::connectWifi(String ssid, String password) {
  _ssid = ssid;
  _password = password;
  uint32_t timer;
  uint8_t WiFi_status;
   
  WiFi.begin(_ssid, _password);
  while (WiFi_status != WL_CONNECTED) {
    if (millis() - timer >= 1000) {
      timer = millis();
      WiFi_status = WiFi.status();
    }
    yield(); 
  }
}

void WebCommunicator::setupSensor(DeviceType type, int port) {
  _init_data += "{\"type\": \"" + String(type) + "\", \"port\": \"" + String(port) + "\"}, ";
}

void WebCommunicator::initializeSensors(String user) {
  String data = _init_data;
  _user = user;
  if ((_WiFiMulti.run() == WL_CONNECTED)) {
        WiFiClient client;
        HTTPClient http;

        if (data.substring(data.length() - 2, data.length() - 1) == "\n") {
          data = data.substring(0, data.length() - 1);  
        }

        String url_register = _url_server + "en/init_sensors/";
        if (http.begin(client, url_register)) {
            http.addHeader("Content-Type", "application/json");
 
            String postData = "{\"ip\": \"" + _ip + "\", \"user\": \"" + _user + "\", \"init\": [" + data.substring(0, data.length() - 2) + "]}";

            int httpCode = http.POST(postData);
            if (httpCode > 0) {
                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
                    String payload = http.getString();
                    if(payload != "") {
                        _response = payload;
                    }
                }
            }
            http.end();
        }
    }    
}

void WebCommunicator::sendData(String data) {
  if ((_WiFiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;

    if (data.substring(data.length() - 2, data.length() - 1) == "\n") {
      data = data.substring(0, data.length() - 1);  
    }

    String url_sender = _url_server + "receive_data/";
    if (http.begin(client, url_sender)) {
      http.addHeader("Content-Type", "application/json");
       
      String postData = "{\"ip\": \"" + _ip + "\", \"user\": \"" + _user + "\", \"data\": " + data + "}";

      int httpCode = http.POST(postData);
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          if(payload != "") {
            _response = payload;
          }
        }
      }
      http.end();
    }
  }
}

String WebCommunicator::receiveData() {
  if ((_WiFiMulti.run() == WL_CONNECTED)) {    
    WiFiClient client;
    HTTPClient http;

    String url_sender = _url_server + "send_data/";
    if (http.begin(client, url_sender)) {
      http.addHeader("Content-Type", "application/json");
          
      String postData = "{\"user\": \"" + _user + "\"}";

      int httpCode = http.POST(postData);
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          if(payload != "") {
            _response = payload;
          }
        }
      }
      http.end();
    }
  }
  return _response;    
}
