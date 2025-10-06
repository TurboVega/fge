// File: fge_task.c
// Purpose: Source file for FGE task functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_task.h"

static FgeTask* gActiveHead;
static FgeTask* gActiveTail;
static FgeTask* gInactiveHead;
static FgeTask* gInactiveTail;

void fge_task_initialize() {
}

void fge_task_uninitialize() {
}

void fge_task_create(FgeTask* task, uint8_t id, const char* name) {

}

FgeTask* fge_task_find(uint8_t id) {

}

fge_fcns_task fge_task = {
    fge_task_initialize,
    fge_task_uninitialize,
    fge_task_create,
    fge_task_find
};
