#include "Matrix.h"

#define RADIANS 0.01745329251994329576923690768489f

Mat4f::Mat4f(float v) {
	m00 = v;
	m11 = v;
	m22 = v;
	m33 = v;
    updateBuffer();
}

Mat4f &Mat4f::identity() {
    m00 = 1.0f;
    m11 = 1.0f;
    m22 = 1.0f;
    m33 = 1.0f;
    updateBuffer();
    return *this;
}

Mat4f &Mat4f::translate(const Vec3f &v) {
    return translate(v.x, v.y, v.z);
}

Mat4f &Mat4f::translate(float x, float y, float z) {
    m30 = m00 * x + m10 * y + m20 * z;
    m31 = m01 * x + m11 * y + m21 * z;
    m32 = m02 * x + m12 * y + m22 * z;

    updateBuffer();
    return *this;
}

Mat4f &Mat4f::rotate(float angle, const Vec3f &axis) {
	return rotate(angle, axis.x, axis.y, axis.z);
}

Mat4f &Mat4f::rotate(float angle, float x, float y, float z) {
	float angleRadians = angle * RADIANS;
	float c = std::cos(angleRadians);
	float s = std::sin(angleRadians);
	float oneminusc = 1.0f - c;
	float xy = x * y;
	float yz = y * z;
	float xz = x * z;
	float xs = x * s;
	float ys = y * s;
	float zs = z * s;
	float f00 = x * x * oneminusc + c;
	float f2 = xy * oneminusc + zs;
	float f3 = xz * oneminusc - ys;
	float f4 = xy * oneminusc - zs;
	float f5 = y * y * oneminusc + c;
	float f6 = yz * oneminusc + xs;
	float f7 = xz * oneminusc + ys;
	float f8 = yz * oneminusc - xs;
	float f9 = z * z * oneminusc + c;
	float e1 = m00 * f00 + m10 * f2 + m20 * f3;
	float e2 = m01 * f00 + m11 * f2 + m21 * f3;
	float e3 = m02 * f00 + m12 * f2 + m22 * f3;
	float e4 = m03 * f00 + m13 * f2 + m23 * f3;
	float e5 = m00 * f4 + m10 * f5 + m20 * f6;
	float e6 = m01 * f4 + m11 * f5 + m21 * f6;
	float e7 = m02 * f4 + m12 * f5 + m22 * f6;
	float e8 = m03 * f4 + m13 * f5 + m23 * f6;
	float e9 = m00 * f7 + m10 * f8 + m20 * f9;
	float e10 = m01 * f7 + m11 * f8 + m21 * f9;
	float e11 = m02 * f7 + m12 * f8 + m22 * f9;
	float e12 = m03 * f7 + m13 * f8 + m23 * f9;
	m00 = e1;
	m01 = e2;
	m02 = e3;
	m03 = e4;
	m10 = e5;
	m11 = e6;
	m12 = e7;
	m13 = e8;
	m20 = e9;
	m21 = e10;
	m22 = e11;
	m23 = e12;
    updateBuffer();
	return *this;
}

Mat4f &Mat4f::scale(float s) {
	return scale(s, s, s);
}

Mat4f &Mat4f::scale(float x, float y, float z) {
	m00 *= x;
	m01 *= x;
	m02 *= x;
	m03 *= x;
	m10 *= y;
	m11 *= y;
	m12 *= y;
	m13 *= y;
	m20 *= z;
	m21 *= z;
	m22 *= z;
	m23 *= z;
    updateBuffer();
	return *this;
}

Mat4f &Mat4f::scale(const Vec3f &v) {
    return scale(v.x, v.y, v.z);
}

Mat4f& Mat4f::multiply(const Mat4f& matrix) {
    m00 = m00 * matrix.m00 + m10 * matrix.m01 + m20 * matrix.m02 + m30 * matrix.m03;
    m01 = m01 * matrix.m00 + m11 * matrix.m01 + m21 * matrix.m02 + m31 * matrix.m03;
    m02 = m02 * matrix.m00 + m12 * matrix.m01 + m22 * matrix.m02 + m32 * matrix.m03;
    m03 = m03 * matrix.m00 + m13 * matrix.m01 + m23 * matrix.m02 + m33 * matrix.m03;
    m10 = m00 * matrix.m10 + m10 * matrix.m11 + m20 * matrix.m12 + m30 * matrix.m13;
    m11 = m01 * matrix.m10 + m11 * matrix.m11 + m21 * matrix.m12 + m31 * matrix.m13;
    m12 = m02 * matrix.m10 + m12 * matrix.m11 + m22 * matrix.m12 + m32 * matrix.m13;
    m13 = m03 * matrix.m10 + m13 * matrix.m11 + m23 * matrix.m12 + m33 * matrix.m13;
    m20 = m00 * matrix.m20 + m10 * matrix.m21 + m20 * matrix.m22 + m30 * matrix.m23;
    m21 = m01 * matrix.m20 + m11 * matrix.m21 + m21 * matrix.m22 + m31 * matrix.m23;
    m22 = m02 * matrix.m20 + m12 * matrix.m21 + m22 * matrix.m22 + m32 * matrix.m23;
    m23 = m03 * matrix.m20 + m13 * matrix.m21 + m23 * matrix.m22 + m33 * matrix.m23;
    m30 = m00 * matrix.m30 + m10 * matrix.m31 + m20 * matrix.m32 + m30 * matrix.m33;
    m31 = m01 * matrix.m30 + m11 * matrix.m31 + m21 * matrix.m32 + m31 * matrix.m33;
    m32 = m02 * matrix.m30 + m12 * matrix.m31 + m22 * matrix.m32 + m32 * matrix.m33;
    m33 = m03 * matrix.m30 + m13 * matrix.m31 + m23 * matrix.m32 + m33 * matrix.m33;

    updateBuffer();
    return *this;
}

Mat4f& Mat4f::multiply(const Mat4f& one, const Mat4f& two) {
    m00 = one.m00 * two.m00 + one.m10 * two.m01 + one.m20 * two.m02 + one.m30 * two.m03;
    m01 = one.m01 * two.m00 + one.m11 * two.m01 + one.m21 * two.m02 + one.m31 * two.m03;
    m02 = one.m02 * two.m00 + one.m12 * two.m01 + one.m22 * two.m02 + one.m32 * two.m03;
    m03 = one.m03 * two.m00 + one.m13 * two.m01 + one.m23 * two.m02 + one.m33 * two.m03;
    m10 = one.m00 * two.m10 + one.m10 * two.m11 + one.m20 * two.m12 + one.m30 * two.m13;
    m11 = one.m01 * two.m10 + one.m11 * two.m11 + one.m21 * two.m12 + one.m31 * two.m13;
    m12 = one.m02 * two.m10 + one.m12 * two.m11 + one.m22 * two.m12 + one.m32 * two.m13;
    m13 = one.m03 * two.m10 + one.m13 * two.m11 + one.m23 * two.m12 + one.m33 * two.m13;
    m20 = one.m00 * two.m20 + one.m10 * two.m21 + one.m20 * two.m22 + one.m30 * two.m23;
    m21 = one.m01 * two.m20 + one.m11 * two.m21 + one.m21 * two.m22 + one.m31 * two.m23;
    m22 = one.m02 * two.m20 + one.m12 * two.m21 + one.m22 * two.m22 + one.m32 * two.m23;
    m23 = one.m03 * two.m20 + one.m13 * two.m21 + one.m23 * two.m22 + one.m33 * two.m23;
    m30 = one.m00 * two.m30 + one.m10 * two.m31 + one.m20 * two.m32 + one.m30 * two.m33;
    m31 = one.m01 * two.m30 + one.m11 * two.m31 + one.m21 * two.m32 + one.m31 * two.m33;
    m32 = one.m02 * two.m30 + one.m12 * two.m31 + one.m22 * two.m32 + one.m32 * two.m33;
    m33 = one.m03 * two.m30 + one.m13 * two.m31 + one.m23 * two.m32 + one.m33 * two.m33;

    updateBuffer();
    return *this;
}

float determinant3x3(float t00, float t01, float t02, float t10, float t11, float t12, float t20, float t21, float t22) {
    return   t00 * (t11 * t22 - t12 * t21)
             + t01 * (t12 * t20 - t10 * t22)
             + t02 * (t10 * t21 - t11 * t20);
}

Mat4f& Mat4f::invert() {
    float f = m00 * ((m11 * m22 * m33 + m12 * m23 * m31 + m13 * m21 * m32)
                     - m13 * m22 * m31- m11 * m23 * m32- m12 * m21 * m33);
    f -= m01 * ((m10 * m22 * m33 + m12 * m23 * m30 + m13 * m20 * m32)
                - m13 * m22 * m30- m10 * m23 * m32- m12 * m20 * m33);
    f += m02 * ((m10 * m21 * m33 + m11 * m23 * m30 + m13 * m20 * m31)
                - m13 * m21 * m30- m10 * m23 * m31- m11 * m20 * m33);
    f -= m03 * ((m10 * m21 * m32 + m11 * m22 * m30 + m12 * m20 * m31)
                - m12 * m21 * m30- m10 * m22 * m31- m11 * m20 * m32);
    float determinant_inv = 1.0f / f;

    float t00 =  determinant3x3(m11, m12, m13, m21, m22, m23, m31, m32, m33);
    float t01 = -determinant3x3(m10, m12, m13, m20, m22, m23, m30, m32, m33);
    float t02 =  determinant3x3(m10, m11, m13, m20, m21, m23, m30, m31, m33);
    float t03 = -determinant3x3(m10, m11, m12, m20, m21, m22, m30, m31, m32);

    float t10 = -determinant3x3(m01, m02, m03, m21, m22, m23, m31, m32, m33);
    float t11 =  determinant3x3(m00, m02, m03, m20, m22, m23, m30, m32, m33);
    float t12 = -determinant3x3(m00, m01, m03, m20, m21, m23, m30, m31, m33);
    float t13 =  determinant3x3(m00, m01, m02, m20, m21, m22, m30, m31, m32);

    float t20 =  determinant3x3(m01, m02, m03, m11, m12, m13, m31, m32, m33);
    float t21 = -determinant3x3(m00, m02, m03, m10, m12, m13, m30, m32, m33);
    float t22 =  determinant3x3(m00, m01, m03, m10, m11, m13, m30, m31, m33);
    float t23 = -determinant3x3(m00, m01, m02, m10, m11, m12, m30, m31, m32);

    float t30 = -determinant3x3(m01, m02, m03, m11, m12, m13, m21, m22, m23);
    float t31 =  determinant3x3(m00, m02, m03, m10, m12, m13, m20, m22, m23);
    float t32 = -determinant3x3(m00, m01, m03, m10, m11, m13, m20, m21, m23);
    float t33 =  determinant3x3(m00, m01, m02, m10, m11, m12, m20, m21, m22);

    m00 = t00 * determinant_inv;
    m11 = t11 * determinant_inv;
    m22 = t22 * determinant_inv;
    m33 = t33 * determinant_inv;
    m01 = t10 * determinant_inv;
    m10 = t01 * determinant_inv;
    m20 = t02 * determinant_inv;
    m02 = t20 * determinant_inv;
    m12 = t21 * determinant_inv;
    m21 = t12 * determinant_inv;
    m03 = t30 * determinant_inv;
    m30 = t03 * determinant_inv;
    m13 = t31 * determinant_inv;
    m31 = t13 * determinant_inv;
    m32 = t23 * determinant_inv;
    m23 = t32 * determinant_inv;

    updateBuffer();
    return *this;
}

Mat4f &Mat4f::removeTranslation() {
    m30 = 0.0f;
    m31 = 0.0f;
    m32 = 0.0f;
    updateBuffer();
    return *this;
}

Mat4f &Mat4f::orthographic(float left, float right, float bottom, float top, float near, float far){
    m00 = 2.0f / (right - left);
    m11 = 2.0f / (top - bottom);
    m22 = 2.0f / (near - far);

    m30 = (left + right) / (left - right);
    m31 = (bottom + top) / (bottom - top);
    m32 = (far + near) / (far - near);

    updateBuffer();
    return *this;
}

Mat4f &Mat4f::perspective(float fov, float width, float height, float near, float far){
    float aspectRatio = width / height;
    float yScale = std::tan(fov / 2.0f * RADIANS);

    m00 = 1.0f / (aspectRatio * yScale);
    m11 = 1.0f / (yScale);
    m22 = far / (near - far);
    m23 = -1.0f;
    m32 = -(far * near) / (far - near);

    updateBuffer();
    return *this;
}

Mat4f &Mat4f::lookAt(const Vec3f &eye, const Vec3f &center, const Vec3f &up) {
    Vec3f f = (center - eye).norm();
    Vec3f s = (f.cross(up)).norm();
    Vec3f u = s.cross(f);

    m00 = s.x;
    m10 = s.y;
    m20 = s.z;
    m01 = u.x;
    m11 = u.y;
    m21 = u.z;
    m02 =-f.x;
    m12 =-f.y;
    m22 =-f.z;
    m30 =-s.dot(eye);
    m31 =-u.dot(eye);
    m32 =f.dot(eye);

    updateBuffer();
    return *this;
}

char *Mat4f::toString() const {
	const char *fmt = "|%+6.2f %+6.2f %+6.2f %+6.2f|\n|%+6.2f %+6.2f %+6.2f %+6.2f|\n|%+6.2f %+6.2f %+6.2f %+6.2f|\n|%+6.2f %+6.2f %+6.2f %+6.2f|\n";
	char *s = (char *) malloc(sizeof(char) * 128);
	std::sprintf(s, fmt, m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33);
	return s;
}


float * Mat4f::getBuffer() const {
    return buffer;
}

void Mat4f::updateBuffer() {
    buffer[0] = m00;
    buffer[1] = m01;
    buffer[2] = m02;
    buffer[3] = m03;

    buffer[4] = m10;
    buffer[5] = m11;
    buffer[6] = m12;
    buffer[7] = m13;

    buffer[8] = m20;
    buffer[9] = m21;
    buffer[10] = m22;
    buffer[11] = m23;

    buffer[12] = m30;
    buffer[13] = m31;
    buffer[14] = m32;
    buffer[15] = m33;
}

Mat4f identityMatrix() {
	return Mat4f(1.0f);
}

Mat4f perspectiveMatrix(float fov, float width, float height, float near, float far) {
	Mat4f mat = identityMatrix();
	float aspectRatio = width / height;
	float yScale = std::tan(fov / 2.0f * RADIANS);

	mat.m00 = 1.0f / (aspectRatio * yScale);
	mat.m11 = 1.0f / (yScale);
	mat.m22 = far / (near - far);
	mat.m23 = -1.0f;
	mat.m32 = -(far * near) / (far - near);

    mat.updateBuffer();
	return mat;
}

Mat4f orthographicMatrix(float left, float right, float bottom, float top, float near, float far) {
	Mat4f mat = identityMatrix();

	mat.m00 = 2.0f / (right - left);
	mat.m11 = 2.0f / (top - bottom);
	mat.m22 = 2.0f / (near - far);

	mat.m30 = (left + right) / (left - right);
	mat.m31 = (bottom + top) / (bottom - top);
	mat.m32 = (far + near) / (far - near);

    mat.updateBuffer();
	return mat;
}

Mat4f lookAtMatrix(const Vec3f &eye, const Vec3f &center, const Vec3f &up) {
	Mat4f mat = identityMatrix();
	Vec3f f = (center - eye).norm();
	Vec3f s = (f.cross(up)).norm();
	Vec3f u = s.cross(f);

	mat.m00 = s.x;
	mat.m10 = s.y;
	mat.m20 = s.z;
	mat.m01 = u.x;
	mat.m11 = u.y;
	mat.m21 = u.z;
	mat.m02 =-f.x;
	mat.m12 =-f.y;
	mat.m22 =-f.z;
	mat.m30 =-s.dot(eye);
	mat.m31 =-u.dot(eye);
	mat.m32 =f.dot(eye);

	mat.updateBuffer();
	return mat;
}