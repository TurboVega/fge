// File: fge_joystick.h
// Purpose: Header file for FGE joystick functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_joystick
#define _fge_joystick

typedef void (*joystick_initialize)();
typedef void (*joystick_uninitialize)();

typedef struct {
    joystick_initialize          initialize;
    joystick_uninitialize        uninitialize;
} fge_fcns_joystick;

extern fge_fcns_joystick fcns_joystick;

#define fge_joystick(fge_function, ...)   (*fcns_joystick.fge_function)(__VA_ARGS__);

#endif // _fge_joystick
