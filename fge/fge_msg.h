// File: fge_msg.h
// Purpose: Header file for FGE message functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_msg
#define _fge_msg

typedef void (*msg_initialize)();
typedef void (*msg_uninitialize)();

typedef struct {
    msg_initialize          initialize;
    msg_uninitialize        uninitialize;
} fge_fcns_msg;

extern fge_fcns_msg fcns_msg;

#define fge_msg(fge_function, ...)   (*fcns_msg.fge_function)(__VA_ARGS__);

#endif // _fge_msg
