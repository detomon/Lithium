AM_CFLAGS = -I$(srcdir)/../src -L$(srcdir)/../src -llithium

TEST_NAMES = \
	scalar \
	vector_make \
	reflect \
	plane \
	matrix_invert

check_PROGRAMS = $(TEST_NAMES)

scalar_SOURCES        = scalar.c
vector_make_SOURCES   = vector_make.c
plane_SOURCES         = plane.c
reflect_SOURCES       = reflect.c
matrix_invert_SOURCES = matrix_invert.c

TESTS_ENVIRONMENT = top_builddir=$(top_builddir)

TESTS = $(TEST_NAMES)
