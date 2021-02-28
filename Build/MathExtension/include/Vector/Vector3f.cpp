#include "Vector3f.h"

Vector3f::Vector3f() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3f::Vector3f(float value) {
    x = value;
    y = value;
    z = value;
}

Vector3f::Vector3f(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f& Vector3f::cross(const Vector3f& other){
    float xx = y * other.z - other.y * z;
    float yy = z * other.x - other.z * x;
    float zz = x * other.y - other.x * y;
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

Vector3f& Vector3f::cross(const Vector3f& left, const Vector3f &right){
    float xx = left.y * right.z - right.y * left.z;
    float yy = left.z * right.x - right.z * left.x;
    float zz = left.x * right.y - right.x * left.y;
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

Vector3f& cross(Vector3f& left, const Vector3f &right){
    float xx = left.y * right.z - right.y * left.z;
    float yy = left.z * right.x - right.z * left.x;
    float zz = left.x * right.y - right.x * left.y;
    left.x = xx;
    left.y = yy;
    left.z = zz;
    return left;
}

float dot(Vector3f& left, const Vector3f &right){
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3f& Vector3f::normalize(){
    float lengthSquared = (x * x + y * y + z * z);
    if(lengthSquared == 0)
        return *this;
    float length = 1.0f / std::sqrt(lengthSquared);
    float xx = length * x;
    float yy = length * y;
    float zz = length * z;
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

Vector3f& normalize(Vector3f& vector){
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

Vector3f operator+(const Vector3f& left, const Vector3f &right) {
    return { left.x + right.x, left.y + right.y, left.z + right.z };
}

Vector3f operator+(const Vector3f& left, float value) {
    return { left.x + value, left.y + value, left.z + value };
}

Vector3f operator-(const Vector3f& left, const Vector3f &right) {
    return { left.x - right.x, left.y - right.y, left.z - right.z };
}

Vector3f operator-(const Vector3f& left, float value) {
    return { left.x - value, left.y - value, left.z - value };
}

Vector3f operator*(const Vector3f& left, const Vector3f &right) {
    return { left.x * right.x, left.y * right.y, left.z * right.z };
}

Vector3f operator*(const Vector3f& left, float value) {
    return { left.x * value, left.y * value, left.z * value };
}

Vector3f operator/(const Vector3f& left, const Vector3f &right) {
    return { left.x / right.x, left.y / right.y, left.z / right.z };
}

Vector3f operator/(const Vector3f& left, float value) {
    return { left.x / value, left.y / value, left.z / value };
}

float Vector3f::length(){
    return std::sqrt(x * x + y * y + z * z);
}

bool Vector3f::operator==(const Vector3f &other) {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3f::operator!=(const Vector3f &other) {
    return !(*this==other);
}

Vector3f& Vector3f::operator+=(const Vector3f &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3f& Vector3f::operator-=(const Vector3f &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3f& Vector3f::operator*=(const Vector3f &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3f& Vector3f::operator/=(const Vector3f &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

const char* Vector3f::toString() {
    std::string string;
    string.append(std::to_string((x)));
    string.append(" : ");
    string.append(std::to_string((y)));
    string.append(" : ");
    string.append(std::to_string((z)));
    return string.c_str();
}