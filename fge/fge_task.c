// File: fge_task.c
// Purpose: Source file for FGE task functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "fge_task.h"
#include <stdio.h>

static FgeTask* gActiveHead;
static FgeTask* gInactiveHead;
static FgeTask* gCurrentTask;

void fge_task_initialize() {
    printf("fge_task_initialize\n");
    gActiveHead = FGE_NULL;
    gInactiveHead = FGE_NULL;
}

void fge_task_uninitialize() {
    printf("fge_task_uninitialize\n");
    while (gActiveHead) {
        FgeMsg msg;
        msg.toTaskId = gActiveHead->id;
        msg.type = FGE_SYS_MSG_TYPE_TERMINATE;
        gActiveHead->receive(&msg);
        gActiveHead = gActiveHead->next;
    }

    while (gInactiveHead) {
        FgeMsg msg;
        msg.toTaskId = gInactiveHead->id;
        msg.type = FGE_SYS_MSG_TYPE_TERMINATE;
        gInactiveHead->receive(&msg);
        gInactiveHead = gInactiveHead->next;
    }
}

void fge_task_start(FgeTask* task) {
    printf("fge_task_start\n");
    task->state = FGE_TASK_STATE_ACTIVE;
    task->next = gActiveHead;
    gActiveHead = task;
    printf("started %s\n", task->name);
}

FgeTask* fge_task_find(uint8_t id) {
    printf("fge_task_find %hu\n", id);
    FgeTask* task = gActiveHead;
    while (task) {
        if (task->id == id) {
            printf("found %s\n", task->name);
            break;
        } else {
            task = task->next;
        }
    }
    return task;
}

FgeTask* fge_task_current() {
    printf("fge_task_current\n");
    return gCurrentTask;
}

void fge_task_suspend(FgeTask* task) {
    printf("fge_task_suspend\n");
    if (task == gActiveHead) {
        gActiveHead = task->next;
        task->state = FGE_TASK_STATE_SUSPENDED;
        task->next = gInactiveHead;
        gInactiveHead = task;
    } else if (gActiveHead) {
        FgeTask* task2 = gActiveHead;
        while (task2->next) {
            if (task2->next == task) {
                task2->next = task->next;
                task->state = FGE_TASK_STATE_SUSPENDED;
                task->next = gInactiveHead;
                gInactiveHead = task;
                break;
            } else {
                task2 = task2->next;
            }
        }
    }
}

void fge_task_resume(FgeTask* task) {
    printf("fge_task_resume\n");
    if (task == gInactiveHead) {
        gInactiveHead = task->next;
        task->state = FGE_TASK_STATE_ACTIVE;
        task->next = gActiveHead;
        gActiveHead = task;
    } else if (gInactiveHead) {
        FgeTask* task2 = gInactiveHead;
        while (task2->next) {
            if (task2->next == task) {
                task2->next = task->next;
                task->state = FGE_TASK_STATE_ACTIVE;
                task->next = gActiveHead;
                gActiveHead = task;
                break;
            } else {
                task2 = task2->next;
            }
        }
    }
}

void fge_task_delete(FgeTask* task) {
    printf("fge_task_delete\n");
    fge_task_suspend(task);
    if (task == gInactiveHead) {
        gInactiveHead = task->next;
        FgeMsg msg;
        msg.toTaskId = task->id;
        msg.type = FGE_SYS_MSG_TYPE_TERMINATE;
        task->receive(&msg);
        task->state = FGE_TASK_STATE_DEAD;
    } else if (gInactiveHead) {
        FgeTask* task2 = gInactiveHead;
        while (task2->next) {
            if (task2->next == task) {
                task2->next = task->next;
                FgeMsg msg;
                msg.toTaskId = task->id;
                msg.type = FGE_SYS_MSG_TYPE_TERMINATE;
                task->receive(&msg);
                task->state = FGE_TASK_STATE_DEAD;
                break;
            } else {
                task2 = task2->next;
            }
        }
    }
}

void fge_task_activate(FgeTask* task) {
    gCurrentTask = task;
}

fge_fcns_task fge_task = {
    fge_task_initialize,
    fge_task_uninitialize,
    fge_task_start,
    fge_task_find,
    fge_task_current,
    fge_task_suspend,
    fge_task_resume,
    fge_task_delete,
    fge_task_activate
};
