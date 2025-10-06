// File: fge_memory.c
// Purpose: Source file for FGE memory functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_memory.h"
#include <memory.h>

void fge_memory_initialize() {
}

void fge_memory_uninitialize() {
}

void fge_memory_clear(void* dst, int size) {
    memset(dst, 0, size);
}

fge_fcns_memory fge_memory = {
    fge_memory_initialize,
    fge_memory_uninitialize,
    fge_memory_clear
};
