#include "test.h"

int main (int argc, char const * argv [])
{
	LIVec2 result2 = (LIVec2) {3.0, 4.0};

	TestVec2 (LIMakeVec2 (3.0, 4.0), result2);
	TestVec2 (LIMakeVec2Vec3 (LIMakeVec3 (3.0, 4.0, 5.0)), result2);
	TestVec2 (LIMakeVec2Vec4 (LIMakeVec4 (3.0, 4.0, 5.0, 6.0)), result2);

	LIVec3 result3 = (LIVec3) {3.0, 4.0, 5.0};

	TestVec3 (LIMakeVec3 (3.0, 4.0, 5.0), result3);
	TestVec3 (LIMakeVec3Vec4 (LIMakeVec4 (3.0, 4.0, 5.0, 6.0)), result3);
	TestVec3 (LIMakeVec3Vec2 (LIMakeVec2 (3.0, 4.0), 5.0), result3);

	LIVec4 result4 = (LIVec4) {3.0, 4.0, 5.0, 6.0};

	TestVec4 (LIMakeVec4 (3.0, 4.0, 5.0, 6.0), result4);
	TestVec4 (LIMakeVec4Vec2 (LIMakeVec2 (3.0, 4.0), 5.0, 6.0), result4);
	TestVec4 (LIMakeVec4Vec3 (LIMakeVec3 (3.0, 4.0, 5.0), 6.0), result4);

	return STATUS_PASS;
}
