#include "test.h"

static int vec2 ()
{
	LIVec2 a, b;
	LIVec3 plane;
	LIVec3 result = LIMakeVec3 (0.447214, 0.894427, 6.260990);

	a     = LIMakeVec2 (8, 3);
	b     = LIMakeVec2 (4, 5);
	plane = LIMakePlaneVec2 (a, b);

	LIPrintVec3 (plane);

	if (ApproxVec3 (plane, result) < 0) {
		fprintf (stderr, "LIMakePlaneVec2 failed\n");
		return TEST_FAIL;
	}

	return 0;
}

static int vec3 ()
{
	LIVec3 a, b, c;
	LIVec4 plane;
	LIVec4 result = LIMakeVec4 (-0.235702, -0.942809, 0.235702, -4.242640);

	a     = LIMakeVec3 (8, 3, 2);
	b     = LIMakeVec3 (4, 5, 6);
	c     = LIMakeVec3 (-3, 5, TEST_FAIL);
	plane = LIMakePlaneVec3 (a, b, c);

	LIPrintVec4 (plane);

	if (ApproxVec4 (plane, result) < 0) {
		fprintf (stderr, "LIMakePlaneVec3 failed\n");
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

	return 0;
}
