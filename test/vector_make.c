#include "test.h"

static int vec2 ()
{
	LIFloat aexp [] = {3.0, 4.0};
	LIVec2 a;

	a = LIMakeVec2 (3.0, 4.0);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 2) < 0) {
		fprintf (stderr, "LIMakeVec2 failed\n");
		return TEST_FAIL;
	}

	a = LIMakeVec2Vec3 (LIMakeVec3 (3.0, 4.0, 5.0));

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 2) < 0) {
		fprintf (stderr, "LIMakeVec2Vec3 failed\n");
		return TEST_FAIL;
	}

	a = LIMakeVec2Vec4 (LIMakeVec4 (3.0, 4.0, 5.0, 6.0));

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 2) < 0) {
		fprintf (stderr, "LIMakeVec2Vec4 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec3 ()
{
	LIFloat aexp [] = {3.0, 4.0, 5.0};
	LIVec3 a;

	a = LIMakeVec3 (3.0, 4.0, 5.0);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 3) < 0) {
		fprintf (stderr, "LIMakeVec3 failed\n");
		return TEST_FAIL;
	}

	a = LIMakeVec3Vec4 (LIMakeVec4 (3.0, 4.0, 5.0, 6.0));

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 3) < 0) {
		fprintf (stderr, "LIMakeVec3Vec4 failed\n");
		return TEST_FAIL;
	}

	a = LIMakeVec3Vec2 (LIMakeVec2 (3.0, 4.0), 5.0);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 3) < 0) {
		fprintf (stderr, "LIMakeVec3Vec2 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec4 ()
{
	LIFloat aexp [] = {3.0, 4.0, 5.0, 6.0};
	LIVec4 a;

	a = LIMakeVec4 (3.0, 4.0, 5.0, 6.0);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 4) < 0) {
		fprintf (stderr, "LIMakeVec4 failed\n");
		return TEST_FAIL;
	}

	a = LIMakeVec4Vec2 (LIMakeVec2 (3.0, 4.0), 5.0, 6.0);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 4) < 0) {
		fprintf (stderr, "LIMakeVec4Vec2 failed\n");
		return TEST_FAIL;
	}

	a = LIMakeVec4Vec3 (LIMakeVec3 (3.0, 4.0, 5.0), 6.0);

	if (ApproxVec ((LIFloat *) & a, (LIFloat *) & aexp, 4) < 0) {
		fprintf (stderr, "LIMakeVec4Vec3 failed\n");
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
