#include <iostream>

int main(void) {
    int n;
    
    std::cout << "Input satu angka bulat: ";
    std::cin >> n;

    bool isPrime = true;

    for (int i = 2; i <= n / 2 && isPrime; i++) {
        if (n % i == 0) {
            isPrime = false;
        }
    }

    if (isPrime && n > 1) {
        std::cout << n << " adalah angka prima\n";
    }
    else {
        std::cout << n << " bukan angka prima\n";
    }

    return 0;
}