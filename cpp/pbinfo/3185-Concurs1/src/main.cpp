#include <iostream>

int
main ()
{
    int a, b, n;
    std::cin >> a >> b >> n;

    std::cout << (n >= a and n <= b ? "DA" : "NU") << std::endl;
}
