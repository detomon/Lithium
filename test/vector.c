#include "test.h"

static int vec2 ()
{
	LIVec2 a;

	a = LIMakeVec2 (3.0, 4.0);

	if (APPROX (a.x, 3.0) < 0) {
		fprintf (stderr, "LIMakeVec2 failed\n");
		return TEST_FAIL;
	}

	if (APPROX (a.y, 4.0) < 0) {
		fprintf (stderr, "LIMakeVec2 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec3 ()
{
	LIVec3 a;

	a = LIMakeVec3 (3.0, 4.0, 5.0);

	if (APPROX (a.x, 3.0) < 0) {
		fprintf (stderr, "LIMakeVec3 failed\n");
		return TEST_FAIL;
	}

	if (APPROX (a.y, 4.0) < 0) {
		fprintf (stderr, "LIMakeVec3 failed\n");
		return TEST_FAIL;
	}

	if (APPROX (a.z, 5.0) < 0) {
		fprintf (stderr, "LIMakeVec3 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec4 ()
{
	LIVec4 a;

	a = LIMakeVec4 (3.0, 4.0, 5.0, -7.0);

	if (APPROX (a.x, 3.0) < 0) {
		fprintf (stderr, "LIMakeVec4 failed\n");
		return TEST_FAIL;
	}

	if (APPROX (a.y, 4.0) < 0) {
		fprintf (stderr, "LIMakeVec4 failed\n");
		return TEST_FAIL;
	}

	if (APPROX (a.z, 5.0) < 0) {
		fprintf (stderr, "LIMakeVec4 failed\n");
		return TEST_FAIL;
	}

	if (APPROX (a.z, -7.0) < 0) {
		fprintf (stderr, "LIMakeVec4 failed\n");
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
