// Short c++ program that reads in user input

#include <iostream>

int main() 
{
	char * my_name = new char[100];;
    std::cout << "Please enter your name:" << '\n';
    std::cin >> my_name;
    std::cout << "My name is " << my_name << '\n';
    return 0;
}

