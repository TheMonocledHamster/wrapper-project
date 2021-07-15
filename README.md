# wrapper-project
CPP Wrappers

To run jsoncpp code:  
1) g++ test.cpp -ljsoncpp   
2) ./a.out

or just this = g++ test.cpp -ljsoncpp;./a.out

To compile and create static libraries:  
1) g++ -c -o testlib.o testlib.cpp  
2) ar rcs testlib.a testlib.o  
3) g++ testlibcode.cpp testlib.a -ljsoncpp
4) ./a.out  

DBLib:
g++ -c -o DBLib.o DBLib.cpp;ar rcs DBLib.a DBLib.o;g++ trial.cpp DBLib.a -ljsoncpp;./a.out

reset = 0, black = 30, red = 31, green = 32, yellow = 33, blue = 34, magenta = 35, cyan = 36, and white = 37