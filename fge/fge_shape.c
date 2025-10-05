// File: fge_shape.c
// Purpose: Source file for FGE shape functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_shape.h"

void fge_shape_initialize() {
}

void fge_shape_uninitialize() {
}

fge_fcns_shape fcns_shape = {
    fge_shape_initialize,
    fge_shape_uninitialize
};
