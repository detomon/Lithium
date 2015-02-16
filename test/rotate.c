#include "test.h"

int main (int argc, char const * argv [])
{
	TestVec2 (LIRotateVec2 (LIMakeVec2 (18, -31), 30), LIMakeVec2 (31.088457268, -17.846787518));
	TestVec2 (LIRotateRelativeVec2 (LIMakeVec2 (18, -31), 30, LIMakeVec2 (-5, 11)), LIMakeVec2 (35.918584287, -13.87306696));

	TestVec3 (LIRotateVec3 (LIMakeVec3 (18, -31, 14), LIMakeVec3 (-4, 9, 8), 30), LIMakeVec3 (31.121648, -20.755617, 9.035894));
	TestVec3 (LIRotateRelativeVec3 (LIMakeVec3 (18, -31, 14), LIMakeVec3 (-4, 9, 8), 30, LIMakeVec3 (-5, 11, -2)), LIMakeVec3 (34.971602, -18.161826, 8.042855));

	return STATUS_PASS;
}
