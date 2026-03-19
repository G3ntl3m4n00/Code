#include <iostream>

int
main ()
{
    int a, r, n;
    std::cin >> a >> r >> n;

    for (int i = 0; i < n; i++)
        std::cout << a + r * i << " ";
    std::cout << std::endl;
}
