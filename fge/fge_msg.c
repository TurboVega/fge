// File: fge_msg.c
// Purpose: Source file for FGE message functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_msg.h"

static FgeMsg* gFreeHead;
static FgeMsg gMessages[FGE_MAX_MESSAGES];

void fge_msg_initialize() {
}

void fge_msg_uninitialize() {
}

FgeMsg* fge_msg_alloc_from(uint8_t fromTaskId, uint8_t toTaskId, uint8_t type) {

}

FgeMsg* fge_msg_alloc(uint8_t toTaskId, uint8_t type) {

}

void fge_msg_free(FgeMsg* msg) {

}

void fge_msg_post(FgeMsg* msg) {

}

FgeMsgParam fge_msg_send(FgeMsg* msg) {

}

fge_fcns_msg fge_msg = {
    fge_msg_initialize,
    fge_msg_uninitialize,
    fge_msg_alloc_from,
    fge_msg_alloc,
    fge_msg_free,
    fge_msg_post,
    fge_msg_send
};
