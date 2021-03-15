cmake_minimum_required(VERSION 3.17)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp MatcherAutomaton.h Undefined.h Token.h StringClass.h Lexer.h Comments.h BadString.h BadComment.h Automaton.h Identification.h Identification.h FileEnd.h)