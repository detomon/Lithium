AM_CFLAGS = -I$(srcdir)/../src -L$(srcdir)/../src -llithium

check_PROGRAMS = \
	reflect \
	plane

plane_SOURCES = plane.c
plane_CFLAGS = $(AM_CFLAGS)

TESTS_ENVIRONMENT = top_builddir=$(top_builddir)

TESTS = \
	reflect \
	plane
