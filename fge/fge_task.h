// File: fge_task.h
// Purpose: Header file for FGE task functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_task
#define _fge_task

#pragma pack(push, 1)

#include "fge_types.h"
#include "fge_msg.h"

#define FGE_TASK_STATE_DEAD         0
#define FGE_TASK_STATE_ACTIVE       1
#define FGE_TASK_STATE_SUSPENDED    2

// This represents a function that handles (processes) a message
// that was posted to the app queue and processed asynchronously.
typedef void (*task_handle)(FgeMsg* msg);

// This represents a function that receives (processes) a message
// that was sent to a particular task synchronously, such that the
// caller might obtain some kind of result from the callee.
typedef FgeTypeUnion (*task_receive)(FgeMsg* msg);

typedef struct tagFgeTask {
    uint8_t         id;
    uint8_t         state;
    char            name[FGE_MAX_TASK_NAME_SIZE];
    task_handle     handle;
    task_receive    receive;
    struct tagFgeTask* next;
} FgeTask;

#pragma pack(pop)

typedef void (*task_initialize)();
typedef void (*task_uninitialize)();
typedef void (*task_start)(FgeTask* task);
typedef FgeTask* (*task_find)(uint8_t id);
typedef FgeTask* (*task_current)();
typedef void (*task_suspend)(FgeTask* task);
typedef void (*task_resume)(FgeTask* task);
typedef void (*task_delete)(FgeTask* task);
typedef void (*task_activate)(FgeTask* task);

typedef struct {
    task_initialize         initialize;
    task_uninitialize       uninitialize;
    task_start              start;
    task_find               find;
    task_current            current;
    task_suspend            suspend;
    task_resume             resume;
    task_delete             delete;
    task_activate           activate;
} fge_fcns_task;

extern fge_fcns_task fge_task;

#endif // _fge_task
