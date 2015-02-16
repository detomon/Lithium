AM_CFLAGS = -I$(srcdir)/../src -L$(srcdir)/../src -llithium

TEST_NAMES = \
	scalar \
	vector_make \
	vector_arithmetic \
	length_normalize \
	dot_cross \
	rotate \
	reflect \
	plane \
	matrix_invert

check_PROGRAMS = $(TEST_NAMES)

scalar_SOURCES        = scalar.c
vector_make_SOURCES   = vector_make.c
vector_arithmetic     = vector_arithmetic.c
length_normalize      = length_normalize.c
dot_cross             = dot_cross.c
rotate                = rotate.c
plane_SOURCES         = plane.c
reflect_SOURCES       = reflect.c
matrix_invert_SOURCES = matrix_invert.c

TESTS_ENVIRONMENT = top_builddir=$(top_builddir)

TESTS = $(TEST_NAMES)
