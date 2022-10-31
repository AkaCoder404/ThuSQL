#include "SQLBaseListener.h"

class MySQLListener : public SQLBaseListener {
public:
  void enterProgram(SQLParser::ProgramContext* ctx) override {
    // printf("enter key %s\n", ctx->getText());
    std::cout << "enter key" << ctx->getText() << "\n";
  }
};
