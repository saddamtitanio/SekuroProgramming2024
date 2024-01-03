#include <iostream>

int main(){
    int a = 10;
    int b = 20;
    int* pa = &a;
    int* pb = &b;
    int** ppa = &pa;
    int** ppb = &pb;
    // Asumsikan address dari a adalah 0x111111
    // Asumsikan address dari b adalah 0x222222
    // Asumsikan address dari pa adalah 0x333333
    // Asumsikan address dari pb adalah 0x444444

    // Mengakses data yang disimpan di variabel a yang telah diinisiasikan saat pembuatan variabel a
    std::cout<<a<<std::endl;

    // Print alamat dari variabel a yang diasumsikan adalah 0x111111. Penggunaan '&' operator sebagai cara untuk mengakses alamat memori dimana variabel tersebut disimpan dalam memori komputer
    std::cout<<&a<<std::endl;

    // Print value dari variabel pb yang menyimpan alamat dari variabel b dengan menggunkan '&' operator
    std::cout<<pb<<std::endl;

    // Variabel ppa adalah pointer-to-pointer (**) yang menyimpan alamat dari pointer pa
    std::cout<<ppa<<std::endl;

    // Output dari *pa adalah nilai yang disimpan pada alamat memori yang disimpan oleh pointer pa
    std::cout<<*pa<<std::endl;

    // Output dari *ppb adalah nilai dari variabel pb, yaitu alamat memori variabel b dengan menggunkan dereference (*) operator
    std::cout<<*ppb<<std::endl;

    // Output dari **ppa adalah nilai dari variabel pb, yaitu alamat memori variabel b dengan menggunkan dereference (*) operator
    std::cout<<**ppa<<std::endl;

    // Mengalikan nilai yang disimpan pada alamat memori yang ditunjuk oleh pointer pb dengan nilai yang disimpan pada alamat memori yang ditunjuk oleh pointer-to-pointer ppb
    std::cout << *pb * **ppb << std::endl;

}
