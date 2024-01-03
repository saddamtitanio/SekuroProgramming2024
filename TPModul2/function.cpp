#include <iostream>

float luas(float r) {
    return r * r * 3.14;
}

int main(void) {
    float radius;

    std::cout << "Radius: ";
    std::cin >> radius;

    std::cout << "Luas lingkaran: " << luas(radius) << '\n';

    return 0;
}