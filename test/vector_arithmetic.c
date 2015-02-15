#include "test.h"

int main (int argc, char const * argv [])
{
	TestVec2 (LIAddVec2 (LIMakeVec2 (-4, 7), LIMakeVec2 (9, 1)), LIMakeVec2 (5, 8));
	TestVec3 (LIAddVec3 (LIMakeVec3 (-4, 7, 2), LIMakeVec3 (9, 1, -10)), LIMakeVec3 (5, 8, -8));
	TestVec4 (LIAddVec4 (LIMakeVec4 (-4, 7, 2, 0.2), LIMakeVec4 (9, 1, -10, 0.7)), LIMakeVec4 (5, 8, -8, 0.9));

	TestVec2 (LISubVec2 (LIMakeVec2 (-4, 7), LIMakeVec2 (9, 1)), LIMakeVec2 (-13, 6));
	TestVec3 (LISubVec3 (LIMakeVec3 (-4, 7, 2), LIMakeVec3 (9, 1, -10)), LIMakeVec3 (-13, 6, 12));
	TestVec4 (LISubVec4 (LIMakeVec4 (-4, 7, 2, 0.2), LIMakeVec4 (9, 1, -10, 0.7)), LIMakeVec4 (-13, 6, 12, -0.5));

	TestVec2 (LIMultVec2 (LIMakeVec2 (-4, 7), -0.6), LIMakeVec2 (2.4, -4.2));
	TestVec3 (LIMultVec3 (LIMakeVec3 (-4, 7, 2), -0.6), LIMakeVec3 (2.4, -4.2, -1.2));
	TestVec4 (LIMultVec4 (LIMakeVec4 (-4, 7, 2, 0.2), -0.6), LIMakeVec4 (2.4, -4.2, -1.2, -0.12));

	TestVec2 (LIDivVec2 (LIMakeVec2 (-4, 7), 1.6), LIMakeVec2 (-2.5, 4.375));
	TestVec3 (LIDivVec3 (LIMakeVec3 (-4, 7, 2), 1.6), LIMakeVec3 (-2.5, 4.375, 1.25));
	TestVec4 (LIDivVec4 (LIMakeVec4 (-4, 7, 2, 0.2), 1.6), LIMakeVec4 (-2.5, 4.375, 1.25, 0.125));

	return STATUS_PASS;
}
