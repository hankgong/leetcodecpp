using namespace std;
#include <iostream>

class Complex{
private:
    float real;
    float imag;

public:
    Complex(): real(0), imag(0) {}
    Complex(float i, float j): real(i), imag(j) {};
    
    Complex operator - (Complex c2) {
        Complex temp;
        temp.real = real - c2.real;
        temp.imag = imag - c2.imag;

        return temp;
    }

    friend ostream& operator<<(ostream& os, Complex c) {
        if (c.imag < 0)
            os << c.real << c.imag << "i";
        else
            os << c.real << "+" << c.imag << "i";

        return os;
    }
};


int main(int argc, char const *argv[])
{
    Complex c0;
    Complex c1(1, 2);
    Complex c2(-2.1, 3.2);

    cout << c0 << endl;
    cout << c1 << endl;
    cout << c2 << endl;

    Complex c3 = c1 - c2;

    cout << c1 - c2 << endl;
    return 0;
}