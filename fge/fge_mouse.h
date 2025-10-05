// File: fge_mouse.h
// Purpose: Header file for FGE mouse functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_mouse
#define _fge_mouse

typedef void (*mouse_initialize)();
typedef void (*mouse_uninitialize)();

typedef struct {
    mouse_initialize          initialize;
    mouse_uninitialize        uninitialize;
} fge_fcns_mouse;

extern fge_fcns_mouse fcns_mouse;

#define fge_mouse(fge_function, ...)   (*fcns_mouse.fge_function)(__VA_ARGS__);

#endif // _fge_mouse
