#include <algorithm>
#include <iostream>
#include <string>

int
main ()
{
    int a, b;
    std::cin >> a >> b;

    std::string sa = std::to_string (a);
    std::string sb = std::to_string (b);

    std::sort (sa.begin (), sa.end ());
    std::sort (sb.begin (), sb.end ());

    std::cout << (sa == sb ? "DA" : "NU") << std::endl;
}
