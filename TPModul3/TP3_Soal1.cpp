#include <iostream>
class LinearLine
{
private:
    // empat float data type, yaitu x1, y1, x2, dan y2
    float x1;
    float x2;
    float y1;
    float y2;
public:
    LinearLine (float x1, float y1, float x2, float y2) {
        // Isilah definisi constructor ini dengan tujuan untuk
        // menginisialisasi data member
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    float gradient() {
        // hitunglah gradient berdasarkan 4 titik tersebut
        return (this->y2 - this->y1) / (this->x2 -this->x1);
    }
    float y_intercept() {
        return this->y2 - (this->gradient() * this->x2);
    }
    void operator + (float a) {
        // Buatlah operator overloading untuk menggeser garis linear
        // sejauh a pada arah sumbu x
        this->x1 += a;
        this->x2 += a;

    }
    void printEquation() {
        float m = gradient();
        float c = y_intercept();

        std::cout << "y = " << m << "x + " << c << '\n';  
    } 
    void printPoints() {
        std::cout << "(x1, y1) = (" << this->x1 << ", " << this->y1 << ")\n"
          << "(x2, y2) = (" << this->x2 << ", " << this->y2 << ")\n";
    } 
};

int main()
{
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f); // inisialisasi objek line
    int a = 3; // nilai banyaknya penggeseran pada persamaan linear
    /*
    lengkapilah fungsi main sehingga output program seperti pada contoh di bawah
    (x1, y1) = (1, 8)
    (x2, y2) = (2, 3)
    Sehingga didapatkan
    gradient = -5
    y_intercept = 13
    y = -5 x + 13
    Setelah digeser sejauh a, didapatkan persamaan baru:
    y = -5 x + 28
    */
    line.printPoints();
    std::cout << "Sehingga didapatkan\n";
    std::cout << "gradient = " << line.gradient() << '\n';
    std::cout << "y_intercept = " << line.y_intercept() << '\n';
    line.printEquation();

    std::cout << "Setelah digeser sejauh" << a << ", didapatkan persamaan baru:\n";
    line.operator+(a);
    line.printEquation();

}
