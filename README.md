# wrapper-project
CPP Wrappers

To run jsoncpp code:  
1) g++ test.cpp -ljsoncpp   
2) ./a.out

To compile and create static libraries:  
1) g++ -c -o testlib.o testlib.cpp  
2) ar rcs testlib.a testlib.o  
3) g++ testlibcode.cpp testlib.a  
4) ./a.out  

a.out can run on any machine without having to install dependencies
