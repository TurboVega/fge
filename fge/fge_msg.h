// File: fge_msg.h
// Purpose: Header file for FGE message functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_msg
#define _fge_msg

#include "fge_types.h"

#pragma pack(push, 1)

typedef union tagFgeMsgParam {
    int32_t     i32;
    int16_t     i16[2];
    int8_t      i8[4];
    uint32_t    u32;
    uint16_t    u16[2];
    uint8_t     u8[4];
    char        ch[4];
} FgeMsgParam;

typedef struct tagFgeMsg {
    uint8_t     fromTaskId;
    uint8_t     toTaskId;
    uint8_t     type;
    FgeMsgParam param[FGE_MAX_MSG_PARAMS];
    struct tagFgeMsg* next;
} FgeMsg;

#pragma pack(pop)

typedef void (*msg_initialize)();
typedef void (*msg_uninitialize)();
typedef FgeMsg* (*msg_alloc_from)(uint8_t fromTaskId, uint8_t toTaskId, uint8_t type);
typedef FgeMsg* (*msg_alloc)(uint8_t toTaskId, uint8_t type);
typedef void (*msg_free)(FgeMsg* msg);
typedef void (*msg_post)(FgeMsg* msg);
typedef FgeMsgParam (*msg_send)(FgeMsg* msg);

typedef struct {
    msg_initialize          initialize;
    msg_uninitialize        uninitialize;
    msg_alloc_from          alloc_from;
    msg_alloc               alloc;
    msg_free                free;
    msg_post                post;
    msg_send                send;
} fge_fcns_msg;

extern fge_fcns_msg  fge_msg;

#endif // _fge_msg
