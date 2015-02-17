#include "test.h"

int main (int argc, char const * argv [])
{
	LIMat2 a2, i2;

	LIMakeRotationMat2 (&a2, 30);
	LIInvertMat2 (&i2, &a2);
	LIInvertMat2 (&i2, &i2);

	TestMat2 (a2, i2);


	LIMat3 a3, i3;

	LIMakeRotationMat3 (&a3, 30);
	LITranslateMat3 (&a3, LIMakeVec2 (3, -2));

	LIInvertMat3 (&i3, &a3);
	LIInvertMat3 (&i3, &i3);

	TestMat3 (a3, i3);


	LIMat4 a4, i4;

	LIMakeRotationMat4 (&a4, LIMakeVec3 (-4, 5, 8), 30);
	LITranslateMat4 (&a4, LIMakeVec3 (3, -2, -7));

	LIInvertMat4 (&i4, &a4);
	LIInvertMat4 (&i4, &i4);

	TestMat4 (a4, i4);

	return STATUS_PASS;
}
