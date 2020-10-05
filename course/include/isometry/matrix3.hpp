/*
 * Isometry library
 * Copyright 2020 Ekumen Inc.
 * Author: Alexis Pojomovsky, 2020
 */

#pragma once

#include <isometry/vector3.hpp>

namespace ekumen {
namespace math {

/**
 * This class is used to represent a 3x3 matrix of doubles.
 */
class Matrix3 {
 public:
  /// \brief Default constructor.
  Matrix3();

  /// Constructs a 3-dimensional matrix from a list of doubles.
  /// \param a1 First row, first column element.
  /// \param a2 First row, second column element.
  /// \param a3 First row, third column element.
  /// \param b1 Second row, first column element.
  /// \param b2 Second row, second column element.
  /// \param b3 Second row, third column element.
  /// \param c1 Third row, first column element.
  /// \param c2 Third row, second column element.
  /// \param c3 Third row, third column element.
  Matrix3(const double a1, const double a2, const double a3, const double b1,
          const double b2, const double b3, const double c1, const double c2,
          const double c3);

  // Constant matrices
  static const Matrix3 kIdentity;
  static const Matrix3 kOnes;
  static const Matrix3 kZero;

  /// \brief Equals to operator.
  /// \returns A bool indicating equality.
  bool operator==(const Matrix3& matrix) const;

  /// \brief Non-equals to operator.
  /// \returns A bool indicating non equality.
  bool operator!=(const Matrix3& matrix) const;

  /// \brief Const implementation of the [] accessor.
  /// \returns An rval copy of the requested row vector.
  ///
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  Vector3 operator[](const int index) const;

  /// \brief Non-const implementation of the [] accessor.
  /// \returns A mutable reference to the requested row vector.
  ///
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  Vector3& operator[](const int index);

  /// \brief Non const implementation of the plus assign operator.
  Matrix3& operator+=(const Matrix3& matrix);

  /// \brief Non const implementation of the minus assign operator.
  Matrix3& operator-=(const Matrix3& matrix);

  /// \brief Non const implementation of the mult times matrix assign operator.
  Matrix3& operator*=(const Matrix3& matrix);

  /// \brief Non const implementation of the mult times double assign operator.
  Matrix3& operator*=(const double scalar);

  /// \brief Non const implementation of the divide over matrix assign operator.
  Matrix3& operator/=(const Matrix3& matrix);

  /// \brief Non const implementation of the divide over double assign operator.
  Matrix3& operator/=(const double scalar);

  /// \brief Const implementation of the sum operator.
  Matrix3 operator+(const Matrix3& matrix) const;

  /// \brief Const implementation of the sub operator.
  Matrix3 operator-(const Matrix3& matrix) const;

  /// \brief Const implementation of the mult times matrix operator.
  Matrix3 operator*(const Matrix3& matrix) const;

  /// \brief Const implementation of the mult times vector operator.
  Vector3 operator*(const Vector3& vector) const;

  /// \brief Const implementation of the mult times double operator.
  Matrix3 operator*(const double scalar) const;

  /// \brief Const implementation of the over integer operator.
  Matrix3 operator/(const Matrix3& matrix) const;

  /// \brief Const implementation of the mult times double operator.
  Matrix3 operator/(const double scalar) const;

  /// \brief Returns the determinant of the matrix.
  /// \returns A double with value of the matrix' determinant.
  double det() const;

  /// \brief Returns a reference to a row.
  /// \param index Row number.
  /// \returns A Vector3.
  ///
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  Vector3& row(const int index);

  /// \brief Const implementation of the row accessor.
  /// \param index Row number.
  /// \returns A Vector3.
  ///
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  Vector3 row(const int index) const;

  /// \brief Const implementation of the column accessor.
  /// \param index Column number.
  /// \returns A Vector3.
  ///
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  Vector3 col(const int index) const;

 private:
  Vector3 row_0_;
  Vector3 row_1_;
  Vector3 row_2_;
};

/// \brief Free function implementation of the operator*
Matrix3 operator*(double scalar, const Matrix3& matrix);

/// \brief Free function implementation of the operator<<
std::ostream& operator<<(std::ostream& os, const Matrix3& matrix);

}  // namespace math
}  // namespace ekumen
