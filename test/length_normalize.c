#include "test.h"

int main (int argc, char const * argv [])
{
	TestValue (LILengthVec2 (LIMakeVec2 (3, 4)), 5);
	TestValue (LILengthVec3 (LIMakeVec3 (3, 4, -5)), 7.071067812);
	TestValue (LILengthVec4 (LIMakeVec4 (3, 4, -5, 6)), 9.273618495);

	TestValue (LIDistanceVec2 (LIMakeVec2 (3, 4), LIMakeVec2 (-5, -2)), 10);
	TestValue (LIDistanceVec3 (LIMakeVec3 (3, 4, -5), LIMakeVec3 (-5, -2, 7)), 15.62049935);
	TestValue (LIDistanceVec4 (LIMakeVec4 (3, 4, -5, 6), LIMakeVec4 (-5, -2, 7, -8)), 20.97617696);

	TestVec2 (LINormalizeMultVec2 (LIMakeVec2 (3, 4), -1.2), LIMultVec2 (LIMakeVec2 (0.6, 0.8), -1.2));
	TestVec3 (LINormalizeMultVec3 (LIMakeVec3 (3, 4, 5), -1.2), LIMultVec3 (LIMakeVec3 (0.4242640687, 0.5656854249, 0.7071067812), -1.2));
	TestVec4 (LINormalizeMultVec4 (LIMakeVec4 (3, 4, 5, 6), -1.2), LIMultVec4 (LIMakeVec4 (0.3234983196, 0.4313310928, 0.539163866, 0.6469966393), -1.2));

	TestVec2 (LINormalizeVec2 (LIMakeVec2 (3, 4)), LIMakeVec2 (0.6, 0.8));
	TestVec3 (LINormalizeVec3 (LIMakeVec3 (3, 4, 5)), LIMakeVec3 (0.4242640687, 0.5656854249, 0.7071067812));
	TestVec4 (LINormalizeVec4 (LIMakeVec4 (3, 4, 5, 6)), LIMakeVec4 (0.3234983196, 0.4313310928, 0.539163866, 0.6469966393));

	return STATUS_PASS;
}
