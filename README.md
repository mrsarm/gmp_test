gmp_test C-project
==================

This is just a test example project.

The only purpose of this project is to use as a test
for **GMP library**, and as an example of how to import
this library in a *CMakes* project.

The project uses *CMakes* to build the executable.


Build and execute
-----------------

To compile you need first installed the **GMP library**,
in many Linux distribution the package is
named `libgmp-dev`.

1. From the source directory, generate the "Makefile":

       $ cmake .

2. *Make* the project and generate the executable "gmp_test".

       $ make

3. Then execute with:

       $ out/gmp_test

To clean the compiled binaries and compiled modules:

    $ make clean

To clean all compiled files and generated "Makefiles":

    $ make clean-all

A more complete example of a C project with
CMake and CHEAT for unit testing is
at https://github.com/mrsarm/helloworld-c

About
-----

Source: https://github.com/mrsarm/gmp_test

Authors: (2015-2018) Mariano Ruiz <mrsarm@gmail.cm>

License: GPL-3
