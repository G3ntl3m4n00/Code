#include <iostream>

int
main ()
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
        if (i % 2 == 0)
            std::cout << i << " ";
    std::cout << std::endl;

    for (int i = 1; i <= n; i++)
        if (i % 3 == 0)
            std::cout << i << " ";
    std::cout << std::endl;

    for (int i = 1; i <= n; i++)
        if ((i % 2 == 0 or i % 3 == 0) and i % 6 != 0)
            std::cout << i << " ";
    std::cout << std::endl;
}
