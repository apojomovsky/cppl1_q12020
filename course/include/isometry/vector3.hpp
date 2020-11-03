/*
 * Isometry library
 * Copyright 2020 Ekumen Inc.
 * Author: Alexis Pojomovsky, 2020
 */

#pragma once

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <string>

namespace ekumen {

namespace math {

/**
 * This class is used to represent a 3-dimensional vector of doubles.
 */
class Vector3 {
 public:
  /// \brief Default constructor.
  Vector3();

  /// \brief Constructor parametrized with 3 doubles.
  Vector3(const double x, const double y, const double z);

  /// \brief Constructor parametrized with an initializer list.
  /// \throw std::out_of_range When size of initializer list is different to 3.
  explicit Vector3(std::initializer_list<double> list);

  /// \brief Const implementation of the sum operator.
  Vector3 operator+(const Vector3& vector) const;

  /// \brief Const implementation of the sub operator.
  Vector3 operator-(const Vector3& vector) const;

  /// \brief Const implementation of the mult operator.
  Vector3 operator*(const Vector3& vector) const;

  /// \brief Const implementation of the mult times double operator.
  Vector3 operator*(double scalar) const;

  /// \brief Const implementation of the over integer operator.
  Vector3 operator/(const Vector3& vector) const;

  /// \brief Const implementation of the mult times double operator.
  Vector3 operator/(double scalar) const;

  /// \brief Non const implementation of the plus assign operator.
  Vector3& operator+=(const Vector3& vector);

  /// \brief Non const implementation of the minus assign operator.
  Vector3& operator-=(const Vector3& vector);

  /// \brief Non const implementation of the mult times vector assign operator.
  Vector3& operator*=(const Vector3& vector);

  /// \brief Non const implementation of the mult times double assign operator.
  Vector3& operator*=(const double scalar);

  /// \brief Non const implementation of the divide over vector assign operator.
  Vector3& operator/=(const Vector3& vector);

  /// \brief Non const implementation of the divide over double assign operator.
  Vector3& operator/=(const double scalar);

  /// \brief Equals to operator.
  bool operator==(const Vector3& vector) const;

  /// \brief Non-equals to operator.
  bool operator!=(const Vector3& vector) const;

  /// \brief Const implementation of the [] accessor.
  /// \return An rval copy of the requested field.
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  double operator[](const int index) const;

  /// \brief Non-const implementation of the [] accessor.
  /// \return A mutable reference to the requested field.
  /// \throw std::out_of_range When `index` is less than 0 or greater than 2.
  double& operator[](const int index);

  /// \brief Dot product between this and a given vector.
  double dot(const Vector3& vector) const;

  /// \brief Cross product between this and a given vector.
  Vector3 cross(const Vector3& vector) const;

  /// \brief Calculates the norm of this vector.
  /// \return The norm of the vector.
  double norm() const;

  /// \brief Getter of x.
  /// \return An rval copy of x.
  double x() const;

  /// \brief Getter of y.
  /// \return An rval copy of y.
  double y() const;

  /// \brief Getter of z.
  /// \return An rval copy of z.
  double z() const;

  /// \brief Getter of x.
  /// \return A mutable reference to x.
  double& x();

  /// \brief Getter of y.
  /// \return A mutable reference to y.
  double& y();

  /// \brief Getter of z.
  /// \return A mutable reference to z.
  double& z();

  // Null vector.
  static const Vector3 kZero;

  // Unit vectors along the 3 axis.
  static const Vector3 kUnitX;
  static const Vector3 kUnitY;
  static const Vector3 kUnitZ;

 private:
  // X value.
  double x_;

  // Y value.
  double y_;

  // Z value.
  double z_;
};

/// \brief Free function implementation of the operator*
Vector3 operator*(double scalar, const Vector3& vector);

/// \brief Free function implementation of the operator<<
std::ostream& operator<<(std::ostream& os, const Vector3& vector);

}  // namespace math
}  // namespace ekumen
