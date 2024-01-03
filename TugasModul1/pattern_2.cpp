#include <iostream>

int main(void) {
    int n;
    int count = 0; 

    do {
        std::cout << "N = ";
        std::cin >> n;

    } while (n < 0);

    
    for (int i = 0; i < n; i++) {
        int column = i <= (n / 2) ? (n / 2) + 1 - i : i - (n / 2) + 1;
        int spaces = (i <= n / 2) ? i : n / 2;
        
        for (int k = 0; k < spaces; k++) {
            std::cout << " ";
        }

        for (int j = 0; j < column; j++, count++) {
            std::cout << count % 10;
        }
        std::cout << '\n';
    }
    return 0;
}