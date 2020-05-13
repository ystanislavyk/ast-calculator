#include "InputHandler.hpp"

#include <iostream>

namespace ASTCalculator {

  std::string InputHandler::ProcessInput(const int argc, const char * const argv[]) const {
    if (argc < 1) {
      std::cout << "Please specify the calculation argument" << std::endl;
      return {};
    }

    std::string inputBuffer(argv[1]);
    inputBuffer += "\n";
    return inputBuffer;
  }

} // namespace ASTCalculator
