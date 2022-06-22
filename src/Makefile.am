SUBDIRS = common delim-reader

bin_PROGRAMS = main
main_SOURCES = main.c
main_CPPFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/src/delim-reader
main_LDADD = $(top_srcdir)/src/common/libcommon.la $(top_srcdir)/src/delim-reader/libreader.la
main_LDFLAGS = -static
