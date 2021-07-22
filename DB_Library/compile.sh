g++ -c -o DBLib.o DBLib.cpp
ar rcs DBLib.a DBLib.o
g++ trial.cpp DBLib.a -ljsoncpp
./a.out
