#pragma once

extern int yylineno;
void yyerror(char *s, ...);

struct ASTNode {
  int node_type;
  struct ASTNode *left;
  struct ASTNode *right;
};

struct NumericNode {
  int node_type; /* type K */
  double number;
};

struct ASTNode* NewASTNode(const int node_type, struct ASTNode *left, struct ASTNode *right);
struct ASTNode* NewNumericNode(const double number);

double Evaluate(struct ASTNode *);

void FreeASTTree(struct ASTNode *);

void SetASTEvaluationResult(const double result);
double GetASTEvaluationResult();
