// File: fge_msg.c
// Purpose: Source file for FGE message functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_task.h"
#include "fge_memory.h"

static FgeMsg* gFreeHead;
static FgeMsg* gUsedHead;
static FgeMsg* gUsedTail;
static FgeMsg gMessages[FGE_MAX_MESSAGES];

void fge_msg_initialize() {
    FgeMsg* msg = gMessages;
    for (int i = 0; i < FGE_MAX_MESSAGES - 1; i++) {
        msg->next = msg + 1;
    }
    gFreeHead = gMessages;
    gUsedHead = FGE_NULL;
    gUsedTail = FGE_NULL;
}

void fge_msg_uninitialize() {
    gFreeHead = FGE_NULL;
    gUsedHead = FGE_NULL;
    gUsedTail = FGE_NULL;
}

FgeMsg* fge_msg_alloc_from(uint8_t fromTaskId, uint8_t toTaskId, uint8_t type) {
    FgeMsg* msg = gFreeHead;
    if (msg) {
        gFreeHead = msg->next;
        msg->fromTaskId = fromTaskId;
        msg->toTaskId = toTaskId;
        msg->type = type;
        fge_memory.clear(msg->param, sizeof(msg->param));
    }
    return msg;
}

FgeMsg* fge_msg_alloc(uint8_t toTaskId, uint8_t type) {
    uint8_t fromTaskId = fge_task.current()->id;
    return fge_msg_alloc_from(fromTaskId, toTaskId, type);
}

void fge_msg_free(FgeMsg* msg) {
    msg->next = gFreeHead;
    gFreeHead = msg;
}

void fge_msg_post(FgeMsg* msg) {
    if (!gUsedHead) {
        gUsedHead = msg;
    } else {
        gUsedTail->next = msg;
    }
    gUsedTail = msg;
    msg->next = FGE_NULL;
}

FgeTypeUnion fge_msg_send(FgeMsg* msg) {
    FgeTask* task = fge_task.find(msg->toTaskId);
    if (task) {
        return task->receive(msg);
    }
}

fge_fcns_msg fge_msg = {
    fge_msg_initialize,
    fge_msg_uninitialize,
    fge_msg_alloc_from,
    fge_msg_alloc,
    fge_msg_free,
    fge_msg_post,
    fge_msg_send
};
