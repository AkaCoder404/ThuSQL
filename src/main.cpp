#include <iostream>
#include "antlr4-runtime.h"
// #include "backend/BuffManagement/BufPageManager.h"
#include "backend/defs.h"

#include "../third-party/tabulate/table.hpp"
#include "frontend/parser/SQLLexer.h"
#include "frontend/parser/SQLParser.h"
// #include "frontend/parser/SQLBaseListener.h"
// #include "frontend/parser/SQLBaseVisitor.h"

#include "frontend/parser/MySQLListener.h"
#include "frontend/parser/MySQLVisitor.h"



void testtables();

int main(int argc, char* argv[]) {
    printf("Welcome to ThuSQL!\n");
    std::cout << "Input: " << argv[1] << "\n";

    std::ifstream stream(argv[1]);
    // std::string line;
    // stream.open("../tests/1.txt");
    // if (!stream.is_open()) {
    //     printf("File not found\n");
    //     return 0;
    // } else {
    //     printf("File found\n");
    //     // while (std::getline(stream, line)) {
    //     //     std::cout << line << std::endl;
    //     // }
    // }

    std::string str_input = "CREATE DATABASE db;";

    antlr4::ANTLRInputStream input(stream);    // convert input to antlr format
    SQLLexer lexer(&input);                    // give input to lexer
    antlr4::CommonTokenStream tokens(&lexer);  // create tokens
    SQLParser parser(&tokens);                 // create translation that will parse input


    tokens.fill();
    // std::cout << "*****TOKENS*****" << std::endl;
    // for (auto token : tokens.getTokens()) {
    //     std::cout << token->toString() << std::endl;
    // }

    // /* performs walk on given parse tree starting at root */
    // antlr4::tree::ParseTree *tree = parser.program();
    // if (false) {
    //     MySQLListener listener;
    //     antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    // }

    MySQLVisitor visitor;
    auto res = visitor.visitProgram(parser.program());

    


    // debug
    // d_main();
    
}

