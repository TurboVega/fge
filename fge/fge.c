// File: fge.c
// Purpose: Source file for FGE functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use(but at your own risk. Nothing guaranteed!

#include "fge.h"

void fge_initialize() {
    fge_hal(initialize);
    fge_memory(initialize);
    fge_system(initialize);
    fge_msg(initialize);
    fge_timer(initialize);
    fge_task(initialize);
    fge_file(initialize);
    fge_dir(initialize);
    fge_key(initialize);
    fge_mouse(initialize);
    fge_joystick(initialize);
    fge_sound(initialize);
    fge_color(initialize);
    fge_pixel(initialize);
    fge_line(initialize);
    fge_shape(initialize);
    fge_text(initialize);
    fge_bitmap(initialize);
    fge_tile(initialize);
    fge_sprite(initialize);
    fge_app(initialize);
}

void fge_uninitialize() {
    fge_app(uninitialize);
    fge_sprite(uninitialize);
    fge_tile(uninitialize);
    fge_bitmap(uninitialize);
    fge_text(uninitialize);
    fge_shape(uninitialize);
    fge_line(uninitialize);
    fge_pixel(uninitialize);
    fge_color(uninitialize);
    fge_sound(uninitialize);
    fge_joystick(uninitialize);
    fge_mouse(uninitialize);
    fge_key(uninitialize);
    fge_dir(uninitialize);
    fge_file(uninitialize);
    fge_task(initialize);
    fge_timer(initialize);
    fge_msg(initialize);
    fge_system(uninitialize);
    fge_memory(uninitialize);
    fge_hal(uninitialize);
}
