/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_CONNECTION_SERVICE_NANOPB_H_INCLUDED
#define PB_CONNECTION_SERVICE_NANOPB_H_INCLUDED
#include <pb.h>
#include "connection.nanopb.h"
#include "executor.nanopb.h"
#include "sensor.nanopb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _ConnectionRequest {
    bool has_usercreds;
    User_Creds usercreds;
} ConnectionRequest;

typedef struct _ConnectionResponce {
    bool has_key;
    Session_key key;
} ConnectionResponce;

typedef struct _DeviceData {
    bool has_key;
    Session_key key;
    pb_callback_t sensor;
    pb_callback_t executor;
} DeviceData;

typedef struct _ResultData {
    bool has_key;
    Session_key key;
    pb_callback_t responce;
} ResultData;

typedef struct _ReceiveCommandsRequest {
    bool has_key;
    Session_key key;
    pb_callback_t executors;
} ReceiveCommandsRequest;

typedef struct _ReceiveCommandsResponse {
    bool has_key;
    Session_key key;
    pb_callback_t command;
} ReceiveCommandsResponse;

typedef struct _VirtSensorData {
    bool has_key;
    Session_key key;
} VirtSensorData;

typedef struct _VirtSensorResponce {
    bool has_key;
    Session_key key;
    pb_callback_t sensors;
    pb_callback_t data;
} VirtSensorResponce;

typedef struct _SensorDataRequest {
    bool has_key;
    Session_key key;
    pb_callback_t sensor;
    pb_callback_t data;
} SensorDataRequest;

typedef struct _SensorDataResponce {
    bool has_key;
    Session_key key;
    pb_callback_t serverResponce;
} SensorDataResponce;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ConnectionRequest_init_default           {false, User_Creds_init_default}
#define ConnectionResponce_init_default          {false, Session_key_init_default}
#define DeviceData_init_default                  {false, Session_key_init_default, {{NULL}, NULL}, {{NULL}, NULL}}
#define ResultData_init_default                  {false, Session_key_init_default, {{NULL}, NULL}}
#define ReceiveCommandsRequest_init_default      {false, Session_key_init_default, {{NULL}, NULL}}
#define ReceiveCommandsResponse_init_default     {false, Session_key_init_default, {{NULL}, NULL}}
#define VirtSensorData_init_default              {false, Session_key_init_default}
#define VirtSensorResponce_init_default          {false, Session_key_init_default, {{NULL}, NULL}, {{NULL}, NULL}}
#define SensorDataRequest_init_default           {false, Session_key_init_default, {{NULL}, NULL}, {{NULL}, NULL}}
#define SensorDataResponce_init_default          {false, Session_key_init_default, {{NULL}, NULL}}
#define ConnectionRequest_init_zero              {false, User_Creds_init_zero}
#define ConnectionResponce_init_zero             {false, Session_key_init_zero}
#define DeviceData_init_zero                     {false, Session_key_init_zero, {{NULL}, NULL}, {{NULL}, NULL}}
#define ResultData_init_zero                     {false, Session_key_init_zero, {{NULL}, NULL}}
#define ReceiveCommandsRequest_init_zero         {false, Session_key_init_zero, {{NULL}, NULL}}
#define ReceiveCommandsResponse_init_zero        {false, Session_key_init_zero, {{NULL}, NULL}}
#define VirtSensorData_init_zero                 {false, Session_key_init_zero}
#define VirtSensorResponce_init_zero             {false, Session_key_init_zero, {{NULL}, NULL}, {{NULL}, NULL}}
#define SensorDataRequest_init_zero              {false, Session_key_init_zero, {{NULL}, NULL}, {{NULL}, NULL}}
#define SensorDataResponce_init_zero             {false, Session_key_init_zero, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define ConnectionRequest_usercreds_tag          1
#define ConnectionResponce_key_tag               1
#define DeviceData_key_tag                       1
#define DeviceData_sensor_tag                    2
#define DeviceData_executor_tag                  3
#define ResultData_key_tag                       1
#define ResultData_responce_tag                  2
#define ReceiveCommandsRequest_key_tag           1
#define ReceiveCommandsRequest_executors_tag     2
#define ReceiveCommandsResponse_key_tag          1
#define ReceiveCommandsResponse_command_tag      2
#define VirtSensorData_key_tag                   1
#define VirtSensorResponce_key_tag               1
#define VirtSensorResponce_sensors_tag           2
#define VirtSensorResponce_data_tag              3
#define SensorDataRequest_key_tag                1
#define SensorDataRequest_sensor_tag             2
#define SensorDataRequest_data_tag               3
#define SensorDataResponce_key_tag               1
#define SensorDataResponce_serverResponce_tag    2

/* Struct field encoding specification for nanopb */
#define ConnectionRequest_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  usercreds,         1)
#define ConnectionRequest_CALLBACK NULL
#define ConnectionRequest_DEFAULT NULL
#define ConnectionRequest_usercreds_MSGTYPE User_Creds

#define ConnectionResponce_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1)
#define ConnectionResponce_CALLBACK NULL
#define ConnectionResponce_DEFAULT NULL
#define ConnectionResponce_key_MSGTYPE Session_key

#define DeviceData_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, REPEATED, MESSAGE,  sensor,            2) \
X(a, CALLBACK, REPEATED, MESSAGE,  executor,          3)
#define DeviceData_CALLBACK pb_default_field_callback
#define DeviceData_DEFAULT NULL
#define DeviceData_key_MSGTYPE Session_key
#define DeviceData_sensor_MSGTYPE Sensor
#define DeviceData_executor_MSGTYPE Executor

#define ResultData_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, SINGULAR, STRING,   responce,          2)
#define ResultData_CALLBACK pb_default_field_callback
#define ResultData_DEFAULT NULL
#define ResultData_key_MSGTYPE Session_key

#define ReceiveCommandsRequest_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, REPEATED, MESSAGE,  executors,         2)
#define ReceiveCommandsRequest_CALLBACK pb_default_field_callback
#define ReceiveCommandsRequest_DEFAULT NULL
#define ReceiveCommandsRequest_key_MSGTYPE Session_key
#define ReceiveCommandsRequest_executors_MSGTYPE Executor

#define ReceiveCommandsResponse_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, REPEATED, STRING,   command,           2)
#define ReceiveCommandsResponse_CALLBACK pb_default_field_callback
#define ReceiveCommandsResponse_DEFAULT NULL
#define ReceiveCommandsResponse_key_MSGTYPE Session_key

#define VirtSensorData_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1)
#define VirtSensorData_CALLBACK NULL
#define VirtSensorData_DEFAULT NULL
#define VirtSensorData_key_MSGTYPE Session_key

#define VirtSensorResponce_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, REPEATED, MESSAGE,  sensors,           2) \
X(a, CALLBACK, REPEATED, MESSAGE,  data,              3)
#define VirtSensorResponce_CALLBACK pb_default_field_callback
#define VirtSensorResponce_DEFAULT NULL
#define VirtSensorResponce_key_MSGTYPE Session_key
#define VirtSensorResponce_sensors_MSGTYPE Sensor
#define VirtSensorResponce_data_MSGTYPE SensorData

#define SensorDataRequest_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, REPEATED, MESSAGE,  sensor,            2) \
X(a, CALLBACK, REPEATED, MESSAGE,  data,              3)
#define SensorDataRequest_CALLBACK pb_default_field_callback
#define SensorDataRequest_DEFAULT NULL
#define SensorDataRequest_key_MSGTYPE Session_key
#define SensorDataRequest_sensor_MSGTYPE Sensor
#define SensorDataRequest_data_MSGTYPE SensorData

#define SensorDataResponce_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  key,               1) \
X(a, CALLBACK, SINGULAR, STRING,   serverResponce,    2)
#define SensorDataResponce_CALLBACK pb_default_field_callback
#define SensorDataResponce_DEFAULT NULL
#define SensorDataResponce_key_MSGTYPE Session_key

extern const pb_msgdesc_t ConnectionRequest_msg;
extern const pb_msgdesc_t ConnectionResponce_msg;
extern const pb_msgdesc_t DeviceData_msg;
extern const pb_msgdesc_t ResultData_msg;
extern const pb_msgdesc_t ReceiveCommandsRequest_msg;
extern const pb_msgdesc_t ReceiveCommandsResponse_msg;
extern const pb_msgdesc_t VirtSensorData_msg;
extern const pb_msgdesc_t VirtSensorResponce_msg;
extern const pb_msgdesc_t SensorDataRequest_msg;
extern const pb_msgdesc_t SensorDataResponce_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ConnectionRequest_fields &ConnectionRequest_msg
#define ConnectionResponce_fields &ConnectionResponce_msg
#define DeviceData_fields &DeviceData_msg
#define ResultData_fields &ResultData_msg
#define ReceiveCommandsRequest_fields &ReceiveCommandsRequest_msg
#define ReceiveCommandsResponse_fields &ReceiveCommandsResponse_msg
#define VirtSensorData_fields &VirtSensorData_msg
#define VirtSensorResponce_fields &VirtSensorResponce_msg
#define SensorDataRequest_fields &SensorDataRequest_msg
#define SensorDataResponce_fields &SensorDataResponce_msg

/* Maximum encoded size of messages (where known) */
/* DeviceData_size depends on runtime parameters */
/* ResultData_size depends on runtime parameters */
/* ReceiveCommandsRequest_size depends on runtime parameters */
/* ReceiveCommandsResponse_size depends on runtime parameters */
/* VirtSensorResponce_size depends on runtime parameters */
/* SensorDataRequest_size depends on runtime parameters */
/* SensorDataResponce_size depends on runtime parameters */
#if defined(User_Creds_size)
#define ConnectionRequest_size                   (6 + User_Creds_size)
#endif
#if defined(Session_key_size)
#define ConnectionResponce_size                  (6 + Session_key_size)
#define VirtSensorData_size                      (6 + Session_key_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
