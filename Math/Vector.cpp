#include "Vector.h"

template<typename T>
Vec2<T>::Vec2(T v) {
	this->x = v;
	this->y = v;
}

template<typename T>
Vec2<T>::Vec2(T x, T y) {
	this->x = x;
	this->y = y;
}

template<typename T>
Vec2<T>::Vec2(const Vec2<T> &v) {
	this->x = v.x;
	this->y = v.y;
}

template<typename T>
Vec2<T> operator+ (const Vec2<T> &a, const Vec2<T> &b) {
	return Vec2<T>(a.x + b.x, a.y + b.y);
}

template<typename T>
Vec2<T> operator+ (const Vec2<T> &a, T b) {
	return Vec2<T>(a.x + b, a.y + b);
}

template<typename T>
Vec2<T> operator- (const Vec2<T> &a, const Vec2<T> &b) {
	return Vec2<T>(a.x - b.x, a.y - b.y);
}

template<typename T>
Vec2<T> operator- (const Vec2<T> &a, T b) {
	return Vec2<T>(a.x - b, a.y - b);
}

template<typename T>
Vec2<T> operator* (const Vec2<T> &a, const Vec2<T> &b) {
	return Vec2<T>(a.x * b.x, a.y * b.y);
}

template<typename T>
Vec2<T> operator* (const Vec2<T> &a, T b) {
	return Vec2<T>(a.x * b, a.y * b);
}

template<typename T>
Vec2<T> operator/ (const Vec2<T> &a, const Vec2<T> &b) {
	return Vec2<T>(a.x / b.x, a.y / b.y);
}

template<typename T>
Vec2<T> operator/ (const Vec2<T> &a, T b) {
	return Vec2<T>(a.x / b, a.y / b);
}

template<typename T>
Vec2<T>& Vec2<T>::operator+= (const Vec2<T> &a) {
	x += a.x;
	y += a.y;
	return *this;
}

template<typename T>
Vec2<T>& Vec2<T>::operator-= (const Vec2<T> &a) {
	x -= a.x;
	y -= a.y;
	return *this;
}

template<typename T>
Vec2<T>& Vec2<T>::operator*= (T v) {
	x *= v;
	y *= v;
	return *this;
}

template<typename T>
bool Vec2<T>::operator== (Vec2<T> &a) const {
	return x == a.x && y == a.y;
}

template<typename T>
bool Vec2<T>::operator!= (Vec2<T> &a) const {
	return x != a.x || y != a.y;
}

template<typename T>
Vec2<T> Vec2<T>::norm() const {
	T f = 1.0 / len();
	return Vec2<T>(f * x, f * y);
}

template<typename T>
T Vec2<T>::dot(Vec2<T> const &a) const {
	return x * a.x + y * a.y;
}

template<typename T>
T Vec2<T>::len() const {
	return std::sqrt(x * x + y * y);
}

template<typename T>
T Vec2<T>::len2() const {
	return x * x + y * y;
}

template<typename T>
Vec3<T>::Vec3(T v) {
	x = v;
	y = v;
	z = v;
}

template<typename T>
Vec3<T>::Vec3(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename T>
Vec3<T>::Vec3(const Vec2<T>& xy, T z) {
	this->x = xy.x;
	this->y = xy.y;
	this->z = z;
}

template<typename T>
Vec3<T>::Vec3(const Vec3<T>& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

template<typename T>
Vec2<T> Vec3<T>::xy() const {
	return Vec2<T>(x, y);
}

template<typename T>
Vec2<T> Vec3<T>::xz() const {
	return Vec2<T>(x, z);
}

template<typename T>
Vec2<T> Vec3<T>::yz() const {
	return Vec2<T>(y, z);
}

template<typename T>
Vec3<T> operator+ (const Vec3<T> &a, const Vec3<T> &b) {
	return Vec3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
}

template<typename T>
Vec3<T> operator+ (const Vec3<T> &a, T b) {
	return Vec3<T>(a.x + b, a.y + b, a.z + b);
}

template<typename T>
Vec3<T> operator- (const Vec3<T> &a, const Vec3<T> &b) {
	return Vec3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
}

template<typename T>
Vec3<T> operator- (const Vec3<T> &a, T b) {
	return Vec3<T>(a.x - b, a.y - b, a.z - b);
}

template<typename T>
Vec3<T> operator* (const Vec3<T> &a, const Vec3<T> &b) {
	return Vec3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
}

template<typename T>
Vec3<T> operator* (const Vec3<T> &a, T b) {
	return Vec3<T>(a.x * b, a.y * b, a.z * b);
}

template<typename T>
Vec3<T> operator/ (const Vec3<T> &a, const Vec3<T> &b) {
	return Vec3<T>(a.x / b.x, a.y / b.y, a.z / b.z);
}

template<typename T>
Vec3<T> operator/ (const Vec3<T> &a, T b) {
	return Vec3<T>(a.x / b, a.y / b, a.z / b);
}

template<typename T>
Vec3<T>& Vec3<T>::operator+= (const Vec3<T> &a) {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-= (const Vec3<T> &a) {
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*= (T v) {
	x *= v;
	y *= v;
	z *= v;
	return *this;
}

template<typename T>
bool Vec3<T>::operator== (Vec3<T> &a) const {
	return x == a.x && y == a.y && z == a.z;
}

template<typename T>
bool Vec3<T>::operator!= (Vec3<T> &a) const {
	return x != a.x || y != a.y || z != a.z;
}

template<typename T>
Vec3<T> Vec3<T>::cross(Vec3<T> const &a) const {
	T xx = y * a.z - a.y * z;
    T yy = z * a.x - a.z * x;
    T zz = x * a.y - a.x * y;
	return Vec3<T>(xx, yy, zz);
}

template<typename T>
Vec3<T> Vec3<T>::norm() const {
    T lengthSquared = (x * x + y * y + z * z);
    if(lengthSquared == 0)
        return *this;
    T length = 1.0 / std::sqrt(lengthSquared);
	return Vec3<T>(x * length, y * length, z * length);
}

template<typename T>
T Vec3<T>::dot(Vec3<T> const &a) const {
	return x * a.x + y * a.y + z * a.z;
}

template<typename T>
T Vec3<T>::len() const {
	return std::sqrt(x * x + y * y + z * z);
}

template<typename T>
T Vec3<T>::len2() const {
	return x * x + y * y + z * z;
}

template<typename T>
Vec4<T>::Vec4(T v) {
    x = v;
    y = v;
    z = v;
    w = v;
}

template<typename T>
Vec4<T>::Vec4(T x, T y, T z, T w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template<typename T>
Vec4<T> operator+ (const Vec4<T> &a, const Vec4<T> &b) {
    return Vec4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

template<typename T>
Vec4<T> operator+ (const Vec4<T> &a, T b) {
    return Vec4<T>(a.x + b, a.y + b, a.z + b, a.w + b);
}

template<typename T>
Vec4<T> operator- (const Vec4<T> &a, const Vec4<T> &b) {
    return Vec4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

template<typename T>
Vec4<T> operator- (const Vec4<T> &a, T b) {
    return Vec4<T>(a.x - b, a.y - b, a.z - b, a.w - b);
}

template<typename T>
Vec4<T> operator* (const Vec4<T> &a, const Vec4<T> &b) {
    return Vec4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

template<typename T>
Vec4<T> operator* (const Vec4<T> &a, T b) {
    return Vec4<T>(a.x * b, a.y * b, a.z * b, a.w * b);
}

template<typename T>
Vec4<T> operator/ (const Vec4<T> &a, const Vec4<T> &b) {
    return Vec4<T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

template<typename T>
Vec4<T> operator/ (const Vec4<T> &a, T b) {
    return Vec4<T>(a.x / b, a.y / b, a.z / b, a.w / b);
}

template<typename T>
Vec4<T>& Vec4<T>::operator+= (const Vec4<T> &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    w += a.w;
    return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator-= (const Vec4<T> &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    w -= a.w;
    return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator*= (T v) {
    x *= v;
    y *= v;
    z *= v;
    w *= v;
    return *this;
}

template<typename T>
bool Vec4<T>::operator== (Vec4<T> &a) const {
    return x == a.x && y == a.y && z == a.z && w == a.w;
}

template<typename T>
bool Vec4<T>::operator!= (Vec4<T> &a) const {
    return x != a.x || y != a.y || z != a.z || w != a.w;
}