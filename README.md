
# Sample media player #

## Build the docker images ##

`./build -f Dockerfile.arch -t arch .`

`./build -f Dockerfile.debian -t debian .`

## Run the docker images ##

`./run -r sample -t arch`

`./run -r sample -t debian`

## Environment ##

**Arch**: _CMake 3.29.3_, _Ninja 1.12.1_, _GCC 14.1.1_, _Qt 6.7.0_

**Debian 12.5**: _CMake 3.25_, _Ninja 1.11.1_, _GCC 12.2.0_, _Qt 6.4.2_

