// File: fge_sprite.h
// Purpose: Header file for FGE sprite functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_sprite
#define _fge_sprite

typedef void (*sprite_initialize)();
typedef void (*sprite_uninitialize)();

typedef struct {
    sprite_initialize           initialize;
    sprite_uninitialize         uninitialize;
} fge_fcns_sprite;

extern fge_fcns_sprite  fge_sprite;

#endif // _fge_sprite
