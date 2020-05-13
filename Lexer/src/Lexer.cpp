#include "Lexer.hpp"

#include <iostream>

#include "ASTTree.h"

namespace ASTCalculator {

  extern "C" {
    typedef struct yy_buffer_state *YY_BUFFER_STATE;
    YY_BUFFER_STATE yy_scan_string(const char *str);
    void yy_switch_to_buffer(YY_BUFFER_STATE new_buffer);
    int yyparse();
    double GetASTEvaluationResult();
  }

  void Lexer::ScanInput(const std::string& string) const {
    auto buffer = yy_scan_string(string.data());
    yy_switch_to_buffer(buffer);
  }

  double Lexer::ParseInput() const {
    yyparse();
    return GetASTEvaluationResult();
  }

} // namespace ASTCalculator
