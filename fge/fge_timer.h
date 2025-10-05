// File: fge_timer.h
// Purpose: Header file for FGE timer functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_timer
#define _fge_timer

typedef void (*timer_initialize)();
typedef void (*timer_uninitialize)();

typedef struct {
    timer_initialize          initialize;
    timer_uninitialize        uninitialize;
} fge_fcns_timer;

extern fge_fcns_timer fcns_timer;

#define fge_timer(fge_function, ...)   (*fcns_timer.fge_function)(__VA_ARGS__);

#endif // _fge_timer
