// File: fge_sound.h
// Purpose: Header file for FGE sound functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_sound
#define _fge_sound

typedef void (*sound_initialize)();
typedef void (*sound_uninitialize)();

typedef struct {
    sound_initialize          initialize;
    sound_uninitialize        uninitialize;
} fge_fcns_sound;

extern fge_fcns_sound fcns_sound;

#define fge_sound(fge_function, ...)   (*fcns_sound.fge_function)(__VA_ARGS__);

#endif // _fge_sound
