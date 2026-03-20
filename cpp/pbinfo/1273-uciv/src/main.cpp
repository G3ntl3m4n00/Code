#include <iostream>

int
main ()
{
    int x, y;
    std::cin >> x >> y;

    std::cout << (x + y) % 10 << std::endl;
}
