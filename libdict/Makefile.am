lib_LTLIBRARIES = libdict.la

AM_CPPFLAGS = -I$(includedir)

libdict_la_SOURCES = dict.c
libdict_la_LIBADD = $(libdir)/libmem.la \
	$(libdir)/liberror.la \
	$(libdir)/libcstrings.la

include_HEADERS =	dict.h
