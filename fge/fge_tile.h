// File: fge_tile.h
// Purpose: Header file for FGE tile functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_tile
#define _fge_tile

typedef void (*tile_initialize)();
typedef void (*tile_uninitialize)();

typedef struct {
    tile_initialize          initialize;
    tile_uninitialize        uninitialize;
} fge_fcns_tile;

extern fge_fcns_tile fcns_tile;

#define fge_tile(fge_function, ...)   (*fcns_tile.fge_function)(__VA_ARGS__);

#endif // _fge_tile
