#include "Vector4f.h"

Vector4f::Vector4f() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

Vector4f::Vector4f(float value) {
    x = value;
    y = value;
    z = value;
    w = value;
}

Vector4f::Vector4f(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4f operator+(const Vector4f& left, const Vector4f &right) {
    return { left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w };
}

Vector4f operator+(const Vector4f& left, float value) {
    return { left.x + value, left.y + value, left.z + value, left.w + value };
}

Vector4f operator-(const Vector4f& left, const Vector4f &right) {
    return { left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w };
}

Vector4f operator-(const Vector4f& left, float value) {
    return { left.x - value, left.y - value, left.z - value, left.w - value };
}

Vector4f operator*(const Vector4f& left, const Vector4f &right) {
    return { left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w };
}

Vector4f operator*(const Vector4f& left, float value) {
    return { left.x * value, left.y * value, left.z * value, left.w * value };
}

Vector4f operator/(const Vector4f& left, const Vector4f &right) {
    return { left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w };
}

Vector4f operator/(const Vector4f& left, float value) {
    return { left.x / value, left.y / value, left.z / value, left.w / value };
}

bool Vector4f::operator==(const Vector4f &other) {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4f::operator!=(const Vector4f &other) {
    return !(*this==other);
}

Vector4f& Vector4f::operator+=(const Vector4f &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

Vector4f& Vector4f::operator-=(const Vector4f &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

Vector4f& Vector4f::operator*=(const Vector4f &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

Vector4f& Vector4f::operator/=(const Vector4f &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
}

const char* Vector4f::toString(){
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