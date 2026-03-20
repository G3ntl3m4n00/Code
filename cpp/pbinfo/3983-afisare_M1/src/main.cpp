#include <iostream>

int
main ()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = n * m; i >= m; i -= m)
        std::cout << i << " ";
    std::cout << std::endl;
}
