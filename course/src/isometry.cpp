/*
 * Isometry library
 * Copyright 2020 Ekumen Inc.
 * Author: Alexis Pojomovsky, 2020
 */

#include <cmath>
#include <iomanip>

#include <isometry/isometry.hpp>

namespace ekumen {
namespace math {

Isometry::Isometry() : rotation_{Matrix3::kZero}, translation_{Vector3()} {}

Isometry::Isometry(const Vector3& translation, const Matrix3& rotation)
    : rotation_{rotation}, translation_{translation} {}

Isometry::Isometry(const Isometry& obj) = default;

Isometry Isometry::fromTranslation(const Vector3& vector) {
  return Isometry{vector, Matrix3::kIdentity};
}

Isometry Isometry::rotateAround(const Vector3& vector, const double radians) {
  const double ux = vector[0] / vector.norm();
  const double uy = vector[1] / vector.norm();
  const double uz = vector[2] / vector.norm();
  const double cosAngle = cos(radians);
  const double sinAngle = sin(radians);
  Matrix3 rotationMatrix =
      Matrix3(cosAngle + std::pow(ux, 2.) * (1. - cosAngle),
              ux * uy * (1. - cosAngle) - uz * sinAngle,
              ux * uz * (1. - cosAngle) + uy * sinAngle,
              uy * ux * (1. - cosAngle) + uz * sinAngle,
              cosAngle + std::pow(uy, 2.) * (1 - cosAngle),
              uy * uz * (1. - cosAngle) - ux * sinAngle,
              uz * ux * (1. - cosAngle) - uy * sinAngle,
              uz * uy * (1. - cosAngle) + ux * sinAngle,
              cosAngle + std::pow(uz, 2.) * (1. - cosAngle));
  return Isometry{Vector3(), rotationMatrix};
}

Isometry Isometry::fromEulerAngles(const double roll, const double pitch,
                                   const double yaw) {
  return rotateAround(Vector3::kUnitX, roll) *
         rotateAround(Vector3::kUnitY, pitch) *
         rotateAround(Vector3::kUnitZ, yaw);
}

Vector3 Isometry::transform(const Vector3& vector) const {
  return rotation_ * vector + translation_;
}

Vector3& Isometry::translation() { return translation_; }

const Vector3& Isometry::translation() const { return translation_; }

Matrix3& Isometry::rotation() { return rotation_; }

const Matrix3& Isometry::rotation() const { return rotation_; }

Isometry Isometry::inverse() const {
  const Matrix3 inv_rot = rotation_.inverse();
  return Isometry(-1 * inv_rot.product(translation_), inv_rot);
}

Isometry Isometry::compose(const Isometry& isometry) const {
  return (*this) * isometry;
}

Isometry& Isometry::operator=(const Isometry& isometry) {
  // self-assignment guard
  if (this == &isometry) {
    return *this;
  }
  rotation_ = isometry.rotation_;
  translation_ = isometry.translation_;
  return *this;
}

bool Isometry::operator==(const Isometry& isometry) const {
  return rotation_ == isometry.rotation_ &&
         translation_ == isometry.translation_;
}

Isometry& Isometry::operator*=(const Isometry& isometry) {
  translation_ = rotation_ * isometry.translation() + translation_;
  rotation_ = rotation_ * isometry.rotation();
  return *this;
}

Vector3 Isometry::operator*(const Vector3& vector) const {
  return rotation_.product(vector) + translation_;
}

Isometry Isometry::operator*(const Isometry& isometry) const {
  return Isometry((rotation_ * isometry.translation()) + translation_,
                  rotation_ * isometry.rotation());
}

std::ostream& operator<<(std::ostream& os, const Isometry& isometry) {
  os << std::setprecision(9) << "[T: " << isometry.translation()
     << ", R:" << isometry.rotation() << "]";
  return os;
}

}  // namespace math
}  // namespace ekumen
