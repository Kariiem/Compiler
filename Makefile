# Compiler settings
CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall -Wextra -Wconversion -Wshadow -ggdb -fsanitize=address,undefined -fno-omit-frame-pointer -std=c99 -Isrc -Isrc/ast -Isrc/ast/datastructures -Isrc/ast/declaration -Isrc/ast/expression
LDFLAGS =

# Directories
BUILD_DIR = build
SRC_DIR = src
AST_DIR = $(SRC_DIR)/ast
DS_DIR = $(AST_DIR)/datastructures
DECL_DIR = $(AST_DIR)/declaration
EXPR_DIR = $(AST_DIR)/expression

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
LEX_SRCS = comp.l
YACC_SRCS = comp.y
AST_SRCS = $(wildcard $(AST_DIR)/*.c)
DS_SRCS = $(wildcard $(DS_DIR)/*.c)
DECL_SRCS = $(wildcard $(DECL_DIR)/*.c)
EXPR_SRCS = $(wildcard $(EXPR_DIR)/*.c)

LEX_C = $(patsubst %.l,$(SRC_DIR)/%.lex.c,$(LEX_SRCS))
YACC_C = $(patsubst %.y,$(SRC_DIR)/%.tab.c,$(YACC_SRCS))

ALL_SRCS = $(SRCS) $(LEX_C) $(YACC_C) $(AST_SRCS) $(DS_SRCS) $(DECL_SRCS) $(EXPR_SRCS)

ifeq ($(NDEBUG),1)
	CFLAGS += -DNDEBUG
endif
all: comp

$(LEX_C): $(LEX_SRCS)
	flex -o $@ --header-file=$(patsubst %.c,%.h,$@) --debug $<

$(YACC_C): $(YACC_SRCS)
	bison -o $@ --defines=$(patsubst %.c,%.h,$@) --debug $<  
#-Wcounterexamples 

comp: main.c $(ALL_SRCS) #comp.tab.c comp.lex.l
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@ 

clean:
	rm -f comp src/comp.* 