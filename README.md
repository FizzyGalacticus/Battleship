Battleship
==========

CS372 Project 1 - Make a Battleship game

Compiling on different systems
================================

Windows - "g++ main.cpp Sound.cpp irrKlang\lib\Win32-gcc\libirrKlang.a"

Linux - "g++ main.cpp -m32 Sound.cpp libIrrKlang.so -pthread"
**NOTE** For compiling on 64-bit linux, you must use the -m32 switch and have the following libraries installed: { g++-multilib ia32-libs lib32gcc1 libc6-dev-i386 ia32-libs }. You must also set the LD_LIBRARY_PATH to the directory where the libIrrKlang.so file is located.
