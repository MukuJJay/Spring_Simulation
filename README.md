# Spring Simulation

A small C/raylib project that visualizes a horizontal spring attached to a block.
The block moves using a simple spring-force equation with damping, and you can
drag it with the mouse to disturb the system.

## Requirements

- GCC
- raylib
- Linux graphics/system libraries used by raylib:
  - OpenGL
  - pthread
  - dl
  - rt
  - X11

On Debian/Ubuntu-based systems, install raylib using the package available for
your distribution, or build/install raylib from source if your package manager
does not provide it.

## Build

```sh
./build.sh
```

This compiles `main.c` into an executable named `main`:

```sh
gcc -Wall -Wextra -g -o main main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

## Run

```sh
./main
```

## Controls

- Hold the left mouse button to move the block horizontally.
- Release the mouse button to let the spring simulation continue.
- Close the window to exit.

## Clean

```sh
./clean.sh
```

This removes the compiled `main` executable.

## Project Files

- `main.c` - spring simulation source code
- `build.sh` - build command
- `clean.sh` - removes the compiled executable
