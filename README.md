<<<<<<< HEAD
# wrapper-project
CPP Wrappers

To run jsoncpp code:  
1) g++ test.cpp -ljsoncpp   
2) ./a.out

or just this = g++ test.cpp -ljsoncpp;./a.out

To compile and create static libraries:  
1) g++ -c -o testlib.o testlib.cpp  
2) ar rcs testlib.a testlib.o  
3) g++ testlibcode.cpp testlib.a  
4) ./a.out  

or just this = g++ -c -o testlib.o testlib.cpp;ar rcs testlib.a testlib.o;g++ testlibcode.cpp testlib.a;./a.out

a.out can run on any machine without having to install dependencies
=======
# wrapper-project
CPP Wrappers

To run jsoncpp code:  
1) g++ test.cpp -ljsoncpp   
2) ./a.out

or just this = g++ test.cpp -ljsoncpp;./a.out

To compile and create static libraries:  
1) g++ -c -o testlib.o testlib.cpp  
2) ar rcs testlib.a testlib.o  
3) g++ testlibcode.cpp testlib.a  
4) ./a.out  

or just this = g++ -c -o testlib.o testlib.cpp;ar rcs testlib.a testlib.o;g++ testlibcode.cpp testlib.a;./a.out

a.out can run on any machine without having to install dependencies
>>>>>>> ca8de61f915a5e43a0e177fd98628d1ce130f996
