// complexnumber.h
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class ComplexNumber {
public:
    ComplexNumber(double real, double imaginary);

    double getReal() const; // Getter for real part
    double getImaginary() const; // Getter for imaginary part

    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;

    std::string toString() const; // Function to convert to string
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& num);

private:
    double real_;
    double imaginary_;
};

#endif // COMPLEXNUMBER_H
