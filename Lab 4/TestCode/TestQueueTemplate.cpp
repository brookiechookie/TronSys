

#include <iostream>

int i = 37;
int j = 43;

int& r = i;   // initialising the reference
int* p = &i;  // initialising the pointer
std::cout << i << ", " << j << std::endl;
std::cout << r << ", " << *p << std::endl;
p = &j;  // reassigning the pointer
*p = 3;  // modifying what's pointed to by p
std::cout << i << ", " << j << std::endl;std::cout << r << ", " << *p << std::endl;
r = j;   // modifying what's referenced by r// NOT reassigning r
std::cout << i << ", " << j << std::endl;
std::cout << r << ", " << *p << std::endl;


int k = r;
std::cout << r << ", " << k << std::endl;
