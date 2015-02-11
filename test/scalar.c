#include "test.h"

int main (int argc, char const * argv [])
{
	LIFloat s = LISin(54);

	if (LIAbs (-15) != 15) {
		fprintf (stderr, "LIAbs failed\n");
		return TEST_FAIL;
	}

	if (LIAbs (18) != 18) {
		fprintf (stderr, "LIAbs failed\n");
		return TEST_FAIL;
	}

	if (LIMin (-12, -5) != -12) {
		fprintf (stderr, "LIMin failed\n");
		return TEST_FAIL;
	}

	if (LIMin (56, 6) != 6) {
		fprintf (stderr, "LIMin failed\n");
		return TEST_FAIL;
	}

	if (LIMax (23, 9) != 23) {
		fprintf (stderr, "LIMax failed\n");
		return TEST_FAIL;
	}

	if (LIMax (-1, -17) != -1) {
		fprintf (stderr, "LIMax failed\n");
		return TEST_FAIL;
	}

	if (LIClamp (10, -5, 15) != 10) {
		fprintf (stderr, "LIClamp failed\n");
		return TEST_FAIL;
	}

	if (LIClamp (10, 12, 25) != 12) {
		fprintf (stderr, "LIClamp failed\n");
		return TEST_FAIL;
	}

	if (LIClamp (10, -9, 7) != 7) {
		fprintf (stderr, "LIClamp failed\n");
		return TEST_FAIL;
	}

	if (APPROX (LIRadToDegree (0.872664626), 50) < 0) {
		fprintf (stderr, "LIClamp failed\n");
		return TEST_FAIL;
	}

	if (APPROX (LIDegreeToRad (60), -1.0471975512) < 0) {
		fprintf (stderr, "LIClamp failed\n");
		return TEST_FAIL;
	}

	return 0;
}
