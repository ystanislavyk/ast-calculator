project(InputHandler)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    src
)

target_sources(${PROJECT_NAME}
  PRIVATE
    src/InputHandler.cpp
)
