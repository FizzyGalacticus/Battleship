#Battleship

###CS372 Project 1 - Make a Battleship game

####Compiling on different systems

**Windows** - "g++ main.cpp Sound.cpp Ship.cpp Board.cpp Player.cpp irrKlang/lib/Win32-gcc/libirrKlang.a"

**Linux** - "g++ main.cpp -m32 Sound.cpp Board.cpp Ship.cpp Player.cpp libIrrKlang.so -pthread"

**NOTE:** For compiling on 64-bit linux, you must use the -m32 switch and have the following libraries installed: 

{ g++-multilib, ia32-libs, lib32gcc1, libc6-dev-i386, ia32-libs }

You must also move libIrrKlang.so to **/usr/lib** AND-OR **/usr/local/lib.**

**Command to get completely set up in Linux x64 environment:**

From /src/ file of repository, type:

sudo apt-get install g++-multilib && sudo apt-get install ia32-libs && sudo apt-get install lib32gcc1 && sudo apt-get install  libc6-dev-i386 && sudo cp libIrrKlang.so /usr/lib && sudo cp libIrrKlang.so /usr/local/lib

...and press enter.