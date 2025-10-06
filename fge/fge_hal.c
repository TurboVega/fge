// File: fge_hal.c
// Purpose: Source file for FGE hal functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_hal.h"

void fge_hal_initialize() {
}

void fge_hal_uninitialize() {
}

fge_fcns_hal fge_hal = {
    fge_hal_initialize,
    fge_hal_uninitialize
};
