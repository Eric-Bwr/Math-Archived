#include "Vector4i.h"

Vector4i::Vector4i() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

Vector4i::Vector4i(int value) {
    x = value;
    y = value;
    z = value;
    w = value;
}

Vector4i::Vector4i(int x, int y, int z, int w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4i& operator+(Vector4i& left, const Vector4i &right) {
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}

Vector4i& operator+(Vector4i& left, int value) {
    left.x += value;
    left.y += value;
    left.z += value;
    left.w += value;
    return left;
}

Vector4i operator+(const Vector4i& left, const Vector4i &right) {
    return { left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w };
}

Vector4i operator+(const Vector4i& left, int value) {
    return { left.x + value, left.y + value, left.z + value, left.w + value };
}

Vector4i operator-(const Vector4i& left, const Vector4i &right) {
    return { left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w };
}

Vector4i operator-(const Vector4i& left, int value) {
    return { left.x - value, left.y - value, left.z - value, left.w - value };
}

Vector4i operator*(const Vector4i& left, const Vector4i &right) {
    return { left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w };
}

Vector4i operator*(const Vector4i& left, int value) {
    return { left.x * value, left.y * value, left.z * value, left.w * value };
}

Vector4i operator/(const Vector4i& left, const Vector4i &right) {
    return { left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w };
}

Vector4i operator/(const Vector4i& left, int value) {
    return { left.x / value, left.y / value, left.z / value, left.w / value };
}

bool Vector4i::operator==(const Vector4i &other) {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4i::operator!=(const Vector4i &other) {
    return !(*this==other);
}

Vector4i& Vector4i::operator+=(const Vector4i &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

Vector4i& Vector4i::operator-=(const Vector4i &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

Vector4i& Vector4i::operator*=(const Vector4i &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

Vector4i& Vector4i::operator/=(const Vector4i &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
}

const char* Vector4i::toString(){
    std::string string;
    string.append(std::to_string((x)));
    string.append(" : ");
    string.append(std::to_string((y)));
    string.append(" : ");
    string.append(std::to_string((z)));
    string.append(" : ");
    string.append(std::to_string((w)));
    return string.c_str();
}