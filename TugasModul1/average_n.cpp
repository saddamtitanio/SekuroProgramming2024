#include <iostream>

int main(void) {
    int n;
    float sum = 0;
    std::cout << "Jumlah bilangan: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        float num;
        std::cout << "Bilangan " << i << ": ";
        std::cin >> num;
        sum += num;
    }

    std::cout << "Rata-rata: " << (sum / n) << "\n";

    return 0;
}