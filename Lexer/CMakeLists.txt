project(Lexer)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    src
)

target_sources(${PROJECT_NAME}
  PRIVATE
    gen/lex.yy.c
    gen/lexer.tab.c
    src/ASTTree.c
    src/Lexer.cpp
)

