#include <iostream>
#include <strstream>
#include "antlr4-runtime.h"
// #include "backend/BuffManagement/BufPageManager.h"
#include "backend/defs.h"

#include "../third-party/tabulate/table.hpp"
#include "frontend/parser/SQLLexer.h"
#include "frontend/parser/SQLParser.h"
#include "frontend/parser/MySQLListener.h"
#include "frontend/parser/MySQLVisitor.h"
#include "frontend/parser/MySQLErrorListener.h"

#include <chrono>

class MyParserErrorListener: public antlr4::BaseErrorListener {
  virtual void syntaxError(
      antlr4::Recognizer *recognizer,
      antlr4::Token *offendingSymbol,
      size_t line,
      size_t charPositionInLine,
      const std::string &msg,
      std::exception_ptr e) override {
    std::ostrstream s;
    s << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")";
    throw std::invalid_argument(s.str());
  }
};

void inputFromFile(char *fileName) {
    std::cout << "Reading from " << fileName << "\n";
    std::ifstream stream(fileName);
    antlr4::ANTLRInputStream input(stream);    // convert input to antlr format
    SQLLexer lexer(&input);                    // give input to lexer
    antlr4::CommonTokenStream tokens(&lexer);  // create tokens
    SQLParser parser(&tokens);                 // create translation that will parse input

    tokens.fill();
    MySQLVisitor visitor;
    auto res = visitor.visitProgram(parser.program());
}

void gui() {
    std::string line;
    MySQLVisitor visitor;

    while (std::getline(std::cin, line)) {
        if (line == "exit()") {
            dprint("Exit GUI!");
            return;
        }

        antlr4::ANTLRInputStream input(line.c_str());
        SQLLexer lexer(&input);                    // give input to lexer
        antlr4::CommonTokenStream tokens(&lexer);  // create tokens
        SQLParser parser(&tokens);                 // create translation that will parse input

        MyParserErrorListener errorListner;        // custom error handling
        parser.removeErrorListeners();             // remove any default error handling
        parser.addErrorListener(&errorListner);    // add custom error handling

        tokens.fill();
        try {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            auto res = visitor.visitProgram(parser.program());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::string time_dif = "Command Finished in " 
                +  std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) 
                + "microseconds";
            dprint(time_dif.c_str());
        }
        catch (std::exception& e) {
            eprint("Syntax Error");
            std::cout << e.what() << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    printf("Welcome to ThuSQL!\n");

    if (argc == 1) gui();
    else inputFromFile(argv[1]);
}

