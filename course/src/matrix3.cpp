/*
 * Isometry library
 * Copyright 2020 Ekumen Inc.
 * Author: Alexis Pojomovsky, 2020
 */

#include <isometry/matrix3.hpp>
#include <limits>
#include <stdexcept>

namespace ekumen {
namespace math {

const Matrix3 Matrix3::kIdentity{Matrix3(1., 0., 0., 0., 1., 0., 0., 0., 1.)};
const Matrix3 Matrix3::kOnes{Matrix3(1., 1., 1., 1., 1., 1., 1., 1., 1.)};
const Matrix3 Matrix3::kZero{Matrix3(0., 0., 0., 0., 0., 0., 0., 0., 0.)};

Matrix3::Matrix3()
    : row_0_{0., 0., 0.}, row_1_{0., 0., 0.}, row_2_{0., 0., 0.} {}

Matrix3::Matrix3(const double a1, const double a2, const double a3,
                 const double b1, const double b2, const double b3,
                 const double c1, const double c2, const double c3)
    : row_0_{a1, a2, a3}, row_1_{b1, b2, b3}, row_2_{c1, c2, c3} {}

bool Matrix3::operator==(const Matrix3& matrix) const {
  return row_0_ == matrix[0] && row_1_ == matrix[1] && row_2_ == matrix[2];
}

bool Matrix3::operator!=(const Matrix3& matrix) const {
  return !(*this == matrix);
}

Vector3 Matrix3::operator[](const int index) const {
  switch (index) {
    case 0:
      return row_0_;
    case 1:
      return row_1_;
    case 2:
      return row_2_;
    default:
      throw std::out_of_range("Matrix3 has only 3 elements");
  }
}

Vector3& Matrix3::operator[](const int index) {
  switch (index) {
    case 0:
      return row_0_;
    case 1:
      return row_1_;
    case 2:
      return row_2_;
    default:
      throw std::out_of_range("Matrix3 has only 3 elements");
  }
}

std::ostream& operator<<(std::ostream& os, const Matrix3& matrix) {
  os << "[[" << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2]
     << "], [" << matrix[1][0] << ", " << matrix[1][1] << ", " << matrix[1][2]
     << "], [" << matrix[2][0] << ", " << matrix[2][1] << ", " << matrix[2][2]
     << "]]";
  return os;
}

Matrix3& Matrix3::operator+=(const Matrix3& matrix) {
  row_0_ += matrix[0];
  row_1_ += matrix[1];
  row_2_ += matrix[2];
  return *this;
}

Matrix3& Matrix3::operator-=(const Matrix3& matrix) {
  row_0_ -= matrix[0];
  row_1_ -= matrix[1];
  row_2_ -= matrix[2];
  return *this;
}

Matrix3& Matrix3::operator*=(const Matrix3& matrix) {
  row_0_ *= matrix[0];
  row_1_ *= matrix[1];
  row_2_ *= matrix[2];
  return *this;
}

Matrix3& Matrix3::operator*=(const double scalar) {
  row_0_ *= scalar;
  row_1_ *= scalar;
  row_2_ *= scalar;
  return *this;
}

Matrix3& Matrix3::operator/=(const Matrix3& matrix) {
  row_0_ /= matrix[0];
  row_1_ /= matrix[1];
  row_2_ /= matrix[2];
  return *this;
}

Matrix3& Matrix3::operator/=(const double scalar) {
  row_0_ /= scalar;
  row_1_ /= scalar;
  row_2_ /= scalar;
  return *this;
}

Matrix3 Matrix3::operator+(const Matrix3& matrix) const {
  Matrix3 aux{*this};
  aux += matrix;
  return aux;
}

Matrix3 Matrix3::operator-(const Matrix3& matrix) const {
  Matrix3 aux{*this};
  aux -= matrix;
  return aux;
}

Matrix3 Matrix3::operator*(const Matrix3& matrix) const {
  Matrix3 aux{*this};
  aux *= matrix;
  return aux;
}

Vector3 Matrix3::operator*(const Vector3& vector) const {
  return {row_0_.dot(vector), row_1_.dot(vector), row_2_.dot(vector)};
}

Matrix3 Matrix3::operator*(const double scalar) const {
  Matrix3 aux{*this};
  aux *= scalar;
  return aux;
}

Matrix3 operator*(double scalar, const Matrix3& matrix) {
  return matrix * scalar;
}

Matrix3 Matrix3::operator/(const Matrix3& matrix) const {
  Matrix3 aux{*this};
  aux /= matrix;
  return aux;
}

Matrix3 Matrix3::operator/(const double scalar) const {
  Matrix3 aux{*this};
  aux /= scalar;
  return aux;
}

double Matrix3::det() const {
  return row_0_[0] * (row_1_[1] * row_2_[2] - row_1_[2] * row_2_[1]) -
         row_0_[1] * (row_1_[0] * row_2_[2] - row_1_[2] * row_2_[0]) +
         row_0_[2] * (row_1_[0] * row_2_[1] - row_1_[1] * row_2_[0]);
}

Vector3& Matrix3::row(const int index) { return (*this)[index]; }

Vector3 Matrix3::row(const int index) const { return (*this)[index]; }

Vector3 Matrix3::col(const int index) const {
  return Vector3{row_0_[index], row_1_[index], row_2_[index]};
}

}  // namespace math
}  // namespace ekumen
