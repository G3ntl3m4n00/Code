#include <fstream>
#include <iostream>

int
readFromFile ()
{
    std::ifstream inputFile ("file.in");

    int x;

    inputFile >> x;

    return x;
}

int
main ()
{
    int x;
    std::cout << "Hello World" << std::endl;
    std::cin >> x;
    std::cout << x << std::endl;

    std::cout << readFromFile () << std::endl;
    return 0;
}
