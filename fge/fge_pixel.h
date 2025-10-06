// File: fge_pixel.h
// Purpose: Header file for FGE pixel functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_pixel
#define _fge_pixel

typedef void (*pixel_initialize)();
typedef void (*pixel_uninitialize)();

typedef struct {
    pixel_initialize          initialize;
    pixel_uninitialize        uninitialize;
} fge_fcns_pixel;

extern fge_fcns_pixel  fge_pixel;

#endif // _fge_pixel
