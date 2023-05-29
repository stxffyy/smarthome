#pragma once

//#include <Arduino.h>
#include <accel_gyro.h>
#include <Display.h>
#include <MP3Player_KT403A.h> 

Display fidfidmfo = Display(UART1);

typedef enum {
//    DEFAULT_SENSOR = -1,
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

String getStringValues(DeviceType type_l, int port_l);

class WemosCommunicator {
  public:
    WemosCommunicator(int port);
    void begin();
    void storeSensor(DeviceType type, int port, String value);
    void storeSensorWithArg(DeviceType type, int port, String value, String arg);
    void autoStoreAllSensors();
    void send();
    void send(String data);
    void receive();
    String receiveAndGet();
    String loadExecutor(DeviceType type, int port);
    void autoLoadExecutor(DeviceType type, int port);
    void stringToInts(String s);
  private:
    int _port = 0;
    int _bauds = 9600;
    int _i = 0;
    String _sensors_t = "";
    String _sensors_p = "";
    String _sent_data = "";
    String _received_data = "";
    HardwareSerial *_serial;
//    Display _display1 = Display(UART1);  
//    display = Display(UART1); //????
    mp3player _mp3 = mp3player(UART1);
//    Display _display2;
    int vals[5] = {};
    int groups[10][9] = {{0, 1, 2, -1, -1, -1, -1, -1, -1}, 
      {3, 4, 5, -1, -1, -1, -1, -1, -1}, 
      {50, 50, 52, -1, -1, -1, -1, -1, -1},
      {31, 32, 33, 34, 35, 36, 37, 38, 39}, 
      {10, 11, 12, -1, -1, -1, -1, -1, -1}, 
      {58, 59, 60, -1, -1, -1, -1, -1, -1}, 
      {42, 43, 44, 45, 46, 47, 48, 49, -1},
      {61, 62, 63, 64, 65, 66, -1, -1, -1}, 
      {54, 55, 56, 57, -1, -1, -1, -1, -1}, 
      {28, 29, 30, -1, -1, -1, -1, -1, -1}};
    };
