# Makefile for 3Com Fast Ethernet 10/100 driver (FE100)
PROG=	fe100
SRCS=	fe100.c

FILES=$(PROG).conf
FILESNAME=$(PROG)
FILESDIR= /etc/system.conf.d

DPADD+=	${LIBNETDRIVER} ${LIBSYS} ${LIBTIMERS}
LDADD+=	-lnetdriver -lsys -ltimers

MAN=

BINDIR?= /usr/sbin

.include <minix.service.mk>
