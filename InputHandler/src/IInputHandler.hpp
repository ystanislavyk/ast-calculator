#pragma once

#include <string>

namespace ASTCalculator {

  class IInputHandler {
    public:
      virtual ~IInputHandler() = default;
      virtual std::string ProcessInput(const int argc, const char * const argv[]) const = 0;
  };

} // namespace ASTCalculator
