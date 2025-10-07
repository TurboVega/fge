// File: pectin.c
// Purpose: Source file for PECTIN application functions
// Copyright (C) 2025 by Curtis Whitley.
//
// Free for use, but at your own risk. Nothing guaranteed!

#include "../fge/fge.h"
#include <stdio.h>
#include <string.h>

FgeTask mainTask;

void main_handle(FgeMsg* msg) {
    printf("main_handle: from %hu to %hu as %hu\n", msg->fromTaskId, msg->toTaskId, msg->type);
    printf("msg->param[0].ch[0] is '%c'\n", msg->param[0].ch[0]);
}

FgeTypeUnion main_receive(FgeMsg* msg) {
}

int main() {
    printf("PECTIN!\n");
    fge_initialize();

    mainTask.id = 1;
    mainTask.handle = main_handle;
    mainTask.receive = main_receive;
    strcpy(mainTask.name, "MainTask");
    fge_task.start(&mainTask);
    fge_task.activate(&mainTask);
    FgeMsg* msg = fge_msg.alloc(1, 7);
    msg->param[0].ch[0] = 'X';
    fge_msg.post(msg);

    while (mainTask.state == FGE_TASK_STATE_ACTIVE) {
        FgeMsg* msg = fge_msg.get();
        if (msg) {
            FgeTask* task = fge_task.find(msg->toTaskId);
            if (task) {
                fge_task.activate(task);
                task->handle(msg);
                fge_task.activate(&mainTask);
            }
            fge_msg.free(msg);
        } else {
            break;
        }
    }

    fge_uninitialize();
    printf("DONE!\n");
}
