#include "test.h"

int main (int argc, char const * argv [])
{
	TestValue (LIDotVec2 (LIMakeVec2 (-4, 2), LIMakeVec2 (2, 3)), -2);
	TestValue (LIDotVec3 (LIMakeVec3 (-4, 2, 8), LIMakeVec3 (2, 3, -10)), -82);

	TestVec2 (LICrossVec2 (LIMakeVec2 (-4, 2)), LIMakeVec2 (2, 4));
	TestVec3 (LICrossVec3 (LIMakeVec3 (-4, 2, 8), LIMakeVec3 (2, 3, -10)), LIMakeVec3 (-44, -24, -16));

	return STATUS_PASS;
}
