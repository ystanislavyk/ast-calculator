%{
#include <stdio.h>
#include <stdlib.h>
#include "ASTTree.h"
%}

%union {
  struct ASTNode* node;
  double value;
}

%token <value> NUMBER
%token EOL

%type <node> exp factor term

%%

calclist: /* nothing */
        | calclist exp EOL { /*printf("Result: %4.4g\n", Evaluate($2)); FreeASTTree($2);*/ SetASTEvaluationResult(Evaluate($2)); FreeASTTree($2); }
        | calclist EOL
;

exp: factor
   | exp '+' factor { $$ = NewASTNode('+', $1,$3); }
   | exp '-' factor { $$ = NewASTNode('-', $1,$3);}
;

factor: term
      | factor '*' term { $$ = NewASTNode('*', $1,$3); }
      | factor '/' term { $$ = NewASTNode('/', $1,$3); }
;

term: NUMBER   { $$ = NewNumericNode($1); }
    | '(' exp ')' { $$ = $2; }
    | '-' term    { $$ = NewASTNode('M', $2, NULL); }
;
%%
