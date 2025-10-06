// File: fge_app.h
// Purpose: Header file for FGE app functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_app
#define _fge_app

typedef void (*app_initialize)();
typedef void (*app_uninitialize)();

typedef struct {
    app_initialize          initialize;
    app_uninitialize        uninitialize;
} fge_fcns_app;

extern fge_fcns_app  fge_app;

#endif // _fge_app
