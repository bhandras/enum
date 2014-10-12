#include <iostream>
#include "enum.h"

MAKE_ENUM(Fruit, Apple, Banana, Orange)

int main(int argc, const char * argv[])
{
    std::cout << Fruit::as_string(Fruit::Apple) << std::endl;
    std::cout << Fruit::as_string(Fruit::Banana) << std::endl;
    
    std::cout << (Fruit::Banana == Fruit::from_string("Banana") ? "Banana" : "undefined") << std::endl;
    std::cout << (Fruit::undefined == Fruit::from_string("Cat") ? "Cat is not defined" : "Cat is defined") << std::endl;
    
    return 0;
}
