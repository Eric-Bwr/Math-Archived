#include "Vector2f.h"

Vector2f::Vector2f() {
    x = 0.0f;
    y = 0.0f;
}

Vector2f::Vector2f(float value) {
    x = value;
    y = value;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2f operator+(const Vector2f& left, const Vector2f &right) {
    return { left.x + right.x, left.y + right.y };
}

Vector2f operator+(const Vector2f& left, float value) {
    return { left.x + value, left.y + value };
}

Vector2f operator-(const Vector2f& left, const Vector2f &right) {
    return { left.x - right.x, left.y - right.y };
}

Vector2f operator-(const Vector2f& left, float value) {
    return { left.x - value, left.y - value };
}

Vector2f operator*(const Vector2f& left, const Vector2f &right) {
    return { left.x * right.x, left.y * right.y };
}

Vector2f operator*(const Vector2f& left, float value) {
    return { left.x * value, left.y * value };
}

Vector2f operator/(const Vector2f& left, const Vector2f &right) {
    return { left.x / right.x, left.y / right.y };
}

Vector2f operator/(const Vector2f& left, float value) {
    return { left.x / value, left.y / value };
}

bool Vector2f::operator==(const Vector2f &other) {
    return x == other.x && y == other.y;
}

bool Vector2f::operator!=(const Vector2f &other) {
    return !(*this==other);
}

Vector2f& Vector2f::operator+=(const Vector2f &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2f& Vector2f::operator+=(const float& other) {
    x += other;
    y += other;
    return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2f& Vector2f::operator-=(const float &other) {
    x -= other;
    y -= other;
    return *this;
}

Vector2f& Vector2f::operator*=(const Vector2f &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vector2f& Vector2f::operator*=(const float &other) {
    x *= other;
    y *= other;
    return *this;
}

Vector2f& Vector2f::operator/=(const Vector2f &other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

Vector2f& Vector2f::operator/=(const float &other) {
    x /= other;
    y /= other;
    return *this;
}

const char* Vector2f::toString() {
    std::string string;
    string.append(std::to_string((x)));
    string.append(" : ");
    string.append(std::to_string((y)));
    return string.c_str();
}