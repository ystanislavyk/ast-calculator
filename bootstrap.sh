#!/usr/bin/env bash

mkdir Lexer/gen && cd Lexer/gen && flex ../lexer.l && bison -d ../lexer.y
