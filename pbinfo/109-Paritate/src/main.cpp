#include <iostream>

int
main ()
{
    int n;

    std::cin >> n;

    if (n % 2 == 0)
        std::cout << n << " este par" << std::endl;
    else
        std::cout << n << " este impar" << std::endl;
}
