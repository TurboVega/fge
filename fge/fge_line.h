// File: fge_line.h
// Purpose: Header file for FGE line functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_line
#define _fge_line

typedef void (*line_initialize)();
typedef void (*line_uninitialize)();

typedef struct {
    line_initialize          initialize;
    line_uninitialize        uninitialize;
} fge_fcns_line;

extern fge_fcns_line  fge_line;

#endif // _fge_line
