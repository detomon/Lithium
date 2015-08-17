#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.61])
AC_INIT([Lithium],[0.3],[simon@monoxid.net],[lithium],[])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_RANLIB
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h])

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 test/Makefile
])

AC_OUTPUT
