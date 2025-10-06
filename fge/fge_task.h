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

typedef void (*task_handler)(FgeMsg* msg);

typedef struct tagFgeTask {
    uint8_t     id;
    uint8_t     state;
    char        name[FGE_MAX_TASK_NAME_SIZE];
    task_handler handler;
    struct tagFgeTask* next;
    struct tagFgeTask* prev;
} FgeTask;

#pragma pack(pop)

typedef void (*task_initialize)();
typedef void (*task_uninitialize)();
typedef void (*task_create)(FgeTask* task, uint8_t id, const char* name);
typedef FgeTask* (*task_find)(uint8_t id);
typedef FgeTask* (*task_current)();
typedef void (*task_suspend)(FgeTask* task);
typedef void (*task_resume)(FgeTask* task);
typedef void (*task_delete)(FgeTask* task);

typedef struct {
    task_initialize         initialize;
    task_uninitialize       uninitialize;
    task_create             create;
    task_find               find;

} fge_fcns_task;

extern fge_fcns_task fge_task;

#endif // _fge_task
