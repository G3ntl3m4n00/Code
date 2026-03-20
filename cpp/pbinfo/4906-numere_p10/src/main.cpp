#include <iostream>

/*
 * #4906 - numere_p10
 *
 */

int
main ()
{
    int n{};
    std::cin >> n;

    int numere_p10{};

    for (int i = 0; i < n; i++)
        {
            int a;
            std::cin >> a;

            if (a > 9 && a < 1000000)
                {
                    int temp = a;

                    while (temp % 10 == 0)
                        temp /= 10;

                    if (temp == 1)
                        numere_p10++;
                }
        }

    std::cout << numere_p10 << std::endl;
}
