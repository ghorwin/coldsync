#!/bin/sh

CPPFLAGS="-g3 -fno-strict-aliasing"

# On NetBSD, enable declaration of u_{char,int,long} and friends
if [ x"`uname`" = x"NetBSD" ]
then
    CPPFLAGS="${CPPFLAGS} -D_NETBSD_SOURCE"
fi

autoconf

env CPPFLAGS="${CPPFLAGS}" \
    sh ./configure --prefix=/usr/local/coldsync --without-i18n
