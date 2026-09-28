# FusionHeaders

Shared headers for **Fusion**, used as a submodule by the core and by backends.

The core owns the headers. Backends only consume them.

## Layout

- `Fusion/`: public API
- `Internal/`: core internal types (backends need them)
- `BackendInterface/`: interface every backend implements
- `modules_flags.mk`: required flags for building modules

## Usage

```sh
git submodule add https://github.com/Fusion-Toolchain/FusionHeaders.git include
```

When cloning a project that uses this submodule:

```sh
git clone --recurse-submodules PROJECT-URL
```

## Rules

- Backends: read-only, do not commit inside the submodule.
- Core: commit and push here first, then commit the new submodule pointer in Fusion.
