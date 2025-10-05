// File: fge_bitmap.h
// Purpose: Header file for FGE bitmap functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_bitmap
#define _fge_bitmap

typedef void (*bitmap_initialize)();
typedef void (*bitmap_uninitialize)();

typedef struct {
    bitmap_initialize          initialize;
    bitmap_uninitialize        uninitialize;
} fge_fcns_bitmap;

extern fge_fcns_bitmap fcns_bitmap;

#define fge_bitmap(fge_function, ...)   (*fcns_bitmap.fge_function)(__VA_ARGS__);

#endif // _fge_bitmap
