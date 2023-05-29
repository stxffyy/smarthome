/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_CONNECTION_NANOPB_H_INCLUDED
#define PB_CONNECTION_NANOPB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _User_Creds {
    pb_callback_t username;
    pb_callback_t pass;
    uint32_t board_id;
} User_Creds;

typedef struct _Session_key {
    pb_callback_t key;
} Session_key;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define User_Creds_init_default                  {{{NULL}, NULL}, {{NULL}, NULL}, 0}
#define Session_key_init_default                 {{{NULL}, NULL}}
#define User_Creds_init_zero                     {{{NULL}, NULL}, {{NULL}, NULL}, 0}
#define Session_key_init_zero                    {{{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define User_Creds_username_tag                  1
#define User_Creds_pass_tag                      2
#define User_Creds_board_id_tag                  3
#define Session_key_key_tag                      1

/* Struct field encoding specification for nanopb */
#define User_Creds_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   username,          1) \
X(a, CALLBACK, SINGULAR, STRING,   pass,              2) \
X(a, STATIC,   SINGULAR, UINT32,   board_id,          3)
#define User_Creds_CALLBACK pb_default_field_callback
#define User_Creds_DEFAULT NULL

#define Session_key_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   key,               1)
#define Session_key_CALLBACK pb_default_field_callback
#define Session_key_DEFAULT NULL

extern const pb_msgdesc_t User_Creds_msg;
extern const pb_msgdesc_t Session_key_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define User_Creds_fields &User_Creds_msg
#define Session_key_fields &Session_key_msg

/* Maximum encoded size of messages (where known) */
/* User_Creds_size depends on runtime parameters */
/* Session_key_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif