#include "Vector3i.h"

Vector3i::Vector3i() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3i::Vector3i(int value) {
    x = value;
    y = value;
    z = value;
}

Vector3i::Vector3i(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3i& operator+(Vector3i& left, const Vector3i &right) {
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

Vector3i& operator+(Vector3i& left, int value) {
    left.x += value;
    left.y += value;
    left.z += value;
    return left;
}

Vector3i& operator-(Vector3i& left, const Vector3i &right) {
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

Vector3i operator+(const Vector3i& left, const Vector3i &right) {
    return { left.x + right.x, left.y + right.y, left.z + right.z };
}

Vector3i operator+(const Vector3i& left, int value) {
    return { left.x + value, left.y + value, left.z + value };
}

Vector3i operator-(const Vector3i& left, const Vector3i &right) {
    return { left.x - right.x, left.y - right.y, left.z - right.z };
}

Vector3i operator-(const Vector3i& left, int value) {
    return { left.x - value, left.y - value, left.z - value };
}

Vector3i operator*(const Vector3i& left, const Vector3i &right) {
    return { left.x * right.x, left.y * right.y, left.z * right.z };
}

Vector3i operator*(const Vector3i& left, int value) {
    return { left.x * value, left.y * value, left.z * value };
}

Vector3i operator/(const Vector3i& left, const Vector3i &right) {
    return { left.x / right.x, left.y / right.y, left.z / right.z };
}

Vector3i operator/(const Vector3i& left, int value) {
    return { left.x / value, left.y / value, left.z / value };
}

bool Vector3i::operator==(const Vector3i &other) {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3i::operator!=(const Vector3i &other) {
    return !(*this==other);
}

Vector3i& Vector3i::operator+=(const Vector3i &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3i& Vector3i::operator-=(const Vector3i &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3i& Vector3i::operator*=(const Vector3i &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3i& Vector3i::operator/=(const Vector3i &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vector3i& cross(Vector3i& left, const Vector3i &right){
    float xx = left.y * right.z - right.y * left.z;
    float yy = left.z * right.x - right.z * left.x;
    float zz = left.x * right.y - right.x * left.y;
    left.x = xx;
    left.y = yy;
    left.z = zz;
    return left;
}

float dot(Vector3i& left, const Vector3i &right){
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3i& normalize(Vector3i& vector){
    float lengthSquared = (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    if(lengthSquared == 0)
        return vector;
    float length = 1.0f / std::sqrt(lengthSquared);
    float xx = length * vector.x;
    float yy = length * vector.y;
    float zz = length * vector.z;
    vector.x = xx;
    vector.y = yy;
    vector.z = zz;
    return vector;
}

const char* Vector3i::toString() {
    std::string string;
    string.append(std::to_string((x)));
    string.append(" : ");
    string.append(std::to_string((y)));
    string.append(" : ");
    string.append(std::to_string((z)));
    return string.c_str();
}