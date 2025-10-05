// File: fge_math.h
// Purpose: Header file for FGE math functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_math
#define _fge_math

typedef void (*math_initialize)();
typedef void (*math_uninitialize)();

typedef struct {
    math_initialize          initialize;
    math_uninitialize        uninitialize;
} fge_fcns_math;

extern fge_fcns_math fcns_math;

#define fge_math(fge_function, ...)   (*fcns_math.fge_function)(__VA_ARGS__);

#endif // _fge_math
