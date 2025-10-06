// File: fge_system.h
// Purpose: Header file for FGE system functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_system
#define _fge_system

typedef void (*system_initialize)();
typedef void (*system_uninitialize)();

typedef struct {
    system_initialize          initialize;
    system_uninitialize        uninitialize;
} fge_fcns_system;

extern fge_fcns_system  fge_system;

#endif // _fge_system
