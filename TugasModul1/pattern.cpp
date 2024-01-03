#include <iostream>

int main(void) {
    int n;

    std::cin >> n;

    for (int i = 1; i <= (2 * n) - 1; i++) {
        int jumlahBintang = i <= n ? i : (2 * n) - i;

        for (int j = 0; j < jumlahBintang; j++) {
            std::cout << "*";
        }
        std::cout << '\n';
    }
    
    return 0;
}