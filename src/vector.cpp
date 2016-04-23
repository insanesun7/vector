#include <vector.h>

Vector::Vector() {
    for (unsigned long i = 0; i < n; i++) {
        coords_[i] = 0;
    }
}

Vector::Vector(double number) {
    for (unsigned long i = 0; i < n; i++) {
        coords_[i] = number;
    }
}

Vector::Vector(const Vector &object) {
    for (unsigned long i = 0; i < n; i++) {
        coords_[i] = object.coords_[i];
    }
}

Vector &Vector::operator=(const Vector &object) {
    for (unsigned long i = 0; i < n; i++) {
        coords_[i] = object.coords_[i];
    }
    return *this;
}

double Vector::operator[](unsigned long i) const {
    return coords_[i];
}

double &Vector::operator[](unsigned long i) {
    return coords_[i];
}



Vector &Vector::operator+=(const Vector &object) {
    for (unsigned long i = 0; i < n; i++)
        coords_[i] += object.coords_[i];
    return *this;
}

Vector &Vector::operator-=(const Vector &object) {
    for (unsigned long i = 0; i < n; i++)
        coords_[i] -= object.coords_[i];
    return *this;
}

Vector &Vector::operator*=(double number) {
    for (unsigned long i = 0; i < n; i++)
        coords_[i] *= number;
    return *this;
}

Vector &Vector::operator/=(double number) {
    for (unsigned long i = 0; i < n; i++)
        coords_[i] /= number;
    return *this;
}

bool operator==(const Vector &lhs, const Vector &rhs) {
    for (unsigned long i = 0; i < Vector::n; i++) {
        if (lhs.coords_[i] != rhs.coords_[i]) {
            return false;
        }
    }
    return true;
}

Vector operator+(const Vector &lhs, const Vector &rhs) {
    Vector new_vector(lhs);
    new_vector += rhs;
    return new_vector;
}

Vector operator-(const Vector &lhs, const Vector &rhs) {
    Vector new_vector(lhs);
    new_vector -= rhs;
    return new_vector;
}

Vector operator*(const Vector &lhs, double number) {
    Vector new_vector(lhs);
    new_vector *= number;
    return new_vector;
}

Vector operator*(double number, const Vector &rhs) {
    Vector new_vector(rhs);
    new_vector *= number;
    return new_vector;
}

Vector operator/(const Vector &lhs, double number) {
    Vector new_vector(lhs);
    new_vector /= number;
    return new_vector;
}

double operator^(const Vector &lhs, const Vector &rhs) {
    double result = 0;
    for (unsigned long i = 0; i < Vector::n; i++) {
        result += lhs.coords_[i] * rhs.coords_[i];
    }
    return result;
}

Vector Vector::operator-() const {
    Vector new_vector(*this);
    new_vector*=-1;
    return new_vector;
}


bool operator!=(const Vector &lhs, const Vector &rhs) {
    return !(lhs == rhs);
}