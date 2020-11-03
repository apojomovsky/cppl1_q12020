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

#include <isometry/matrix3.hpp>
#include <isometry/vector3.hpp>

namespace ekumen {

namespace math {

/**
 * This class is used to represent isometric transformations among vectors and
 * matrices.
 */
class Isometry {
 public:
  /// \brief Default constructor
  Isometry();

  /// \brief Constructs an Isometry object from a translation vector and a
  /// rotation matrix.
  /// \param translation A translation vector.
  /// \param rotation A rotation matrix.
  Isometry(const Vector3& translation, const Matrix3& rotation);

  /// \brief Constructs an Isometry object based on an existing instance.
  /// \param obj A reference to an existing Isometry object.
  Isometry(const Isometry& obj);

  /// \brief Creates an Isometry object from within a translation vector.
  /// \param vector A translation vector.
  /// \returns An new Isometry object.
  static Isometry fromTranslation(const Vector3& vector);

  /// \brief Creates an Isometry object from a rotation around a vector.
  /// \param vector Axis vector.
  /// \param radians Number of radians to rotate along the given vector.
  /// \returns An new Isometry object.
  static Isometry rotateAround(const Vector3& vector, const double radians);

  /// \brief Creates an Isometry object from given euler angles.
  /// \param roll Roll angle in radians.
  /// \param pitch Pitch angle in radians.
  /// \param yaw Yaw angle in radians.
  /// \returns An new Isometry object.
  static Isometry fromEulerAngles(const double roll, const double pitch,
                                  const double yaw);

  /// \brief Applies an isometric transformation to a given vector.
  /// \param vector A Vector3.
  /// \returns A new Vector3.
  Vector3 transform(const Vector3& vector) const;

  /// \brief Translation getter.
  Vector3& translation();

  /// \brief Const implementation of the translation getter.
  const Vector3& translation() const;

  /// \brief Rotation getter.
  Matrix3& rotation();

  /// \brief Const implementation of the rotation getter.
  const Matrix3& rotation() const;

  /// \brief Calculates the inverse of the current Isometry.
  /// \returns A new Isometry object.
  Isometry inverse() const;

  /// \brief Calculates a new Isometry based on two others.
  /// \param isometry Isometry to compose with.
  /// \returns The newly composed Isometry object.
  Isometry compose(const Isometry& isometry) const;

  /// \brief Assignement operator.
  Isometry& operator=(const Isometry& isometry);

  /// \brief Equality operator.
  bool operator==(const Isometry& isometry) const;

  /// \brief Product-equal operator.
  Isometry& operator*=(const Isometry& isometry);

  /// \brief Product operator between Isometry and vector.
  /// \returns A new Vector3.
  Vector3 operator*(const Vector3& vector) const;

  /// \brief Product operator.
  /// \returns A new Isometry.
  Isometry operator*(const Isometry& isometry) const;

 private:
  /// \brief Rotation matrix.
  Matrix3 rotation_;

  /// \brief Translation vector.
  Vector3 translation_;
};

/// \brief Free function implementation of the output stream operator.
/// \param os ToDo.
/// \param isometry ToDo.
std::ostream& operator<<(std::ostream& os, const Isometry& isometry);

}  // namespace math
}  // namespace ekumen
