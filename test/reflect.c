#include "test.h"

int main (int argc, char const * argv [])
{
	TestVec2 (LIReflectVec2 (
		LIMakeVec2 (2, 7),
		LIMakeVec2 (-5, -6)
	), LIMakeVec2 (-6.524590, -3.229507));

	TestVec3 (LIReflectVec3 (
		LIMakeVec3 (2, 7, 4),
		LIMakeVec3 (-5, -6, -7)
	), LIMakeVec3 (-5.272727, -1.727273, -6.181818));

	return STATUS_PASS;
}
