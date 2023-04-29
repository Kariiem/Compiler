CC     := gcc
CFLAGS := -Wall -O -ggdb
CFLAGS += -DDEBUG

main: main.c parser.tab.o scanner.o
	$(CC) $^ -o $@ $(CFLAGS)

parser.tab.o: parser.tab.c
	$(CC) -c $^  -o $@ $(CFLAGS)

scanner.o: scanner.c
	$(CC) -c $^ -o $@ $(CFLAGS)

parser.tab.c: parser.y scanner.c
	bison -d $<

scanner.c: lexer.l
	flex $^

clean:
	-rm main scanner.* parser.tab.*

.PHONY: clean
