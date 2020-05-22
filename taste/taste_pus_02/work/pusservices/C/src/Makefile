VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-pusservices.h \
                  ../../dataview/C/Context-pusservices.c \
                  src/pusservices.h \
                  src/pusservices.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
