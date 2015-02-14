#include "test.h"

int main (int argc, char const * argv [])
{
	TestFloat (LIAbs (-15), 15);
	TestFloat (LIAbs (18), 18);

	TestFloat (LIMin (-12, -5), -12);
	TestFloat (LIMin (56, 6), 6);

	TestFloat (LIMax (23, 9), 23);
	TestFloat (LIMax (-1, -17), -1);

	TestFloat (LIClamp (10, -5, 15), 10);
	TestFloat (LIClamp (10, 12, 25), 12);
	TestFloat (LIClamp (10, -9, 7), 7);

	TestFloat (LIRadToDegree (0.872664626), 50);
	TestFloat (LIDegreeToRad (-60), -1.0471975512);

	return 0;
}
