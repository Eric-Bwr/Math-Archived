#include "Vector.h"

Vec2f::Vec2f(float v) {
	this->x = v;
	this->y = v;
}

Vec2f::Vec2f(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2f::Vec2f(const Vec2f &v) {
	this->x = v.x;
	this->y = v.y;
}

Vec2f operator+ (const Vec2f &a, const Vec2f &b) {
	return Vec2f(a.x + b.x, a.y + b.y);
}

Vec2f operator+ (const Vec2f &a, float b) {
	return Vec2f(a.x + b, a.y + b);
}

Vec2f operator- (const Vec2f &a, const Vec2f &b) {
	return Vec2f(a.x - b.x, a.y - b.y);
}

Vec2f operator- (const Vec2f &a, float b) {
	return Vec2f(a.x - b, a.y - b);
}

Vec2f operator* (const Vec2f &a, const Vec2f &b) {
	return Vec2f(a.x * b.x, a.y * b.y);
}

Vec2f operator* (const Vec2f &a, float b) {
	return Vec2f(a.x * b, a.y * b);
}

Vec2f operator/ (const Vec2f &a, const Vec2f &b) {
	return Vec2f(a.x / b.x, a.y / b.y);
}

Vec2f operator/ (const Vec2f &a, float b) {
	return Vec2f(a.x / b, a.y / b);
}

Vec2f& Vec2f::operator+= (const Vec2f &a) {
	x += a.x;
	y += a.y;
	return *this;
}

Vec2f& Vec2f::operator-= (const Vec2f &a) {
	x -= a.x;
	y -= a.y;
	return *this;
}

Vec2f& Vec2f::operator*= (float v) {
	x *= v;
	y *= v;
	return *this;
}
	
bool Vec2f::operator== (Vec2f &a) const {
	return x == a.x && y == a.y;
}

bool Vec2f::operator!= (Vec2f &a) const {
	return x != a.x || y != a.y;
}

Vec2f Vec2f::norm() const {
	float f = 1.0f / len();
	return Vec2f(f * x, f * y);
}

float Vec2f::dot(Vec2f const &a) const {
	return x * a.x + y * a.y;
}

float Vec2f::len() const {
	return std::sqrt(x * x + y * y);
}

Vec3f::Vec3f(float v) {
	x = v;
	y = v;
	z = v;
}

Vec3f::Vec3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3f::Vec3f(const Vec2f& xy, float z) {
	this->x = xy.x;
	this->y = xy.y;
	this->z = z;
}

Vec3f::Vec3f(const Vec3f& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

Vec2f Vec3f::xy() const {
	return Vec2f(x, y);
}

Vec2f Vec3f::xz() const {
	return Vec2f(x, z);
}

Vec2f Vec3f::yz() const {
	return Vec2f(y, z);
}

Vec3f operator+ (const Vec3f &a, const Vec3f &b) {
	return Vec3f(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3f operator+ (const Vec3f &a, float b) {
	return Vec3f(a.x + b, a.y + b, a.z + b);
}

Vec3f operator- (const Vec3f &a, const Vec3f &b) {
	return Vec3f(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3f operator- (const Vec3f &a, float b) {
	return Vec3f(a.x - b, a.y - b, a.z - b);
}

Vec3f operator* (const Vec3f &a, const Vec3f &b) {
	return Vec3f(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vec3f operator* (const Vec3f &a, float b) {
	return Vec3f(a.x * b, a.y * b, a.z * b);
}

Vec3f operator/ (const Vec3f &a, const Vec3f &b) {
	return Vec3f(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vec3f operator/ (const Vec3f &a, float b) {
	return Vec3f(a.x / b, a.y / b, a.z / b);
}

Vec3f& Vec3f::operator+= (const Vec3f &a) {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

Vec3f& Vec3f::operator-= (const Vec3f &a) {
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

Vec3f& Vec3f::operator*= (float v) {
	x *= v;
	y *= v;
	z *= v;
	return *this;
}
	
bool Vec3f::operator== (Vec3f &a) const {
	return x == a.x && y == a.y && z == a.z;
}

bool Vec3f::operator!= (Vec3f &a) const {
	return x != a.x || y != a.y || z != a.z;
}

Vec3f Vec3f::cross(Vec3f const &a) const {
	float xx = y * a.z - a.y * z;
    float yy = z * a.x - a.z * x;
    float zz = x * a.y - a.x * y;
	return Vec3f(xx, yy, zz);
}

Vec3f Vec3f::norm() const {
    float lengthSquared = (x * x + y * y + z * z);
    if(lengthSquared == 0)
        return *this;
    float length = 1.0f / std::sqrt(lengthSquared);
	return Vec3f(x * length, y * length, z * length);
}

float Vec3f::dot(Vec3f const &a) const {
	return x * a.x + y * a.y + z * a.z;
}

float Vec3f::len() const {
	return std::sqrt(x * x + y * y + z * z);
}