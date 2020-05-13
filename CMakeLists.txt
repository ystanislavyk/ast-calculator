cmake_minimum_required(VERSION 3.12)

project(ast_calc)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(InputHandler)
add_subdirectory(Lexer)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    InputHandler
    Lexer
)
