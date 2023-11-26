#include <iostream>

class Shape
{
    private:
    float area;
    float keliling;
    public:
    // gunakan virtual function
    virtual float calculateArea() { return 0; }
    virtual float calculateKeliling() { return 0; }
};

// Buatlah class Rectangle sebagai turunan dari class Shape
// {
// deklarasikan member data, (float) width dan (float) length
// Buatlah constructor untuk menginisialisasi member!
// Buatlah calculateArea() 
// Buatlah calculateKeliling()
// };

class Rectangle : public Shape {
    private:
        float width;
        float length;
    public:
        Rectangle (float width, float length) {
            this->width = width;
            this->length = length;
        } 
        float calculateArea() {
            return this->width * this->length;
        }
        float calculateKeliling() {
            return 2 * (this->width + this->length);
        }
};

int main()
{
    Rectangle rect (5.0, 4.0);
    Shape* shape1 = &rect;

    std::cout << "Area: " << shape1->calculateArea() << '\n';
    std::cout << "Keliling: " << shape1->calculateKeliling() << '\n';
    // dengan menggunakan pointer shape1, panggillah
    // function calculateArea() dan calculateKeliling() pada class Rectangle
    // PERIKSA HASILNYA BENAR ATAU SALAH? Jika salah maka perbaikilah base class-nya
    return 0;
}