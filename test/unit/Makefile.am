AM_TESTSUITE_SUMMARY_HEADER = ' of unit tests for $(PACKAGE_STRING)'

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test_record test_dataframe

test_record_SOURCES = test-record.c
test_record_LDADD = $(top_srcdir)/src/common/libcommon.la

test_dataframe_SOURCES = test-dataframe.c
test_dataframe_LDADD = $(top_srcdir)/src/common/libcommon.la


AM_CPPFLAGS = -I$(top_srcdir)/include
