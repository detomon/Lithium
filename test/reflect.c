#include "test.h"

static int vec2 ()
{
	LIVec2 a, w, r;
	LIVec2 result = LIMakeVec2 (-6.524590, -3.229507);

	a = LIMakeVec2 (2, 7);
	w = LIMakeVec2 (-5, -6);
	r = LIReflectVec2 (a, w);

	LIPrintVec2 (r);

	if (ApproxVec2 (r, result) < 0) {
		fprintf (stderr, "vec2 failed\n");
		return -1;
	}

	return 0;
}

static int vec3 ()
{
	LIVec3 a, w, r;
	LIVec3 result = LIMakeVec3 (-5.272727, -1.727273, -6.181818);

	a = LIMakeVec3 (2, 7, 4);
	w = LIMakeVec3 (-5, -6, -7);
	r = LIReflectVec3 (a, w);

	LIPrintVec3 (r);

	if (ApproxVec3 (r, result) < 0) {
		fprintf (stderr, "vec3 failed\n");
		return -1;
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
