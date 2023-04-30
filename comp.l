%option outfile="comp.lex.c" header-file="comp.lex.h"
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
  #include "utils.h"

  #define YY_USER_ACTION                                               \
      yylloc->first_line = yylloc->last_line;                          \
      yylloc->first_column = yylloc->last_column;                      \
      if (yylloc->last_line == yylineno)                               \
        yylloc->last_column += yyleng;                                 \
      else {                                                           \
        yylloc->last_line = yylineno;                                  \
        yylloc->last_column = yytext + yyleng - strrchr(yytext, '\n'); \
      }
%}


newline     ("\n")
white_space (" "|"\t"|"\r"|"\v"|"\f")
id          ([a-zA-Z_]+[a-zA-Z0-9?!]*)
integer     ([0-9]+)
real        ({integer}"."{integer})
string      (\"[^\"\n]*\")

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

%%

"module"    {   return TOKEN_MODULE;   }
"import"    {   return TOKEN_IMPORT;   }
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
"true"      {   yylval->BOOL = 1; return BOOL; }
"false"     {   yylval->BOOL = 0; return BOOL; }

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
";"         {   return TOKEN_SEMICOLON;}
"|"         {   return TOKEN_PIPE;     }
"&"         {   return TOKEN_AMP;      }
"("         {   return TOKEN_LPAREN;   }
")"         {   return TOKEN_RPAREN;   }
"{"         {   return TOKEN_LBRACE;   }
"}"         {   return TOKEN_RBRACE;   }


{id}            { 
                    yylval->IDENTIFIER = yytext; 
                    return IDENTIFIER;
                }
{integer}       { 
                    yylval->INTEGER = yytext;
                    return INTEGER;
                }
{real}          {
                    yylval->REAL = yytext;
                    return REAL;
                }
{string}        { 
                    yylval->STRING = yytext;
                    return STRING;
                }

{newline}+      { return TOKEN_NEWLINE; }
{white_space}+  { /*return TOKEN_WS;*/  }  
<<EOF>>         { return TOKEN_EOF;     }
.               { return TOKEN_UNKNOWN; }
%%
