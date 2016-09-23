CC      = gcc

CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

LDFLAGS = -g

TOUS:= prlimit maccess maccess+

tout: ${TOUS}

%.o: %.c
	${CC} ${CFLAGS} -c $<

%: %.o
	${CC} ${LDFLAGS} -o $@ $^

# Désactive la règle implicite (de GNU Make) de compilation d’un .c en
# exécutable, pour forcer l’utilisation des règles précédentes
%: %.c

#clean:
#	rm core *.o || true

#realclean: clean
#	rm ${TOUS} || true

#.PHONY: all clean realclean
