// File: fge.c
// Purpose: Source file for FGE functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge.h"

void fge_initialize() {
    fge_hal_initialize();
    fge_memory_initialize();
    fge_system_initialize();
    fge_msg_initialize();
    fge_timer_initialize();
    fge_task_initialize();
    fge_file_initialize();
    fge_dir_initialize();
    fge_key_initialize();
    fge_mouse_initialize();
    fge_joystick_initialize();
    fge_sound_initialize();
    fge_color_initialize();
    fge_pixel_initialize();
    fge_line_initialize();
    fge_shape_initialize();
    fge_text_initialize();
    fge_bitmap_initialize();
    fge_tile_initialize();
    fge_sprite_initialize();
    fge_app_initialize();
}

void fge_uninitialize() {
    fge_app_uninitialize();
    fge_sprite_uninitialize();
    fge_tile_uninitialize();
    fge_bitmap_uninitialize();
    fge_text_uninitialize();
    fge_shape_uninitialize();
    fge_line_uninitialize();
    fge_pixel_uninitialize();
    fge_color_uninitialize();
    fge_sound_uninitialize();
    fge_joystick_uninitialize();
    fge_mouse_uninitialize();
    fge_key_uninitialize();
    fge_dir_uninitialize();
    fge_file_uninitialize();
    fge_task_initialize();
    fge_timer_initialize();
    fge_msg_initialize();
    fge_system_uninitialize();
    fge_memory_uninitialize();
    fge_hal_uninitialize();
}
