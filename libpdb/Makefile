# $Id$

TOP =		..
SUBDIR =	libpdb

LIBNAME =	pdb
SHLIB_MAJOR =	0
SHLIB_MINOR =	0

LIBSRCS =	pdb.c util.c
LIBOBJS =	${LIBSRCS:.c=.o}
SHLIBOBJS =	${LIBSRCS:.c=.So}

CLEAN =		${LIBOBJS} ${SHLIBOBJS} ${LIBRARY} \
		*.ln *.bak *~ core *.core .depend
DISTCLEAN =	util.c
SPOTLESS =

DISTFILES =	Makefile ${LIBSRCS}

OTHERTAGFILES =	${LIBSRCS}

include ${TOP}/Make.rules

# "util.c" is a symlink because both "libpdb" and "libpconn" use it, but I
# don't want to maintain two identical copies of the same file. However,
# CVS doesn't handle symlinks, so instead we create it here.
all depend install lint::	util.c
util.c:
	ln -s ${TOP}/libpconn/util.c util.c

depend::
	${MKDEP} ${CPPFLAGS} ${LIBSRCS}

all::	${LIBRARY}

install::	${LIBRARY}
	${MKDIR} ${DESTDIR}/${LIBDIR}
	${INSTALL_PROGRAM} ${LIBRARY} ${DESTDIR}/${LIBDIR}/${LIBRARY}

# This is for Emacs's benefit:
# Local Variables:	***
# fill-column:	75	***
# End:			***
