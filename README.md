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

or just this = g++ -c -o testlib.o testlib.cpp;ar rcs testlib.a testlib.o;g++ testlibcode.cpp testlib.a;./a.out