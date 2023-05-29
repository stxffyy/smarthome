#pragma once
#include <Arduino.h>
#include <ESP8266WiFiMulti.h>

typedef enum {
//    DEFAULT_SENSOR = 0,
    // Light sensors
    IR, //ИК оптопара irAnalog(int port)
    IR_White, //ИК оптопара irWhite(int port, int threshold)
    IR_Black, //ИК оптопара irBlack(int port, int threshold)
    Light, //Датчик освещенности cdsAnalog(int port)
    Light_Light, //Датчик освещенности cdfLight(int port, int threshold)
    Light_Black, //Датчик освещенности cdsDark(int port, int threshold)
    LightI2C, //Датчик освещенности cdsAnalog(int port)

    //Direct interaction sensors
    Button, //Кнопка buttonRead(int port)
    IR_RC, //ИК ПДУ IRRC_setup(int port, int channel)...
    Touch_perc,
    Touch_mm,
    Touch_n,
    Angle,

    // Physical sensors
    Tilt, //Датчик наклона digitalRead(int port)
    Vibration, //Датчик удара(вибрации) shock(int port)
    Magnetic_field, //Датчик магнитного поля(геркон) digitalRead(int port)
    Orientation_x_gyro, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_x_accel, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_x_filtered, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_y_gyro, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_y_accel, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_y_filtered, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_z_gyro, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_z_accel, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)
    Orientation_z_filtered, //Датчик положения(гироскоп/акселерометр) readAccelAngle(char axis, int mode)

    // Special sensors
    Distance, //Датчик расстояния distanceCM(int port)
    DistanceI2C, 
    Microphone, //Микрофон аналоговый(датчик звука) micAnalog(int port)
    Flame, //Датчик огня flame(int port)

    // Color sensors
    Color, //Датчик цвета getColor(void)
    RedI2C,
    GreenI2C,
    BlueI2C,
    GeneralI2C,
    HueI2C,
    SaturationI2C,
    BrightnessI2C,
    ColorI2C,

    // Time sensors
    Day,
    Month,
    Year,
    Hour,
    Minute,
    Second,

    // Environmental sensors
    Soil_moisture,
    Temperature,
    Humidity,
    Pressure_kPa,
    Pressure_mm,

    // Motor executors
    BIG_SM, //Серводвигатель(малый) servo_port_PORTX.write(int angle)
    SMALL_SM, //Серводвигатель(большой) servo_port_PORTX.write(int angle);
    Motor, //Двигатель startMotor(int portM, speed),stopMotor(int portM),stopMotorHard(int portM)
    Motor_stop,
    Motor_stopHard,

    // Direct impact executors
    LED, //Модуль светодиода led(int port, bool state)
    LED_PWM, //Модуль светодиода ledPWM(int port, int PWM)
    Buzzer, //Динамик tone(int port, int freq)
    Buzzer_timer, //Динамик tone(int port, int freq, int time)
    Buzzer_off, //Динамик noTone(int port)
//    Piezo_Buzzer, //Пьезоизлучатель tone(int port, int freq)
//    Piezo_Buzzer_timer, //Пьезоизлучатель tone(int port, int freq, int time)
//    Piezo_BUZZER_off, //Пьезоизлучатель noTone(int port)
    Display, //Дисплей display.clear(), display.line(int x1, int y1, int x2, int y2, int color),...
    MP3, //Аудиотрек mp3.SpecifyMusicPlay(int track), mp3.SpecifyfolderPlay(int folder,int track),...
    Set_time,
    Set_date,
    Set_LED_TIME,
    Set_LED_COLOR,

    AutoFlag
} DeviceType;

class TrackduinoCommunicator {
  public:
    TrackduinoCommunicator();
    void begin();
    void send();
    void send(String data);
    void receive();
    String receiveAndGet();
  private:
    int _port;
    int _bauds = 9600;
    String _sent_data = "";
    String _received_data = "";
    HardwareSerial *_serial;
};

class WebCommunicator {
  public:
    WebCommunicator();
    void connectWifi(String ssid, String password);
    void setupSensor(DeviceType type, int port);
    void initializeSensors(String user);
    void sendData(String data);
    String receiveData();
  private:
    String _ssid = "";
    String _password = "";
    String _user = "";
    String _ip = "";
//    String _url_server = "http://192.168.43.76:8000/";
    String _url_server = "http://192.168.50.249:8000/";
    String _init_data = "";
    String _response = "";
    
    ESP8266WiFiMulti _WiFiMulti;
};
