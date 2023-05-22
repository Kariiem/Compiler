


%{

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
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
    void add_symbol(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id ,bool is_const, bool is_enum, bool is_func)
    {

        // Check if the symbol table stack is empty
        if(stack->num_sym_tabs == 0){
            // If it is, Error out
            printf("Error: Symbol table stack is empty\n");
            return;
        }

        // Get the top symbol table from the stack
        symTable* sym_tab = stack->sym_tabs[stack->num_sym_tabs - 1];

        // Check if the symbol is already in the symbol table
        for(int i = 0; i < sym_tab->num_symbols; i++){
            if(strcmp(sym_tab->symbols[i].name, name) == 0){
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

