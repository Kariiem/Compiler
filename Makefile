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

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
LEX_OBJS = $(patsubst %.l,$(SRC_DIR)/%.lex.c,$(LEX_SRCS))
YACC_OBJS = $(patsubst %.y,$(SRC_DIR)/%.tab.c,$(YACC_SRCS))
AST_OBJS = $(patsubst $(AST_DIR)/%.c,$(BUILD_DIR)/%.o,$(AST_SRCS))
DS_OBJS = $(patsubst $(DS_DIR)/%.c,$(BUILD_DIR)/%.o,$(DS_SRCS))
DECL_OBJS = $(patsubst $(DECL_DIR)/%.c,$(BUILD_DIR)/%.o,$(DECL_SRCS))
EXPR_OBJS = $(patsubst $(EXPR_DIR)/%.c,$(BUILD_DIR)/%.o,$(EXPR_SRCS))

ALL_OBJS = $(OBJS) $(LEX_OBJS) $(YACC_OBJS) $(AST_OBJS) $(DS_OBJS) $(DECL_OBJS) $(EXPR_OBJS)


all: comp


$(OBJS): $(SRCS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LEX_OBJS): $(LEX_SRCS)
	flex -o $@ --header-file=$(patsubst %.c,%.h,$@) --debug $<

$(YACC_OBJS): $(YACC_SRCS)
	bison -o $@ --defines=$(patsubst %.c,%.h,$@) --debug $<  
#-Wcounterexamples 
$(AST_OBJS): $(AST_SRCS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(DS_OBJS): $(DS_SRCS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(DECL_OBJS): $(DECL_SRCS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXPR_OBJS): $(EXPR_SRCS)
	$(CC) -c -o $@ $< $(CFLAGS)

comp: main.c $(ALL_OBJS) #comp.tab.c comp.lex.l
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@ 

clean:
	rm -f comp src/comp.* $(ALL_OBJS) build/*