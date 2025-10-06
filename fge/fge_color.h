// File: fge_color.h
// Purpose: Header file for FGE color functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_color
#define _fge_color

typedef void (*color_initialize)();
typedef void (*color_uninitialize)();

typedef struct {
    color_initialize          initialize;
    color_uninitialize        uninitialize;
} fge_fcns_color;

extern fge_fcns_color  fge_color;

#endif // _fge_color
