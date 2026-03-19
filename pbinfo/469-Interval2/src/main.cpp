#include <iostream>

int
main ()
{
    int a, b, x;
    std::cin >> a >> b >> x;
    std::cout << ((a <= x and x <= b) ? "DA" : "NU") << std::endl;
}
