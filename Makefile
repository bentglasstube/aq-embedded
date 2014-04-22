SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,obj/%.o,${SRC})
BIN=aq

all: ${BIN}

obj/%.o: src/%.c
	@mkdir -p $(@D)
	${CC} -c ${CFLAGS} -o $@ $<

${BIN}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${BIN} ${OBJ}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${BIN} ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/${BIN}

.PHONY: all clean install
