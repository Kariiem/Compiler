all: comp

comp.lex.c: comp.l
	flex -o $@ --header-file=$(patsubst %.c,%.h,$@) --debug $<

comp.tab.c: comp.y
	bison -o $@ --defines=$(patsubst %.c,%.h,$@) --debug $< 
#-Wcounterexamples 

comp: main.c comp.tab.c comp.lex.c comp.h
	$(CC) -DDEBUG -o $@ -Wall -ggdb $(filter %.c,$^)

clean:
	rm -f comp comp.tab.c comp.lex.c comp.tab.h comp.lex.h main