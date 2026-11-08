# libnvapi - The C library stubs for NVAPI, NVIDIA's API for GPU and driver features

> **NOTE:**
> This package does not contain any source code. Instead, in order to "build"
> the exported target(s) it downloads the prebuilt `nvapi64.lib` stub provided
> by NVIDIA for the target platform.
>
> Supported platforms/compilers are 64-bit Windows (MSVC).

This is a `build2` package for the [`nvapi`](https://github.com/NVIDIA/nvapi)
C library. It imports NVIDIA's prebuilt NVAPI link stub for 64-bit Windows
and re-exports the headers from
[`libnvapi-headers`](https://github.com/build2-packaging/nvidia-nvapi).

On `x86_64-windows` it provides `nvapi64.lib`, the static stub that loads the
driver's `nvapi64.dll` at runtime. There is no redistributable shared library
in the SDK. The stub is an MSVC object archive, which MinGW cannot link.
Binaries are downloaded at build time into `config.libnvapi.cache` (not
shipped).


## Usage

To start using `libnvapi` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvapi >= 615.0.0
```

Then import the library in your `buildfile`:

```
import libs = libnvapi%lib{nvapi}
```


## Importable targets

This package provides the following importable targets:

```
lib{nvapi}
```


## Configuration variables

This package provides the following configuration variables:

```
[dir_path] config.libnvapi.cache ?= $out_root
```

Download cache. Only a symlink is a target, so `b clean` keeps the files.
