# wrapper-project
CPP Wrappers

To run jsoncpp code
(Ubuntu):  
1) g++ test.cpp -ljsoncpp   
2) ./a.out


To compile and create static libraries
(Ubuntu):  
1) g++ -c -o testlib.o testlib.cpp  
2) ar rcs testlib.a testlib.o  
3) g++ testcode.cpp testlib.a -ljsoncpp
4) ./a.out  

DBLib:
Ubuntu: g++ -c -o DBLib.o DBLib.cpp;ar rcs DBLib.a DBLib.o;g++ trial.cpp DBLib.a -ljsoncpp;./a.out

CPP ANSI colour formatting:
std::cout<<"\033[<X>m -> Text <- \033[0m";
X: reset = 0, black = 30, red = 31, green = 32, yellow = 33, blue = 34, magenta = 35, cyan = 36, white = 37