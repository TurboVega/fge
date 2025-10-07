// File: fge_msg.c
// Purpose: Source file for FGE message functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_task.h"
#include "fge_memory.h"
#include <stdio.h>

static FgeMsg* gFreeHead;
static FgeMsg* gUsedHead;
static FgeMsg* gUsedTail;
static FgeMsg gMessages[FGE_MAX_MESSAGES];

void fge_msg_initialize() {
    printf("fge_msg_initialize\n");
    FgeMsg* msg = gMessages;
    for (int i = 0; i < FGE_MAX_MESSAGES - 1; i++) {
        msg->next = msg + 1;
        msg++;
    }
    msg->next = FGE_NULL;
    gFreeHead = gMessages;
    gUsedHead = FGE_NULL;
    gUsedTail = FGE_NULL;
}

void fge_msg_uninitialize() {
    printf("fge_msg_uninitialize\n");
    gFreeHead = FGE_NULL;
    gUsedHead = FGE_NULL;
    gUsedTail = FGE_NULL;
}

FgeMsg* fge_msg_alloc_from(uint8_t fromTaskId, uint8_t toTaskId, uint8_t type) {
    printf("fge_msg_alloc_from %hu to %hu as %hu\n", fromTaskId, toTaskId, type);
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
    printf("fge_msg_alloc\n");
    uint8_t fromTaskId = fge_task.current()->id;
    return fge_msg_alloc_from(fromTaskId, toTaskId, type);
}

void fge_msg_free(FgeMsg* msg) {
    printf("fge_msg_free\n");
    msg->next = gFreeHead;
    gFreeHead = msg;
}

void fge_msg_post(FgeMsg* msg) {
    printf("fge_msg_post\n");
    if (!gUsedHead) {
        gUsedHead = msg;
    } else {
        gUsedTail->next = msg;
    }
    gUsedTail = msg;
    msg->next = FGE_NULL;
}

FgeMsg* fge_msg_get() {
    printf("fge_msg_get\n");
    FgeMsg* msg = gUsedHead;
    if (msg) {
        printf("fge_msg_get %hu %hu %hu\n", msg->fromTaskId, msg->toTaskId, msg->type);
        gUsedHead = msg->next;
    }
    return msg;
}

FgeTypeUnion fge_msg_send(FgeMsg* msg) {
    printf("fge_msg_send %hu to %hu as %hu\n", msg->fromTaskId, msg->toTaskId, msg->type);
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
    fge_msg_send,
    fge_msg_get
};
