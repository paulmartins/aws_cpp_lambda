// Short c++ program that shows the use of arrays
#include <iostream>
#include <math.h>

long int array_sum(int size)
{
    // Define the array of integers
    unsigned int x1[size];
    // Initialise the sum
    unsigned int sum = 0;

    for(unsigned int i=0; i<size; i++){ 
        x1[i] = pow(i,2); 
        sum += x1[i];
    }

    return sum;
}

int main()
{
    // just overwriting the amount of digit to print
    std::cout.unsetf ( std::ios::floatfield ); 
    std::cout.precision(12);
   
    long int sum10 = array_sum(10);
    std::cout << "Sum of squares up to 10 = " << sum10 << std::endl;

    // Each element of the array x1 can store the value of the square
    // 10,000^2 = 100,000,000 < max_int = 2,147,483,648

    // However the sum cannot: 333,383,335,000 > max_int = 2,147,483,648
    // This is an integer overflow !
    // An unhandled arithmetic overflow in the engine steering software was 
    // the primary cause of the crash of the maiden flight of the Ariane 5 rocket. 
    // The software had been considered bug-free since it had been used in many 
    // previous flights; but those used smaller rockets which generated smaller 
    // accelerations than Ariane 5's.
    long int sum10000 = array_sum(10000);
    std::cout << "Sum of squares up to 10000 = " << sum10000 << std::endl;

    // A single array element doesn't have enough memory allocated to it to save the number
    // Segmentation Fault 
    long int sum10000000 = array_sum(10000000);
    std::cout << "Sum of squares up to 10000000 = " << sum10000000 << std::endl;

    return 0;
}

