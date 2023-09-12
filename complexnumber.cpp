// complexnumber.cpp
#include "complexnumber.h"
#include <string> // Include the <string> header

ComplexNumber::ComplexNumber(double real, double imaginary)
    : real_(real), imaginary_(imaginary) {}

double ComplexNumber::getReal() const {
    return real_;
}

double ComplexNumber::getImaginary() const {
    return imaginary_;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(real_ + other.getReal(), imaginary_ + other.getImaginary());
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(real_ - other.getReal(), imaginary_ - other.getImaginary());
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    double resultReal = (real_ * other.getReal()) - (imaginary_ * other.getImaginary());
    double resultImaginary = (real_ * other.getImaginary()) + (imaginary_ * other.getReal());
    return ComplexNumber(resultReal, resultImaginary);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    double denominator = (other.getReal() * other.getReal()) + (other.getImaginary() * other.getImaginary());
    double resultReal = ((real_ * other.getReal()) + (imaginary_ * other.getImaginary())) / denominator;
    double resultImaginary = ((imaginary_ * other.getReal()) - (real_ * other.getImaginary())) / denominator;
    return ComplexNumber(resultReal, resultImaginary);
}

std::string ComplexNumber::toString() const {
    return std::to_string(real_) + " + " + std::to_string(imaginary_) + "i";
}
std::ostream& operator<<(std::ostream& os, const ComplexNumber& num) {
    os << num.getReal() << " + " << num.getImaginary() << "i";
    return os;
}
