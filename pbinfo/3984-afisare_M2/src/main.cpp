#include <iostream>

int
main ()
{
    unsigned short a, b;
    std::cin >> a >> b;

    for (int i = 1; i <= b; i++)
        std::cout << i * a << " ";
    std::cout << std::endl;
}
