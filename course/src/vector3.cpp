/*
 * Isometry library
 * Copyright 2020 Ekumen Inc.
 * Author: Alexis Pojomovsky, 2020
 */

#include <isometry/vector3.hpp>
#include <limits>
#include <stdexcept>

namespace ekumen {
namespace math {

const Vector3 Vector3::kZero{Vector3(0., 0., 0.)};
const Vector3 Vector3::kUnitX{Vector3(1., 0., 0.)};
const Vector3 Vector3::kUnitY{Vector3(0., 1., 0.)};
const Vector3 Vector3::kUnitZ{Vector3(0., 0., 1.)};

Vector3::Vector3() : x_{0.}, y_{0.}, z_{0.} {}

Vector3::Vector3(const double x, const double y, const double z)
    : x_{x}, y_{y}, z_{z} {}

Vector3 Vector3::operator+(const Vector3& vector) const {
  Vector3 aux{*this};
  aux += vector;
  return aux;
}

Vector3 Vector3::operator-(const Vector3& vector) const {
  Vector3 aux{*this};
  aux -= vector;
  return aux;
}

Vector3 Vector3::operator*(const Vector3& vector) const {
  Vector3 aux{*this};
  aux *= vector;
  return aux;
}

Vector3 Vector3::operator*(double scalar) const {
  Vector3 aux{*this};
  aux *= scalar;
  return aux;
}

Vector3 operator*(double scalar, const Vector3& vector) {
  return vector * scalar;
}

Vector3 Vector3::operator/(const Vector3& vector) const {
  Vector3 aux{*this};
  aux /= vector;
  return aux;
}

Vector3 Vector3::operator/(double scalar) const {
  Vector3 aux{*this};
  aux /= scalar;
  return aux;
}

Vector3& Vector3::operator+=(const Vector3& vector) {
  x_ += vector.x();
  y_ += vector.y();
  z_ += vector.z();
  return *this;
}

Vector3& Vector3::operator-=(const Vector3& vector) {
  x_ -= vector.x();
  y_ -= vector.y();
  z_ -= vector.z();
  return *this;
}

Vector3& Vector3::operator*=(const Vector3& vector) {
  x_ *= vector.x();
  y_ *= vector.y();
  z_ *= vector.z();
  return *this;
}

Vector3& Vector3::operator*=(const double scalar) {
  x_ *= scalar;
  y_ *= scalar;
  z_ *= scalar;
  return *this;
}

Vector3& Vector3::operator/=(const Vector3& vector) {
  x_ /= vector.x();
  y_ /= vector.y();
  z_ /= vector.z();
  return *this;
}

Vector3& Vector3::operator/=(const double scalar) {
  x_ /= scalar;
  y_ /= scalar;
  z_ /= scalar;
  return *this;
}

bool Vector3::operator==(const Vector3& vector) const {
  return std::fabs(x_ - vector.x()) <= std::numeric_limits<double>::epsilon() &&
         std::fabs(y_ - vector.y()) <= std::numeric_limits<double>::epsilon() &&
         std::fabs(z_ - vector.z()) <= std::numeric_limits<double>::epsilon();
}

bool Vector3::operator!=(const Vector3& vector) const {
  return !(*this == vector);
}

double Vector3::operator[](const int index) const {
  switch (index) {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
    default:
      throw std::out_of_range("Vector3 has only 3 elements");
  }
}

double& Vector3::operator[](const int index) {
  switch (index) {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
    default:
      throw std::out_of_range("Vector3 has only 3 elements");
  }
}

std::ostream& operator<<(std::ostream& os, const Vector3& vector) {
  os << "(x: " << vector.x() << ", y: " << vector.y() << ", z: " << vector.z()
     << ")";
  return os;
}

double Vector3::dot(const Vector3& vector) const {
  return x() * vector.x() + y() * vector.y() + z() * vector.z();
}

Vector3 Vector3::cross(const Vector3& vector) const {
  return Vector3{y_ * vector.z() - z_ * vector.y(),
                 z_ * vector.x() - x_ * vector.z(),
                 x_ * vector.y() - y_ * vector.x()};
}

double Vector3::norm() const { return sqrt(dot(*this)); }

double Vector3::x() const { return x_; }

double Vector3::y() const { return y_; }

double Vector3::z() const { return z_; }

double& Vector3::x() { return x_; }

double& Vector3::y() { return y_; }

double& Vector3::z() { return z_; }

}  // namespace math
}  // namespace ekumen
