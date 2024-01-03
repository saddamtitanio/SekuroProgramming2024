#include <iostream>

int main(void) {
    int a, b;

    do {
        std::cin >> a >> b;
        if (b < a) {
            std::cout << "Input b tidak bisa lebih kecil dari a\n";
        }

    } while (b < a);
    
    for (int i = (a % 2 == 0 ? a : a + 1); i <= b; i+=2) {
        std::cout << i << '\n';
    }

    return 0;
}