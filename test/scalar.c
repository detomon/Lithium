#include "test.h"

int main (int argc, char const * argv [])
{
	TestValue (LIAbs (-15), 15);
	TestValue (LIAbs (18), 18);

	TestValue (LIMin (-12, -5), -12);
	TestValue (LIMin (56, 6), 6);

	TestValue (LIMax (23, 9), 23);
	TestValue (LIMax (-1, -17), -1);

	TestValue (LIClamp (10, -5, 15), 10);
	TestValue (LIClamp (10, 12, 25), 12);
	TestValue (LIClamp (10, -9, 7), 7);

	TestValue (LIRadToDegree (0.872664626), 50);
	TestValue (LIDegreeToRad (-60), -1.0471975512);

	return 0;
}
