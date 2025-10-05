// File: fge_hit.h
// Purpose: Header file for FGE hit (collision) functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_hit
#define _fge_hit

typedef void (*hit_initialize)();
typedef void (*hit_uninitialize)();

typedef struct {
    hit_initialize          initialize;
    hit_uninitialize        uninitialize;
} fge_fcns_hit;

extern fge_fcns_hit fcns_hit;

#define fge_hit(fge_function, ...)   (*fcns_hit.fge_function)(__VA_ARGS__);

#endif // _fge_hit
