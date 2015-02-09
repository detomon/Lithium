#ifndef _TEST_H_
#define _TEST_H_

#define TEST_PASS   0
#define TEST_FAIL  -1
#define TEST_SKIP  77
#define TEST_ERROR 99

#include "lithium.h"

#define APPROX_DELTA 0.00001
#define APPROX(a, b) (fabs((a) - (b)) <= APPROX_DELTA)

static int ApproxVec (LIFloat const * v1, LIFloat const * v2, int nc)
{
	for (int i = 0; i < nc; i ++) {
		if (!APPROX (v1 [i], v2 [i])) {
			return -1;
		}
	}

	return 0;
}

static int ApproxVec2 (LIVec2 a, LIVec2 b)
{
	return ApproxVec ((LIFloat *) & a, (LIFloat *) & b, 2);
}

static int ApproxVec3 (LIVec3 a, LIVec3 b)
{
	return ApproxVec ((LIFloat *) & a, (LIFloat *) & b, 3);
}

static int ApproxVec4 (LIVec4 a, LIVec4 b)
{
	return ApproxVec ((LIFloat *) & a, (LIFloat *) & b, 4);
}

static int ApproxMat2 (LIMat2 const * a, LIMat2 const * b)
{
	return ApproxVec ((LIFloat *) a, (LIFloat *) b, 4);
}

static int ApproxMat3 (LIMat3 const * a, LIMat3 const * b)
{
	return ApproxVec ((LIFloat *) a, (LIFloat *) b, 9);
}

static int ApproxMat4 (LIMat4 const * a, LIMat4 const * b)
{
	return ApproxVec ((LIFloat *) a, (LIFloat *) b, 16);
}

#include "Lithium.h"

#endif /* ! _TEST_H_ */
