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

#include "Lithium.h"

LIMat2 const LIIdentityMat2 =
{
	1.0, 0.0,
	0.0, 1.0,
};

LIMat3 const LIIdentityMat3 =
{
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
};

LIMat4 const LIIdentityMat4 =
{
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	0.0, 0.0, 0.0, 1.0,
};

LIVec2 LIRotateVec2 (LIVec2 v, LIFloat r)
{
	LIVec2  vr;
	LIFloat c, s;

	r = LIDegreeToRad (r);
	c = LICos (r);
	s = LISin (r);

	vr.x = v.x * c - v.y * s;
	vr.y = v.x * s + v.y * c;

	return vr;
}

LIVec2 LIRotateRelativeVec2 (LIVec2 vector, LIFloat angle, LIVec2 center)
{
	// (v - c) *^ a + c
	return LIAddVec2 (LIRotateVec2 (LISubVec2 (vector, center), angle), center);
}

LIVec3 LIRotateVec3 (LIVec3 v, LIVec3 a, LIFloat r)
{
	LIVec3  vr;
	LIFloat c, s, t;

	r = LIDegreeToRad (r);
	a = LINormalizeVec3 (a);
	c = LICos (r);
	s = LISin (r);
	t = 1.0 - c;

	vr.x = v.x * (c + t * a.x * a.x)       + v.y * (t * a.x * a.y - s * a.z) + v.z * (t * a.x * a.z + s * a.y);
	vr.y = v.x * (t * a.x * a.y + s * a.z) + v.y * (c + t * a.y * a.y)       + v.z * (t * a.y * a.z - s * a.x);
	vr.z = v.x * (t * a.x * a.z - s * a.y) + v.y * (t * a.y * a.z + s * a.x) + v.z * (c + t * a.z * a.z);

	return vr;
}

LIVec3 LIRotateRelativeVec3 (LIVec3 vector, LIVec3 axis, LIFloat angle, LIVec3 center)
{
	// (v - c) *^ a + c
	return LIAddVec3 (LIRotateVec3 (LISubVec3 (vector, center), axis, angle), center);
}

LIVec2 LIReflectVec2 (LIVec2 vector, LIVec2 wall)
{
	wall   = LINormalizeVec2 (wall);
	vector = LISubVec2 (vector, LIMultVec2 (wall, 2.0 * LIDotVec2 (wall, vector)));

	return vector;
}

LIVec3 LIReflectVec3 (LIVec3 vector, LIVec3 wall)
{
	wall   = LINormalizeVec3 (wall);
	vector = LISubVec3 (vector, LIMultVec3 (wall, 2.0 * LIDotVec3 (wall, vector)));

	return vector;
}

LIVec3 LIMakePlaneVec2 (LIVec2 a, LIVec2 b)
{
	LIVec3 plane;
	LIVec2 d1 = LISubVec2 (b, a);
	LIVec2 p  = LINormalizeVec2 (LICrossVec2 (d1));

	plane = LIMakeVec3Vec2 (p, LIDotVec2 (p, a));

	return plane;
}

LIVec4 LIMakePlaneVec3 (LIVec3 a, LIVec3 b, LIVec3 c)
{
	LIVec4 plane;
	LIVec3 d1 = LISubVec3 (b, a);
	LIVec3 d2 = LISubVec3 (c, a);
	LIVec3 p  = LINormalizeVec3 (LICrossVec3 (d1, d2));

	plane = LIMakeVec4Vec3 (p, LIDotVec3 (p, a));

	return plane;
}

void LIMakeTranslationMat3 (LIMat3 * m, LIVec2 v)
{
	m -> m00 = 1.0;
	m -> m01 = 0.0;
	m -> m02 = 0.0;

	m -> m10 = 0.0;
	m -> m11 = 1.0;
	m -> m12 = 0.0;

	m -> m20 = v.x;
	m -> m21 = v.y;
	m -> m22 = 1.0;
}

void LIMakeTranslationMat4 (LIMat4 * m, LIVec3 v)
{
	m -> m00 = 1.0;
	m -> m01 = 0.0;
	m -> m02 = 0.0;
	m -> m03 = 0.0;

	m -> m10 = 0.0;
	m -> m11 = 1.0;
	m -> m12 = 0.0;
	m -> m13 = 0.0;

	m -> m20 = 0.0;
	m -> m21 = 0.0;
	m -> m22 = 1.0;
	m -> m23 = 0.0;

	m -> m30 = v.x;
	m -> m31 = v.y;
	m -> m32 = v.z;
	m -> m33 = 1.0;
}

void LIMakeScaleMat2 (LIMat2 * m, LIVec2 v)
{
	m -> m00 = v.x;
	m -> m01 = 0.0;

	m -> m10 = 0.0;
	m -> m11 = v.y;
}

void LIMakeScaleMat3Vec3 (LIMat3 * m, LIVec3 v)
{
	m -> m00 = v.x;
	m -> m01 = 0.0;
	m -> m02 = 0.0;

	m -> m10 = 0.0;
	m -> m11 = v.y;
	m -> m12 = 0.0;

	m -> m20 = 0.0;
	m -> m21 = 0.0;
	m -> m22 = v.z;
}

void LIMakeScaleMat3 (LIMat3 * m, LIVec2 v)
{
	m -> m00 = v.x;
	m -> m01 = 0.0;
	m -> m02 = 0.0;

	m -> m10 = 0.0;
	m -> m11 = v.y;
	m -> m12 = 0.0;

	m -> m20 = 0.0;
	m -> m21 = 0.0;
	m -> m22 = 0.0;
}

void LIMakeScaleMat4 (LIMat4 * m, LIVec3 v)
{
	m -> m00 = v.x;
	m -> m01 = 0.0;
	m -> m02 = 0.0;
	m -> m03 = 0.0;

	m -> m10 = 0.0;
	m -> m11 = v.y;
	m -> m12 = 0.0;
	m -> m13 = 0.0;

	m -> m20 = 0.0;
	m -> m21 = 0.0;
	m -> m22 = v.z;
	m -> m23 = 0.0;

	m -> m30 = 0.0;
	m -> m31 = 0.0;
	m -> m32 = 0.0;
	m -> m33 = 1.0;
}

void LIMakeRotationMat2 (LIMat2 * m, LIFloat a)
{
	LIFloat c, s;

	a = LIDegreeToRad (a);
	c = LICos (a);
	s = LISin (a);

	m -> m00 = c;
	m -> m01 = s;

	m -> m10 = -s;
	m -> m11 = c;
}

void LIMakeRotationMat3 (LIMat3 * m, LIFloat a)
{
	LIFloat c, s;

	a = LIDegreeToRad (a);
	c = LICos (a);
	s = LISin (a);

	m -> m00 = c;
	m -> m01 = s;
	m -> m02 = 0.0;

	m -> m10 = -s;
	m -> m11 = c;
	m -> m12 = 0.0;

	m -> m20 = 0.0;
	m -> m21 = 0.0;
	m -> m22 = 1.0;
}

void LIMakeRotationMat3Vec3 (LIMat3 * m, LIVec3 v, LIFloat a)
{
	LIFloat c, s, t;

	a = LIDegreeToRad (a);
	v = LINormalizeVec3 (v);
	c = LICos (a);
	s = LISin (a);
	t = 1.0 - c;

	m -> m00 = (c + t * v.x * v.x);
	m -> m01 = (t * v.x * v.y + s * v.z);
	m -> m02 = (t * v.x * v.z - s * v.y);

	m -> m10 = (t * v.x * v.y - s * v.z);
	m -> m11 = (c + t * v.y * v.y);
	m -> m12 = (t * v.y * v.z + s * v.x);

	m -> m20 = (t * v.x * v.z + s * v.y);
	m -> m21 = (t * v.y * v.z - s * v.x);
	m -> m22 = (c + t * v.z * v.z);
}

void LIMakeRotationMat4 (LIMat4 * m, LIVec3 v, LIFloat a)
{
	LIFloat c, s, t;

	a = LIDegreeToRad (a);
	v = LINormalizeVec3 (v);
	c = LICos (a);
	s = LISin (a);
	t = 1.0 - c;

	m -> m00 = (c + t * v.x * v.x);
	m -> m01 = (t * v.x * v.y + s * v.z);
	m -> m02 = (t * v.x * v.z - s * v.y);
	m -> m03 = 0.0;

	m -> m10 = (t * v.x * v.y - s * v.z);
	m -> m11 = (c + t * v.y * v.y);
	m -> m12 = (t * v.y * v.z + s * v.x);
	m -> m13 = 0.0;

	m -> m20 = (t * v.x * v.z + s * v.y);
	m -> m21 = (t * v.y * v.z - s * v.x);
	m -> m22 = (c + t * v.z * v.z);
	m -> m23 = 0.0;

	m -> m30 = 0.0;
	m -> m31 = 0.0;
	m -> m32 = 0.0;
	m -> m33 = 1.0;
}

void LICopyMat2Mat3 (LIMat2 * n, LIMat3 const * m)
{
	n -> m00 = m -> m00;
	n -> m01 = m -> m01;

	n -> m10 = m -> m10;
	n -> m11 = m -> m11;
}

void LICopyMat3Mat2 (LIMat3 * n, LIMat2 const * m)
{
	n -> m00 = m -> m00;
	n -> m01 = m -> m01;

	n -> m10 = m -> m10;
	n -> m11 = m -> m11;
}

void LICopyMat3Mat4 (LIMat3 * n, LIMat4 const * m)
{
	n -> m00 = m -> m00;
	n -> m01 = m -> m01;
	n -> m02 = m -> m02;

	n -> m10 = m -> m10;
	n -> m11 = m -> m11;
	n -> m12 = m -> m12;

	n -> m20 = m -> m20;
	n -> m21 = m -> m21;
	n -> m22 = m -> m22;
}

void LICopyMat4Mat3 (LIMat4 * n, LIMat3 const * m)
{
	n -> m00 = m -> m00;
	n -> m01 = m -> m01;
	n -> m02 = m -> m02;

	n -> m10 = m -> m10;
	n -> m11 = m -> m11;
	n -> m12 = m -> m12;

	n -> m20 = m -> m20;
	n -> m21 = m -> m21;
	n -> m22 = m -> m22;
}

void LITranslateMat3 (LIMat3 * m, LIVec2 v)
{
	m -> m20 += v.x * m -> m00 + v.y * m -> m10;
	m -> m21 += v.x * m -> m01 + v.y * m -> m11;
}

void LITranslateMat4 (LIMat4 * m, LIVec3 v)
{
	m -> m30 += v.x * m -> m00 + v.y * m -> m10 + v.z * m -> m20;
	m -> m31 += v.x * m -> m01 + v.y * m -> m11 + v.z * m -> m21;
	m -> m32 += v.x * m -> m02 + v.y * m -> m12 + v.z * m -> m22;
}

void LIScaleMat2 (LIMat2 * m, LIVec2 v)
{
	m -> m00 = m -> m00 * v.x;
	m -> m01 = m -> m01 * v.x;

	m -> m10 = m -> m10 * v.y;
	m -> m11 = m -> m11 * v.y;
}

void LIScaleMat3 (LIMat3 * m, LIVec2 v)
{
	m -> m00 = m -> m00 * v.x;
	m -> m01 = m -> m01 * v.x;

	m -> m10 = m -> m10 * v.y;
	m -> m11 = m -> m11 * v.y;
}

void LIScaleMat3Vec3 (LIMat3 * m, LIVec3 v)
{
	m -> m00 = m -> m00 * v.x;
	m -> m01 = m -> m01 * v.x;
	m -> m02 = m -> m02 * v.x;

	m -> m10 = m -> m10 * v.y;
	m -> m11 = m -> m11 * v.y;
	m -> m12 = m -> m12 * v.y;

	m -> m20 = m -> m20 * v.z;
	m -> m21 = m -> m21 * v.z;
	m -> m22 = m -> m22 * v.z;
}

void LIScaleMat4 (LIMat4 * m, LIVec3 v)
{
	m -> m00 = m -> m00 * v.x;
	m -> m01 = m -> m01 * v.x;
	m -> m02 = m -> m02 * v.x;

	m -> m10 = m -> m10 * v.y;
	m -> m11 = m -> m11 * v.y;
	m -> m12 = m -> m12 * v.y;

	m -> m20 = m -> m20 * v.z;
	m -> m21 = m -> m21 * v.z;
	m -> m22 = m -> m22 * v.z;
}

void LIRotateMat2 (LIMat2 * m, LIFloat a)
{
	LIMat2 r;

	LIMakeRotationMat2 (& r, a);
	LIMultMat2 (m, m, & r);
}

void LIRotateMat3 (LIMat3 * m, LIFloat a)
{
	LIMat2 r;

	LIMakeRotationMat2 (& r, a);
	LIMultMat3Mat2 (m, m, & r);
}

void LIRotateMat3Vec3 (LIMat3 * m, LIVec3 v, LIFloat a)
{
	LIMat3 r;

	LIMakeRotationMat3Vec3 (& r, v, a);
	LIMultMat3 (m, m, & r);
}

void LIRotateMat4 (LIMat4 * m, LIVec3 v, LIFloat a)
{
	LIMat4 r;

	LIMakeRotationMat4 (& r, v, a);
	LIMultMat4 (m, m, & r);
}

void LIMultMat2 (LIMat2 * r, LIMat2 const * m1, LIMat2 const * m2)
{
	LIMat2   r0;
	int      makeCopy = (r == m1 || r == m2);
	LIMat2 * result = makeCopy ? & r0 : r;

	result -> m00 = m1 -> m00 * m2 -> m00 + m1 -> m10 * m2 -> m01;
	result -> m01 = m1 -> m01 * m2 -> m00 + m1 -> m11 * m2 -> m01;

	result -> m10 = m1 -> m00 * m2 -> m10 + m1 -> m10 * m2 -> m11;
	result -> m11 = m1 -> m01 * m2 -> m10 + m1 -> m11 * m2 -> m11;

	if (makeCopy) {
		LICopyMat2 (r, result);
	}
}

void LIMultMat3 (LIMat3 * r, LIMat3 const * m1, LIMat3 const * m2)
{
	LIMat3   r0;
	int      makeCopy = (r == m1 || r == m2);
	LIMat3 * result = makeCopy ? & r0 : r;

	result -> m00 = m1 -> m00 * m2 -> m00 + m1 -> m10 * m2 -> m01 + m1 -> m20 * m2 -> m02;
	result -> m01 = m1 -> m01 * m2 -> m00 + m1 -> m11 * m2 -> m01 + m1 -> m21 * m2 -> m02;
	result -> m02 = m1 -> m02 * m2 -> m00 + m1 -> m12 * m2 -> m01 + m1 -> m22 * m2 -> m02;

	result -> m10 = m1 -> m00 * m2 -> m10 + m1 -> m10 * m2 -> m11 + m1 -> m20 * m2 -> m12;
	result -> m11 = m1 -> m01 * m2 -> m10 + m1 -> m11 * m2 -> m11 + m1 -> m21 * m2 -> m12;
	result -> m12 = m1 -> m02 * m2 -> m10 + m1 -> m12 * m2 -> m11 + m1 -> m22 * m2 -> m12;

	result -> m20 = m1 -> m00 * m2 -> m20 + m1 -> m10 * m2 -> m21 + m1 -> m20 * m2 -> m22;
	result -> m21 = m1 -> m01 * m2 -> m20 + m1 -> m11 * m2 -> m21 + m1 -> m21 * m2 -> m22;
	result -> m22 = m1 -> m02 * m2 -> m20 + m1 -> m12 * m2 -> m21 + m1 -> m22 * m2 -> m22;

	if (makeCopy) {
		LICopyMat3 (r, result);
	}
}

void LIMultMat3Mat2 (LIMat3 * r, LIMat3 const * m1, LIMat2 const * m2)
{
	LIMat3   r0;
	int      makeCopy = (r == m1);
	LIMat3 * result = makeCopy ? & r0 : r;

	result -> m00 = m1 -> m00 * m2 -> m00 + m1 -> m10 * m2 -> m01;
	result -> m01 = m1 -> m01 * m2 -> m00 + m1 -> m11 * m2 -> m01;
	result -> m02 = m1 -> m02 * m2 -> m00 + m1 -> m12 * m2 -> m01;

	result -> m10 = m1 -> m00 * m2 -> m10 + m1 -> m10 * m2 -> m11;
	result -> m11 = m1 -> m01 * m2 -> m10 + m1 -> m11 * m2 -> m11;
	result -> m12 = m1 -> m02 * m2 -> m10 + m1 -> m12 * m2 -> m11;

	result -> m20 = m1 -> m20;
	result -> m21 = m1 -> m21;
	result -> m22 = m1 -> m22;

	if (makeCopy) {
		LICopyMat3 (r, result);
	}
}

void LIMultMat4 (LIMat4 * r, LIMat4 const * m1, LIMat4 const * m2)
{
	LIMat4   r0;
	int      makeCopy = (r == m1 || r == m2);
	LIMat4 * result = makeCopy ? & r0 : r;

	result -> m00 = m1 -> m00 * m2 -> m00 + m1 -> m10 * m2 -> m01 + m1 -> m20 * m2 -> m02 + m1 -> m30 * m2 -> m03;
	result -> m01 = m1 -> m01 * m2 -> m00 + m1 -> m11 * m2 -> m01 + m1 -> m21 * m2 -> m02 + m1 -> m31 * m2 -> m03;
	result -> m02 = m1 -> m02 * m2 -> m00 + m1 -> m12 * m2 -> m01 + m1 -> m22 * m2 -> m02 + m1 -> m32 * m2 -> m03;
	result -> m03 = m1 -> m03 * m2 -> m00 + m1 -> m13 * m2 -> m01 + m1 -> m23 * m2 -> m02 + m1 -> m33 * m2 -> m03;

	result -> m10 = m1 -> m00 * m2 -> m10 + m1 -> m10 * m2 -> m11 + m1 -> m20 * m2 -> m12 + m1 -> m30 * m2 -> m13;
	result -> m11 = m1 -> m01 * m2 -> m10 + m1 -> m11 * m2 -> m11 + m1 -> m21 * m2 -> m12 + m1 -> m31 * m2 -> m13;
	result -> m12 = m1 -> m02 * m2 -> m10 + m1 -> m12 * m2 -> m11 + m1 -> m22 * m2 -> m12 + m1 -> m32 * m2 -> m13;
	result -> m13 = m1 -> m03 * m2 -> m10 + m1 -> m13 * m2 -> m11 + m1 -> m23 * m2 -> m12 + m1 -> m33 * m2 -> m13;

	result -> m20 = m1 -> m00 * m2 -> m20 + m1 -> m10 * m2 -> m21 + m1 -> m20 * m2 -> m22 + m1 -> m30 * m2 -> m23;
	result -> m21 = m1 -> m01 * m2 -> m20 + m1 -> m11 * m2 -> m21 + m1 -> m21 * m2 -> m22 + m1 -> m31 * m2 -> m23;
	result -> m22 = m1 -> m02 * m2 -> m20 + m1 -> m12 * m2 -> m21 + m1 -> m22 * m2 -> m22 + m1 -> m32 * m2 -> m23;
	result -> m23 = m1 -> m03 * m2 -> m20 + m1 -> m13 * m2 -> m21 + m1 -> m23 * m2 -> m22 + m1 -> m33 * m2 -> m23;

	result -> m30 = m1 -> m00 * m2 -> m30 + m1 -> m10 * m2 -> m31 + m1 -> m20 * m2 -> m32 + m1 -> m30 * m2 -> m33;
	result -> m31 = m1 -> m01 * m2 -> m30 + m1 -> m11 * m2 -> m31 + m1 -> m21 * m2 -> m32 + m1 -> m31 * m2 -> m33;
	result -> m32 = m1 -> m02 * m2 -> m30 + m1 -> m12 * m2 -> m31 + m1 -> m22 * m2 -> m32 + m1 -> m32 * m2 -> m33;
	result -> m33 = m1 -> m03 * m2 -> m30 + m1 -> m13 * m2 -> m31 + m1 -> m23 * m2 -> m32 + m1 -> m33 * m2 -> m33;

	if (makeCopy) {
		LICopyMat4 (r, result);
	}
}

void LIMultMat4Mat3 (LIMat4 * r, LIMat4 const * m1, LIMat3 const * m2)
{
	LIMat4   r0;
	int      makeCopy = (r == m1);
	LIMat4 * result = makeCopy ? & r0 : r;

	result -> m00 = m1 -> m00 * m2 -> m00 + m1 -> m10 * m2 -> m01 + m1 -> m20 * m2 -> m02;
	result -> m01 = m1 -> m01 * m2 -> m00 + m1 -> m11 * m2 -> m01 + m1 -> m21 * m2 -> m02;
	result -> m02 = m1 -> m02 * m2 -> m00 + m1 -> m12 * m2 -> m01 + m1 -> m22 * m2 -> m02;
	result -> m03 = m1 -> m03 * m2 -> m00 + m1 -> m13 * m2 -> m01 + m1 -> m23 * m2 -> m02;

	result -> m10 = m1 -> m00 * m2 -> m10 + m1 -> m10 * m2 -> m11 + m1 -> m20 * m2 -> m12;
	result -> m11 = m1 -> m01 * m2 -> m10 + m1 -> m11 * m2 -> m11 + m1 -> m21 * m2 -> m12;
	result -> m12 = m1 -> m02 * m2 -> m10 + m1 -> m12 * m2 -> m11 + m1 -> m22 * m2 -> m12;
	result -> m13 = m1 -> m03 * m2 -> m10 + m1 -> m13 * m2 -> m11 + m1 -> m23 * m2 -> m12;

	result -> m20 = m1 -> m00 * m2 -> m20 + m1 -> m10 * m2 -> m21 + m1 -> m20 * m2 -> m22;
	result -> m21 = m1 -> m01 * m2 -> m20 + m1 -> m11 * m2 -> m21 + m1 -> m21 * m2 -> m22;
	result -> m22 = m1 -> m02 * m2 -> m20 + m1 -> m12 * m2 -> m21 + m1 -> m22 * m2 -> m22;
	result -> m23 = m1 -> m03 * m2 -> m20 + m1 -> m13 * m2 -> m21 + m1 -> m23 * m2 -> m22;

	result -> m30 = m1 -> m30;
	result -> m31 = m1 -> m31;
	result -> m32 = m1 -> m32;
	result -> m33 = m1 -> m33;

	if (makeCopy) {
		LICopyMat4 (r, result);
	}
}

LIVec2 LIMultMat2Vec2 (LIMat2 const * m, LIVec2 v)
{
	LIVec2 vm;

	vm.x = m -> m00 * v.x + m -> m10 * v.y;
	vm.y = m -> m01 * v.x + m -> m11 * v.y;

	return vm;
}

LIVec2 LIMultMat3Vec2 (LIMat3 const * m, LIVec2 v)
{
	LIVec2 vm;

	vm.x = m -> m00 * v.x + m -> m10 * v.y;
	vm.y = m -> m01 * v.x + m -> m11 * v.y;

	return vm;
}

LIVec3 LIMultMat3Vec3 (LIMat3 const * m, LIVec3 v)
{
	LIVec3 vm;

	vm.x = m -> m00 * v.x + m -> m10 * v.y + m -> m20 * v.z;
	vm.y = m -> m01 * v.x + m -> m11 * v.y + m -> m21 * v.z;
	vm.z = m -> m02 * v.x + m -> m12 * v.y + m -> m22 * v.z;

	return vm;
}

LIVec3 LIMultMat4Vec3 (LIMat4 const * m, LIVec3 v)
{
	LIVec3 vm;

	// v = {x, y, z, w=1.0}
	vm.x = m -> m00 * v.x + m -> m10 * v.y + m -> m20 * v.z + m -> m30 * 1.0;
	vm.y = m -> m01 * v.x + m -> m11 * v.y + m -> m21 * v.z + m -> m31 * 1.0;
	vm.z = m -> m02 * v.x + m -> m12 * v.y + m -> m22 * v.z + m -> m32 * 1.0;

	return vm;
}

LIVec4 LIMultMat4Vec4 (LIMat4 const * m, LIVec4 v)
{
	LIVec4 vm;

	vm.x = m -> m00 * v.x + m -> m10 * v.y + m -> m20 * v.z + m -> m30 * v.w;
	vm.y = m -> m01 * v.x + m -> m11 * v.y + m -> m21 * v.z + m -> m31 * v.w;
	vm.z = m -> m02 * v.x + m -> m12 * v.y + m -> m22 * v.z + m -> m32 * v.w;
	vm.w = m -> m03 * v.x + m -> m13 * v.y + m -> m23 * v.z + m -> m33 * v.w;

	return vm;
}

///**
// * Gauss-Jordan Elimination
// * Mathematics for 3D Programming & Computer Graphics / Second Edition
// * Page 45
// */
///*
//static int LIMatNMInvert (LIFloat * r, const LIFloat * m, unsigned cols, unsigned rows)
//{
//	// Augmented matrix
//	// r r r 1 0 0
//	// r r r 0 1 0
//	// r r r 0 0 1
//
//	LIFloat inverse [cols * 2][rows];
//
//	// Build augmented matrix (A)
//	memcpy (& inverse [0], m, cols * rows * sizeof (LIFloat));
//
//	// make identity matrix in extra matrix
//	for (int i = 0; i < cols; i ++) {
//		for (int j = 0; j < rows; j ++) {
//			if (i == j) {
//				inverse [i + cols][j] = 1.0;
//			} else {
//				inverse [i + cols][j] = 0.0;
//			}
//		}
//	}
//
//	// Loop through columns 1 to n (B)
//	for (int j = 0; j < cols; j ++) {
//		int     i = j;
//		LIFloat v = LIAbs (inverse [j][j]);
//
//		// Search for largest absolute value in column with i >= j (C)
//		for (int r = j; r < rows; r ++) {
//			LIFloat av = LIAbs (inverse [j][r]);
//			if (av > v) {
//				v = av;
//				i = r;
//			}
//		}
//
//		// No value != 0; Matrix not invertible
//		if (v == 0.0)
//			return -1;
//
//		// Exchange row i with row j (D)
//		if (i != j) {
//			for (int c = 0; c < cols * 2; c ++) {
//				LIFloat t = inverse [c][i];
//				inverse [c][i] = inverse [c][j];
//				inverse [c][j] = t;
//			}
//		}
//
//		// Normalize row j (E)
//		LIFloat d = inverse [j][j];
//
//		for (int r = 0; r < cols * 2; r ++)
//			inverse [r][j] /= d;
//
//		// (F)
//		for (int r = 0; r < rows; r ++) {
//			if (r != j) {
//				LIFloat v = inverse [j][r];
//				for (int c = 0; c < cols * 2; c ++)
//					inverse [c][r] += -v * inverse [c][j];
//			}
//		}
//	}
//
//	// Copy extra columns of augmented matrix
//	memcpy (r, & inverse [cols][0], sizeof (LIMat3));
//
//	return 0;
//}

int LIInvertMat2 (LIMat2 * r, LIMat2 const * m)
{
	LIMat2   r0;
	int      makeCopy = (r == m);
	LIMat2 * result = makeCopy ? & r0 : r;
	LIFloat  det;

	det = result -> m00 * result -> m11 - result -> m01 * result -> m10;

	if (det == 0.0) {
		return -1;
	}

	det = 1.0 / det;

	result -> m00 =  m -> m11 * det;
	result -> m01 = -m -> m01 * det;

	result -> m10 = -m -> m10 * det;
	result -> m11 =  m -> m00 * det;

	if (makeCopy) {
		LICopyMat2 (r, result);
	}

	return 0;
}

int LIInvertMat3 (LIMat3 * r, LIMat3 const * m)
{
	LIMat3   r0;
	int      makeCopy = (r == m);
	LIMat3 * inv = makeCopy ? & r0 : r;
	LIFloat  det;

	inv -> m00 =  m -> m11 * m -> m22 - m -> m12 * m -> m21;
	inv -> m01 = -m -> m01 * m -> m22 + m -> m02 * m -> m21;
	inv -> m02 =  m -> m01 * m -> m12 - m -> m02 * m -> m11;
	inv -> m10 = -m -> m10 * m -> m22 + m -> m12 * m -> m20;
	inv -> m11 =  m -> m00 * m -> m22 - m -> m02 * m -> m20;
	inv -> m12 = -m -> m00 * m -> m12 + m -> m02 * m -> m10;
	inv -> m20 =  m -> m10 * m -> m21 - m -> m11 * m -> m20;
	inv -> m21 = -m -> m00 * m -> m21 + m -> m01 * m -> m20;
	inv -> m22 =  m -> m00 * m -> m11 - m -> m01 * m -> m10;

	det = m -> m00 * inv -> m00 + m -> m10 * inv -> m01 + m -> m20 * inv -> m02;

	if (det == 0.0) {
		return -1;
	}

	det = 1.0 / det;

	for (int i = 0; i < 9; i ++) {
		((LIFloat *) inv) [i] *= det;
	}

	if (makeCopy) {
		LICopyMat3 (r, inv);
	}

	return 0;
}

int LIInvertMat4 (LIMat4 * r, LIMat4 const * m)
{
	LIMat4   r0;
	int     makeCopy = (r == m);
	LIMat4 * inv = makeCopy ? & r0 : r;
	LIFloat  det;

	inv -> m00 =  m -> m11 * m -> m22 * m -> m33 - m -> m11 * m -> m32 * m -> m23 - m -> m12 * m -> m21 * m -> m33
	           +  m -> m12 * m -> m31 * m -> m23 + m -> m13 * m -> m21 * m -> m32 - m -> m13 * m -> m31 * m -> m22;
	inv -> m01 = -m -> m01 * m -> m22 * m -> m33 + m -> m01 * m -> m32 * m -> m23 + m -> m02 * m -> m21 * m -> m33
	           -  m -> m02 * m -> m31 * m -> m23 - m -> m03 * m -> m21 * m -> m32 + m -> m03 * m -> m31 * m -> m22;
	inv -> m02 =  m -> m01 * m -> m12 * m -> m33 - m -> m01 * m -> m32 * m -> m13 - m -> m02 * m -> m11 * m -> m33
	           +  m -> m02 * m -> m31 * m -> m13 + m -> m03 * m -> m11 * m -> m32 - m -> m03 * m -> m31 * m -> m12;
	inv -> m03 = -m -> m01 * m -> m12 * m -> m23 + m -> m01 * m -> m22 * m -> m13 + m -> m02 * m -> m11 * m -> m23
	           -  m -> m02 * m -> m21 * m -> m13 - m -> m03 * m -> m11 * m -> m22 + m -> m03 * m -> m21 * m -> m12;
	inv -> m10 = -m -> m10 * m -> m22 * m -> m33 + m -> m10 * m -> m32 * m -> m23 + m -> m12 * m -> m20 * m -> m33
	           -  m -> m12 * m -> m30 * m -> m23 - m -> m13 * m -> m20 * m -> m32 + m -> m13 * m -> m30 * m -> m22;
	inv -> m11 =  m -> m00 * m -> m22 * m -> m33 - m -> m00 * m -> m32 * m -> m23 - m -> m02 * m -> m20 * m -> m33
	           +  m -> m02 * m -> m30 * m -> m23 + m -> m03 * m -> m20 * m -> m32 - m -> m03 * m -> m30 * m -> m22;
	inv -> m12 = -m -> m00 * m -> m12 * m -> m33 + m -> m00 * m -> m32 * m -> m13 + m -> m02 * m -> m10 * m -> m33
	           -  m -> m02 * m -> m30 * m -> m13 - m -> m03 * m -> m10 * m -> m32 + m -> m03 * m -> m30 * m -> m12;
	inv -> m13 =  m -> m00 * m -> m12 * m -> m23 - m -> m00 * m -> m22 * m -> m13 - m -> m02 * m -> m10 * m -> m23
	           +  m -> m02 * m -> m20 * m -> m13 + m -> m03 * m -> m10 * m -> m22 - m -> m03 * m -> m20 * m -> m12;
	inv -> m20 =  m -> m10 * m -> m21 * m -> m33 - m -> m10 * m -> m31 * m -> m23 - m -> m11 * m -> m20 * m -> m33
	           +  m -> m11 * m -> m30 * m -> m23 + m -> m13 * m -> m20 * m -> m31 - m -> m13 * m -> m30 * m -> m21;
	inv -> m21 = -m -> m00 * m -> m21 * m -> m33 + m -> m00 * m -> m31 * m -> m23 + m -> m01 * m -> m20 * m -> m33
	           -  m -> m01 * m -> m30 * m -> m23 - m -> m03 * m -> m20 * m -> m31 + m -> m03 * m -> m30 * m -> m21;
	inv -> m22 =  m -> m00 * m -> m11 * m -> m33 - m -> m00 * m -> m31 * m -> m13 - m -> m01 * m -> m10 * m -> m33
	           +  m -> m01 * m -> m30 * m -> m13 + m -> m03 * m -> m10 * m -> m31 - m -> m03 * m -> m30 * m -> m11;
	inv -> m23 = -m -> m00 * m -> m11 * m -> m23 + m -> m00 * m -> m21 * m -> m13 + m -> m01 * m -> m10 * m -> m23
	           -  m -> m01 * m -> m20 * m -> m13 - m -> m03 * m -> m10 * m -> m21 + m -> m03 * m -> m20 * m -> m11;
	inv -> m30 = -m -> m10 * m -> m21 * m -> m32 + m -> m10 * m -> m31 * m -> m22 + m -> m11 * m -> m20 * m -> m32
	           -  m -> m11 * m -> m30 * m -> m22 - m -> m12 * m -> m20 * m -> m31 + m -> m12 * m -> m30 * m -> m21;
	inv -> m31 =  m -> m00 * m -> m21 * m -> m32 - m -> m00 * m -> m31 * m -> m22 - m -> m01 * m -> m20 * m -> m32
	           +  m -> m01 * m -> m30 * m -> m22 + m -> m02 * m -> m20 * m -> m31 - m -> m02 * m -> m30 * m -> m21;
	inv -> m32 = -m -> m00 * m -> m11 * m -> m32 + m -> m00 * m -> m31 * m -> m12 + m -> m01 * m -> m10 * m -> m32
	           -  m -> m01 * m -> m30 * m -> m12 - m -> m02 * m -> m10 * m -> m31 + m -> m02 * m -> m30 * m -> m11;
	inv -> m33 =  m -> m00 * m -> m11 * m -> m22 - m -> m00 * m -> m21 * m -> m12 - m -> m01 * m -> m10 * m -> m22
	           +  m -> m01 * m -> m20 * m -> m12 + m -> m02 * m -> m10 * m -> m21 - m -> m02 * m -> m20 * m -> m11;

	det = m -> m00 * inv -> m00 + m -> m10 * inv -> m01 + m -> m20 * inv -> m02 + m -> m30 * inv -> m03;

	if (det == 0.0) {
		return -1;
	}

	det = 1.0 / det;

	for (int i = 0; i < 16; i ++) {
		((LIFloat *) inv) [i] *= det;
	}

	if (makeCopy) {
		LICopyMat4 (r, inv);
	}

	return 0;
}

void LITransposeMat2 (LIMat2 * r, LIMat2 const * m)
{
	LIMat2   r0;
	int      makeCopy = (r == m);
	LIMat2 * result = makeCopy ? & r0 : r;

	result -> m00 = m -> m00;
	result -> m01 = m -> m10;

	result -> m10 = m -> m01;
	result -> m11 = m -> m11;

	if (makeCopy) {
		LICopyMat2 (r, result);
	}
}

void LITransposeMat3 (LIMat3 * r, LIMat3 const * m)
{
	LIMat3   r0;
	int      makeCopy = (r == m);
	LIMat3 * result = makeCopy ? & r0 : r;

	result -> m00 = m -> m00;
	result -> m01 = m -> m10;
	result -> m02 = m -> m20;

	result -> m10 = m -> m01;
	result -> m11 = m -> m11;
	result -> m12 = m -> m21;

	result -> m20 = m -> m02;
	result -> m21 = m -> m12;
	result -> m22 = m -> m22;

	if (makeCopy) {
		LICopyMat3 (r, result);
	}
}

void LITransposeMat4 (LIMat4 * r, LIMat4 const * m)
{
	LIMat4   r0;
	int      makeCopy = (r == m);
	LIMat4 * result = makeCopy ? & r0 : r;

	result -> m00 = m -> m00;
	result -> m01 = m -> m10;
	result -> m02 = m -> m20;
	result -> m03 = m -> m30;

	result -> m10 = m -> m01;
	result -> m11 = m -> m11;
	result -> m12 = m -> m21;
	result -> m13 = m -> m31;

	result -> m20 = m -> m02;
	result -> m21 = m -> m12;
	result -> m22 = m -> m22;
	result -> m23 = m -> m32;

	result -> m30 = m -> m03;
	result -> m31 = m -> m13;
	result -> m32 = m -> m23;
	result -> m33 = m -> m33;

	if (makeCopy) {
		LICopyMat4 (r, result);
	}
}

void LIMakeModelviewEyeMat4 (LIMat4 * m, LIVec3 eye, LIVec3 lookAt, LIVec3 up)
{
	LIVec3 out = LINormalizeVec3 (LISubVec3 (eye, lookAt));  // -||LOS||
	LIVec3 rgt = LINormalizeVec3 (LICrossVec3 (up, out));    // ||Up × Out||
	LIVec3 upr = LICrossVec3 (out, rgt);                     // Out × Right

	// right
	m -> m00 = rgt.x;
	m -> m10 = rgt.y;
	m -> m20 = rgt.z;

	// up
	m -> m01 = upr.x;
	m -> m11 = upr.y;
	m -> m21 = upr.z;

	// out
	m -> m02 = out.x;
	m -> m12 = out.y;
	m -> m22 = out.z;

	// translation
	m -> m30 = m -> m00 * -eye.x + m -> m10 * -eye.y + m -> m20 * -eye.z;
	m -> m31 = m -> m01 * -eye.x + m -> m11 * -eye.y + m -> m21 * -eye.z;
	m -> m32 = m -> m02 * -eye.x + m -> m12 * -eye.y + m -> m22 * -eye.z;

	m -> m03 = 0.0;
	m -> m13 = 0.0;
	m -> m23 = 0.0;
	m -> m33 = 1.0;
}

void LIMakeProjectionOrthogonalMat4 (LIMat4 * m, LIVec2 viewportSize, LIFloat near, LIFloat far)
{
	LIFloat left   = -viewportSize.x / 2.0;
	LIFloat right  =  viewportSize.x / 2.0;
	LIFloat bottom = -viewportSize.y / 2.0;
	LIFloat top    =  viewportSize.y / 2.0;

	m -> m00 = 2.0 / (right - left);
	m -> m10 = 0.0;
	m -> m20 = 0.0;
	m -> m30 = -(right + left) / (right - left);

	m -> m01 = 0.0;
	m -> m11 = 2.0 / (top - bottom);
	m -> m21 = 0.0;
	m -> m31 = -(top + bottom) / (top - bottom);

	m -> m02 = 0.0;
	m -> m12 = 0.0;
	m -> m22 = -2.0 / (far - near);
	m -> m32 = -(far + near) / (far - near);

	m -> m03 = 0.0;
	m -> m13 = 0.0;
	m -> m23 = 0.0;
	m -> m33 = 1.0;
}

void LIMakeProjectionPerspectiveMat4 (LIMat4 * m, LIVec2 viewportSize, LIFloat near, LIFloat far, LIFloat fovy)
{
	LIFloat aspect = viewportSize.x / viewportSize.y;
	LIFloat f = 1.0 / LITan (LIDegreeToRad (fovy));

	m -> m00 = f / aspect;
	m -> m10 = 0.0;
	m -> m20 = 0.0;
	m -> m30 = 0.0;

	m -> m01 = 0.0;
	m -> m11 = f;
	m -> m21 = 0.0;
	m -> m31 = 0.0;

	m -> m02 = 0.0;
	m -> m12 = 0.0;
	m -> m22 = (far + near) / (near - far);
	m -> m32 = (2.0 * far * near) / (near - far);

	m -> m03 = 0.0;
	m -> m13 = 0.0;
	m -> m23 = -1.0;
	m -> m33 = 0.0;
}

//void LIMat4MakeProjectionPerspectiveFOVX (LIMat4 * m, LIVec2 viewportSize, LIFloat near, LIFloat far, LIFloat fovx)
//{
//	LIFloat aspect = viewportSize.y / viewportSize.x;
//	LIFloat f = 1.0 / LITan (LIDegreeToRad (fovx));
//
//	m -> m00 = f;
//	m -> m10 = 0.0;
//	m -> m20 = 0.0;
//	m -> m30 = 0.0;
//
//	m -> m01 = 0.0;
//	m -> m11 = f / aspect;
//	m -> m21 = 0.0;
//	m -> m31 = 0.0;
//
//	m -> m02 = 0.0;
//	m -> m12 = 0.0;
//	m -> m22 = (far + near) / (near - far);
//	m -> m32 = (2.0 * far * near) / (near - far);
//
//	m -> m03 = 0.0;
//	m -> m13 = 0.0;
//	m -> m23 = -1.0;
//	m -> m33 = 0.0;
//}

int LIProjectVec3 (LIVec3 * screen, LIVec3 object, LIMat4 const * modelView, LIMat4 const * projection, LIVec2 viewportPosition, LIVec2 viewportSize)
{
	LIVec4 v = LIMakeVec4 (object.x, object.y, object.z, 1.0);

	if (projection != NULL) {
		// P * (M * V)
		// same as: (P * M) * V; but faster
		v = LIMultMat4Vec4 (modelView, v);
		v = LIMultMat4Vec4 (projection, v);
	}
	// interpret `modelView` as pre-calculated modelview projection matrix (P * M)
	else {
		v = LIMultMat4Vec4 (modelView, v);
	}

	if (v.w == 0.0) {
		return -1;
	}

	v.x /= v.w;
	v.y /= v.w;
	v.z /= v.w;

	// map to range 0.0 to 1.0
	v.x = v.x * 0.5 + 0.5;
	v.y = v.y * 0.5 + 0.5;
	v.z = v.z * 0.5 + 0.5;

	// map to screen coordinates
	v.x = v.x * viewportSize.x + viewportPosition.x;
	v.y = v.y * viewportSize.y + viewportPosition.y;

	screen -> x = v.x;
	screen -> y = v.y;
	screen -> z = v.z;

	return 0;
}

int LIUnprojectVec3 (LIVec3 * object, LIVec3 screen, LIMat4 const * modelView, LIMat4 const * projection, LIVec2 viewportPosition, LIVec2 viewportSize)
{
	LIMat4 imvp;
	LIMat4 const * inv;
	LIVec4 v;

	// make inverse of modelview projection matrix
	if (projection != NULL) {
		LIMultMat4 (& imvp, projection, modelView);

		if (LIInvertMat4 (& imvp, & imvp) < 0) {
			return -1;
		}

		inv = & imvp;
	}
	// interpret `modelView` as pre-calculated inverse of model view projection matrix (P * M) ^ -1
	else {
		inv = modelView;
	}

	v = LIMakeVec4 (screen.x, screen.y, screen.z, 1.0);

	// map from screen coordinates
	v.x = (v.x - viewportPosition.x) / viewportSize.x;
	v.y = (v.y - viewportPosition.y) / viewportSize.y;

	// map to range -1.0 to 1.0
	v.x = v.x * 2.0 - 1.0;
	v.y = v.y * 2.0 - 1.0;
	v.z = v.z * 2.0 - 1.0;

	v = LIMultMat4Vec4 (inv, v);

	if (v.w == 0.0) {
		return -1;
	}

	v.x /= v.w;
	v.y /= v.w;
	v.z /= v.w;

	object -> x = v.x;
	object -> y = v.y;
	object -> z = v.z;

	return 0;
}

void LIPrintVec2 (LIVec2 v)
{
	printf ("%f  %f\n", v.x, v.y);
	printf ("\n");
}

void LIPrintVec3 (LIVec3 v)
{
	printf ("%f  %f  %f\n", v.x, v.y, v.z);
	printf ("\n");
}

void LIPrintVec4 (LIVec4 v)
{
	printf ("%f  %f  %f  %f\n", v.x, v.y, v.z, v.w);
	printf ("\n");
}

void LIPrintMat2 (LIMat2 const * m)
{
	printf ("%9.6f %9.6f\n", m -> m00, m -> m10);
	printf ("%9.6f %9.6f\n", m -> m01, m -> m11);
	printf ("\n");
}

void LIPrintMat3 (LIMat3 const * m)
{
	printf ("%9.6f %9.6f %9.6f\n", m -> m00, m -> m10, m -> m20);
	printf ("%9.6f %9.6f %9.6f\n", m -> m01, m -> m11, m -> m21);
	printf ("%9.6f %9.6f %9.6f\n", m -> m02, m -> m12, m -> m22);
	printf ("\n");
}

void LIPrintMat4 (LIMat4 const * m)
{
	printf ("%9.6f %9.6f %9.6f %9.6f\n", m -> m00, m -> m10, m -> m20, m -> m30);
	printf ("%9.6f %9.6f %9.6f %9.6f\n", m -> m01, m -> m11, m -> m21, m -> m31);
	printf ("%9.6f %9.6f %9.6f %9.6f\n", m -> m02, m -> m12, m -> m22, m -> m32);
	printf ("%9.6f %9.6f %9.6f %9.6f\n", m -> m03, m -> m13, m -> m23, m -> m33);
	printf ("\n");
}
