%code requires {
    #include "cvector.h"
    #include "cvector_utils.h"
    #include "utils.h"
}

%{

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "cvector.h"
    #include "cvector_utils.h"
    #include "utils.h"
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
        int symbol_id;     // ID of the symbol
        int * enum_values;  // Values of the enum
        vtype(char*) enum_value_names; // Names of the enum values
        int num_enum_values;    // Number of values in the enum
        int return_type;    // Return type of the function
        int num_parameters; // Number of parameters of the function
        int * parameter_list_types; // Types of the parameters of the function
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
    typedef struct symTableStack {
        symTable** sym_tabs;
        int num_sym_tabs;
        int max_sym_tabs;
    } symTableStack;


    enum types {
        TYPE_INT,
        TYPE_REAL,
        TYPE_STRING,
        TYPE_BOOL,
        TYPE_VOID,
        TYPE_ENUM,
        TYPE_FUNC,
        TYPE_JUMP   // Used for jumps in the code like IF, ELSE, FOR, WHILE, etc.
    };

    // Define a function to create a new symbol table
    symTable* create_sym_table();

    // Define a function to create a new symbol table stack
    symTableStack* create_sym_tab_stack();

    // Define a function to push a symbol table onto the stack
    void push_sym_tab(symTableStack* stack, symTable* sym_tab);

    // Define a function to pop a symbol table off the stack
    symTable* pop_sym_tab(symTableStack* stack);

    // Define a function to add a symbol to the symbol table
    void add_symbol(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id, bool is_const, bool is_enum, bool is_func);

    // Define a function to add a symbol to the symbol table
    void add_symbol_enum(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id, bool is_const, bool is_enum, bool is_func, vtype(char*) enum_values);

    // Define a function to add a symbol to the symbol table but with a list of parameters
    void add_symbol_with_args(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id, bool is_const, bool is_enum, bool is_func, char * return_identifier, vtype(char*) enum_value_names);

    // Define a function to get a symbol from the symbol table
    // reverse_search is used to search the symbol table stack from top to bottom with default value false
    symbol* get_symbol(symTableStack* stack, char* name, bool reverse_search, bool search_parent);

    // Define a function to copy value of a symbol to another symbol
    char* copy_value(char* value);
    // Define a function to copy value of void
    void* copy_void(void* value);

    // Define a function to cast type void to type symbol
    symbol* cast_void_to_symbol(void* value){
        return (symbol*)value;
    }

    // Define a function to know the type of an identifier
    int get_type(char* name){
        if(strcmp(name, "int") == 0){
            return TYPE_INT;
        }
        else if(strcmp(name, "double") == 0){
            return TYPE_REAL;
        }
        else if(strcmp(name, "string") == 0){
            return TYPE_STRING;
        }
        else if(strcmp(name, "bool") == 0){
            return TYPE_BOOL;
        }
        else if(strcmp(name, "void") == 0){
            return TYPE_VOID;
        }
        else{
            return -1;
        }
    }


    // Define a function to check for assignment compatibility with a symbol
    // It takes the assignment type as enum and the symbol to check
    bool check_assignment(symbol* sym, char* type_name);

    // Create a global symbol table stack
    symTableStack* sym_tab_stack;

    extern int line_num; // Line number of the current token for debugging

    int symbol_id = 0; // ID of the current symbol

    int if_label_counter = 0; // Counter for the IF labels

    int while_label_counter = 0; // Counter for the WHILE labels

    int for_label_counter = 0; // Counter for the FOR labels

    int switch_label_counter = 0; // Counter for the SWITCH labels

    int case_label_counter = 0; // Counter for the CASE labels


    char * current_identifier; // Current identifier

    int identifier_flag = 0; // Flag to check if the current token is an identifier

%}


%union{
    char* id;
    int integer;
    double real;
    char* string;
    int boolean;
    void* voidVal;
    void* symbolval;
    vtype(char*) type_list;
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
/* -:- non-terminals -:- */
/*-----------------------------------*/
%type <integer> val_or_var
%type <symbolval> expr
%type <symbolval> optional_assignment
%type <symbolval> atomic_value
%type <symbolval> for_var
%type <type_list>  param_list
%type <string> param
%type <type_list>  arg_list
%type <type_list>  constructor_list


/* module Main */
%left TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_MOD
%left TOKEN_AND TOKEN_OR
%left TOKEN_EQ TOKEN_NEQ TOKEN_GT TOKEN_GEQ TOKEN_LT TOKEN_LEQ
%left TOKEN_COMMA
%right TOKEN_NOT TOKEN_EXP TOKEN_EQUAL
%%
source: 
    module_decl {printf("Kak_BEGINE\n");} top_level_decl_list      {printf("Kak_END\n");}   
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
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER optional_assignment   
    {
        // First check if the name is already taken
        symbol* sym = get_symbol(sym_tab_stack, $2, false, false);

        // If the symbol is not found, add it to the symbol table
        if(sym == NULL){
            // Check if the type is valid
            // The $4 is the type of the variable but it is stored as a string in the token
            // We match the string to the type and get the type as an integer
            int type = get_type($4);
            symbol_id++;
            add_symbol(sym_tab_stack, $2, type, $5, line_num, symbol_id ,($1 == 0), false, false);
            if($5!=NULL)
            {
                // Write an assembly command to sotre the value of the variable
                printf("PUSH_MEM %d\n", symbol_id);
            }
        }
        else{
            printf("ERROR: Symbol %s already defined on line %d\n", $2, sym->line_num);
            exit(1);
        }

        
    }
    ;

assignment:
    IDENTIFIER TOKEN_EQUAL expr TOKEN_SEMICOLON 
    {
        // First check if the symbol exists
        symbol* sym = get_symbol(sym_tab_stack, $1, false, true);

        // If the symbol is not found, add it to the symbol table
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", $1, line_num);
            exit(1);
        }
        else{
            // Check if the assignment is valid
            ////TODO: Apply the stack approach that kamal mentioned and if the identifier is a variable, pop it from the stack machine and but check first if it's there
            // Note that there may be compound expressions on the right hand side of the assignment and binary operations not just atomic values
            // Write an assembly command to store the value of the variable
            printf("PUSH_MEM %d\n", sym->symbol_id);
        }
    }
    ;

val_or_var:
        TOKEN_VAL   { $$=0;}          /// TOTOKEN_VAL is a constant
    |   TOKEN_VAR   { $$=1; }          /// TOKEN_VAR is a variable
    ;

optional_assignment:  
        TOKEN_EQUAL expr TOKEN_SEMICOLON         {$$ = $2;}
    |   TOKEN_SEMICOLON                          {$$ = NULL;}
    ;

expr:
        atomic_value        { $$ = $1; }
    |   arithmetic_expr     {  }
    |   logical_expr        {  }
    |   funcall             {  }
    |   compound_expr       {  }
    |   TOKEN_LPAREN expr TOKEN_RPAREN         { $$ = $2; }
    ;

atomic_value:
        IDENTIFIER      { 
                        identifier_flag = 1; $$ = $1; 
                        // First check if the symbol exists
                        symbol* sym = get_symbol(sym_tab_stack, $1, false, true);
                        
                        // If the symbol is not found, error out
                        if(sym == NULL){
                            printf("ERROR: Symbol %s not defined on line %d\n", $1, line_num);
                            exit(1);
                        }
                        else{
                            printf("POP_MEM %d\n", sym->symbol_id);
                        }
                        }
    |   INTEGER         { 
                        printf("PUSH %d\n", $1);
                        //Create a new void pointer to store the value of the integer
                        void* val = malloc(sizeof(int));
                        //Copy the value of the integer to the void pointer
                        memcpy(val, &$1, sizeof(int));
                        //Return the void pointer
                        $$ = val;
                        }
    |   REAL            { 
                        printf("PUSH %f\n", $1);
                        //Create a new void pointer to store the value of the real
                        void* val = malloc(sizeof(double));
                        //Copy the value of the real to the void pointer
                        memcpy(val, &$1, sizeof(double));
                        //Return the void pointer
                        $$ = val;
                        }
    |   BOOL            { 
                        printf("PUSH %d\n", $1); 
                        //Create a new void pointer to store the value of the boolean
                        void* val = malloc(sizeof(bool));
                        //Copy the value of the boolean to the void pointer
                        memcpy(val, &$1, sizeof(bool));
                        //Return the void pointer
                        $$ = val;
                        }
    |   STRING          { 
                        printf("PUSH %s\n", $1);
                        //Create a new void pointer to store the value of the string
                        void* val = malloc(sizeof(char*));
                        //Copy the value of the string to the void pointer
                        memcpy(val, &$1, sizeof(char*));
                        //Return the void pointer
                        $$ = val;
                        }
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
    TOKEN_IF expr
    {
        // How to hanle labels of the if statement:
        // increment the if_label_counter which is global
        // Store it in the symbol_id of the symbol entry in the symbol table
        // Else and End_if will get the latest entry in the symbol table with type IF 
        // If the expression is flase, Jump to the else label
        if_label_counter++;
        printf("JMP_FALSE ELSE_IF_%d\n", if_label_counter);

        // Create a new symbol for the if statement and push it to the symbol table
        add_symbol(sym_tab_stack, "IF", TYPE_JUMP , NULL , line_num ,if_label_counter, false, false, false);

    }
    block 
    {
        // Search for the last symbol with name IF in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "IF", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "IF", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JUMP END_IF_%d\n", sym->symbol_id);
        }

    }
    TOKEN_ELSE {
        // Search for the last symbol with name IF in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "IF", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "IF", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the else block
            printf("ELSE_IF_%d:\n", sym->symbol_id);
        }

    }
    block { 
        // Search for the last symbol with name IF in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "IF", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "IF", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the else block
            printf("END_IF_%d:\n", sym->symbol_id);
        }

    }
    ;

for_loop_expr:
    TOKEN_FOR IDENTIFIER TOKEN_COLON TOKEN_LPAREN for_var 
    {
        /// $2 is the identifier of the counter variable
        // Create a new symbol for the counter variable and push it to the symbol table
        // First check if the symbol is already defined in the symbol table
        if(get_symbol(sym_tab_stack, $2, false, false) != NULL){
            printf("ERROR: Symbol %s already defined on line %d\n", $2, line_num);
            exit(1);
        }
        else{
            // Create the symbol and push it to the symbol table
            symbol_id++;
            add_symbol(sym_tab_stack, $2, TYPE_INT , NULL , line_num ,symbol_id, false, false, false);
            // Write the assymbly code
            printf("PUSH_MEM %d\n", symbol_id);

            // Increment the for_label_counter which is global
            for_label_counter++;

            // Create a new symbol for the for statement and push it to the symbol table
            add_symbol(sym_tab_stack, "FOR", TYPE_JUMP , NULL , line_num ,for_label_counter, false, false, false);

            // Write the assembly code
            printf("BEGIN_FOR_%d:\n", for_label_counter);
        }

    }
    TOKEN_COMMA for_var TOKEN_COMMA
    {
        // Get the symbol for the counter variable
        symbol* sym = get_symbol(sym_tab_stack, $2, false, false);
        if( sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", $2, line_num);
            exit(1);
        }
        else{
            // Write the assembly code
            printf("POP_MEM %d\n", sym->symbol_id);
        }

        printf("LESS_THAN_OR_EQUAL\n");
        printf("JMP_FALSE END_FOR_%d\n", for_label_counter);

    }
     
    for_var TOKEN_RPAREN 
    {
        // Will create a symbol with the name step_size_for_($for_label_counter) and type Int to store the terminal value
        // No need to check if the symbol is already defined in the symbol table
        char * var_name = malloc(100);
        sprintf(var_name, "step_size_for_%d", for_label_counter);

        // Create the symbol and push it to the symbol table
        symbol_id++;
        add_symbol(sym_tab_stack, var_name, TYPE_INT , NULL , line_num ,symbol_id, false, false, false);

        // Write the assembly code
        printf("PUSH_MEM %d\n", symbol_id);

    }
    block   
    {
 
        // Search for the last symbol with name FOR in the symbol table
        // Search from the top of the stack
        symbol* for_symbol = get_symbol(sym_tab_stack, "FOR", true, false);

        // If the symbol is not found, error out
        if(for_symbol == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "FOR", line_num);
            exit(1);
        }

        // Get the old for label counter and create a new variable to search for the step size
        int old_for_label_counter = for_symbol->symbol_id;
        char * var_name = malloc(100);
        sprintf(var_name, "step_size_for_%d", old_for_label_counter);

        // Get the symbol for the step size
        symbol* step_size_sym = get_symbol(sym_tab_stack, var_name, false, false);
        if( step_size_sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", var_name, line_num);
            exit(1);
        }

        // Want to get the symbol for the counter variable
        // Get the symbol for the counter variable
        symbol* counter_sym = get_symbol(sym_tab_stack, $2, false, false);
        if( counter_sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", $2, line_num);
            exit(1);
        }

        // Write the assembly code
        printf("POP_MEM %d\n", step_size_sym->symbol_id);
        printf("POP_MEM %d\n", counter_sym->symbol_id);
        printf("ADD\n");
        printf("PUSH_MEM %d\n", counter_sym->symbol_id);

        // Write the assembly code
        printf("JMP BEGIN_FOR_%d\n", for_symbol->symbol_id);


        // If the symbol is found, print the label for the end of the for block
        printf("END_FOR_%d:\n", for_symbol->symbol_id);
    }
    ;

for_var:
        IDENTIFIER {
            // Check if the symbol is defined in the symbol table, if not error out
            symbol* sym = get_symbol(sym_tab_stack, $1, false, false);
            if( sym == NULL){
                printf("ERROR: Symbol %s not defined on line %d\n", $1, line_num);
                exit(1);
            }
            else{
                // Write the assembly code
                printf("POP_MEM %d\n", sym->symbol_id);
            }
        }
    |   INTEGER { 
            // Write the assembly code
            printf("PUSH %d\n", $1);
        }
    ;

while_loop_expr:
    TOKEN_WHILE{
        // How to hanle labels of the while statement:
        // increment the while_label_counter which is global
        // Store it in the symbol_id of the symbol entry in the symbol table
        // End_while will get the latest entry in the symbol table with type WHILE 
        // If the expression is flase, Jump to the end_while label
        while_label_counter++;
        printf("BEGIN_WHILE_%d:\n", while_label_counter);

        // Create a new symbol for the while statement and push it to the symbol table
        add_symbol(sym_tab_stack, "WHILE", TYPE_JUMP , NULL , line_num ,while_label_counter, false, false, false);
    }
    expr{
        // Search for the last symbol with name WHILE in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "WHILE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "WHILE", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JMP_FALSE END_WHILE_%d\n", sym->symbol_id);
        }
    }
    block{
        // Search for the last symbol with name WHILE in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "WHILE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "WHILE", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JUMP BEGIN_WHILE_%d\n", sym->symbol_id);
            printf("END_WHILE_%d:\n", sym->symbol_id);
        }
    }
    ;

until_loop_expr:
    TOKEN_UNTIL{
        // How to hanle labels of the while statement:
        // increment the while_label_counter which is global
        // Store it in the symbol_id of the symbol entry in the symbol table
        // End_while will get the latest entry in the symbol table with type WHILE 
        // If the expression is flase, Jump to the end_while label
        while_label_counter++;
        printf("BEGIN_WHILE_%d:\n", while_label_counter);

        // Create a new symbol for the while statement and push it to the symbol table
        add_symbol(sym_tab_stack, "WHILE", TYPE_JUMP , NULL , line_num ,while_label_counter, false, false, false);
    } 
    expr{
        // Search for the last symbol with name WHILE in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "WHILE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "WHILE", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JMP_TRUE END_WHILE_%d\n", sym->symbol_id);
        }
    } 
    block{
        // Search for the last symbol with name WHILE in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "WHILE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "WHILE", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JUMP BEGIN_WHILE_%d\n", sym->symbol_id);
            printf("END_WHILE_%d:\n", sym->symbol_id);
        }
    }
    ;

do_block_expr:
    TOKEN_DO block        
    {  }
    ;

switch_expr:
    TOKEN_SWITCH{
        switch_label_counter++;
        
        printf("SWITCH_%d:\n", switch_label_counter);

        // Create a new symbol for the switch statement and push it to the symbol table
        add_symbol(sym_tab_stack, "SWITCH", TYPE_JUMP , NULL , line_num ,switch_label_counter, false, false, false);

    } 
    expr {
        // Printf DUP
        printf("DUP\n");

    }
    TOKEN_LBRACE case_expr_list TOKEN_RBRACE  
    {
        // Search for the last symbol with name SWITCH in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "SWITCH", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "SWITCH", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("END_SWITCH_%d:\n", sym->symbol_id);
        }
    }
    ;

case_expr_list:
    %empty                          {  }
|   case_expr_list case_expr        
    {  }
    ;

case_expr:
    TOKEN_ELSE TOKEN_COLON
    {
        // Search for the last symbol with name SWITCH in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "SWITCH", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "SWITCH", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("ELSE_SWITCH_%d:\n", sym->symbol_id);
        }

    }
    block    
    { 
        // Search for the last symbol with name SWITCH in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "SWITCH", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "SWITCH", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JMP END_SWITCH_%d\n", sym->symbol_id);
        }
    }
|   expr TOKEN_COLON 
    {
        // Print the assembly code for the comparison
        printf("EQ\n");

        // Search for the last symbol with name SWITCH in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "SWITCH", true, false);

        // We need a unique label for each case
        case_label_counter++;

        // store the label for the case statement in a variable
        char* case_label = (char*)malloc(sizeof(char)*20);
        sprintf(case_label, "CASE_%d_%d", sym->symbol_id, case_label_counter);

        // Create a new symbol for the case statement and push it to the symbol table
        add_symbol(sym_tab_stack, "CASE", TYPE_JUMP , NULL , line_num ,case_label_counter, false, false, false);


        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "SWITCH", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JMP_FALSE END_CASE_%d_%d\n", sym->symbol_id, case_label_counter);
        }
    }
    block
    {
        // After evaluating the block, jump to the end of the switch statement
        // Search for the last symbol with name SWITCH in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "SWITCH", true, false);

        // Search for the last symbol with name CASE in the symbol table to get the case label
        // Search from the top of the stack
        symbol* case_sym = get_symbol(sym_tab_stack, "CASE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "SWITCH", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JMP END_SWITCH_%d\n", sym->symbol_id);
            printf("END_CASE_%d_%d:\n", sym->symbol_id, case_sym->symbol_id);
            printf("DUP\n");
        }
    }
    ;

block:  
    TOKEN_LBRACE {
        // Create a new symbol table for the if block and push it to the stack
        symTable* block_sym_tab = create_sym_table();
        push_sym_tab(sym_tab_stack, block_sym_tab);

    } 
    block_expression_list
    TOKEN_RBRACE  { 
        // After evaluating the block, pop the symbol table on top of the stack
        // First pop the symbol table on top of the stack
        pop_sym_tab(sym_tab_stack);

     }
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
    TOKEN_FUN IDENTIFIER TOKEN_LPAREN 
    {
        current_identifier = $2;
        printf("FUN %s:\n", $2);
    }
    param_list TOKEN_RPAREN IDENTIFIER 
    { 

        //Before continuing, I want to reverse the symbol_id for each symbol of the argument list
        // Parameters are already stored in the symbol table before the symbol of the function
        symTable* sym_tab = sym_tab_stack->sym_tabs[sym_tab_stack->num_sym_tabs-1];

        // Create an array of integers to store the symbol ids of the parameters
        int* param_ids = (int*)malloc(sizeof(int) * cvector_size($5));

        // Iterate through the symbol table and store all the parameters in an array of symbols
        for(int i = 0; i < cvector_size($5); i++){
            param_ids[i] = sym_tab->symbols[sym_tab->num_symbols-1-i].symbol_id;
        }

        // Iterate again to reverse the symbol ids
        int j = cvector_size($5)-1;
        for(int i = 0; i < cvector_size($5); i++){
            sym_tab->symbols[sym_tab->num_symbols-1-i].symbol_id = param_ids[j];
            j--;
        }

        // Create a new symbol for the function and push it to the symbol table
        symbol_id++;
        add_symbol_with_args(sym_tab_stack, current_identifier, TYPE_FUNC, NULL, line_num, symbol_id, false, false, true, $7, $5 );

    }
    fun_block
    {
        // After evaluating the function, pop the symbol table on top of the stack
        // First pop the symbol table on top of the stack
        printf("RET\n");

    }
    ;

param_list:
    %empty                              { $$ = NULL; }
    |   param_list TOKEN_COMMA param     { $$ = $1; cvector_push_back($$, $3); }
    |   param_list TOKEN_COMMA           { $$ = $1; }
    |   param                           { $$ = NULL; cvector_push_back($$, $1); }
;


param:
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER    { 

        // First check if the name is already taken in the parameter list
        symbol* sym = get_symbol(sym_tab_stack, $2, true, false);

        // If the symbol is not found, add it to the symbol table or is found but it is not a function parameter (set the flag to true while creation)
        if(sym == NULL || sym->is_func == false){
            // Check if the type is valid
            // The $4 is the type of the variable but it is stored as a string in the token
            // We match the string to the type and get the type as an integer
            int type = get_type($4);
            symbol_id++;
            add_symbol(sym_tab_stack, $2, type, NULL, line_num, symbol_id ,($1 == 0), false, true);

            // Write an assembly command to sotre the value of the variable
            printf("PUSH_MEM %d\n", symbol_id);
        }
        else{
            printf("ERROR: Symbol %s already defined on line %d\n", $2, sym->line_num);
            exit(1);
        }

        $$ = $4;
    }
    ;

fun_block:  
    TOKEN_LBRACE {

        // Before creating a new symbol table for the function block, we need to store all the parameters in an array of symbols
        // Parameters are already stored in the symbol table before the symbol of the function
        // Get the symbol of the function to get the number of parameters (the last symbol directly in the last symbol table)
        symTable* sym_tab = sym_tab_stack->sym_tabs[sym_tab_stack->num_sym_tabs-1];
        symbol fun_sym = sym_tab->symbols[sym_tab->num_symbols-1];

        // Delete the symbol of the function from the symbol table
        sym_tab->num_symbols--;

        // Create an array of symbols to store the parameters
        symbol* params = (symbol*)malloc(sizeof(symbol) * fun_sym.num_parameters);

        // Iterate through the symbol table and store all the parameters in an array of symbols
        for(int i = 0; i < fun_sym.num_parameters; i++){
            params[i] = sym_tab->symbols[sym_tab->num_symbols-1-i];
            // Delete the parameters from the symbol table
            sym_tab->num_symbols--;
        }

        // Insert the symbol of the function back to the symbol table
        sym_tab->symbols[sym_tab->num_symbols] = fun_sym;
        sym_tab->num_symbols++;

        // Create a new symbol table for the if block and push it to the stack
        symTable* block_sym_tab = create_sym_table();

        // Push the parameters to the new symbol table
        for(int i = 0; i < fun_sym.num_parameters; i++){
            block_sym_tab->symbols[block_sym_tab->num_symbols] = params[i];
            block_sym_tab->num_symbols++;
        }

        push_sym_tab(sym_tab_stack, block_sym_tab);

    } 
    block_expression_list
    TOKEN_RBRACE  { 
        // After evaluating the block, pop the symbol table on top of the stack
        // First pop the symbol table on top of the stack
        pop_sym_tab(sym_tab_stack);

     }
    ;


funcall:
    IDENTIFIER TOKEN_LPAREN arg_list TOKEN_RPAREN   { 
        //TODO: Check type checking for the arguments
        // Get the symbol of the function
        symbol* sym = get_symbol(sym_tab_stack, $1, true, false);

        // Check if the symbol is found and it is a function
        if(sym != NULL && sym->is_func == true){
            // Check if the number of arguments is the same as the number of parameters
            if(sym->num_parameters == cvector_size($3)){
                // Iterate through the arguments and check if the types are the same
                for(int i = 0; i < cvector_size($3); i++){
                    // Get the type of the argument
                    int arg_type = get_type($3[i]);
                    // Get the type of the parameter
                    int param_type = sym->parameter_list_types[i];

                    // Check if the types are the same
                    if(arg_type != param_type){
                        printf("ERROR: Type mismatch in function call on line %d\n", line_num);
                        exit(1);
                    }
                }

                // Write an assembly command to call the function
                printf("CALL %d\n", sym->symbol_id);
            }
            else{
                printf("ERROR: Number of arguments in function call on line %d\n", line_num);
                exit(1);
            }
        }
        else{
            printf("ERROR: Function %s not found on line %d\n", $1, line_num);
            exit(1);
        }
    }
    ;

arg_list:
    %empty              {$$=NULL;}
|   expr                 {$$=NULL; cvector_push_back($$, $1);}
|   arg_list TOKEN_COMMA expr   {cvector_push_back($$, $3);}
    ;
    
type_decl:
    TOKEN_TYPE IDENTIFIER TOKEN_EQUAL constructor_list TOKEN_SEMICOLON   { 

        // Check if the type is already defined in the symbol table
        symbol* sym = get_symbol(sym_tab_stack, $2, false, false);

        // If the symbol is not found, add it to the symbol table
        if(sym == NULL){
            // Check if the type is valid
            symbol_id++;    // Actually no need
            add_symbol_enum(sym_tab_stack, $2, type, NULL, line_num, symbol_id ,false, true, false, $4);
        }
type        else{
            printf("ERROR: Type %s already defined on line %d\n", $2, sym->line_num);
            exit(1);
        }

    }
    ;

constructor_list:
    IDENTIFIER                                   { $$=NULL; cvector_push_back($$, $1); }
|   constructor_list TOKEN_PIPE IDENTIFIER       { cvector_push_back($$, $3); }
    ;
    
%%



int main (void) {
	/* init symbol table */

    // Assign the global sym_tab_stack
    sym_tab_stack = create_sym_tab_stack();

    // Create the global symbol table empty and push it to the stack
    symTable *global_sym_tab = create_sym_table();

    // Push the global symbol table to the stack
    push_sym_tab(sym_tab_stack, global_sym_tab);

	return yyparse ( );
}

// Define a function to create a new symbol table
symTable* create_sym_table(){
    symTable *new_sym_tab = (symTable*)malloc(sizeof(symTable));
    new_sym_tab->num_symbols = 0;
    new_sym_tab->max_symbols = SYM_MAX;
    new_sym_tab->index = 0;
    new_sym_tab->symbols = (symbol*)malloc(sizeof(symbol)*SYM_MAX);
    return new_sym_tab;
}

// Define a function to create a new symbol table stack
symTableStack* create_sym_tab_stack(){
    symTableStack *new_sym_tab_stack = (symTableStack*)malloc(sizeof(symTableStack));
    new_sym_tab_stack->num_sym_tabs = 0;
    new_sym_tab_stack->max_sym_tabs = SYM_TAB_MAX;
    new_sym_tab_stack->sym_tabs = (symTable**)malloc(sizeof(symTable *)*SYM_TAB_MAX);
    return new_sym_tab_stack;
}

// Define a function to push a symbol table to the stack
void push_sym_tab(symTableStack *sym_tab_stack, symTable *sym_tab){
    if(sym_tab_stack->num_sym_tabs < sym_tab_stack->max_sym_tabs){
        sym_tab->index = sym_tab_stack->num_sym_tabs;   // Set the index of the symbol table
        sym_tab_stack->sym_tabs[sym_tab_stack->num_sym_tabs] = sym_tab; // Push the symbol table to the stack
        sym_tab_stack->num_sym_tabs++;  // Increment the number of symbol tables in the stack
    }
    else{
        printf("Error: Symbol table stack overflow\n");
    }
}

// Define a function to pop a symbol table from the stack
symTable* pop_sym_tab(symTableStack *sym_tab_stack){
    if(sym_tab_stack->num_sym_tabs > 0){
        symTable *sym_tab = sym_tab_stack->sym_tabs[sym_tab_stack->num_sym_tabs-1]; // Pop the symbol table from the stack
        sym_tab_stack->num_sym_tabs--;  // Decrement the number of symbol tables in the stack
        return sym_tab;
    }
    else{
        printf("Error: Symbol table stack underflow\n");
        return NULL;
    }
}

// Define a function to add a symbol to the symbol table
void add_symbol(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id ,bool is_const, bool is_enum, bool is_func){

    // Check if the symbol table stack is empty
    if(stack->num_sym_tabs == 0){
        // If it is, Error out
        printf("Error: Symbol table stack is empty\n");
        return;
    }

    // Get the top symbol table from the stack
    symTable* sym_tab = stack->sym_tabs[stack->num_sym_tabs - 1];

    // Check if the symbol is already in the symbol table and it is not a jump (we store names of jumps (which is the keywords) in the symbol table)
    for(int i = 0; i < sym_tab->num_symbols; i++){
        // TODO: Maybe we can delete this check
        if(0 && strcmp(sym_tab->symbols[i].name, name) == 0 && type != TYPE_JUMP ){
            // If it is, Error out
            printf("Error: Symbol %s already exists in symbol table\n", name);
            return;
        }
    }

    // copy the value to avoid dangling pointers
    char* value_copy = copy_value(value);

    // Create instance of symbol
    symbol sym = {
        .name = name,
        .type = type,
        .value = value_copy,
        .line_num = line_num,
        .symbol_id = symbol_id,
        .is_const = is_const,
        .is_enum = is_enum,
        .is_func = is_func,
    };

    // Add the symbol to the symbol table
    sym_tab->symbols[sym_tab->num_symbols] = sym;
    sym_tab->num_symbols++;

}

// Define a function to add a symbol to the symbol table with a list of arguments (check if the symbol is a function)
void add_symbol_with_args(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id, bool is_const, bool is_enum, bool is_func, char * return_identifier, vtype(char*) parameter_list_types){
    
    int return_type = get_type(return_identifier);
    // Check if the symbol table stack is empty
    if(stack->num_sym_tabs == 0){
        // If it is, Error out
        printf("Error: Symbol table stack is empty\n");
        return;
    }

    // Get the top symbol table from the stack
    symTable* sym_tab = stack->sym_tabs[stack->num_sym_tabs - 1];

    // Check if the symbol is already in the symbol table and it is not a jump (we store names of jumps (which is the keywords) in the symbol table)
    for(int i = 0; i < sym_tab->num_symbols; i++){
        if(strcmp(sym_tab->symbols[i].name, name) == 0 && type != TYPE_JUMP ){
            // If it is, Error out
            printf("Error: Symbol %s already exists in symbol table\n", name);
            return;
        }
    }

    // copy the value to avoid dangling pointers
    char* value_copy = copy_value(value);

    // Check that all types are valid (TYPE_INT, TYPE_REAL, TYPE_STRING, TYPE_BOOL)
    // First get the number of parameters from cvector
    int num_parameters = cvector_size(parameter_list_types);
    
    // Then define an array of int to store the types of the parameters and get the types from the cvector while checking that they are valid
    int * parameter_list_types_array = (int *)malloc(sizeof(int)*num_parameters);
    for(int i = 0; i < num_parameters; i++){
        parameter_list_types_array[i] = get_type(parameter_list_types[i]);
        if(parameter_list_types_array[i] != TYPE_INT && parameter_list_types_array[i] != TYPE_REAL && parameter_list_types_array[i] != TYPE_STRING && parameter_list_types_array[i] != TYPE_BOOL){
            printf("Error: Invalid parameter type\n");
            return;
        }
    }

    // Check that the return type is valid (TYPE_INT, TYPE_REAL, TYPE_STRING, TYPE_BOOL, TYPE_VOID)
    if(return_type != TYPE_INT && return_type != TYPE_REAL && return_type != TYPE_STRING && return_type != TYPE_BOOL && return_type != TYPE_VOID){
        printf("Error: Invalid return type\n");
        return;
    }

    // Create instance of symbol
    symbol sym = {
        .name = name,
        .type = type,
        .value = value_copy,
        .line_num = line_num,
        .symbol_id = symbol_id,
        .is_const = is_const,
        .is_enum = is_enum,
        .is_func = is_func,
        .return_type = return_type,
        .num_parameters = num_parameters,
        .parameter_list_types = parameter_list_types_array,
    };

    // Add the symbol to the symbol table
    sym_tab->symbols[sym_tab->num_symbols] = sym;
    sym_tab->num_symbols++;
    
}

// Define a function to add a symbol to the symbol table
void add_symbol_enum(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id, bool is_const, bool is_enum, bool is_func, vtype(char*) enum_values){
    // Check if the symbol table stack is empty
    if(stack->num_sym_tabs == 0){
        // If it is, Error out
        printf("Error: Symbol table stack is empty\n");
        return;
    }

    // Get the top symbol table from the stack
    symTable* sym_tab = stack->sym_tabs[stack->num_sym_tabs - 1];

    // Check if the symbol is already in the symbol table and it is not a jump (we store names of jumps (which is the keywords) in the symbol table)
    for(int i = 0; i < sym_tab->num_symbols; i++){
        // TODO: Maybe we can delete this check
        if(0 && strcmp(sym_tab->symbols[i].name, name) == 0 && type != TYPE_JUMP ){
            // If it is, Error out
            printf("Error: Symbol %s already exists in symbol table\n", name);
            return;
        }
    }

    // copy the value to avoid dangling pointers
    char* value_copy = copy_value(value);

    // Create instance of symbol
    symbol sym = {
        .name = name,
        .type = type,
        .value = value_copy,
        .line_num = line_num,
        .symbol_id = symbol_id,
        .is_const = is_const,
        .is_enum = is_enum,
        .is_func = is_func,
        .enum_value_names = enum_values,
    };

    // Add the symbol to the symbol table
    sym_tab->symbols[sym_tab->num_symbols] = sym;
    sym_tab->num_symbols++;

}


// Define a function to get a symbol from the symbol table
symbol* get_symbol(symTableStack* stack, char* name, bool reverse_search, bool search_parent){


    // Check if the symbol table stack is empty
    if(stack->num_sym_tabs == 0){
        // If it is, Error out
        printf("Error: Symbol table stack is empty\n");
        return NULL;
    }
    // Loop over the stack until the symbol is found or the stack is empty
    for(int i = stack->num_sym_tabs - 1; i >= 0; i--){

        // Get the symbol table from the stack
        symTable* sym_tab = stack->sym_tabs[i];

        if (reverse_search){
            // Check if the symbol is in the symbol table
            for(int j = sym_tab->num_symbols - 1; j >= 0; j--){
                if(strcmp(sym_tab->symbols[j].name, name) == 0){
                    // If it is, return the symbol
                    return &sym_tab->symbols[j];
                }
            }
        }
        else {
            // Check if the symbol is in the symbol table
            for(int j = 0; j < sym_tab->num_symbols; j++){
                if(strcmp(sym_tab->symbols[j].name, name) == 0){
                    // If it is, return the symbol
                    return &sym_tab->symbols[j];
                }
            }
        }
        if (!search_parent){
            break;
        }
    }


    // If it is not, Error out
    return NULL;

}

// Define a function to copy value of a symbol to another symbol
char* copy_value(char* value)
{
    // Check if the value is null
    if(value == NULL){
        // If it is, return null
        return NULL;
    }

    // Get the length of the value
    int len = strlen(value);

    // Allocate memory for the copy
    char* copy = malloc(len + 1);

    // Copy the value
    strcpy(copy, value);

    // Return the copy
    return copy;
}

// Define a function to check for assignment compatibility with a symbol
// It takes the assignment type as enum and the symbol to check
bool check_assignment(symbol* sym, char* type_name)
{
    int type = get_type(type_name);
    if (type == -1) {
        // Check if the type_name is actually a number
        return true;    //TODO: Handle type checking for numbers
    }
    // Check if the symbol is null
    if(sym == NULL){
        // If it is, return false
        return false;
    }

    // Check if the symbol is a constant
    if(sym->is_const){
        // If it is, error out
        printf("Error: Cannot assign to constant\n");
        exit(1);
    }

    // Check if the symbol is an enum
    if(sym->is_enum){
        // If it is, error out
        printf("Error: Cannot assign to enum\n");
        exit(1);
    }

    // Check if the symbol is a function
    if(sym->is_func){
        // If it is, error out
        printf("Error: Cannot assign to function\n");
        exit(1);
    }

    // Check if the symbol is a void
    if(sym->type == TYPE_VOID){
        // If it is, error out
        printf("Error: Cannot assign to void\n");
        exit(1);
    }

    // Check if the symbol is an integer
    if(sym->type == TYPE_INT){
        // If it is, check if the assignment type is an integer or real
        if(type == TYPE_INT || type == TYPE_REAL){
            // If it is, return true
            return true;
        }
    }

    // Check if the symbol is a real
    if(sym->type == TYPE_REAL){
        // If it is, check if the assignment type is an integer or real
        if(type == TYPE_INT || type == TYPE_REAL){
            // If it is, return true
            return true;
        }
    }

    // Check if the symbol is a string
    if(sym->type == TYPE_STRING){
        // If it is, check if the assignment type is a string
        if(type == TYPE_STRING){
            // If it is, return true
            return true;
        }
    }

    // Check if the symbol is a boolean
    if(sym->type == TYPE_BOOL){
        // If it is, check if the assignment type is a boolean
        if(type == TYPE_BOOL){
            // If it is, return true
            return true;
        }
    }

    // If it is not, return false
    return false;
}



void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

