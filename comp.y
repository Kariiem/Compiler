%{

    #include <stdio.h>

    #define SYM_TAB_MAX 1000
    #define SYM_MAX 1000
    #define SYM_TAB_STACK_MAX 1000

    typedef enum { false, true } bool;

    // Struct of a single entry in the symbol table
    typedef struct symbol {
        char* name; // Name of the symbol
        int type;   // Type of the symbol
        char* value;  // Value of the symbol
        int line_num;   // Line number of the symbol for debugging
        bool is_const;  // Whether the symbol is a constant
        bool is_enum;   // Whether the symbol is an enum
        bool is_func;   // Whether the symbol is a function
    } symbol;

    // Struct of the symbol table itself
    typedef struct symTable {
        symbol* symbols;
        int num_symbols;
        int max_symbols;
        int index;
    } symTable;

    // Struct of a stack of symbol tables
    typedef struct symTabStack {
        symTable** sym_tabs;
        int num_sym_tabs;
        int max_sym_tabs;
    } symTabStack;


    enum types {
        TYPE_INT,
        TYPE_REAL,
        TYPE_STRING,
        TYPE_BOOL,
        TYPE_VOID,
        TYPE_ENUM,
    };

    // Define a function to create a new symbol table
    symTable* create_sym_table();

    // Define a function to create a new symbol table stack
    symTabStack* create_sym_tab_stack();

    // Define a function to push a symbol table onto the stack
    void push_sym_tab(symTabStack* stack, symTable* sym_tab);

    // Define a function to pop a symbol table off the stack


    extern int line_num; // Line number of the current token for debugging

%}


%union{
    char* id;
    int integer;
    double real;
    char* string;
    int boolean;
    void* voidVal;
    void* symbolval;
}


/*-----------------------------------*/
/* -:- keywords -:- */
/*-----------------------------------*/
%token TOKEN_MODULE
%token TOKEN_IMPORT
%token TOKEN_FUN
%token TOKEN_VAL
%token TOKEN_VAR 
%token TOKEN_TYPE
%token TOKEN_DO 
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_FOR  
%token TOKEN_WHILE
%token TOKEN_UNTIL
%token TOKEN_SWITCH
%token TOKEN_NOT
%token TOKEN_AND
%token TOKEN_OR

/*-----------------------------------*/
/* -:- arithmetic operators -:- */
/*-----------------------------------*/
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MULT
%token TOKEN_DIV
%token TOKEN_EXP
%token TOKEN_MOD

/*-----------------------------------*/
/* -:- comparison operators -:- */
/*-----------------------------------*/
%token TOKEN_LT 
%token TOKEN_GT 
%token TOKEN_LEQ
%token TOKEN_GEQ
%token TOKEN_EQ 
%token TOKEN_NEQ

/*-----------------------------------*/
/* -:- other tokens -:- */
/*-----------------------------------*/
%token TOKEN_EQUAL
%token TOKEN_COLON
%token TOKEN_QUALIFY
%token TOKEN_COMMA 
%token TOKEN_SEMICOLON
%token TOKEN_PIPE
%token TOKEN_AMP
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACE
%token TOKEN_RBRACE

/*-----------------------------------*/
/* -:- non-char/whitespace -:- */
/*-----------------------------------*/
%token TOKEN_NEWLINE
%token TOKEN_WS
%token TOKEN_EOF 
%token TOKEN_UNKNOWN

/*-----------------------------------*/
/* -:- atoms -:- */
/*-----------------------------------*/
%token <id> IDENTIFIER
%token <string> INTEGER
%token <string> REAL
%token <string> STRING
%token <boolean>     BOOL
/*-----------------------------------*/

/* module Main */
%left TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_MOD
%left TOKEN_AND TOKEN_OR
%left TOKEN_EQ TOKEN_NEQ TOKEN_GT TOKEN_GEQ TOKEN_LT TOKEN_LEQ
%left TOKEN_COMMA
%right TOKEN_NOT TOKEN_EXP TOKEN_EQUAL
%%
source: 
    module_decl top_level_decl_list         
    ;

module_decl: 
    TOKEN_MODULE IDENTIFIER TOKEN_NEWLINE   
    {}
    ;

top_level_decl_list: 
    %empty                                  {}
|   top_level_decl_list top_level_decl      
    {}
    ;

top_level_decl:
    import_decl                 
    {}
|   type_decl                   
    {}
|   term_decl                   
    {}
|   fun_decl                    
    {}
|   assignment                  
    {}
    ;

import_decl:
    TOKEN_IMPORT IDENTIFIER TOKEN_NEWLINE 
    {}
    ;

term_decl: 
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER optional_assignment   {}
    ;

assignment:
    IDENTIFIER TOKEN_EQUAL expr TOKEN_SEMICOLON 
    {}
    ;

val_or_var:
    TOKEN_VAL   {}
|   TOKEN_VAR   {}
    ;

optional_assignment:    ///// TODO: NO %nterm ///////
    TOKEN_EQUAL expr TOKEN_SEMICOLON         {}
|   TOKEN_SEMICOLON                          {}
    ;

expr:
    atomic_value        { }
|   arithmetic_expr     {  }
|   logical_expr        {  }
|   funcall             {  }
|   compound_expr       {  }
|   TOKEN_LPAREN expr TOKEN_RPAREN         { }
    ;

atomic_value:
    IDENTIFIER      { printf("PUSH_MEM %d\n", 5 ); }
|   INTEGER         { printf("PUSH %s\n", $1); }
|   REAL            { printf("PUSH %s\n", $1); }
|   BOOL            { printf("PUSH %d\n", $1); }
|   STRING          { printf("PUSH %s\n", $1); }
    ;

arithmetic_expr:    ////TODO: We call create_ast_bin_expr_t inside the create_ast_expr_t //
    expr TOKEN_PLUS expr      { printf("ADD\n"); }
|   expr TOKEN_MINUS expr     { printf("SUB\n"); }
|   expr TOKEN_MULT expr      { printf("MUL\n"); }
|   expr TOKEN_DIV expr       { printf("DIV\n"); }
|   expr TOKEN_MOD expr       { printf("MOD\n"); }
|   expr TOKEN_EXP expr       { printf("EXP\n"); }
    ;

logical_expr:       ////TODO: We call create_ast_bin_expr_t inside the create_ast_expr_t //
    TOKEN_NOT expr              { printf("NOT\n"); } 
|   expr TOKEN_AND expr         { printf("AND\n"); } 
|   expr TOKEN_OR expr          { printf("OR\n"); } 
|   expr TOKEN_LT expr          { printf("LT\n"); } 
|   expr TOKEN_GT expr          { printf("GT\n"); } 
|   expr TOKEN_LEQ expr         { printf("LEQ\n"); }
|   expr TOKEN_GEQ expr         { printf("GEQ\n"); }
|   expr TOKEN_EQ expr          { printf("EQ\n"); } 
|   expr TOKEN_NEQ expr         { printf("NEQ\n"); }
    ;

compound_expr:
    if_then_else_expr           { }
|   for_loop_expr               {  }
|   while_loop_expr             {  }
|   until_loop_expr             {  }
|   do_block_expr               {  }
|   switch_expr                 {  }
    ;

if_then_else_expr:
    TOKEN_IF expr block TOKEN_ELSE block    
    {  }
    ;

for_loop_expr:
    TOKEN_FOR IDENTIFIER TOKEN_COLON range block   
    {  }
    ;

range:
    TOKEN_LPAREN expr TOKEN_COMMA expr optional_step TOKEN_RPAREN  
    {  }
    ;

optional_step:
    %empty          { }
|   TOKEN_COMMA expr    {  }
    ;

while_loop_expr:
    TOKEN_WHILE expr block      
    { }
    ;

until_loop_expr:
    TOKEN_UNTIL expr block    
    {  }
    ;

do_block_expr:
    TOKEN_DO block        
    {  }
    ;

switch_expr:
    TOKEN_SWITCH expr TOKEN_LBRACE case_expr_list TOKEN_RBRACE  
    {  }
    ;

case_expr_list:
    %empty                          {  }
|   case_expr_list case_expr        
    {  }
    ;

case_expr:
    TOKEN_ELSE TOKEN_COLON block    
    {  }
|   expr TOKEN_COLON block          
    {  }
    ;

block:  
    TOKEN_LBRACE block_expression_list TOKEN_RBRACE  {  }
    ;

block_expression_list:
    %empty                                      {  }
|   block_expression_list block_expression      { }
    ;

block_expression:
    expr TOKEN_SEMICOLON                    {  }
|   term_decl                               {  }
|   assignment                              {  }
    ;

fun_decl:
    TOKEN_FUN IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN IDENTIFIER block   { }
    ;

param_list:
    %empty                              {}
|   param                               {}
|   param_list TOKEN_COMMA param        {}
    ;

param:
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER    {  }
    ;

funcall:
    IDENTIFIER TOKEN_LPAREN arg_list TOKEN_RPAREN   {  }
    ;

arg_list:
    %empty              {}
|   expr                {}
|   arg_list TOKEN_COMMA expr   {}
    ;
    
type_decl:
    TOKEN_TYPE IDENTIFIER TOKEN_EQUAL constructor_list TOKEN_SEMICOLON   {  }
    ;

constructor_list:
    constructor_field                                   {  }
|   constructor_list TOKEN_PIPE constructor_field       {  }
    ;

constructor_field: 
    IDENTIFIER                                          { }
    ;

    
%%



int main (void) {
	/* init symbol table */
    printf("PUSH_MEM %d", 5 );
	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

