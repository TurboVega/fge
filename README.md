# Foenix Game Engine (FGE)

The FGE is a set of C functions that wrap common system operations and allow applications
to be written using those functions, and compiled for various machine platforms. There is
a hardware abstraction layer (HAL) that allows functions to be custom-fitted to particular
machines, where there are differences in operation. In fact, nearly every FGE function may
be overridden from its default implementation, (hopefully) without applications needing to
care about that fact.

## Theory of FGE Function Calls

FGE functions are divided into <i>subsystems</i>, such as <b>sound</b>, <b>mouse</b>, and
<sprite>. Each subsystem has its own set of functions, but <b>all</b> subsystems have at
least two common functions: <i>initialize</i> and <i>uninitialize</i>. This makes it
possible for FGE to do any specialized setup or teardown for each subsystem. These functions
are also used as examples of the calling mechanism.

### Standard Subsystem Header File

The following is an (early) example of a subsystem header file. The example contains the minimum set
of functions, but the real code will grow, adding more functions, as the subsystem is written.

```
typedef void (*mouse_initialize)();
typedef void (*mouse_uninitialize)();

typedef struct {
    mouse_initialize          initialize;
    mouse_uninitialize        uninitialize;
} fge_fcns_mouse;

extern fge_fcns_mouse fcns_mouse;

#define fge_mouse(fge_function, ...)   (*fcns_mouse.fge_function)(__VA_ARGS__);
```

Note that there is a type definition for each function, plus a function member based on that type in
a jump table structure unique to the subsystem. That structure becomes the basis for potential customization.

### Standard Subsystem Source File

The following is an (early) example of a subsystem source file. It defines the jump table by
defaulting all of its function members to point to the actual default functions that are also
defined in the source file. Any of these functions may be overridden simply by setting the
corresponding function member (pointer) to point to a new custom function with a similar type signature.

```
void fge_mouse_initialize() {
}

void fge_mouse_uninitialize() {
}

fge_fcns_mouse fcns_mouse = {
    fge_mouse_initialize,
    fge_mouse_uninitialize
};
```

### Example Function Invocation

The following code comes from "fge.c", which is an overall source file that pulls together the subsystems, relative to
initialization and uninitialization. Note that this code makes
use of the "fge_mouse" macro shown above, along with the
function member ("initialize") defined in the jump table.
This is an indirect function call, which is how it allows for customization.

```
void fge_initialize() {
    fge_hal(initialize);
    ...
    fge_mouse(initialize);
    ...
```
