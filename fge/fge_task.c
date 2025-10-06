// File: fge_task.c
// Purpose: Source file for FGE task functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_task.h"

void fge_task_initialize() {
}

void fge_task_uninitialize() {
}

void fge_task_create(FgeTask* task, uint8_t id, const char* name) {

}

fge_fcns_task fge_task = {
    fge_task_initialize,
    fge_task_uninitialize,
    fge_task_create
};
