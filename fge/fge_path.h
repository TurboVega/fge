// File: fge_path.h
// Purpose: Header file for FGE path functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_path
#define _fge_path

typedef void (*path_initialize)();
typedef void (*path_uninitialize)();

typedef struct {
    path_initialize          initialize;
    path_uninitialize        uninitialize;
} fge_fcns_path;

extern fge_fcns_path  fge_path;

#endif // _fge_path
