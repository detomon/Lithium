/**
 * Lithium 0.2
 * Copyright (c) 2015 Simon Schoenenberger
 * http://lithium.monoxid.net/
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef _LITHIUM_H_
#define _LITHIUM_H_

#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * Set to 1 if double values should be used
 */
#define LI_USE_DOUBLE 0

/**
 * Vector and matrix types and functions
 */

#pragma mark - Types

/**
 * LIFloat type
 */
#if LI_USE_DOUBLE
typedef double LIFloat;
#else
typedef float  LIFloat;
#endif

/**
 * Math functions depending on float type
 */
#if LI_USE_DOUBLE
#	define LISin(v) sin(v)
#	define LICos(v) cos(v)
#	define LITan(v) tan(v)
#	define LISqrt(v) sqrt(v)
#else
#	define LISin(v) sinf(v)
#	define LICos(v) cosf(v)
#	define LITan(v) tanf(v)
#	define LISqrt(v) sqrtf(v)
#endif

/**
 * 2-component vector
 */
typedef struct
{
	LIFloat x;
	LIFloat y;
} LIVec2;

/**
 * 3-component vector
 */
typedef struct
{
	LIFloat x;
	LIFloat y;
	LIFloat z;
} LIVec3;

/**
 * 4-component vector
 */
typedef struct
{
	LIFloat x;
	LIFloat y;
	LIFloat z;
	LIFloat w;
} LIVec4;

/**
 * 2×2-component matrix
 */
typedef struct {
	LIFloat m00, m01;
	LIFloat m10, m11;
} LIMat2;

/**
 * 3×3-component matrix
 */
typedef struct {
	LIFloat m00, m01, m02;
	LIFloat m10, m11, m12;
	LIFloat m20, m21, m22;
} LIMat3;

/**
 * 4×4-component matrix
 */
typedef struct {
	LIFloat m00, m01, m02, m03;
	LIFloat m10, m11, m12, m13;
	LIFloat m20, m21, m22, m23;
	LIFloat m30, m31, m32, m33;
} LIMat4;


#pragma mark - Scalar functions

/**
 * Get absolute value
 */
#define LIAbs(a) ((a) < 0 ? -(a) : (a))

/**
 * Get smallest of two value
 */
#define LIMin(a, b) ((a) < (b) ? (a) : (b))

/**
 * Get biggest of two value
 */
#define LIMax(a, b) ((a) > (b) ? (a) : (b))

/**
 * Clamp value v to low value l and high value h
 */
#define LIClamp(v, l, h) ((v) < (l) ? (l) : ((v) > (h) ? (h) : (v)))

/**
 * Radians to degrees
 */
static LIFloat LIRadToDegree (LIFloat rad)
{
	return rad / M_PI * 180.0;
}

/**
 * Degrees to radians
 */
static LIFloat LIDegreeToRad (LIFloat degree)
{
	return degree / 180.0 * M_PI;
}


#pragma mark - Vector creation

/**
 * Make 2-component vector
 */
static LIVec2 LIMakeVec2 (LIFloat x, LIFloat y)
{
	return (LIVec2) {x, y};
}

/**
 * Make 3-component vector
 */
static LIVec3 LIMakeVec3 (LIFloat x, LIFloat y, LIFloat z)
{
	return (LIVec3) {x, y, z};
}

/**
 * Make 4-component vector
 */
static LIVec4 LIMakeVec4 (LIFloat x, LIFloat y, LIFloat z, LIFloat w)
{
	return (LIVec4) {x, y, z, w};
}

/**
 * Make 2-component vector from 3-component vector
 */
static LIVec2 LIMakeVec2Vec3 (LIVec3 v)
{
	return (LIVec2) {v.x, v.y};
}

/**
 * Make 2-component vector from 4-component vector
 */
static LIVec2 LIMakeVec2Vec4 (LIVec4 v)
{
	return (LIVec2) {v.x, v.y};
}

/**
 * Make 3-component vector from 4-component vector
 */
static LIVec3 LIMakeVec3Vec4 (LIVec4 v)
{
	return (LIVec3) {v.x, v.y, v.z};
}

/**
 * Make 3-component vector from 2-component vector
 */
static LIVec3 LIMakeVec3Vec2 (LIVec2 v, LIFloat z)
{
	return (LIVec3) {v.x, v.y, z};
}

/**
 * Make 4-component vector from 2-component vector
 */
static LIVec4 LIMakeVec4Vec2 (LIVec2 v, LIFloat z, LIFloat w)
{
	return (LIVec4) {v.x, v.y, z, w};
}

/**
 * Make 4-component vector from 3-component vector
 */
static LIVec4 LIMakeVec4Vec3 (LIVec3 v, LIFloat w)
{
	return (LIVec4) {v.x, v.y, v.z, w};
}


#pragma mark - Vector arithmetic

/**
 * Add two vectors
 */
static LIVec2 LIAddVec2 (LIVec2 a, LIVec2 b)
{
	return LIMakeVec2 (
		a.x + b.x,
		a.y + b.y
	);
}

/**
 * Add two vectors
 */
static LIVec3 LIAddVec3 (LIVec3 a, LIVec3 b)
{
	return LIMakeVec3 (
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	);
}

/**
 * Add two vectors
 */
static LIVec4 LIAddVec4 (LIVec4 a, LIVec4 b)
{
	return LIMakeVec4 (
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		a.w + b.w
	);
}

/**
 * Subtract two vectors
 */
static LIVec2 LISubVec2 (LIVec2 a, LIVec2 b)
{
	return LIMakeVec2 (
		a.x - b.x,
		a.y - b.y
	);
}

/**
 * Subtract two vectors
 */
static LIVec3 LISubVec3 (LIVec3 a, LIVec3 b)
{
	return LIMakeVec3 (
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	);
}

/**
 * Subtract two vectors
 */
static LIVec4 LISubVec4 (LIVec4 a, LIVec4 b)
{
	return LIMakeVec4 (
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w
	);
}

/**
 * Multiply vector
 */
static LIVec2 LIMultVec2 (LIVec2 a, LIFloat l)
{
	return LIMakeVec2 (
		a.x * l,
		a.y * l
	);
}

/**
 * Multiply vector
 */
static LIVec3 LIMultVec3 (LIVec3 a, LIFloat l)
{
	return LIMakeVec3 (
		a.x * l,
		a.y * l,
		a.z * l
	);
}

/**
 * Multiply vector
 */
static LIVec4 LIMultVec4 (LIVec4 a, LIFloat l)
{
	return LIMakeVec4 (
		a.x * l,
		a.y * l,
		a.z * l,
		a.w * l
	);
}


#pragma mark - Other

/**
 * Get length of vector
 */
static LIFloat LILengthVec2 (LIVec2 v)
{
	return LISqrt (v.x * v.x + v.y * v.y);
}

/**
 * Get length of vector
 */
static LIFloat LILengthVec3 (LIVec3 v)
{
	return LISqrt (v.x * v.x + v.y * v.y + v.z * v.z);
}

/**
 * Distance
 */
static LIFloat LIDistanceVec2 (LIVec2 a, LIVec2 b)
{
	return LILengthVec2 (LISubVec2 (a, b));
}

/**
 * Distance
 */
static LIFloat LIDistanceVec3 (LIVec3 a, LIVec3 b)
{
	return LILengthVec3 (LISubVec3 (a, b));
}

/**
 * Normalize vector to length of 1.0
 */
static LIVec2 LINormalizeVec2 (LIVec2 v)
{
	LIFloat l = LILengthVec2 (v);

	if (l != 0.0) {
		v.x /= l;
		v.y /= l;
	}
	else {
		v.x = 0.0;
		v.y = 0.0;
	}

	return v;
}

/**
 * Normalize vector to length of a
 */
static LIVec2 LINormalizeMultVec2 (LIVec2 v, LIFloat a)
{
	LIFloat l = a != 0.0 ? LILengthVec2 (v) / a : 0.0;

	if (l != 0.0) {
		v.x /= l;
		v.y /= l;
	}
	else {
		v.x = 0.0;
		v.y = 0.0;
	}

	return v;
}

/**
 * Normalize vector to length of 1.0
 */
static LIVec3 LINormalizeVec3 (LIVec3 v)
{
	LIFloat l = LILengthVec3 (v);

	if (l != 0.0) {
		v.x /= l;
		v.y /= l;
		v.z /= l;
	}
	else {
		v.x = 0.0;
		v.y = 0.0;
		v.z = 0.0;
	}

	return v;
}

/**
 * Normalize vector to length of a
 */
static LIVec3 LINormalizeMultVec3 (LIVec3 v, LIFloat a)
{
	LIFloat l = a != 0.0 ? LILengthVec3 (v) / a : 0.0;

	if (l != 0.0) {
		v.x /= l;
		v.y /= l;
		v.z /= l;
	}
	else {
		v.x = 0.0;
		v.y = 0.0;
		v.z = 0.0;
	}

	return v;
}

/**
 * Dot product of two vectors
 */
static LIFloat LIDotVec2 (LIVec2 a, LIVec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

/**
 * Dot product of two vectors
 */
static LIFloat LIDotVec3 (LIVec3 a, LIVec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/**
 * Create vector perpendicular to `a`
 */
static LIVec2 LICrossVec2 (LIVec2 a)
{
	return LIMakeVec2 (a.y, -a.x);
}

/**
 * Cross product of two vectors
 */
static LIVec3 LICrossVec3 (LIVec3 a, LIVec3 b)
{
	return LIMakeVec3 (
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}


#pragma mark - Vector rotation

/**
 * Rotate `vector` around origin point `(0, 0)` by `angle` degrees counter clockwise
 */
extern LIVec2 LIRotateVec2 (LIVec2 vector, LIFloat angle);

/**
 * Rotate `vector` around `center` point by `angle` degrees counter clockwise
 */
extern LIVec2 LIRotateRelativeVec2 (LIVec2 vector, LIFloat angle, LIVec2 center);

/**
 * Rotate vector `v` around axis `a`
 * angle: degrees
 */
extern LIVec3 LIRotateVec3 (LIVec3 vector, LIVec3 axis, LIFloat angle);

/**
 * Rotate vector `v` around axis `a` around `center`
 * angle: degrees
 */
extern LIVec3 LIRotateRelativeVec3 (LIVec3 vector, LIVec3 axis, LIFloat angle, LIVec3 center);


#pragma mark - Tool functions

/**
 * Reflect vector at wall
 * wall is a normal vector pointing away from the wall
 */
extern LIVec2 LIReflectVec2 (LIVec2 vector, LIVec2 wall);

/**
 * Reflect vector at wall
 * wall is a normal vector pointing away from the wall
 */
extern LIVec3 LIReflectVec3 (LIVec3 vector, LIVec3 wall);

/**
 * Create plane vector from 2 points
 * `z` contains the plane distance from zero
 */
extern LIVec3 LIMakePlaneVec2 (LIVec2 a, LIVec2 b);

/**
 * Create plane vector from 3 points
 * `w` contains the plane distance from zero
 */
extern LIVec4 LIMakePlaneVec3 (LIVec3 a, LIVec3 b, LIVec3 c);


#pragma mark - Matrix creation

/**
 * The 2x2 identity matrix
 */
extern const LIMat2 LIIdentityMat2;

/**
 * The 3x3 identity matrix
 */
extern const LIMat3 LIIdentityMat3;

/**
 * The 4x4 identity matrix
 */
extern const LIMat4 LIIdentityMat4;

/**
 * Set identity matrix
 */
static void LIMakeIdentityMat2 (LIMat2 * m)
{
	memcpy (m, & LIIdentityMat2, sizeof (LIMat2));
}

/**
 * Set identity matrix
 */
static void LIMakeIdentityMat3 (LIMat3 * m)
{
	memcpy (m, & LIIdentityMat3, sizeof (LIMat3));
}

/**
 * Set identity matrix
 */
static void LIMakeIdentityMat4 (LIMat4 * m)
{
	memcpy (m, & LIIdentityMat4, sizeof (LIMat4));
}

/**
 * Make translation matrix
 */
extern void LIMakeTranslationMat3 (LIMat3 * m, LIVec2 v);

/**
 * Make translation matrix
 */
extern void LIMakeTranslationMat4 (LIMat4 * m, LIVec3 v);

/**
 * Make scale matrix
 */
extern void LIMakeScaleMat2 (LIMat2 * m, LIVec2 v);

/**
 * Make scale matrix
 */
extern void LIMakeScaleMat3 (LIMat3 * m, LIVec2 v);

/**
 * Make scale matrix
 */
extern void LIMakeScaleMat3Vec3 (LIMat3 * m, LIVec3 v);

/**
 * Make scale matrix
 */
extern void LIMakeScaleMat4 (LIMat4 * m, LIVec3 v);

/**
 * Make rotation matrix
 */
extern void LIMakeRotationMat2 (LIMat2 * m, LIFloat a);

/**
 * Make rotation matrix
 */
extern void LIMakeRotationMat3 (LIMat3 * m, LIFloat a);

/**
 * Make rotation matrix
 */
extern void LIMakeRotationMat3Vec3 (LIMat3 * m, LIVec3 v, LIFloat a);

/**
 * Make rotation matrix
 */
extern void LIMakeRotationMat4 (LIMat4 * m, LIVec3 v, LIFloat a);


#pragma mark - Transformation

/**
 * Translate matrix by vector `v`
 */
extern void LITranslateMat3 (LIMat3 * m, LIVec2 v);

/**
 * Translate matrix by vector `v`
 */
extern void LITranslateMat4 (LIMat4 * m, LIVec3 v);

/**
 * Scale matrix by vector `v`
 */
extern void LIScaleMat2 (LIMat2 * m, LIVec2 v);

/**
 * Scale matrix by vector `v`
 */
extern void LIScaleMat3 (LIMat3 * m, LIVec2 v);

/**
 * Scale matrix by vector `v`
 */
extern void LIScaleMat3Vec3 (LIMat3 * m, LIVec3 v);

/**
 * Scale matrix by vector v
 */
extern void LIScaleMat4 (LIMat4 * m, LIVec3 v);

/**
 * Rotate matrix by `a` degrees
 */
extern void LIRotateMat2 (LIMat2 * m, LIFloat a);

/**
 * Rotate matrix by `a` degrees
 */
extern void LIRotateMat3 (LIMat3 * m, LIFloat a);

/**
 * Rotate matrix around axis `v` by `a` degrees
 */
extern void LIRotateMat3Vec3 (LIMat3 * m, LIVec3 v, LIFloat a);

/**
 * Rotate matrix around axis `v` by `a` degrees
 */
extern void LIRotateMat4 (LIMat4 * m, LIVec3 v, LIFloat a);


#pragma mark - Multiplication

/**
 * Mutiply matrix m by n
 * Target and source matrices may be the same
 */
extern void LIMultMat2 (LIMat2 * r, LIMat2 const * m, LIMat2 const * n);

/**
 * Mutiply matrix m by n
 * Target and source matrices may be the same
 */
extern void LIMultMat3 (LIMat3 * r, LIMat3 const * m, LIMat3 const * n);

/**
 * Mutiply matrix m by n
 * Target and source matrices may be the same
 */
extern void LIMultMat3Mat2 (LIMat3 * r, LIMat3 const * m, LIMat2 const * n);

/**
 * Mutiply matrix m by n
 * Target and source matrices may be the same
 */
extern void LIMultMat4 (LIMat4 * r, LIMat4 const * m, LIMat4 const * n);

/**
 * Mutiply matrix m by n
 * Target and source matrices may be the same
 */
extern void LIMultMat4Mat3 (LIMat4 * r, LIMat4 const * m, LIMat3 const * n);

/**
 * Multiply matrix m by vector v
 */
extern LIVec2 LIMultMat2Vec2 (LIMat2 const * m, LIVec2 v);

/**
 * Multiply matrix m by vector v
 */
extern LIVec2 LIMultMat3Vec2 (LIMat3 const * m, LIVec2 v);

/**
 * Multiply matrix m by vector v
 */
extern LIVec3 LIMultMat3Vec3 (LIMat3 const * m, LIVec3 v);

/**
 * Multiply matrix m by vector v
 */
extern LIVec3 LIMultMat4Vec3 (LIMat4 const * m, LIVec3 v);

/**
 * Multiply matrix m by vector v
 */
extern LIVec4 LIMultMat4Vec4 (LIMat4 const * m, LIVec4 v);


#pragma mark - Inverse and transpose

/**
 * Invert matrix
 * Write result to r
 * Returns NO if matrix is not invertible
 * Target and source matrices may be the same
 */
extern int LIInvertMat2 (LIMat2 * r, LIMat2 const * m);

/**
 * Invert matrix
 * Write result to r
 * Returns NO if matrix is not invertible
 * Target and source matrices may be the same
 */
extern int LIInvertMat3 (LIMat3 * r, LIMat3 const * m);

/**
 * Invert matrix
 * Write result to r
 * Returns NO if matrix is not invertible
 * Target and source matrices may be the same
 */
extern int LIInvertMat4 (LIMat4 * r, LIMat4 const * m);

/**
 * Transpose matrix m
 * Write result to r
 * Target and source matrices may be the same
 */
extern void LITransposeMat2 (LIMat2 * r, LIMat2 const * m);

/**
 * Transpose matrix m
 * Write result to r
 * Target and source matrices may be the same
 */
extern void LITransposeMat3 (LIMat3 * r, LIMat3 const * m);

/**
 * Transpose matrix m
 * Write result to r
 * Target and source matrices may be the same
 */
extern void LITransposeMat4 (LIMat4 * r, LIMat4 const * m);


#pragma mark - Copying

/**
 * Copy matrix m to n
 */
static void LICopyMat2 (LIMat2 * n, LIMat2 const * m)
{
	memcpy (n, m, sizeof (LIMat2));
}

/**
 * Copy rotation and scale components m to n
 */
extern void LICopyMat2Mat3 (LIMat2 * n, LIMat3 const * m);

/**
 * Copy matrix m to n
 */
static void LICopyMat3 (LIMat3 * n, LIMat3 const * m)
{
	memcpy (n, m, sizeof (LIMat3));
}

/**
 * Copy rotation and scale components m to n
 */
extern void LICopyMat3Mat2 (LIMat3 * n, LIMat2 const * m);

/**
 * Copy rotation and scale components m to n
 */
extern void LICopyMat3Mat4 (LIMat3 * n, LIMat4 const * m);

/**
 * Copy matrix m to n
 */
static void LICopyMat4 (LIMat4 * n, LIMat4 const * m)
{
	memcpy (n, m, sizeof (LIMat4));
}

/**
 * Copy rotation and scale components m to n
 */
extern void LICopyMat4Mat3 (LIMat4 * n, LIMat3 const * m);


#pragma mark - Print

/**
 * Print LIVec2
 */
extern void LIPrintVec2 (LIVec2 v);

/**
 * Print LIVec3
 */
extern void LIPrintVec3 (LIVec3 v);

/**
 * Print LIVec4
 */
extern void LIPrintVec4 (LIVec4 v);

/**
 * Print LIMat2
 */
extern void LIPrintMat2 (LIMat2 const * m);

/**
 * Print LIMat3
 */
extern void LIPrintMat3 (LIMat3 const * m);

/**
 * Print LIMat4
 */
extern void LIPrintMat4 (LIMat4 const * m);



#pragma mark - Camera

/**
 * Make modelview lookat-matrix
 */
extern void LIMakeModelviewEyeMat4 (LIMat4 * m, LIVec3 eye, LIVec3 lookAt, LIVec3 up);

/**
 * Make orthogonal projection matrix
 */
extern void LIMakeProjectionOrthogonalMat4 (LIMat4 * m, LIVec2 viewportSize, LIFloat near, LIFloat far);

/**
 * Make perspective projection matrix
 */
extern void LIMakeProjectionPerspectiveMat4 (LIMat4 * m, LIVec2 viewportSize, LIFloat near, LIFloat far, LIFloat fovy);

/**
 * Project point on screen
 * If `projection` is NULL, `modelView` is interpreted as pre-calculated
 * modelview projection matrix (P * M)
 */
extern int LIProjectVec3 (LIVec3 * screen, LIVec3 object, LIMat4 const * modelView, LIMat4 const * projection, LIVec2 viewportPosition, LIVec2 viewportSize);

/**
 * Unproject point from screen
 * If `projection` is NULL, `modelView` is interpreted as pre-calculated inverse
 * of model view projection matrix (P * M) ^ -1
 */
extern int LIUnprojectVec3 (LIVec3 * object, LIVec3 screen, LIMat4 const * modelView, LIMat4 const * projection, LIVec2 viewportPosition, LIVec2 viewportSize);

#endif /* ! _LITHIUM_H_ */
