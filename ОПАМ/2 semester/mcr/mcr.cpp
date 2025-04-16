#include <iostream>

char bilOrmen(int a, int b) {
    if (a > b) return '>';
    if (a < b) return '<';
    else return '=';
}

int main ()
{
    std::cout << bilOrmen(2, 4) << std::endl;
    std::cout << bilOrmen(4, 4) << std::endl;

    return 0;
}