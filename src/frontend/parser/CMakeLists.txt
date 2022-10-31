cmake_minimum_required(VERSION 3.14)

add_library(parser SQLBaseListener.cpp SQLBaseListener.h SQLBaseVisitor.cpp SQLBaseVisitor.h SQLLexer.cpp SQLLexer.h SQLListener.cpp SQLListener.h SQLParser.cpp SQLParser.h SQLVisitor.cpp SQLVisitor.h)