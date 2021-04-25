#
# ------------------------------------------------------------------------------
# configure.ac
# ------------------------------------------------------------------------------
#

AC_PREREQ([2.69])
AC_INIT([libdict], [0.1], [tylerwayne3@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects])

LT_PREREQ([2.2.])
LT_INIT([dlopen])

AC_CONFIG_SRCDIR([libdict/dict.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdio.h stddef.h, string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_SEARCH_LIBS([dlopen])

AC_CONFIG_FILES([
  Makefile
  libdict/Makefile
  src/Makefile
  test/Makefile])

AC_OUTPUT
