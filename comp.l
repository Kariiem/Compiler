
%{
  #include <stdlib.h>                                                           
  #include <string.h>
  #include "comp.tab.h"                                                   
  #include "utils.h"

  void yyerror (char *s); 
  // called by the parser whenever it needs a token. This is where the lexical analyzer is called. 
  int yylex();
  int line=1;
  #include <stdio.h>
  #include <stdarg.h>
  #define SHOW_LOGS 0

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
"true"      {   yylval.boolean = 1; return BOOL; }
"false"     {   yylval.boolean = 0; return BOOL; }

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
                    yylval.id = yytext; 
                    return IDENTIFIER;
                }
{integer}       { 
                    yylval.string = yytext;
                    return INTEGER;
                }
{real}          {
                    yylval.string = yytext;
                    return REAL;
                }
{string}        { 
                    yylval.string = yytext;
                    return STRING;
                }

<SPECIAL>{newline}+      { BEGIN(INITIAL); return TOKEN_NEWLINE; }
<INITIAL>{newline}+  /**/
{white_space}+    /*return TOKEN_WS;*/    
<<EOF>>         { return 0;     }
.               { return TOKEN_UNKNOWN; }
%%
// C code
// The wrapper function yywrap() 
int yywrap (void) {return 1;}