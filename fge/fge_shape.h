// File: fge_shape.h
// Purpose: Header file for FGE shape functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_shape
#define _fge_shape

typedef void (*shape_initialize)();
typedef void (*shape_uninitialize)();

typedef struct {
    shape_initialize          initialize;
    shape_uninitialize        uninitialize;
} fge_fcns_shape;

extern fge_fcns_shape  fge_shape;

#endif // _fge_shape
