// File: fge_text.h
// Purpose: Header file for FGE text functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_text
#define _fge_text

typedef void (*text_initialize)();
typedef void (*text_uninitialize)();

typedef struct {
    text_initialize          initialize;
    text_uninitialize        uninitialize;
} fge_fcns_text;

extern fge_fcns_text fcns_text;

#define fge_text(fge_function, ...)   (*fcns_text.fge_function)(__VA_ARGS__);

#endif // _fge_text
