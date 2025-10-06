// File: fge_types.h
// Purpose: Header file for FGE data types, etc.
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#ifndef _fge_types
#define _fge_types

#include <stdint.h>

#define FGE_NULL                0

#define FGE_TASK_ID_ANY         0
#define FGE_MAX_TASK_NAME_LEN   15
#define FGE_MAX_TASK_NAME_SIZE  (FGE_MAX_TASK_NAME_LEN + 1)

#define FGE_MAX_MSG_PARAMS      4
#define FGE_MAX_MESSAGES        32

#pragma pack(push, 1)

typedef union {
    int32_t     i32;
    int16_t     i16[2];
    int8_t      i8[4];
    uint32_t    u32;
    uint16_t    u16[2];
    uint8_t     u8[4];
    char        ch[4];
} FgeTypeUnion;

#pragma pack(pop)

#endif // _fge_types
