%define api.pure full
%locations
%param {yyscan_t scanner}
%param {ast_source_t** source_module}

%code top {
  #include <stdio.h>
} 
%code requires {
  typedef void* yyscan_t;
}
%code {
    int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner,ast_source_t** source_module);
    void yyerror(YYLTYPE* yyllocp, yyscan_t unused, ast_source_t **source_module, const char* msg);


    #include <src/ast/ast.h>
    #define SYM_TAB_MAX 1000
    #define SYM_MAX 1000
    #define SYM_TAB_STACK_MAX 1000

    typedef enum { false, true } bool;

    // Struct of a single entry in the symbol table
    typedef struct symbol_t {
        char* name; // Name of the symbol
        enum {
            SYM_TY_TERM,
            SYM_TY_FUNC,
            SYM_TY_ENUM,
        } type;
        char* value;  // Value of the symbol
        int line_num;   // Line number of the symbol for debugging
        union {
            ast_fundecl_t* func_val;
            ast_term_decl_t* term_val;
            ast_type_decl_t* type_val;
        } val;
    } symbol_t;

    // Struct of the symbol table itself
    typedef struct sym_tab_t {
        symbol_t* entries;
        int num_entries;
        int index;
        sym_tab_t* parent;
    } sym_tab_t;

    // Symbol table functions
    sym_tab_t* sym_tab_init();
    void add_sym(sym_tab_t* head, int type, void* val, char* name, int line_num);
    symbol_t* get_sym(sym_tab_t* head, char* name);
    // Symbol table head functions
    sym_tab_t* sym_tab_list_init();
    void sym_tab_insert(sym_tab_t* head, sym_tab_t* sym_tab);
    sym_tab_t* sym_tab_stack_pop(sym_tab_t* head);




    extern int line_num; // Line number of the current token for debugging

    // Create a stack of symbol tables for global scope
    sym_tab_stack_t* sym_tab_stack = sym_tab_stack_init();

    void sym_tab_free(sym_tab_t* sym_tab);
    void sym_tab_print(sym_tab_t* sym_tab);
    void sym_tab_print_entry(symbol_t* entry);
    void sym_tab_stack_print(sym_tab_stack_t* stack);
    void sym_tab_stack_print_entry(symbol_t* entry);
    void sym_tab_stack_print_all(sym_tab_stack_t* stack);
    void sym_tab_stack_free(sym_tab_stack_t* stack);
    

}


%union{
    char* id;
    int integer;
    double real;
    char* string;
    bool boolean;
    void* unknownVal;
    void* unknownType;
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
%token <integer> INTEGER
%token <real> REAL
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
    module_decl top_level_decl_list {$$=sym_tab_stack_pop(sym_tab_stack);}
    ;

module_decl: 
    TOKEN_MODULE IDENTIFIER TOKEN_NEWLINE   {$$=create_ast_module_decl_t($2);}
    ;

top_level_decl_list: 
    %empty                                  {$$=NULL;}
|   top_level_decl_list top_level_decl      {$$=$1; cvector_push_back($1, $2);}
    ;

top_level_decl:
    import_decl                 {$$=create_ast_top_level_decl_t(DECL_IMPORT, $1);}
|   type_decl                   {$$=create_ast_top_level_decl_t(DECL_TYPE, $1);}
|   term_decl                   {$$=create_ast_top_level_decl_t(DECL_TERM, $1);}
|   fun_decl                    {$$=create_ast_top_level_decl_t(DECL_FUN, $1);}
    ;

import_decl:
    TOKEN_IMPORT IDENTIFIER TOKEN_NEWLINE {$$=create_ast_import_decl_t($2);}
    ;

term_decl: 
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER optional_assignment   {$$=create_ast_term_decl_t($1, $2, $4, $5);}
|   IDENTIFIER TOKEN_EQUAL expr TOKEN_SEMICOLON                        /////TODO/////
    ;

val_or_var:             //////TODO: NO %nterm ////////
    TOKEN_VAL   {$$=TERM_VAL;}
|   TOKEN_VAR   {$$=TERM_VAR;}
    ;

optional_assignment:    ///// TODO: NO %nterm ///////
    TOKEN_EQUAL expr TOKEN_SEMICOLON         {$$=$2;}
|   TOKEN_SEMICOLON                          {$$=NULL;}
    ;

expr:
    atomic_value        { $$=$1; }
|   arithmetic_expr     { $$=$1; }
|   logical_expr        { $$=$1; }
|   funcall             { $$=$1; }
|   compound_expr       { $$=$1; }
|   TOKEN_LPAREN expr TOKEN_RPAREN         { $$=$2; }
    ;

atomic_value:
    IDENTIFIER      { $$=create_ast_expr_t(EXPR_IDENTIFIER, $1); }
|   INTEGER         { $$=create_ast_expr_t(EXPR_INTEGER, $1); }
|   REAL            { $$=create_ast_expr_t(EXPR_REAL, $1); }
|   BOOL            { $$=create_ast_expr_t(EXPR_BOOL, $1); }
|   STRING          { $$=create_ast_expr_t(EXPR_STRING, $1); }
    ;

arithmetic_expr:    ////TODO: We call create_ast_bin_expr_t inside the create_ast_expr_t //
    expr TOKEN_PLUS expr      { $$=creat_ast_expr_t(EXPR_ADD,create_ast_bin_expr_t($1, $3, EXPR_ADD)); }
|   expr TOKEN_MINUS expr     { $$=creat_ast_expr_t(EXPR_SUB,create_ast_bin_expr_t($1, $3, EXPR_SUB)); }
|   expr TOKEN_MULT expr      { $$=creat_ast_expr_t(EXPR_MUL,create_ast_bin_expr_t($1, $3, EXPR_MUL)); }
|   expr TOKEN_DIV expr       { $$=creat_ast_expr_t(EXPR_DIV,create_ast_bin_expr_t($1, $3, EXPR_DIV)); }
|   expr TOKEN_MOD expr       { $$=creat_ast_expr_t(EXPR_MOD,create_ast_bin_expr_t($1, $3, EXPR_MOD)); }
|   expr TOKEN_EXP expr       { $$=creat_ast_expr_t(EXPR_EXP,create_ast_bin_expr_t($1, $3, EXPR_EXP)); }
    ;

logical_expr:       ////TODO: We call create_ast_bin_expr_t inside the create_ast_expr_t //
    TOKEN_NOT expr              { $$=creat_ast_expr_t(EXPR_NOT,create_ast_bin_expr_t(NULL, $2 ,EXPR_NOT)); } ///TODO: Considered as binary expr with the left operand is NULL
|   expr TOKEN_AND expr         { $$=creat_ast_expr_t(EXPR_AND,create_ast_bin_expr_t($1, $3, EXPR_AND)); } 
|   expr TOKEN_OR expr          { $$=creat_ast_expr_t(EXPR_OR,create_ast_bin_expr_t($1, $3, EXPR_OR)); } 
|   expr TOKEN_LT expr          { $$=creat_ast_expr_t(EXPR_LT,create_ast_bin_expr_t($1, $3, EXPR_LT)); } 
|   expr TOKEN_GT expr          { $$=creat_ast_expr_t(EXPR_GT,create_ast_bin_expr_t($1, $3, EXPR_GT)); } 
|   expr TOKEN_LEQ expr         { $$=creat_ast_expr_t(EXPR_LEQ,create_ast_bin_expr_t($1, $3, EXPR_LEQ)); }
|   expr TOKEN_GEQ expr         { $$=creat_ast_expr_t(EXPR_GEQ,create_ast_bin_expr_t($1, $3, EXPR_GEQ)); }
|   expr TOKEN_EQ expr          { $$=creat_ast_expr_t(EXPR_EQ,create_ast_bin_expr_t($1, $3, EXPR_EQ)); } 
|   expr TOKEN_NEQ expr         { $$=creat_ast_expr_t(EXPR_NEQ,create_ast_bin_expr_t($1, $3, EXPR_NEQ)); }
    ;

compound_expr:
    if_then_else_expr           { $$=create_ast_expr_t(EXPR_IF, $1); }
|   for_loop_expr               { $$=create_ast_expr_t(EXPR_FOR, $1); }
|   while_loop_expr             { $$=create_ast_expr_t(EXPR_WHILE, $1); }
|   until_loop_expr             { $$=create_ast_expr_t(EXPR_UNTIL, $1); }
|   do_block_expr               { $$=create_ast_expr_t(EXPR_DO, $1); }
|   switch_expr                 { $$=create_ast_expr_t(EXPR_SWITCH, $1); }
    ;

if_then_else_expr:
    TOKEN_IF expr block TOKEN_ELSE block    { $$=create_ast_if_t($2, $3, $5); }
    ;

for_loop_expr:
    TOKEN_FOR IDENTIFIER TOKEN_COLON range block   { $$=create_ast_for_t($2, $4, $5); }
    ;

range:
    TOKEN_LPAREN expr TOKEN_COMMA expr optional_step TOKEN_RPAREN  { $$=create_ast_range_t($2, $4, $5); }
    ;

optional_step:
    %empty          { $$=NULL;}
|   TOKEN_COMMA expr    { $$=$2; }
    ;

while_loop_expr:
    TOKEN_WHILE expr block      { $$=create_ast_while_t($2, $3);}
    ;

until_loop_expr:
    TOKEN_UNTIL expr block    { $$=create_ast_while_t($2, $3); }
    ;

do_block_expr:
    TOKEN_DO block        { $$=create_ast_do_t($2); }
    ;

switch_expr:
    TOKEN_SWITCH expr TOKEN_LBRACE case_expr_list TOKEN_RBRACE  { $$=create_ast_switch_t($2, $4); }
    ;

case_expr_list:
    %empty                          { $$=NULL; }
|   case_expr_list case_expr        { $$=$1; cvector_push_back($1, $2); }
    ;

case_expr:
    TOKEN_ELSE TOKEN_COLON block    { $$=create_ast_case_t(NULL, $3); }
|   expr TOKEN_COLON block          { $$=create_ast_case_t($1, $3); }
    ;

block:  
    TOKEN_LBRACE block_expression_list TOKEN_RBRACE  { $$=create_ast_block_t($2); }
    ;

block_expression_list:
    %empty                                      { $$=NULL; }
|   block_expression_list block_expression      { $$=$1; cvector_push_back($1, $2); }
    ;

block_expression:
    expr TOKEN_SEMICOLON                    { $$=create_ast_block_expr_t(EXPR, $1); }
|   term_decl                               { $$=create_ast_block_expr_t(DECL, $1); }
    ;

fun_decl:
    TOKEN_FUN IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN IDENTIFIER block   { $$=create_ast_fundecl_t($2, $4, $6, $7); }
    ;

param_list:
    %empty                              {$$=NULL;}
|   param                               {$$=cvector_create(ast_param_t, 1); cvector_push_back($$, $1);}         ////TODO: Check if this is correct as it was done by copilot//// I know this should be similar to line 295 but think about it. If this is right, then change line 295
|   param_list TOKEN_COMMA param        {$$=$1; cvector_push_back($1, $3);}
    ;

param:
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER    { $$=create_ast_param_t($1, $2, $4); }
    ;

funcall:
    IDENTIFIER TOKEN_LPAREN arg_list TOKEN_RPAREN   { $$=create_ast_funcall_t($1, $3); }
    ;

arg_list:
    %empty              {$$=NULL;}
|   expr                {cvector_push_back($$, $1);}
|   arg_list TOKEN_COMMA expr{$$=$1;cvector_push_back($1,$3);}
    ;
    
type_decl:
    TOKEN_TYPE IDENTIFIER TOKEN_EQUAL constructor_list TOKEN_SEMICOLON   { $$=create_ast_type_decl_t($2, $4); }
    ;

constructor_list:
    constructor_field                                   { $$=cvector_create(ast_constructor_t, 1); cvector_push_back($$, $1); }         ////TODO: Check if this is correct as it was done by copilot//// I know this should be similar to line 295 but think about it. If this is right, then change line 295
|   constructor_list TOKEN_PIPE constructor_field       { $$=$1; cvector_push_back($1, $3); }
    ;

constructor_field: 
    IDENTIFIER record                              { $$=create_ast_constructors_t($1, $2); }
    ;

record:
    %empty                                          { $$=NULL; }
|   TOKEN_LBRACE record_field_list TOKEN_RBRACE     { $$=$2; }
    ;

record_field_list:
    record_field                                    { $$=cvector_create(ast_record_field_t, 1); cvector_push_back($$, $1); }           ////TODO: Check if this is correct as it was done by copilot//// I know this should be similar to line 295 but think about it. If this is right, then change line 295
|   record_field_list TOKEN_COMMA record_field      { $$=$1; cvector_push_back($1, $3); }
    ;
    
record_field:
    IDENTIFIER TOKEN_COLON IDENTIFIER               { $$=create_ast_record_field_t($1, $3); }
    
%%

void yyerror(YYLTYPE* yyllocp, yyscan_t unused,ast_source_t **source_module, const char* msg) {
  
  char token_name[255];
  
  fprintf(stderr, "[%d:%d]: %s\n",
                  yyllocp->first_line, yyllocp->first_column, msg);
}



// Symbol table functions
sym_tab_t* sym_tab_init(){
    sym_tab_t* sym_tab = (sym_tab_t*)malloc(sizeof(sym_tab_t));
    sym_tab->entries = cvector_create(symbol_t, 0);
    sym_tab->num_entries = 0;
    sym_tab->index = -1;
    return sym_tab;
}

void add_sym(sym_tab_stack_t* stack, char* name, int type, char* value, int line_num, bool is_const, bool is_enum, bool is_func){
    
    // To handle scopes we need to check if there is a symbol table in the stack
    // If there is, we add the symbol to that table
    // If there isn't, this means an error has occured because at least the global scope should be in the stack while creating the stack
    if(stack->num_tables == 0){
        printf("Error: No symbol table in stack\n");
        exit(1);
    }
    // Get the symbol table at the top of the stack
    sym_tab_t* sym_tab = stack->tables[stack->num_tables-1];

    // Check if the symbol already exists in the symbol table
    for(int i = 0; i < sym_tab->num_entries; i++){
        if(strcmp(sym_tab->entries[i]->name, name) == 0){
            printf("Error: Symbol %s already exists in symbol table\n", name);
            exit(1);
        }
    }

    // Create a new symbol table entry
    symbol_t* entry = (symbol_t*)malloc(sizeof(symbol_t));
    entry->name = name;
    entry->type = type;
    entry->value = value;
    entry->line_num = line_num;
    entry->is_const = is_const;
    entry->is_enum = is_enum;
    entry->is_func = is_func;

    // Add the entry to the symbol table
    cvector_push_back(stack->tables[stack->num_tables-1]->entries, entry);
    stack->tables[stack->num_tables-1]->num_entries++;
}
symbol_t* get_sym(sym_tab_stack_t* stack, char* name){
    // To handle scopes we need to check if there is a symbol table in the stack
    // If there is, we add the symbol to that table
    // If there isn't, this means an error has occured because at least the global scope should be in the stack while creating the stack
    if(stack->num_tables == 0){
        printf("Error: No symbol table in stack\n");
        exit(1);
    }
    // Get the symbol table at the top of the stack
    sym_tab_t* sym_tab = stack->tables[stack->num_tables-1];

    // Check if the symbol already exists in the symbol table
    for(int i = 0; i < sym_tab->num_entries; i++){
        if(strcmp(sym_tab->entries[i]->name, name) == 0){
            return sym_tab->entries[i];
        }
    }
    return NULL;
}


// Symbol table stack functions
sym_tab_stack_t* sym_tab_stack_init(){
    sym_tab_stack_t* stack = (sym_tab_stack_t*)malloc(sizeof(sym_tab_stack_t));
    // We create the global scope and add it to the stack
    stack->tables = cvector_create(sym_tab_init(), 1);
    stack->num_tables = 1;
    return stack;
}


void sym_tab_stack_push(sym_tab_stack_t* stack, sym_tab_t* sym_tab){
    cvector_push_back(stack->tables, sym_tab);
    stack->num_tables++;
}


sym_tab_t* sym_tab_stack_pop(sym_tab_stack_t* stack){
    if(stack->num_tables == 0){
        printf("Error: No symbol table in stack\n");
        exit(1);
    }
    sym_tab_t* sym_tab = stack->tables[stack->num_tables-1];
    cvector_pop_back(stack->tables);
    stack->num_tables--;
    return sym_tab;
}



