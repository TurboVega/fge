// File: fge_dir.h
// Purpose: Header file for FGE dir functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_dir
#define _fge_dir

typedef void (*dir_initialize)();
typedef void (*dir_uninitialize)();

typedef struct {
    dir_initialize          initialize;
    dir_uninitialize        uninitialize;
} fge_fcns_dir;

extern fge_fcns_dir fcns_dir;

#define fge_dir(fge_function, ...)   (*fcns_dir.fge_function)(__VA_ARGS__);

#endif // _fge_dir
