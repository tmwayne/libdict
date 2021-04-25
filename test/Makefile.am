TESTS = test_dict

check_PROGRAMS = test_dict

test_dict_SOURCES = test-dict.c
test_dict_LDADD = $(top_srcdir)/libdict/libdict.la $(libdir)/liberror.la

AM_CPPFLAGS = -I$(top_srcdir)/libdict -I$(includedir)
