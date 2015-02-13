AM_CFLAGS = -I$(srcdir)/../src -L$(srcdir)/../src -llithium

check_PROGRAMS = \
	scalar \
	vector_make \
	reflect \
	plane \
	matrix_invert

scalar_SOURCES        = scalar.c
vector_make_SOURCES   = vector_make.c
plane_SOURCES         = plane.c
reflect_SOURCES       = plane.c
matrix_invert_SOURCES = matrix_invert.c

TESTS_ENVIRONMENT = top_builddir=$(top_builddir)

TESTS = \
	scalar \
	vector_make \
	reflect \
	plane \
	matrix_invert
