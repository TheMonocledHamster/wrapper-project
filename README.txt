Team:
  4NI19CS008 - Adithya Hegde
  4NI19CS010 - Aditya Subrahmanya Bhat

Concepts implemented:
  Encapsulation
  Objects and Classes
  Inheritance
  Pointers 
  Reference Parameters
  Constructors & Destructors
  STL - Vectors
  Exception Handling
  File Handling and Parsing
  RTTI (Dynamic Cast)
  Compile-time Polymorphism (Overloading)
  Generic Classes (Templates)
  Static Libraries
  Preprocessor Directives
  Linkers

Project Dependencies:
  JsonCPP 1.8.1 (Open Source) - https://github.com/open-source-parsers/jsoncpp

Compatibility:
  Architecture:
    x86
    x64
  Operating Systems:
    Debian-based Linux Distros (Ubuntu, Debian, Mint, etc)
    Arch-based Distros (Arch, Manjaro, Garuda, SteamOS, etc)
    RedHat Family (RHEL, CentOS, Fedora)
    FreeBSD
  C++ Versions:
    C++ 11
    C++ 14
    C++ 17
  Compiler:
    G++ 7
    G++ 9
  Output Formatting:
    ANSI X3.64

Recommended:
  Ubuntu 20.04, C++11, G++9.3
  Execution:
    1. Create Object Files:			g++ -c -o DBLib.o DBLib.cpp
    2. Create Static Library:			ar rcs DBLib.a DBLib.o
    3. Compile Program:				g++ trial.cpp DBLib.a -ljsoncpp
    4. Execute Program:				./a.out

GitHub Repository: https://github.com/Emperor-Adi/wrapper-project