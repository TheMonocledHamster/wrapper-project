g++ -c -o DBLib.o DBLib.cpp
ar rcs DBLib.a DBLib.o
g++ -o DBexe trial.cpp DBLib.a -ljsoncpp
./DBexe
