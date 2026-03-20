#include <iostream>

int
main ()
{
    unsigned short n;
    std::cin >> n;

    for (unsigned short i = 2; i <= 2 * n; i += 2)
        std::cout << i << " ";
    std::cout << std::endl;
}
