AM_CFLAGS = -I$(srcdir)/../src -L$(srcdir)/../src -llithium

check_PROGRAMS = \
	scalar \
	vector \
	reflect \
	plane

scalar_SOURCES  = scalar.c
vector_SOURCES  = vector.c
plane_SOURCES   = plane.c
reflect_SOURCES = plane.c

TESTS_ENVIRONMENT = top_builddir=$(top_builddir)

TESTS = \
	scalar \
	vector \
	reflect \
	plane
