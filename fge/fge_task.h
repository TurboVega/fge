// File: fge_task.h
// Purpose: Header file for FGE task functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_task
#define _fge_task

typedef void (*task_initialize)();
typedef void (*task_uninitialize)();

typedef struct {
    task_initialize          initialize;
    task_uninitialize        uninitialize;
} fge_fcns_task;

extern fge_fcns_task fcns_task;

#define fge_task(fge_function, ...)   (*fcns_task.fge_function)(__VA_ARGS__);

#endif // _fge_task
