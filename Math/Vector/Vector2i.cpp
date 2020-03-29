#include "Vector2i.h"

Vector2i::Vector2i() {
    x = 0.0f;
    y = 0.0f;
}

Vector2i::Vector2i(int value) {
    x = value;
    y = value;
}

Vector2i::Vector2i(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2i operator+(const Vector2i& left, const Vector2i &right) {
    return { left.x + right.x, left.y + right.y };
}

Vector2i operator+(const Vector2i& left, int value) {
    return { left.x + value, left.y + value };
}

Vector2i operator-(const Vector2i& left, const Vector2i &right) {
    return { left.x - right.x, left.y - right.y };
}

Vector2i operator-(const Vector2i& left, int value) {
    return { left.x - value, left.y - value };
}

Vector2i operator*(const Vector2i& left, const Vector2i &right) {
    return { left.x * right.x, left.y * right.y };
}

Vector2i operator*(const Vector2i& left, int value) {
    return { left.x * value, left.y * value };
}

Vector2i operator/(const Vector2i& left, const Vector2i &right) {
    return { left.x / right.x, left.y / right.y };
}

Vector2i operator/(const Vector2i& left, int value) {
    return { left.x / value, left.y / value };
}

bool Vector2i::operator==(const Vector2i &other) {
    return x == other.x && y == other.y;
}

bool Vector2i::operator!=(const Vector2i &other) {
    return !(*this==other);
}

Vector2i& Vector2i::operator+=(const Vector2i &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2i& Vector2i::operator-=(const Vector2i &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2i& Vector2i::operator*=(const Vector2i &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vector2i& Vector2i::operator/=(const Vector2i &other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

const char* Vector2i::toString() {
    std::string string;
    string.append(std::to_string((x)));
    string.append(" : ");
    string.append(std::to_string((y)));
    return string.c_str();
}