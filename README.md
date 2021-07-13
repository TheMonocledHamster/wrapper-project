# wrapper-project
CPP Wrappers

To run jsoncpp code:  
  g++ test.cpp -ljsoncpp   
  ./a.out

To compile and create static libraries:  
  g++ -c -o testlib.o testlib.cpp  
  ar rcs testlib.a testlib.o  
  g++ testlibcode.cpp testlib.a  
  ./a.out  
a.out can run on any machine without having to install dependencies
