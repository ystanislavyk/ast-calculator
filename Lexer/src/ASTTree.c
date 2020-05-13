#include "ASTTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void yyerror(char *s, ...) {
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%number: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

struct ASTNode* NewASTNode(const int node_type, struct ASTNode *left, struct ASTNode *right) {
  struct ASTNode* node = malloc(sizeof(struct ASTNode));

  if(!node) {
    yyerror("Out of space");
    exit(0);
  }

  node->node_type = node_type;
  node->left = left;
  node->right = right;

  return node;
}

struct ASTNode* NewNumericNode(const double number) {
  struct NumericNode* node = malloc(sizeof(struct NumericNode));

  if(!node) {
    yyerror("Out of space");
    exit(0);
  }

  node->node_type = 'K';
  node->number = number;

  return (struct ASTNode *)node;
}

double Evaluate(struct ASTNode* tree) {
  double result = 0;

  switch(tree->node_type) {
    case 'K': result = ((struct NumericNode *)tree)->number; break;
    case '+': result = (Evaluate(tree->left) + Evaluate(tree->right)); break;
    case '-': result = (Evaluate(tree->left) - Evaluate(tree->right)); break;
    case '*': result = (Evaluate(tree->left) * Evaluate(tree->right)); break;
    case '/': result = (Evaluate(tree->left) / Evaluate(tree->right)); break;
    case 'M': result = -Evaluate(tree->left); break;
    default: printf("Error: Bad node %c\n", tree->node_type);
  }

  return result;
}

void FreeASTTree(struct ASTNode* tree) {
  switch(tree->node_type) {
    /* Two Subtrees */
    case '+':
    case '-':
    case '*':
    case '/':
      FreeASTTree(tree->right);

    /* One Subtree */
    case 'M':
      FreeASTTree(tree->left);

    /* No Subtree */
    case 'K':
      free(tree);
      break;

    default: printf("Error: free bad node %c\n", tree->node_type);
  }
}

double g_ast_evaluation_result = 0;

void SetASTEvaluationResult(const double result) {
  g_ast_evaluation_result = result;
}

double GetASTEvaluationResult() {
  return g_ast_evaluation_result;
}
