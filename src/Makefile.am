include $(top_srcdir)/support/automake/noweb.am
include $(top_srcdir)/support/automake/guile.am

.SECONDARY:

NOWEAVE_HEADER = $(nowebdir)/doc-header.tex
NOWEAVE_FOOTER = $(nowebdir)/doc-footer.tex
NOWEAVE_FLAGS = 
BUILT_SOURCES = $(NOWEB_BUILT_FILES) rigid-body-smob.cpp.x sim-smob.cpp.x
CLEANFILES = $(NOWEB_CLEANFILES) rigid-body-smob.cpp.x sim-smob.cpp.x

WARN_NOTANGLE = $(top_builddir)/bin/warn-notangle

dist-hook:
	cp $(distdir)/*.pdf $(top_distdir)

NOWEB_DOCS = rigid-body-smob.pdf sim-smob.pdf
NOWEB_FILES = rigid-body-smob.nw sim-smob.nw bullet.nw
NOWEB_PRODUCTS = rigid-body-smob.cpp rigid-body-smob.h sim-smob.cpp	\
								  sim-smob.h sim-smob-test.scm bullet.cpp bullet.scm
EXTRA_DIST = $(NOWEB_DOCS) $(NOWEB_EXTRA_DIST)

rigid-body-smob.o : rigid-body-smob.cpp.x

sim-smob.o : sim-smob.cpp.x

check_PROGRAMS = link-test

TESTS = link-test sim-smob-test.scm
TEST_EXTENSIONS = .scm 
SCM_LOG_COMPILER = $(ENV) guile 

lib_LTLIBRARIES = libguile-bullet.la

guilemoduledir = $(prefix)/share/guile/site/
dist_guilemodule_DATA = bullet.scm

AM_CPPFLAGS  = $(GUILE_CFLAGS) $(BULLET_CFLAGS) $(GUILE_LOG4C_CFLAGS)
link_test_LDADD   = $(GUILE_LIBS) libguile-bullet.la 
link_test_LDFLAGS = $(GUILE_LDFLAGS)
link_test_SOURCES = link-test.cpp

libguile_bullet_la_LIBADD  = $(GUILE_LIBS) $(BULLET_LIBS) $(GUILE_LOG4C_LIBS)
libguile_bullet_la_SOURCES = rigid-body-smob.cpp sim-smob.cpp bullet.cpp
include_HEADERS = rigid-body-smob.h sim-smob.h

MAINTAINERCLEANFILES = Makefile.in config.h.in 
