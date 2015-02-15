#ifndef _TEST_H_
#define _TEST_H_

#include "lithium.h"
#include <stdlib.h>

#define STATUS_PASS   0
#define STATUS_FAIL  -1
#define STATUS_SKIP  77
#define STATUS_ERROR 99

#define ABS(a) ((a < 0) ? -(a) : (a))

#define APPROX_DELTA 0.00001
#define Approx(a, b) (ABS((a) - (b)) <= APPROX_DELTA)

#define TestValue(a, b, ...) \
	if (!Approx(a, b)) { \
		fprintf (stderr, "TestValue:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

#define TestVec2(a, b, ...) \
	if (!ApproxVec2(a, b)) { \
		fprintf (stderr, "TestVec2:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

#define TestVec3(a, b, ...) \
	if (!ApproxVec3(a, b)) { \
		fprintf (stderr, "TestVec3:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

#define TestVec4(a, b, ...) \
	if (!ApproxVec4(a, b)) { \
		fprintf (stderr, "TestVec4:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

#define TestMat2(a, b, ...) \
	if (!ApproxMat2(&a, &b)) { \
		fprintf (stderr, "TestMat2:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

#define TestMat3(a, b, ...) \
	if (!ApproxMat3(&a, &b)) { \
		fprintf (stderr, "TestMat3:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

#define TestMat4(a, b, ...) \
	if (!ApproxMat4(&a, &b)) { \
		fprintf (stderr, "TestMat4:%u: " #a ", " #b "\n", __LINE__, ##__VA_ARGS__); \
		exit(STATUS_FAIL); \
	}

static int ApproxVec (void const * v1, void const * v2, int n)
{
	for (int i = 0; i < n; i ++) {
		if (!Approx (((LIFloat *) v1) [i], ((LIFloat *) v2) [i])) {
			return 0;
		}
	}

	return 1;
}

static int ApproxVec2 (LIVec2 a, LIVec2 b)
{
	return ApproxVec (& a, & b, 2);
}

static int ApproxVec3 (LIVec3 a, LIVec3 b)
{
	return ApproxVec (& a, & b, 3);
}

static int ApproxVec4 (LIVec4 a, LIVec4 b)
{
	return ApproxVec (& a, & b, 4);
}

static int ApproxMat2 (LIMat2 const * a, LIMat2 const * b)
{
	return ApproxVec (a, b, 4);
}

static int ApproxMat3 (LIMat3 const * a, LIMat3 const * b)
{
	return ApproxVec (a, b, 9);
}

static int ApproxMat4 (LIMat4 const * a, LIMat4 const * b)
{
	return ApproxVec (a, b, 16);
}

#endif /* ! _TEST_H_ */
