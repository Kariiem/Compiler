all: comp

comp.lex.c: comp.l
	flex -o $@ --header-file=$(patsubst %.c,%.h,$@) --debug $<

comp.tab.c: comp.y
	bison -o $@ --defines=$(patsubst %.c,%.h,$@) --debug $<

comp: main.c comp.tab.c comp.lex.c comp.h
	$(CC) -o $@ -Wall -ggdb $(filter %.c,$^)

clean:
	rm -f comp.tab.c comp.lex.c comp.tab.h comp.lex.h main