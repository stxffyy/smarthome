/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_SENSOR_NANOPB_H_INCLUDED
#define PB_SENSOR_NANOPB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _SensorType {
    SENSOR_TYPE_UNSPECIFIED = 0,
    SENSOR_TYPE_IR = 1,
    SENSOR_TYPE_BUTTON = 2,
    SENSOR_TYPE_SOUND = 3,
    SENSOR_TYPE_DISTANCE = 4,
    SENSOR_TYPE_TILT = 5,
    SENSOR_TYPE_FLAME = 6,
    SENSOR_TYPE_MAGNETIC_FIELD = 7
} SensorType;

typedef enum _SensorMode {
    SENSOR_MODE_UNSPECIFIED = 0,
    SENSOR_MODE_DIGITAL = 1,
    SENSOR_MODE_ANALOG = 2
} SensorMode;

typedef enum _SensorPort {
    SENSOR_PORT_UNSPECIFIED = 0,
    SENSOR_PORT_IN1 = 1,
    SENSOR_PORT_IN2 = 2,
    SENSOR_PORT_IN3 = 3,
    SENSOR_PORT_IN4 = 4,
    SENSOR_PORT_IN5 = 5,
    SENSOR_PORT_IN6 = 6,
    SENSOR_PORT_IN7 = 7,
    SENSOR_PORT_IN8 = 8
} SensorPort;

typedef enum _SensorDigitalValue {
    SENSOR_DIGITAL_VALUE_UNSPECIFIED = 0,
    SENSOR_DIGITAL_VALUE_LOW = 1,
    SENSOR_DIGITAL_VALUE_HIGH = 2
} SensorDigitalValue;

/* Struct definitions */
typedef struct _Sensor {
    uint8_t id;
    SensorType type;
    SensorMode mode;
    char name[17];
    SensorPort port;
} Sensor;

typedef struct _SensorValue {
    pb_size_t which_value;
    union {
        uint16_t analog;
        SensorDigitalValue digital;
    } value;
} SensorValue;

typedef struct _SensorData {
    uint8_t id;
    bool has_value;
    SensorValue value;
} SensorData;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _SensorType_MIN SENSOR_TYPE_UNSPECIFIED
#define _SensorType_MAX SENSOR_TYPE_MAGNETIC_FIELD
#define _SensorType_ARRAYSIZE ((SensorType)(SENSOR_TYPE_MAGNETIC_FIELD+1))
#define SensorType_SENSOR_TYPE_UNSPECIFIED SENSOR_TYPE_UNSPECIFIED
#define SensorType_SENSOR_TYPE_IR SENSOR_TYPE_IR
#define SensorType_SENSOR_TYPE_BUTTON SENSOR_TYPE_BUTTON
#define SensorType_SENSOR_TYPE_SOUND SENSOR_TYPE_SOUND
#define SensorType_SENSOR_TYPE_DISTANCE SENSOR_TYPE_DISTANCE
#define SensorType_SENSOR_TYPE_TILT SENSOR_TYPE_TILT
#define SensorType_SENSOR_TYPE_FLAME SENSOR_TYPE_FLAME
#define SensorType_SENSOR_TYPE_MAGNETIC_FIELD SENSOR_TYPE_MAGNETIC_FIELD

#define _SensorMode_MIN SENSOR_MODE_UNSPECIFIED
#define _SensorMode_MAX SENSOR_MODE_ANALOG
#define _SensorMode_ARRAYSIZE ((SensorMode)(SENSOR_MODE_ANALOG+1))
#define SensorMode_SENSOR_MODE_UNSPECIFIED SENSOR_MODE_UNSPECIFIED
#define SensorMode_SENSOR_MODE_DIGITAL SENSOR_MODE_DIGITAL
#define SensorMode_SENSOR_MODE_ANALOG SENSOR_MODE_ANALOG

#define _SensorPort_MIN SENSOR_PORT_UNSPECIFIED
#define _SensorPort_MAX SENSOR_PORT_IN8
#define _SensorPort_ARRAYSIZE ((SensorPort)(SENSOR_PORT_IN8+1))
#define SensorPort_SENSOR_PORT_UNSPECIFIED SENSOR_PORT_UNSPECIFIED
#define SensorPort_SENSOR_PORT_IN1 SENSOR_PORT_IN1
#define SensorPort_SENSOR_PORT_IN2 SENSOR_PORT_IN2
#define SensorPort_SENSOR_PORT_IN3 SENSOR_PORT_IN3
#define SensorPort_SENSOR_PORT_IN4 SENSOR_PORT_IN4
#define SensorPort_SENSOR_PORT_IN5 SENSOR_PORT_IN5
#define SensorPort_SENSOR_PORT_IN6 SENSOR_PORT_IN6
#define SensorPort_SENSOR_PORT_IN7 SENSOR_PORT_IN7
#define SensorPort_SENSOR_PORT_IN8 SENSOR_PORT_IN8

#define _SensorDigitalValue_MIN SENSOR_DIGITAL_VALUE_UNSPECIFIED
#define _SensorDigitalValue_MAX SENSOR_DIGITAL_VALUE_HIGH
#define _SensorDigitalValue_ARRAYSIZE ((SensorDigitalValue)(SENSOR_DIGITAL_VALUE_HIGH+1))
#define SensorDigitalValue_SENSOR_DIGITAL_VALUE_UNSPECIFIED SENSOR_DIGITAL_VALUE_UNSPECIFIED
#define SensorDigitalValue_SENSOR_DIGITAL_VALUE_LOW SENSOR_DIGITAL_VALUE_LOW
#define SensorDigitalValue_SENSOR_DIGITAL_VALUE_HIGH SENSOR_DIGITAL_VALUE_HIGH

#define Sensor_type_ENUMTYPE SensorType
#define Sensor_mode_ENUMTYPE SensorMode
#define Sensor_port_ENUMTYPE SensorPort


#define SensorValue_value_digital_ENUMTYPE SensorDigitalValue


/* Initializer values for message structs */
#define Sensor_init_default                      {0, _SensorType_MIN, _SensorMode_MIN, "", _SensorPort_MIN}
#define SensorData_init_default                  {0, false, SensorValue_init_default}
#define SensorValue_init_default                 {0, {0}}
#define Sensor_init_zero                         {0, _SensorType_MIN, _SensorMode_MIN, "", _SensorPort_MIN}
#define SensorData_init_zero                     {0, false, SensorValue_init_zero}
#define SensorValue_init_zero                    {0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define Sensor_id_tag                            1
#define Sensor_type_tag                          2
#define Sensor_mode_tag                          3
#define Sensor_name_tag                          4
#define Sensor_port_tag                          5
#define SensorValue_analog_tag                   1
#define SensorValue_digital_tag                  2
#define SensorData_id_tag                        1
#define SensorData_value_tag                     2

/* Struct field encoding specification for nanopb */
#define Sensor_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   id,                1) \
X(a, STATIC,   SINGULAR, UENUM,    type,              2) \
X(a, STATIC,   SINGULAR, UENUM,    mode,              3) \
X(a, STATIC,   SINGULAR, STRING,   name,              4) \
X(a, STATIC,   SINGULAR, UENUM,    port,              5)
#define Sensor_CALLBACK NULL
#define Sensor_DEFAULT NULL

#define SensorData_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   id,                1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  value,             2)
#define SensorData_CALLBACK NULL
#define SensorData_DEFAULT NULL
#define SensorData_value_MSGTYPE SensorValue

#define SensorValue_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    UINT32,   (value,analog,value.analog),   1) \
X(a, STATIC,   ONEOF,    UENUM,    (value,digital,value.digital),   2)
#define SensorValue_CALLBACK NULL
#define SensorValue_DEFAULT NULL

extern const pb_msgdesc_t Sensor_msg;
extern const pb_msgdesc_t SensorData_msg;
extern const pb_msgdesc_t SensorValue_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Sensor_fields &Sensor_msg
#define SensorData_fields &SensorData_msg
#define SensorValue_fields &SensorValue_msg

/* Maximum encoded size of messages (where known) */
#define SensorData_size                          9
#define SensorValue_size                         4
#define Sensor_size                              27

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
