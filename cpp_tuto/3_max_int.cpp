// Short c++ program that shows the max size of integers
// and the use of functions

#include <iostream>
#include <math.h>

void run_integer_loop()
{
	int new_int = 2147483640;
    int old_int = 0;

    while(new_int > old_int){
    	std::cout << new_int << std::endl;
    	old_int = new_int;
    	++new_int;
    }

    std::cout << "2^31 = " << pow(2,31) << std::endl;
}

void run_unsigned_integer_loop()
{
	unsigned int new_int = 4294967290;
    unsigned int old_int = 0;

    while(new_int > old_int){
    	std::cout << new_int << std::endl;
    	old_int = new_int;
    	++new_int;
    }

    std::cout << "2^32 = " << pow(2,32) << std::endl;
}

int main()
{
	// just overwriting the amount of digit to print
	std::cout.unsetf ( std::ios::floatfield ); 
	std::cout.precision(12);

	run_integer_loop();
	run_unsigned_integer_loop();

    return 0;
}

