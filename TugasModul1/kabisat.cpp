#include <iostream>

int main(void) {
    int tahun;
    std::cout << "Tahun: ";
    std::cin >> tahun;

    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) {
        std::cout << "Kabisat\n";
    }
    else {
        std::cout << "Bukan Kabisat\n";
    }
    return 0;
}