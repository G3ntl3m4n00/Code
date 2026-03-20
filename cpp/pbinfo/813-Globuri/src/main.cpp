#include <iostream>

int
main ()
{
    unsigned short a;
    std::cin >> a;

    std::cout << a + (a * 2) + ((a * 2) - 3) << std::endl;
}
