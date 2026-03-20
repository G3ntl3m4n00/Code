#include <iostream>

int
main ()
{
    int x, y;

    std::cin >> x >> y;

    // Dividing with rounding up
    std::cout << (y + x - 1) / x << std::endl;
}
