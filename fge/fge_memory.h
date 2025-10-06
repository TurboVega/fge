// File: fge_memory.h
// Purpose: Header file for FGE memory functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_memory
#define _fge_memory

typedef void (*memory_initialize)();
typedef void (*memory_uninitialize)();
typedef void (*memory_clear)(void* dst, int size);

typedef struct {
    memory_initialize       initialize;
    memory_uninitialize     uninitialize;
    memory_clear            clear;
} fge_fcns_memory;

extern fge_fcns_memory  fge_memory;

#endif // _fge_memory
