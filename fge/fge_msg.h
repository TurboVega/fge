// File: fge_msg.h
// Purpose: Header file for FGE message functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_msg
#define _fge_msg

#include "fge_types.h"

#define FGE_SYS_MSG_TYPE_TERMINATE  0   // tells a task that it is ending
#define FGE_SYS_MSG_TYPE_INITIATE   1   // tells a task that it is starting

#pragma pack(push, 1)

typedef struct tagFgeMsg {
    uint8_t     fromTaskId;
    uint8_t     toTaskId;
    uint8_t     type;
    FgeTypeUnion param[FGE_MAX_MSG_PARAMS];
    struct tagFgeMsg* next;
} FgeMsg;

#pragma pack(pop)

typedef void (*msg_initialize)();
typedef void (*msg_uninitialize)();

// Allocate a message, specifying its originating task.
typedef FgeMsg* (*msg_alloc_from)(uint8_t fromTaskId, uint8_t toTaskId, uint8_t type);

// Allocate a message, assuming that its originating task is the current task.
typedef FgeMsg* (*msg_alloc)(uint8_t toTaskId, uint8_t type);

// Deallocate a message (return it to the free pool).
typedef void (*msg_free)(FgeMsg* msg);

// Post a message to the app message queue.
typedef void (*msg_post)(FgeMsg* msg);

// Get a message from the app message queue, if any exist.
typedef FgeMsg* (*msg_get)();

// Send a message immediately, bypassing the queue.
typedef FgeTypeUnion (*msg_send)(FgeMsg* msg);

typedef struct {
    msg_initialize          initialize;
    msg_uninitialize        uninitialize;
    msg_alloc_from          alloc_from;
    msg_alloc               alloc;
    msg_free                free;
    msg_post                post;
    msg_send                send;
    msg_get                 get;
} fge_fcns_msg;

extern fge_fcns_msg  fge_msg;

#endif // _fge_msg
