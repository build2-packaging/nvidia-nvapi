# nvidia-nvapi - The C headers and library stubs for NVAPI, NVIDIA's API for GPU and driver features

This is a `build2` package repository for [`nvapi`](https://github.com/NVIDIA/nvapi),
the public headers and Windows link stubs of the NVAPI SDK, NVIDIA's API for
accessing GPU and driver features on systems with NVIDIA hardware.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libnvapi` or `libnvapi-headers` in your `build2`-based project, then instead
see the accompanying
[`libnvapi/PACKAGE-README.md`](libnvapi/PACKAGE-README.md) or
[`libnvapi-headers/PACKAGE-README.md`](libnvapi-headers/PACKAGE-README.md)
file.

The development setup for `nvidia-nvapi` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules --shallow-submodules https://github.com/build2-packaging/nvidia-nvapi.git
cd nvidia-nvapi

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
