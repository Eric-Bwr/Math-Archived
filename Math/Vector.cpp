#include "Vector.h"

Vec2::Vec2(double v) {
	this->x = v;
	this->y = v;
}

Vec2::Vec2(double x, double y) {
	this->x = x;
	this->y = y;
}

Vec2::Vec2(const Vec2 &v) {
	this->x = v.x;
	this->y = v.y;
}

Vec2 operator+ (const Vec2 &a, const Vec2 &b) {
	return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator+ (const Vec2 &a, double b) {
	return Vec2(a.x + b, a.y + b);
}

Vec2 operator- (const Vec2 &a, const Vec2 &b) {
	return Vec2(a.x - b.x, a.y - b.y);
}

Vec2 operator- (const Vec2 &a, double b) {
	return Vec2(a.x - b, a.y - b);
}

Vec2 operator* (const Vec2 &a, const Vec2 &b) {
	return Vec2(a.x * b.x, a.y * b.y);
}

Vec2 operator* (const Vec2 &a, double b) {
	return Vec2(a.x * b, a.y * b);
}

Vec2 operator/ (const Vec2 &a, const Vec2 &b) {
	return Vec2(a.x / b.x, a.y / b.y);
}

Vec2 operator/ (const Vec2 &a, double b) {
	return Vec2(a.x / b, a.y / b);
}

Vec2& Vec2::operator+= (const Vec2 &a) {
	x += a.x;
	y += a.y;
	return *this;
}

Vec2& Vec2::operator-= (const Vec2 &a) {
	x -= a.x;
	y -= a.y;
	return *this;
}

Vec2& Vec2::operator*= (double v) {
	x *= v;
	y *= v;
	return *this;
}
	
bool Vec2::operator== (Vec2 &a) const {
	return x == a.x && y == a.y;
}

bool Vec2::operator!= (Vec2 &a) const {
	return x != a.x || y != a.y;
}

Vec2 Vec2::norm() const {
	double f = 1.0 / len();
	return Vec2(f * x, f * y);
}

double Vec2::dot(Vec2 const &a) const {
	return x * a.x + y * a.y;
}

double Vec2::len() const {
	return std::sqrt(x * x + y * y);
}

double Vec2::len2() const {
	return x * x + y * y;
}

Vec3::Vec3(double v) {
	x = v;
	y = v;
	z = v;
}

Vec3::Vec3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::Vec3(const Vec2& xy, double z) {
	this->x = xy.x;
	this->y = xy.y;
	this->z = z;
}

Vec3::Vec3(const Vec3& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

Vec2 Vec3::xy() const {
	return Vec2(x, y);
}

Vec2 Vec3::xz() const {
	return Vec2(x, z);
}

Vec2 Vec3::yz() const {
	return Vec2(y, z);
}

Vec3 operator+ (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 operator+ (const Vec3 &a, double b) {
	return Vec3(a.x + b, a.y + b, a.z + b);
}

Vec3 operator- (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3 operator- (const Vec3 &a, double b) {
	return Vec3(a.x - b, a.y - b, a.z - b);
}

Vec3 operator* (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vec3 operator* (const Vec3 &a, double b) {
	return Vec3(a.x * b, a.y * b, a.z * b);
}

Vec3 operator/ (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vec3 operator/ (const Vec3 &a, double b) {
	return Vec3(a.x / b, a.y / b, a.z / b);
}

Vec3& Vec3::operator+= (const Vec3 &a) {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

Vec3& Vec3::operator-= (const Vec3 &a) {
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

Vec3& Vec3::operator*= (double v) {
	x *= v;
	y *= v;
	z *= v;
	return *this;
}
	
bool Vec3::operator== (Vec3 &a) const {
	return x == a.x && y == a.y && z == a.z;
}

bool Vec3::operator!= (Vec3 &a) const {
	return x != a.x || y != a.y || z != a.z;
}

Vec3 Vec3::cross(Vec3 const &a) const {
	double xx = y * a.z - a.y * z;
    double yy = z * a.x - a.z * x;
    double zz = x * a.y - a.x * y;
	return Vec3(xx, yy, zz);
}

Vec3 Vec3::norm() const {
    double lengthSquared = (x * x + y * y + z * z);
    if(lengthSquared == 0)
        return *this;
    double length = 1.0 / std::sqrt(lengthSquared);
	return Vec3(x * length, y * length, z * length);
}

double Vec3::dot(Vec3 const &a) const {
	return x * a.x + y * a.y + z * a.z;
}

double Vec3::len() const {
	return std::sqrt(x * x + y * y + z * z);
}

double Vec3::len2() const {
	return x * x + y * y + z * z;
}

Vec4::Vec4(double v) {
    x = v;
    y = v;
    z = v;
    w = v;
}

Vec4::Vec4(double x, double y, double z, double w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vec4 operator+ (const Vec4 &a, const Vec4 &b) {
    return Vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vec4 operator+ (const Vec4 &a, double b) {
    return Vec4(a.x + b, a.y + b, a.z + b, a.w + b);
}

Vec4 operator- (const Vec4 &a, const Vec4 &b) {
    return Vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

Vec4 operator- (const Vec4 &a, double b) {
    return Vec4(a.x - b, a.y - b, a.z - b, a.w - b);
}

Vec4 operator* (const Vec4 &a, const Vec4 &b) {
    return Vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

Vec4 operator* (const Vec4 &a, double b) {
    return Vec4(a.x * b, a.y * b, a.z * b, a.w * b);
}

Vec4 operator/ (const Vec4 &a, const Vec4 &b) {
    return Vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

Vec4 operator/ (const Vec4 &a, double b) {
    return Vec4(a.x / b, a.y / b, a.z / b, a.w / b);
}

Vec4& Vec4::operator+= (const Vec4 &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    w += a.w;
    return *this;
}

Vec4& Vec4::operator-= (const Vec4 &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    w -= a.w;
    return *this;
}

Vec4& Vec4::operator*= (double v) {
    x *= v;
    y *= v;
    z *= v;
    w *= v;
    return *this;
}

bool Vec4::operator== (Vec4 &a) const {
    return x == a.x && y == a.y && z == a.z && w == a.w;
}

bool Vec4::operator!= (Vec4 &a) const {
    return x != a.x || y != a.y || z != a.z || w != a.w;
}