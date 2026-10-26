
#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
   
    Complex()
    {
        real = 0;
        imag = 0;
    }

 
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    // Display function
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }


    Complex operator+(Complex c2)
    {
        return Complex(real + c2.real, imag + c2.imag);
    }

    Complex operator-(Complex c2)
    {
        return Complex(real - c2.real, imag - c2.imag);
    }

    Complex operator*(Complex c2)
    {
        float r = real * c2.real - imag * c2.imag;
        float i = real * c2.imag + imag * c2.real;

        return Complex(r, i);
    }
};

int main()
{
    Complex c1(3, 2);
    Complex c2(1, 7);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    Complex sum = c1 + c2;
    cout << "Addition: ";
    sum.display();

    Complex diff = c1 - c2;
    cout << "Subtraction: ";
    diff.display();

    Complex prod = c1 * c2;
    cout << "Multiplication: ";
    prod.display();

    return 0;
}