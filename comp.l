/*%option outfile="comp.lex.c" header-file="comp.lex.h"*/
%option warn debug perf-report
%option reentrant bison-locations bison-bridge
%option yylineno
%option noyywrap
%option interactive
%option nodefault

%{
  #include <stdlib.h>                                                           
  #include <string.h>
  #include "comp.tab.h"                                                   
  #include "./utils.h"

  #define YY_USER_ACTION                                               \
      yylloc->first_line = yylloc->last_line;                          \
      yylloc->first_column = yylloc->last_column;                      \
      if (yylloc->last_line == yylineno)                               \
        yylloc->last_column += yyleng;                                 \
      else {                                                           \
        yylloc->last_line = yylineno;                                  \
        yylloc->last_column = yytext + yyleng - strrchr(yytext, '\n'); \
      }

  char* copy_str(char const * cstr){
    char*ptr=(char*) malloc(strlen(cstr) + 1); // +1 for the null terminator
    
    strcpy(ptr, cstr);
    return ptr;
  }
  // #define copy_str(cstr) (cstr)
%}


newline     ("\n")
white_space ([[:space:]])
id          ([a-zA-Z_]+[a-zA-Z0-9?!]*)
integer     ([0-9]+)
real        ({integer}"."{integer})
string      (\"[^\"\n]*\")
left_brace  ("{")
right_brace ("}")

/* -:-keywords-:- */
/* module */
/* import */
/* fun */
/* const */
/* var */
/* type */
/* do */
/* if */
/* else */
/* for */
/* while */
/* until */
/* switch */

/* -:- logical operators -:- */
/* not */
/* and */
/* or */

/* -:- arithmetic operators -:- */
/* +,-,*,/,**,% */

/* -:- comparison operators -:- */
/* <,>,<=,>=,==,!= */

/* -:- others  -:- */
/* = <assignment statement> */
/* : <type of declaration> */
/* :: <module qualification> */
/* , <comma> */
/* ; <semicolon> */
/* &,|,(,),{,}*/
%s SPECIAL
%%

"module"    {   BEGIN(SPECIAL); return TOKEN_MODULE;   }
"import"    {   BEGIN(SPECIAL); return TOKEN_IMPORT;   }
"fun"       {   return TOKEN_FUN;      }
"val"       {   return TOKEN_VAL;      }
"var"       {   return TOKEN_VAR;      }
"type"      {   return TOKEN_TYPE;     }
"do"        {   return TOKEN_DO;       }
"if"        {   return TOKEN_IF;       }
"else"      {   return TOKEN_ELSE;     }
"for"       {   return TOKEN_FOR;      }
"while"     {   return TOKEN_WHILE;    }
"until"     {   return TOKEN_UNTIL;    }
"switch"    {   return TOKEN_SWITCH;   }
"not"       {   return TOKEN_NOT;      }
"and"       {   return TOKEN_AND;      }
"or"        {   return TOKEN_OR;       }
"true"      {   yylval->BOOL = copy_str(yytext); return BOOL; }
"false"     {   yylval->BOOL = copy_str(yytext); return BOOL; }

"+"         {   return TOKEN_PLUS;     }
"-"         {   return TOKEN_MINUS;    }
"*"         {   return TOKEN_MULT;     }
"/"         {   return TOKEN_DIV;      }
"**"        {   return TOKEN_EXP;      }
"%"         {   return TOKEN_MOD;      }

"<"         {   return TOKEN_LT;       }
">"         {   return TOKEN_GT;       }
"<="        {   return TOKEN_LEQ;      }
">="        {   return TOKEN_GEQ;      }
"=="        {   return TOKEN_EQ;       }
"!="        {   return TOKEN_NEQ;      }

"="         {   return TOKEN_EQUAL;    }
":"         {   return TOKEN_COLON;    }
"::"        {   return TOKEN_QUALIFY;  }
","         {   return TOKEN_COMMA;    }
"|"         {   return TOKEN_PIPE;     }
"&"         {   return TOKEN_AMP;      }
"("         {   return TOKEN_LPAREN;   }
")"         {   return TOKEN_RPAREN;   }

{left_brace}    {   return TOKEN_LBRACE;   }
{right_brace}   {   return TOKEN_RBRACE;   }

";"             {   return TOKEN_SEMICOLON;}
{id}            { 
                    yylval->IDENTIFIER = copy_str(yytext); 
                    return IDENTIFIER;
                }
{integer}       { 
                    yylval->INTEGER = copy_str(yytext);
                    return INTEGER;
                }
{real}          {
                    yylval->REAL = copy_str(yytext);
                    return REAL;
                }
{string}        { 
                    yylval->STRING = copy_str(yytext);
                    return STRING;
                }

<SPECIAL>{newline}+      { BEGIN(INITIAL); return TOKEN_NEWLINE; }
<INITIAL>{newline}+  /**/
{white_space}+    /*return TOKEN_WS;*/    
<<EOF>>         { return YYEOF;     }
.               { return TOKEN_UNKNOWN; }
%%
