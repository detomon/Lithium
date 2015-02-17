#include "test.h"

int main (int argc, char const * argv [])
{
	LIMat2 m2, m2r;
	LIMat3 m3, m3r;
	LIMat4 m4, m4r;

	m2r.m00 = 1; m2r.m10 = 0;
	m2r.m01 = 0; m2r.m11 = 1;
	LIMakeIdentityMat2 (&m2);
	TestMat2 (m2, m2r);

	m3r.m00 = 1; m3r.m10 = 0; m3r.m20 = 7;
	m3r.m01 = 0; m3r.m11 = 1; m3r.m21 = -9;
	m3r.m02 = 0; m3r.m12 = 0; m3r.m22 = 1;
	LIMakeTranslationMat3 (&m3, LIMakeVec2 (7, -9));
	TestMat3 (m3, m3r);

	m3r.m00 = 1; m3r.m10 = 0; m3r.m20 = 0;
	m3r.m01 = 0; m3r.m11 = 1; m3r.m21 = 0;
	m3r.m02 = 0; m3r.m12 = 0; m3r.m22 = 1;
	LIMakeIdentityMat3 (&m3);
	TestMat3 (m3, m3r);

	m4r.m00 = 1; m4r.m10 = 0; m4r.m20 = 0; m4r.m30 = 0;
	m4r.m01 = 0; m4r.m11 = 1; m4r.m21 = 0; m4r.m31 = 0;
	m4r.m02 = 0; m4r.m12 = 0; m4r.m22 = 1; m4r.m32 = 0;
	m4r.m03 = 0; m4r.m13 = 0; m4r.m23 = 0; m4r.m33 = 1;
	LIMakeIdentityMat4 (&m4);
	TestMat4 (m4, m4r);

	m4r.m00 = 1; m4r.m10 = 0; m4r.m20 = 0; m4r.m30 = 7;
	m4r.m01 = 0; m4r.m11 = 1; m4r.m21 = 0; m4r.m31 = -9;
	m4r.m02 = 0; m4r.m12 = 0; m4r.m22 = 1; m4r.m32 = -3;
	m4r.m03 = 0; m4r.m13 = 0; m4r.m23 = 0; m4r.m33 = 1;
	LIMakeTranslationMat4 (&m4, LIMakeVec3 (7, -9, -3));
	TestMat4 (m4, m4r);

	m2r.m00 = 5; m2r.m10 = 0;
	m2r.m01 = 0; m2r.m11 = 2;
	LIMakeScaleMat2 (&m2, LIMakeVec2 (5, 2));
	TestMat2 (m2, m2r);

	m3r.m00 = 5; m3r.m10 = 0; m3r.m20 = 0;
	m3r.m01 = 0; m3r.m11 = 2; m3r.m21 = 0;
	m3r.m02 = 0; m3r.m12 = 0; m3r.m22 = 1;
	LIMakeScaleMat3 (&m3, LIMakeVec2 (5, 2));
	TestMat3 (m3, m3r);

	m3r.m00 = 5; m3r.m10 = 0; m3r.m20 = 0;
	m3r.m01 = 0; m3r.m11 = 2; m3r.m21 = 0;
	m3r.m02 = 0; m3r.m12 = 0; m3r.m22 = 3;
	LIMakeScaleMat3Vec3 (&m3, LIMakeVec3 (5, 2, 3));
	TestMat3 (m3, m3r);

	m4r.m00 = 5; m4r.m10 = 0; m4r.m20 = 0; m4r.m30 = 0;
	m4r.m01 = 0; m4r.m11 = 2; m4r.m21 = 0; m4r.m31 = 0;
	m4r.m02 = 0; m4r.m12 = 0; m4r.m22 = 3; m4r.m32 = 0;
	m4r.m03 = 0; m4r.m13 = 0; m4r.m23 = 0; m4r.m33 = 1;
	LIMakeScaleMat4 (&m4, LIMakeVec3 (5, 2, 3));
	TestMat4 (m4, m4r);

	m2r.m00 = 0.866025; m2r.m10 = -0.5;
	m2r.m01 = 0.5;      m2r.m11 = 0.866025;
	LIMakeRotationMat2 (&m2, 30);
	TestMat2 (m2, m2r);

	m3r.m00 = 0.866025; m3r.m10 = -0.5;     m3r.m20 = 0;
	m3r.m01 = 0.5;      m3r.m11 = 0.866025; m3r.m21 = 0;
	m3r.m02 = 0;        m3r.m12 = 0;        m3r.m22 = 1;
	LIMakeRotationMat3 (&m3, 30);
	TestMat3 (m3, m3r);

	m3r.m00 =  0.879340; m3r.m10 = -0.345201; m3r.m20 = 0.328021;
	m3r.m01 =  0.285287; m3r.m11 =  0.933429; m3r.m21 = 0.217536;
	m3r.m02 = -0.381278; m3r.m12 = -0.097708; m3r.m22 = 0.919282;
	LIMakeRotationMat3Vec3 (&m3, LIMakeVec3 (-4, 9, 8), 30);
	TestMat3 (m3, m3r);

	m4r.m00 =  0.879340; m4r.m10 = -0.345201; m4r.m20 = 0.328021; m4r.m30 = 0;
	m4r.m01 =  0.285287; m4r.m11 =  0.933429; m4r.m21 = 0.217536; m4r.m31 = 0;
	m4r.m02 = -0.381278; m4r.m12 = -0.097708; m4r.m22 = 0.919282; m4r.m32 = 0;
	m4r.m03 = 0;         m4r.m13 = 0;         m4r.m23 = 0;        m4r.m33 = 1;
	LIMakeRotationMat4 (&m4, LIMakeVec3 (-4, 9, 8), 30);
	TestMat4 (m4, m4r);

	return STATUS_PASS;
}
