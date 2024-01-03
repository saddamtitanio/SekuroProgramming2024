#include <iostream>

int main(void) {
    // Initialize and assigning input
    int arr1[10], arr2[10];
    int num;

    for (int i = 0; i < 10; i++) {
        std::cin >> num;
        arr1[i] = num;
    }

    for (int i = 0; i < 10; i++) {
        std::cin >> num;
        arr2[i] = num;
    }

    int arrayElementSum[10];

    for (int i = 0; i < 10; i++) {
        arrayElementSum[i] = arr1[i] + arr2[i];
        std::cout << arrayElementSum[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}