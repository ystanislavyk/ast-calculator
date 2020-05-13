%option noyywrap
%option nodefault
%option yylineno

%{
# include "ASTTree.h"
# include "lexer.tab.h"
%}

numbers     [0-9]+(\.[0-9]+)?

%%
"+" |
"-" |
"*" |
"/" |
"(" |
")"            { return yytext[0]; }
{numbers}      { yylval.value = atof(yytext); return NUMBER; }
\n             { return EOL; }
[ \t]          { /* ignore white space */ }
.	           { yyerror("Unknown character %c\n", *yytext); }
%%
