// File: fge_file.h
// Purpose: Header file for FGE file functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_file
#define _fge_file

typedef void (*file_initialize)();
typedef void (*file_uninitialize)();

typedef struct {
    file_initialize          initialize;
    file_uninitialize        uninitialize;
} fge_fcns_file;

extern fge_fcns_file  fge_file;

#endif // _fge_file
