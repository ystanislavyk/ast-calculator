#pragma once

#include "ILexer.hpp"

namespace ASTCalculator {
  class Lexer : public ILexer {
    public:
      void ScanInput(const std::string& string) const override;
      double ParseInput() const override;
  };
} // namespace ASTCalculator
