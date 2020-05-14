FROM gcc:8.4

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get --no-install-recommends -y install \
    build-essential cmake autoconf automake flex bison && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir /project

COPY InputHandler /project/InputHandler
COPY Lexer /project/Lexer
COPY bootstrap.sh CMakeLists.txt main.cpp Makefile /project/

WORKDIR /project

RUN make && mv ./build/ast_calc ./
