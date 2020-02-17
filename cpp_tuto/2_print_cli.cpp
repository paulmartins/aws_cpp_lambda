// Short c++ program that prints the command line arguments

#include <iostream>

int main(int argc, char** argv) 
{ 
    std::cout << "You have entered " << argc << " arguments:" << "\n"; 
    for (int i = 0; i < argc; ++i){
        std::cout << "Arg number " << i << " is " << argv[i] << "\n"; 
    }
    return 0; 
}