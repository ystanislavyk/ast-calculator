#pragma once

#include "IInputHandler.hpp"

namespace ASTCalculator {

  class InputHandler: public IInputHandler {
    public:
      std::string ProcessInput(const int argc, const char * const argv[]) const override;
  };

} // namespace ASTCalculator
