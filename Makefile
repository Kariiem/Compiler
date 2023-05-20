SRC=$(wildcard src/*/*.c)
OBJ=$(SRC:.c=.o)

all: comp

comp.lex.c: comp.l
	flex -o $@ --header-file=$(patsubst %.c,%.h,$@) --debug $<

comp.tab.c: comp.y
	bison -o $@ --defines=$(patsubst %.c,%.h,$@) --debug $< 
#-Wcounterexamples 

comp: main.c $(OBJ) comp.tab.o comp.lex.o
	$(CC) -o $@ -Wall -ggdb $^

clean:
	rm -f comp comp.tab.c comp.lex.c comp.tab.h comp.lex.h main $(OBJ)