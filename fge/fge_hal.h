// File: fge_hal.h
// Purpose: Header file for FGE hal functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_hal
#define _fge_hal

typedef void (*hal_initialize)();
typedef void (*hal_uninitialize)();

typedef struct {
    hal_initialize          initialize;
    hal_uninitialize        uninitialize;
} fge_fcns_hal;

extern fge_fcns_hal  fge_hal;

#endif // _fge_hal
