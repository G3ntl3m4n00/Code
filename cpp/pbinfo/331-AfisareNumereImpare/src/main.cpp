#include <iostream>

int
main ()
{
    int n;
    std::cin >> n;

    for (int i = 2 * n - 1; i >= 1; i -= 2)
        std::cout << i << " ";
    std::cout << std::endl;
}
