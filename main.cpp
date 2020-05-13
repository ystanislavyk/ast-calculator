#include "InputHandler.hpp"
#include "Lexer.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  ASTCalculator::InputHandler inputHandler;
  const auto inputBuffer = inputHandler.ProcessInput(argc, argv);

  ASTCalculator::Lexer lexer;
  lexer.ScanInput(inputBuffer);

  const auto expression_result = lexer.ParseInput();

  std::cout << "Result: " << expression_result << std::endl;

  return 0;
}
