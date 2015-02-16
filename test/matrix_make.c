#include "test.h"

int main (int argc, char const * argv [])
{
	LIMat2 m2;
	LIMat3 m3;
	LIMat4 m4;

	LIMakeIdentityMat3 (& m3);
	LIMakeTranslationMat3 (& m3, LIMakeVec2 (7, -9));
	TestVec2 (LIMultMat3Vec2 (& m3, LIMakeVec2 (1, 2)), LIMakeVec2 (8, -7));

	LIMakeIdentityMat4 (& m4);
	LIMakeTranslationMat4 (& m4, LIMakeVec3 (7, -9, -3));
	TestVec3 (LIMultMat4Vec3 (& m4, LIMakeVec3 (1, 2, 4)), LIMakeVec3 (8, -7, 1));

	/*LIMakeScaleMat2
	LIMakeScaleMat3
	LIMakeScaleMat3Vec3
	LIMakeScaleMat4
	LIMakeRotationMat2
	LIMakeRotationMat3
	LIMakeRotationMat3Vec3
	LIMakeRotationMat4*/

	return STATUS_PASS;
}
