#include "test.h"

static int vec2 ()
{
	LIMat2 a, i;

	LIMakeRotationMat2 (& a, 30);
	LIInvertMat2 (& i, & a);
	LIInvertMat2 (& i, & i);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & i, 4) < 0) {
		fprintf (stderr, "LIInvertMat2 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec3 ()
{
	LIMat3 a, i;

	LIMakeRotationMat3 (& a, 30);
	LITranslateMat3 (& a, LIMakeVec2 (3, -2));

	LIInvertMat3 (& i, & a);
	LIInvertMat3 (& i, & i);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & i, 9) < 0) {
		fprintf (stderr, "LIInvertMat3 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec4 ()
{
	LIMat4 a, i;

	LIMakeRotationMat4 (& a, LIMakeVec3 (-4, 5, 8), 30);
	LITranslateMat4 (& a, LIMakeVec3 (3, -2, -7));

	LIInvertMat4 (& i, & a);
	LIInvertMat4 (& i, & i);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & i, 16) < 0) {
		fprintf (stderr, "LIInvertMat4 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

int main (int argc, char const * argv [])
{
	int res;

	if ((res = vec2 ()) != 0) {
		return res;
	}

	if ((res = vec3 ()) != 0) {
		return res;
	}

	if ((res = vec4 ()) != 0) {
		return res;
	}

	return 0;
}
