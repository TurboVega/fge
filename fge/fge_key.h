// File: fge_key.h
// Purpose: Header file for FGE key functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_key
#define _fge_key

typedef void (*key_initialize)();
typedef void (*key_uninitialize)();

typedef struct {
    key_initialize          initialize;
    key_uninitialize        uninitialize;
} fge_fcns_key;

extern fge_fcns_key fcns_key;

#define fge_key(fge_function, ...)   (*fcns_key.fge_function)(__VA_ARGS__);

#endif // _fge_key
