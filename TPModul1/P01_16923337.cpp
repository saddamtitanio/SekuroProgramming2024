#include <iostream>

int main(void) {
    // 
    char pesawat;
    do
    {
        // Mendapatkan input
        std::cout << "Jenis pesawat: ";
        std::cin >> pesawat;

        // Cek tipe pesawat
        if (pesawat == 'a') {
            for (int i = 5; i > 0; i--) {
                std::cout << i << '\n';
            }
            std::cout << "PESAWAT A BERANGKAT" << '\n';

            // Untuk terminasi loop
            pesawat = 'o';
        }
        else if (pesawat == 'b') {
            for (int i = 3; i > 0; i--) {
                std::cout << i << '\n';
            }
            std::cout << "PESAWAT B BERANGKAT" << '\n';
            pesawat = 'o';
        }
        else if (pesawat != 'o') {
            std::cout << "INPUT TIDAK VALID" << '\n';
        }

    } while (pesawat != 'o');
    
    if (pesawat == 'o') {
        std::cout << "PENERBANGAN DITUTUP";
    }

    return 0;   
}