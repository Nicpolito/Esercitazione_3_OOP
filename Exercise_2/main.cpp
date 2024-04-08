#include <iostream>

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // Constructor
    ComplexNumber(double r, double i) : real(r), imag(i) {}

    // Overloading the output stream operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);

    // Overloading the addition operator
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Overloading the equality operator
    bool operator==(const ComplexNumber& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Function to compute the conjugate of the complex number
    ComplexNumber conjugate() const {
        return ComplexNumber(real, -imag);
    }
};

// Definition of the overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << c.real;
    if (c.imag >= 0)
        os << "+";
    os << c.imag << "i";
    return os;
}

int main() {
    ComplexNumber a(1, 2);
    ComplexNumber b(1, -2);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    ComplexNumber sum = a + b;
    std::cout << "Sum: " << sum << std::endl;

    if (a == b)
        std::cout << "a is equal to b" << std::endl;
    else
        std::cout << "a is not equal to b" << std::endl;

    std::cout << "Conjugate of a: " << a.conjugate() << std::endl;
    std::cout << "Conjugate of b: " << b.conjugate() << std::endl;

    return 0;
}
