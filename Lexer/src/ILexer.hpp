#pragma once

#include <string>

namespace ASTCalculator {

  class ILexer {
    public:
      virtual ~ILexer() = default;
      virtual void ScanInput(const std::string& string) const = 0;
      virtual double ParseInput() const = 0;
  };

} // namespace ASTCalculator