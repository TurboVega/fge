// File: fge_memory.h
// Purpose: Header file for FGE memory functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_memory
#define _fge_memory

typedef void (*memory_initialize)();
typedef void (*memory_uninitialize)();

typedef struct {
    memory_initialize          initialize;
    memory_uninitialize        uninitialize;
} fge_fcns_memory;

extern fge_fcns_memory fcns_memory;

#define fge_memory(fge_function, ...)   (*fcns_memory.fge_function)(__VA_ARGS__);

#endif // _fge_memory
