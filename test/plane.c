#include "test.h"

int main (int argc, char const * argv [])
{
	TestVec3 (LIMakePlaneVec2 (
		LIMakeVec2 (8, 3),
		LIMakeVec2 (4, 5)
	), LIMakeVec3 (0.447214, 0.894427, 6.260990));

	TestVec4 (LIMakePlaneVec3 (
		LIMakeVec3 (8, 3, 2),
		LIMakeVec3 (4, 5, 6),
		LIMakeVec3 (-3, 5, -1)
	), LIMakeVec4 (-0.235702, -0.942809, 0.235702, -4.242640));

	return STATUS_PASS;
}
