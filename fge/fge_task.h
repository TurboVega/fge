// File: fge_task.h
// Purpose: Header file for FGE task functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_task
#define _fge_task

#pragma pack(push, 1)

#include "fge_types.h"

typedef struct {
    uint8_t     id;
    char        name[FGE_MAX_TASK_NAME_SIZE];
} FgeTask;

#pragma pack(pop)

typedef void (*task_initialize)();
typedef void (*task_uninitialize)();
typedef void (*task_create)(FgeTask* task, uint8_t id, const char* name);


typedef struct {
    task_initialize         initialize;
    task_uninitialize       uninitialize;
    task_create             create;

} fge_fcns_task;

extern fge_fcns_task fge_task;

#endif // _fge_task
