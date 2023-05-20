#!/bin/bash

# Compiler settings
CC=gcc
LEX=flex
YACC=bison
CFLAGS="-Wall -Wextra -Wconversion -Wshadow -ggdb -fsanitize=address,undefined -fno-omit-frame-pointer -std=c99 -Isrc -Isrc/ast -Isrc/ast/datastructures -Isrc/ast/declaration -Isrc/ast/expression"
LDFLAGS=""

# Directories
BUILD_DIR=build
SRC_DIR=src
AST_DIR="$SRC_DIR"/ast
DS_DIR="$AST_DIR"/datastructures
DECL_DIR="$AST_DIR"/declaration
EXPR_DIR="$AST_DIR"/expression

# Source files
SRCS=$(echo "$SRC_DIR"/*.c)
LEX_SRCS=comp.l
YACC_SRCS=comp.y
AST_SRCS=$(echo "$AST_DIR"/*.c)
DS_SRCS=$(echo "$DS_DIR"/*.c)
DECL_SRCS=$(echo "$DECL_DIR"/*.c)
EXPR_SRCS=$(echo "$EXPR_DIR"/*.c)

LEX_C=$(echo "$LEX_SRCS" | sed 's/\.l$/.lex.c/')
YACC_C=$(echo "$YACC_SRCS" | sed 's/\.y$/.tab.c/')

ALL_SRCS="$SRCS $LEX_C $YACC_C $AST_SRCS $DS_SRCS $DECL_SRCS $EXPR_SRCS"

all() {
    comp
}

# Compile the lex source files
"$LEX" -o "$SRC_DIR"/"$LEX_C" --header-file="$SRC_DIR"/"${LEX_C%.c}.h" --debug "$SRC_DIR"/"$LEX_SRCS"

# Compile the yacc source files
"$YACC" -o "$SRC_DIR"/"$YACC_C" --defines="$SRC_DIR"/"${YACC_C%.c}.h" --debug "$SRC_DIR"/"$YACC_SRCS"

comp(){
    # Compile the program
    "$CC" main.c $ALL_SRCS $CFLAGS $LDFLAGS -o comp
}

clean() {
    # Clean up any generated files
    rm -f comp "$SRC_DIR"/comp.* 
}

# Call the appropriate function based on the first argument
"$@"