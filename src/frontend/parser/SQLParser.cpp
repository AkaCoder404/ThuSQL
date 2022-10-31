
// Generated from src/frontend/parser/SQL.g4 by ANTLR 4.10.1


#include "SQLListener.h"
#include "SQLVisitor.h"

#include "SQLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SQLParserStaticData final {
  SQLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SQLParserStaticData(const SQLParserStaticData&) = delete;
  SQLParserStaticData(SQLParserStaticData&&) = delete;
  SQLParserStaticData& operator=(const SQLParserStaticData&) = delete;
  SQLParserStaticData& operator=(SQLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag sqlParserOnceFlag;
SQLParserStaticData *sqlParserStaticData = nullptr;

void sqlParserInitialize() {
  assert(sqlParserStaticData == nullptr);
  auto staticData = std::make_unique<SQLParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "db_statement", "io_statement", "table_statement", 
      "select_table", "alter_statement", "field_list", "field", "type_", 
      "value_lists", "value_list", "value", "where_and_clause", "where_clause", 
      "column", "expression", "set_clause", "selectors", "selector", "identifiers", 
      "operator_", "aggregator"
    },
    std::vector<std::string>{
      "", "';'", "'CREATE'", "'DATABASE'", "'DROP'", "'SHOW'", "'DATABASES'", 
      "'USE'", "'TABLES'", "'INDEXES'", "'LOAD'", "'FROM'", "'FILE'", "'TO'", 
      "'TABLE'", "'DUMP'", "'('", "')'", "'DESC'", "'INSERT'", "'INTO'", 
      "'VALUES'", "'DELETE'", "'WHERE'", "'UPDATE'", "'SET'", "'SELECT'", 
      "'GROUP'", "'BY'", "'LIMIT'", "'OFFSET'", "'ALTER'", "'ADD'", "'INDEX'", 
      "'PRIMARY'", "'KEY'", "'FOREIGN'", "'CONSTRAINT'", "'REFERENCES'", 
      "'UNIQUE'", "','", "'NOT'", "'DEFAULT'", "'INT'", "'VARCHAR'", "'FLOAT'", 
      "'AND'", "'IS'", "'IN'", "'LIKE'", "'.'", "'*'", "'='", "'<'", "'<='", 
      "'>'", "'>='", "'<>'", "'COUNT'", "'AVG'", "'MAX'", "'MIN'", "'SUM'", 
      "'NULL'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "EqualOrAssign", "Less", "LessEqual", "Greater", "GreaterEqual", 
      "NotEqual", "Count", "Average", "Max", "Min", "Sum", "Null", "Identifier", 
      "Integer", "String", "Float", "Whitespace", "Annotation"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,69,409,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,5,0,48,8,0,10,0,12,0,51,9,0,1,0,1,0,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,71,8,1,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,90,8,2,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,106,8,3,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,138,8,4,1,5,1,5,1,
  	5,1,5,1,5,1,5,3,5,146,8,5,1,5,1,5,1,5,3,5,151,8,5,1,5,1,5,1,5,1,5,3,5,
  	157,8,5,3,5,159,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,186,8,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,201,8,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,215,8,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,237,8,6,1,
  	7,1,7,1,7,5,7,242,8,7,10,7,12,7,245,9,7,1,8,1,8,1,8,1,8,3,8,251,8,8,1,
  	8,1,8,3,8,255,8,8,1,8,1,8,1,8,3,8,260,8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	3,8,269,8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,280,8,8,1,9,1,9,1,
  	9,1,9,1,9,1,9,3,9,288,8,9,1,10,1,10,1,10,5,10,293,8,10,10,10,12,10,296,
  	9,10,1,11,1,11,1,11,1,11,5,11,302,8,11,10,11,12,11,305,9,11,1,11,1,11,
  	1,12,1,12,1,13,1,13,1,13,5,13,314,8,13,10,13,12,13,317,9,13,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,332,8,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,3,14,350,8,14,1,15,1,15,3,15,354,8,15,1,15,1,15,1,16,1,16,3,
  	16,360,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,369,8,17,10,17,12,
  	17,372,9,17,1,18,1,18,1,18,1,18,5,18,378,8,18,10,18,12,18,381,9,18,3,
  	18,383,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,395,
  	8,19,1,20,1,20,1,20,5,20,400,8,20,10,20,12,20,403,9,20,1,21,1,21,1,22,
  	1,22,1,22,0,0,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,0,3,2,0,63,63,65,67,1,0,52,57,1,0,58,62,443,0,49,1,0,0,0,
  	2,70,1,0,0,0,4,89,1,0,0,0,6,105,1,0,0,0,8,137,1,0,0,0,10,139,1,0,0,0,
  	12,236,1,0,0,0,14,238,1,0,0,0,16,279,1,0,0,0,18,287,1,0,0,0,20,289,1,
  	0,0,0,22,297,1,0,0,0,24,308,1,0,0,0,26,310,1,0,0,0,28,349,1,0,0,0,30,
  	353,1,0,0,0,32,359,1,0,0,0,34,361,1,0,0,0,36,382,1,0,0,0,38,394,1,0,0,
  	0,40,396,1,0,0,0,42,404,1,0,0,0,44,406,1,0,0,0,46,48,3,2,1,0,47,46,1,
  	0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,52,1,0,0,0,51,49,1,
  	0,0,0,52,53,5,0,0,1,53,1,1,0,0,0,54,55,3,4,2,0,55,56,5,1,0,0,56,71,1,
  	0,0,0,57,58,3,6,3,0,58,59,5,1,0,0,59,71,1,0,0,0,60,61,3,8,4,0,61,62,5,
  	1,0,0,62,71,1,0,0,0,63,64,3,12,6,0,64,65,5,1,0,0,65,71,1,0,0,0,66,67,
  	5,69,0,0,67,71,5,1,0,0,68,69,5,63,0,0,69,71,5,1,0,0,70,54,1,0,0,0,70,
  	57,1,0,0,0,70,60,1,0,0,0,70,63,1,0,0,0,70,66,1,0,0,0,70,68,1,0,0,0,71,
  	3,1,0,0,0,72,73,5,2,0,0,73,74,5,3,0,0,74,90,5,64,0,0,75,76,5,4,0,0,76,
  	77,5,3,0,0,77,90,5,64,0,0,78,79,5,5,0,0,79,80,5,3,0,0,80,90,5,64,0,0,
  	81,82,5,5,0,0,82,90,5,6,0,0,83,84,5,7,0,0,84,90,5,64,0,0,85,86,5,5,0,
  	0,86,90,5,8,0,0,87,88,5,5,0,0,88,90,5,9,0,0,89,72,1,0,0,0,89,75,1,0,0,
  	0,89,78,1,0,0,0,89,81,1,0,0,0,89,83,1,0,0,0,89,85,1,0,0,0,89,87,1,0,0,
  	0,90,5,1,0,0,0,91,92,5,10,0,0,92,93,5,11,0,0,93,94,5,12,0,0,94,95,5,66,
  	0,0,95,96,5,13,0,0,96,97,5,14,0,0,97,106,5,64,0,0,98,99,5,15,0,0,99,100,
  	5,13,0,0,100,101,5,12,0,0,101,102,5,66,0,0,102,103,5,11,0,0,103,104,5,
  	14,0,0,104,106,5,64,0,0,105,91,1,0,0,0,105,98,1,0,0,0,106,7,1,0,0,0,107,
  	108,5,2,0,0,108,109,5,14,0,0,109,110,5,64,0,0,110,111,5,16,0,0,111,112,
  	3,14,7,0,112,113,5,17,0,0,113,138,1,0,0,0,114,115,5,4,0,0,115,116,5,14,
  	0,0,116,138,5,64,0,0,117,118,5,18,0,0,118,138,5,64,0,0,119,120,5,19,0,
  	0,120,121,5,20,0,0,121,122,5,64,0,0,122,123,5,21,0,0,123,138,3,20,10,
  	0,124,125,5,22,0,0,125,126,5,11,0,0,126,127,5,64,0,0,127,128,5,23,0,0,
  	128,138,3,26,13,0,129,130,5,24,0,0,130,131,5,64,0,0,131,132,5,25,0,0,
  	132,133,3,34,17,0,133,134,5,23,0,0,134,135,3,26,13,0,135,138,1,0,0,0,
  	136,138,3,10,5,0,137,107,1,0,0,0,137,114,1,0,0,0,137,117,1,0,0,0,137,
  	119,1,0,0,0,137,124,1,0,0,0,137,129,1,0,0,0,137,136,1,0,0,0,138,9,1,0,
  	0,0,139,140,5,26,0,0,140,141,3,36,18,0,141,142,5,11,0,0,142,145,3,40,
  	20,0,143,144,5,23,0,0,144,146,3,26,13,0,145,143,1,0,0,0,145,146,1,0,0,
  	0,146,150,1,0,0,0,147,148,5,27,0,0,148,149,5,28,0,0,149,151,3,30,15,0,
  	150,147,1,0,0,0,150,151,1,0,0,0,151,158,1,0,0,0,152,153,5,29,0,0,153,
  	156,5,65,0,0,154,155,5,30,0,0,155,157,5,65,0,0,156,154,1,0,0,0,156,157,
  	1,0,0,0,157,159,1,0,0,0,158,152,1,0,0,0,158,159,1,0,0,0,159,11,1,0,0,
  	0,160,161,5,31,0,0,161,162,5,14,0,0,162,163,5,64,0,0,163,164,5,32,0,0,
  	164,165,5,33,0,0,165,166,5,16,0,0,166,167,3,40,20,0,167,168,5,17,0,0,
  	168,237,1,0,0,0,169,170,5,31,0,0,170,171,5,14,0,0,171,172,5,64,0,0,172,
  	173,5,4,0,0,173,174,5,33,0,0,174,175,5,16,0,0,175,176,3,40,20,0,176,177,
  	5,17,0,0,177,237,1,0,0,0,178,179,5,31,0,0,179,180,5,14,0,0,180,181,5,
  	64,0,0,181,182,5,4,0,0,182,183,5,34,0,0,183,185,5,35,0,0,184,186,5,64,
  	0,0,185,184,1,0,0,0,185,186,1,0,0,0,186,237,1,0,0,0,187,188,5,31,0,0,
  	188,189,5,14,0,0,189,190,5,64,0,0,190,191,5,4,0,0,191,192,5,36,0,0,192,
  	193,5,35,0,0,193,237,5,64,0,0,194,195,5,31,0,0,195,196,5,14,0,0,196,197,
  	5,64,0,0,197,198,5,32,0,0,198,200,5,37,0,0,199,201,5,64,0,0,200,199,1,
  	0,0,0,200,201,1,0,0,0,201,202,1,0,0,0,202,203,5,34,0,0,203,204,5,35,0,
  	0,204,205,5,16,0,0,205,206,3,40,20,0,206,207,5,17,0,0,207,237,1,0,0,0,
  	208,209,5,31,0,0,209,210,5,14,0,0,210,211,5,64,0,0,211,212,5,32,0,0,212,
  	214,5,37,0,0,213,215,5,64,0,0,214,213,1,0,0,0,214,215,1,0,0,0,215,216,
  	1,0,0,0,216,217,5,36,0,0,217,218,5,35,0,0,218,219,5,16,0,0,219,220,3,
  	40,20,0,220,221,5,17,0,0,221,222,5,38,0,0,222,223,5,64,0,0,223,224,5,
  	16,0,0,224,225,3,40,20,0,225,226,5,17,0,0,226,237,1,0,0,0,227,228,5,31,
  	0,0,228,229,5,14,0,0,229,230,5,64,0,0,230,231,5,32,0,0,231,232,5,39,0,
  	0,232,233,5,16,0,0,233,234,3,40,20,0,234,235,5,17,0,0,235,237,1,0,0,0,
  	236,160,1,0,0,0,236,169,1,0,0,0,236,178,1,0,0,0,236,187,1,0,0,0,236,194,
  	1,0,0,0,236,208,1,0,0,0,236,227,1,0,0,0,237,13,1,0,0,0,238,243,3,16,8,
  	0,239,240,5,40,0,0,240,242,3,16,8,0,241,239,1,0,0,0,242,245,1,0,0,0,243,
  	241,1,0,0,0,243,244,1,0,0,0,244,15,1,0,0,0,245,243,1,0,0,0,246,247,5,
  	64,0,0,247,250,3,18,9,0,248,249,5,41,0,0,249,251,5,63,0,0,250,248,1,0,
  	0,0,250,251,1,0,0,0,251,254,1,0,0,0,252,253,5,42,0,0,253,255,3,24,12,
  	0,254,252,1,0,0,0,254,255,1,0,0,0,255,280,1,0,0,0,256,257,5,34,0,0,257,
  	259,5,35,0,0,258,260,5,64,0,0,259,258,1,0,0,0,259,260,1,0,0,0,260,261,
  	1,0,0,0,261,262,5,16,0,0,262,263,3,40,20,0,263,264,5,17,0,0,264,280,1,
  	0,0,0,265,266,5,36,0,0,266,268,5,35,0,0,267,269,5,64,0,0,268,267,1,0,
  	0,0,268,269,1,0,0,0,269,270,1,0,0,0,270,271,5,16,0,0,271,272,3,40,20,
  	0,272,273,5,17,0,0,273,274,5,38,0,0,274,275,5,64,0,0,275,276,5,16,0,0,
  	276,277,3,40,20,0,277,278,5,17,0,0,278,280,1,0,0,0,279,246,1,0,0,0,279,
  	256,1,0,0,0,279,265,1,0,0,0,280,17,1,0,0,0,281,288,5,43,0,0,282,283,5,
  	44,0,0,283,284,5,16,0,0,284,285,5,65,0,0,285,288,5,17,0,0,286,288,5,45,
  	0,0,287,281,1,0,0,0,287,282,1,0,0,0,287,286,1,0,0,0,288,19,1,0,0,0,289,
  	294,3,22,11,0,290,291,5,40,0,0,291,293,3,22,11,0,292,290,1,0,0,0,293,
  	296,1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,21,1,0,0,0,296,294,1,
  	0,0,0,297,298,5,16,0,0,298,303,3,24,12,0,299,300,5,40,0,0,300,302,3,24,
  	12,0,301,299,1,0,0,0,302,305,1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,0,
  	304,306,1,0,0,0,305,303,1,0,0,0,306,307,5,17,0,0,307,23,1,0,0,0,308,309,
  	7,0,0,0,309,25,1,0,0,0,310,315,3,28,14,0,311,312,5,46,0,0,312,314,3,28,
  	14,0,313,311,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,0,315,316,1,0,0,0,
  	316,27,1,0,0,0,317,315,1,0,0,0,318,319,3,30,15,0,319,320,3,42,21,0,320,
  	321,3,32,16,0,321,350,1,0,0,0,322,323,3,30,15,0,323,324,3,42,21,0,324,
  	325,5,16,0,0,325,326,3,10,5,0,326,327,5,17,0,0,327,350,1,0,0,0,328,329,
  	3,30,15,0,329,331,5,47,0,0,330,332,5,41,0,0,331,330,1,0,0,0,331,332,1,
  	0,0,0,332,333,1,0,0,0,333,334,5,63,0,0,334,350,1,0,0,0,335,336,3,30,15,
  	0,336,337,5,48,0,0,337,338,3,22,11,0,338,350,1,0,0,0,339,340,3,30,15,
  	0,340,341,5,48,0,0,341,342,5,16,0,0,342,343,3,10,5,0,343,344,5,17,0,0,
  	344,350,1,0,0,0,345,346,3,30,15,0,346,347,5,49,0,0,347,348,5,66,0,0,348,
  	350,1,0,0,0,349,318,1,0,0,0,349,322,1,0,0,0,349,328,1,0,0,0,349,335,1,
  	0,0,0,349,339,1,0,0,0,349,345,1,0,0,0,350,29,1,0,0,0,351,352,5,64,0,0,
  	352,354,5,50,0,0,353,351,1,0,0,0,353,354,1,0,0,0,354,355,1,0,0,0,355,
  	356,5,64,0,0,356,31,1,0,0,0,357,360,3,24,12,0,358,360,3,30,15,0,359,357,
  	1,0,0,0,359,358,1,0,0,0,360,33,1,0,0,0,361,362,5,64,0,0,362,363,5,52,
  	0,0,363,370,3,24,12,0,364,365,5,40,0,0,365,366,5,64,0,0,366,367,5,52,
  	0,0,367,369,3,24,12,0,368,364,1,0,0,0,369,372,1,0,0,0,370,368,1,0,0,0,
  	370,371,1,0,0,0,371,35,1,0,0,0,372,370,1,0,0,0,373,383,5,51,0,0,374,379,
  	3,38,19,0,375,376,5,40,0,0,376,378,3,38,19,0,377,375,1,0,0,0,378,381,
  	1,0,0,0,379,377,1,0,0,0,379,380,1,0,0,0,380,383,1,0,0,0,381,379,1,0,0,
  	0,382,373,1,0,0,0,382,374,1,0,0,0,383,37,1,0,0,0,384,395,3,30,15,0,385,
  	386,3,44,22,0,386,387,5,16,0,0,387,388,3,30,15,0,388,389,5,17,0,0,389,
  	395,1,0,0,0,390,391,5,58,0,0,391,392,5,16,0,0,392,393,5,51,0,0,393,395,
  	5,17,0,0,394,384,1,0,0,0,394,385,1,0,0,0,394,390,1,0,0,0,395,39,1,0,0,
  	0,396,401,5,64,0,0,397,398,5,40,0,0,398,400,5,64,0,0,399,397,1,0,0,0,
  	400,403,1,0,0,0,401,399,1,0,0,0,401,402,1,0,0,0,402,41,1,0,0,0,403,401,
  	1,0,0,0,404,405,7,1,0,0,405,43,1,0,0,0,406,407,7,2,0,0,407,45,1,0,0,0,
  	32,49,70,89,105,137,145,150,156,158,185,200,214,236,243,250,254,259,268,
  	279,287,294,303,315,331,349,353,359,370,379,382,394,401
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sqlParserStaticData = staticData.release();
}

}

SQLParser::SQLParser(TokenStream *input) : SQLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SQLParser::SQLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SQLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sqlParserStaticData->atn, sqlParserStaticData->decisionToDFA, sqlParserStaticData->sharedContextCache, options);
}

SQLParser::~SQLParser() {
  delete _interpreter;
}

const atn::ATN& SQLParser::getATN() const {
  return *sqlParserStaticData->atn;
}

std::string SQLParser::getGrammarFileName() const {
  return "SQL.g4";
}

const std::vector<std::string>& SQLParser::getRuleNames() const {
  return sqlParserStaticData->ruleNames;
}

const dfa::Vocabulary& SQLParser::getVocabulary() const {
  return sqlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SQLParser::getSerializedATN() const {
  return sqlParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

SQLParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::ProgramContext::EOF() {
  return getToken(SQLParser::EOF, 0);
}

std::vector<SQLParser::StatementContext *> SQLParser::ProgramContext::statement() {
  return getRuleContexts<SQLParser::StatementContext>();
}

SQLParser::StatementContext* SQLParser::ProgramContext::statement(size_t i) {
  return getRuleContext<SQLParser::StatementContext>(i);
}


size_t SQLParser::ProgramContext::getRuleIndex() const {
  return SQLParser::RuleProgram;
}

void SQLParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void SQLParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any SQLParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ProgramContext* SQLParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SQLParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQLParser::T__1)
      | (1ULL << SQLParser::T__3)
      | (1ULL << SQLParser::T__4)
      | (1ULL << SQLParser::T__6)
      | (1ULL << SQLParser::T__9)
      | (1ULL << SQLParser::T__14)
      | (1ULL << SQLParser::T__17)
      | (1ULL << SQLParser::T__18)
      | (1ULL << SQLParser::T__21)
      | (1ULL << SQLParser::T__23)
      | (1ULL << SQLParser::T__25)
      | (1ULL << SQLParser::T__30)
      | (1ULL << SQLParser::Null))) != 0) || _la == SQLParser::Annotation) {
      setState(46);
      statement();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    match(SQLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SQLParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::Db_statementContext* SQLParser::StatementContext::db_statement() {
  return getRuleContext<SQLParser::Db_statementContext>(0);
}

SQLParser::Io_statementContext* SQLParser::StatementContext::io_statement() {
  return getRuleContext<SQLParser::Io_statementContext>(0);
}

SQLParser::Table_statementContext* SQLParser::StatementContext::table_statement() {
  return getRuleContext<SQLParser::Table_statementContext>(0);
}

SQLParser::Alter_statementContext* SQLParser::StatementContext::alter_statement() {
  return getRuleContext<SQLParser::Alter_statementContext>(0);
}

tree::TerminalNode* SQLParser::StatementContext::Annotation() {
  return getToken(SQLParser::Annotation, 0);
}

tree::TerminalNode* SQLParser::StatementContext::Null() {
  return getToken(SQLParser::Null, 0);
}


size_t SQLParser::StatementContext::getRuleIndex() const {
  return SQLParser::RuleStatement;
}

void SQLParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void SQLParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any SQLParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::StatementContext* SQLParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, SQLParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(70);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(54);
      db_statement();
      setState(55);
      match(SQLParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(57);
      io_statement();
      setState(58);
      match(SQLParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(60);
      table_statement();
      setState(61);
      match(SQLParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(63);
      alter_statement();
      setState(64);
      match(SQLParser::T__0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(66);
      match(SQLParser::Annotation);
      setState(67);
      match(SQLParser::T__0);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(68);
      match(SQLParser::Null);
      setState(69);
      match(SQLParser::T__0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Db_statementContext ------------------------------------------------------------------

SQLParser::Db_statementContext::Db_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::Db_statementContext::getRuleIndex() const {
  return SQLParser::RuleDb_statement;
}

void SQLParser::Db_statementContext::copyFrom(Db_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Show_dbsContext ------------------------------------------------------------------

SQLParser::Show_dbsContext::Show_dbsContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Show_dbsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_dbs(this);
}
void SQLParser::Show_dbsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_dbs(this);
}

std::any SQLParser::Show_dbsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitShow_dbs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Drop_dbContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Drop_dbContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Drop_dbContext::Drop_dbContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Drop_dbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_db(this);
}
void SQLParser::Drop_dbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_db(this);
}

std::any SQLParser::Drop_dbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitDrop_db(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Show_tablesContext ------------------------------------------------------------------

SQLParser::Show_tablesContext::Show_tablesContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Show_tablesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_tables(this);
}
void SQLParser::Show_tablesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_tables(this);
}

std::any SQLParser::Show_tablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitShow_tables(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Show_dbContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Show_dbContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Show_dbContext::Show_dbContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Show_dbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_db(this);
}
void SQLParser::Show_dbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_db(this);
}

std::any SQLParser::Show_dbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitShow_db(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Create_dbContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Create_dbContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Create_dbContext::Create_dbContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Create_dbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_db(this);
}
void SQLParser::Create_dbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_db(this);
}

std::any SQLParser::Create_dbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitCreate_db(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Use_dbContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Use_dbContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Use_dbContext::Use_dbContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Use_dbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUse_db(this);
}
void SQLParser::Use_dbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUse_db(this);
}

std::any SQLParser::Use_dbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitUse_db(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Show_indexesContext ------------------------------------------------------------------

SQLParser::Show_indexesContext::Show_indexesContext(Db_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Show_indexesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_indexes(this);
}
void SQLParser::Show_indexesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_indexes(this);
}

std::any SQLParser::Show_indexesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitShow_indexes(this);
  else
    return visitor->visitChildren(this);
}
SQLParser::Db_statementContext* SQLParser::db_statement() {
  Db_statementContext *_localctx = _tracker.createInstance<Db_statementContext>(_ctx, getState());
  enterRule(_localctx, 4, SQLParser::RuleDb_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SQLParser::Create_dbContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(72);
      match(SQLParser::T__1);
      setState(73);
      match(SQLParser::T__2);
      setState(74);
      match(SQLParser::Identifier);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SQLParser::Drop_dbContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(75);
      match(SQLParser::T__3);
      setState(76);
      match(SQLParser::T__2);
      setState(77);
      match(SQLParser::Identifier);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SQLParser::Show_dbContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(78);
      match(SQLParser::T__4);
      setState(79);
      match(SQLParser::T__2);
      setState(80);
      match(SQLParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SQLParser::Show_dbsContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(81);
      match(SQLParser::T__4);
      setState(82);
      match(SQLParser::T__5);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SQLParser::Use_dbContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(83);
      match(SQLParser::T__6);
      setState(84);
      match(SQLParser::Identifier);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SQLParser::Show_tablesContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(85);
      match(SQLParser::T__4);
      setState(86);
      match(SQLParser::T__7);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SQLParser::Show_indexesContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(87);
      match(SQLParser::T__4);
      setState(88);
      match(SQLParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Io_statementContext ------------------------------------------------------------------

SQLParser::Io_statementContext::Io_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::Io_statementContext::getRuleIndex() const {
  return SQLParser::RuleIo_statement;
}

void SQLParser::Io_statementContext::copyFrom(Io_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Dump_dataContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Dump_dataContext::String() {
  return getToken(SQLParser::String, 0);
}

tree::TerminalNode* SQLParser::Dump_dataContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Dump_dataContext::Dump_dataContext(Io_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Dump_dataContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDump_data(this);
}
void SQLParser::Dump_dataContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDump_data(this);
}

std::any SQLParser::Dump_dataContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitDump_data(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Load_dataContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Load_dataContext::String() {
  return getToken(SQLParser::String, 0);
}

tree::TerminalNode* SQLParser::Load_dataContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Load_dataContext::Load_dataContext(Io_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Load_dataContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoad_data(this);
}
void SQLParser::Load_dataContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoad_data(this);
}

std::any SQLParser::Load_dataContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitLoad_data(this);
  else
    return visitor->visitChildren(this);
}
SQLParser::Io_statementContext* SQLParser::io_statement() {
  Io_statementContext *_localctx = _tracker.createInstance<Io_statementContext>(_ctx, getState());
  enterRule(_localctx, 6, SQLParser::RuleIo_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__9: {
        _localctx = _tracker.createInstance<SQLParser::Load_dataContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(91);
        match(SQLParser::T__9);
        setState(92);
        match(SQLParser::T__10);
        setState(93);
        match(SQLParser::T__11);
        setState(94);
        match(SQLParser::String);
        setState(95);
        match(SQLParser::T__12);
        setState(96);
        match(SQLParser::T__13);
        setState(97);
        match(SQLParser::Identifier);
        break;
      }

      case SQLParser::T__14: {
        _localctx = _tracker.createInstance<SQLParser::Dump_dataContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(98);
        match(SQLParser::T__14);
        setState(99);
        match(SQLParser::T__12);
        setState(100);
        match(SQLParser::T__11);
        setState(101);
        match(SQLParser::String);
        setState(102);
        match(SQLParser::T__10);
        setState(103);
        match(SQLParser::T__13);
        setState(104);
        match(SQLParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_statementContext ------------------------------------------------------------------

SQLParser::Table_statementContext::Table_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::Table_statementContext::getRuleIndex() const {
  return SQLParser::RuleTable_statement;
}

void SQLParser::Table_statementContext::copyFrom(Table_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Delete_from_tableContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Delete_from_tableContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Where_and_clauseContext* SQLParser::Delete_from_tableContext::where_and_clause() {
  return getRuleContext<SQLParser::Where_and_clauseContext>(0);
}

SQLParser::Delete_from_tableContext::Delete_from_tableContext(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Delete_from_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_from_table(this);
}
void SQLParser::Delete_from_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_from_table(this);
}

std::any SQLParser::Delete_from_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitDelete_from_table(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Insert_into_tableContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Insert_into_tableContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Value_listsContext* SQLParser::Insert_into_tableContext::value_lists() {
  return getRuleContext<SQLParser::Value_listsContext>(0);
}

SQLParser::Insert_into_tableContext::Insert_into_tableContext(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Insert_into_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_into_table(this);
}
void SQLParser::Insert_into_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_into_table(this);
}

std::any SQLParser::Insert_into_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitInsert_into_table(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Create_tableContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Create_tableContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Field_listContext* SQLParser::Create_tableContext::field_list() {
  return getRuleContext<SQLParser::Field_listContext>(0);
}

SQLParser::Create_tableContext::Create_tableContext(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Create_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_table(this);
}
void SQLParser::Create_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_table(this);
}

std::any SQLParser::Create_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitCreate_table(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Describe_tableContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Describe_tableContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Describe_tableContext::Describe_tableContext(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Describe_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescribe_table(this);
}
void SQLParser::Describe_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescribe_table(this);
}

std::any SQLParser::Describe_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitDescribe_table(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Select_table_Context ------------------------------------------------------------------

SQLParser::Select_tableContext* SQLParser::Select_table_Context::select_table() {
  return getRuleContext<SQLParser::Select_tableContext>(0);
}

SQLParser::Select_table_Context::Select_table_Context(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Select_table_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_table_(this);
}
void SQLParser::Select_table_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_table_(this);
}

std::any SQLParser::Select_table_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitSelect_table_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Drop_tableContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Drop_tableContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Drop_tableContext::Drop_tableContext(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Drop_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_table(this);
}
void SQLParser::Drop_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_table(this);
}

std::any SQLParser::Drop_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitDrop_table(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Update_tableContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Update_tableContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Set_clauseContext* SQLParser::Update_tableContext::set_clause() {
  return getRuleContext<SQLParser::Set_clauseContext>(0);
}

SQLParser::Where_and_clauseContext* SQLParser::Update_tableContext::where_and_clause() {
  return getRuleContext<SQLParser::Where_and_clauseContext>(0);
}

SQLParser::Update_tableContext::Update_tableContext(Table_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Update_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_table(this);
}
void SQLParser::Update_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_table(this);
}

std::any SQLParser::Update_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitUpdate_table(this);
  else
    return visitor->visitChildren(this);
}
SQLParser::Table_statementContext* SQLParser::table_statement() {
  Table_statementContext *_localctx = _tracker.createInstance<Table_statementContext>(_ctx, getState());
  enterRule(_localctx, 8, SQLParser::RuleTable_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__1: {
        _localctx = _tracker.createInstance<SQLParser::Create_tableContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(107);
        match(SQLParser::T__1);
        setState(108);
        match(SQLParser::T__13);
        setState(109);
        match(SQLParser::Identifier);
        setState(110);
        match(SQLParser::T__15);
        setState(111);
        field_list();
        setState(112);
        match(SQLParser::T__16);
        break;
      }

      case SQLParser::T__3: {
        _localctx = _tracker.createInstance<SQLParser::Drop_tableContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(SQLParser::T__3);
        setState(115);
        match(SQLParser::T__13);
        setState(116);
        match(SQLParser::Identifier);
        break;
      }

      case SQLParser::T__17: {
        _localctx = _tracker.createInstance<SQLParser::Describe_tableContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(117);
        match(SQLParser::T__17);
        setState(118);
        match(SQLParser::Identifier);
        break;
      }

      case SQLParser::T__18: {
        _localctx = _tracker.createInstance<SQLParser::Insert_into_tableContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(119);
        match(SQLParser::T__18);
        setState(120);
        match(SQLParser::T__19);
        setState(121);
        match(SQLParser::Identifier);
        setState(122);
        match(SQLParser::T__20);
        setState(123);
        value_lists();
        break;
      }

      case SQLParser::T__21: {
        _localctx = _tracker.createInstance<SQLParser::Delete_from_tableContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(124);
        match(SQLParser::T__21);
        setState(125);
        match(SQLParser::T__10);
        setState(126);
        match(SQLParser::Identifier);
        setState(127);
        match(SQLParser::T__22);
        setState(128);
        where_and_clause();
        break;
      }

      case SQLParser::T__23: {
        _localctx = _tracker.createInstance<SQLParser::Update_tableContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(129);
        match(SQLParser::T__23);
        setState(130);
        match(SQLParser::Identifier);
        setState(131);
        match(SQLParser::T__24);
        setState(132);
        set_clause();
        setState(133);
        match(SQLParser::T__22);
        setState(134);
        where_and_clause();
        break;
      }

      case SQLParser::T__25: {
        _localctx = _tracker.createInstance<SQLParser::Select_table_Context>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(136);
        select_table();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_tableContext ------------------------------------------------------------------

SQLParser::Select_tableContext::Select_tableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::SelectorsContext* SQLParser::Select_tableContext::selectors() {
  return getRuleContext<SQLParser::SelectorsContext>(0);
}

SQLParser::IdentifiersContext* SQLParser::Select_tableContext::identifiers() {
  return getRuleContext<SQLParser::IdentifiersContext>(0);
}

SQLParser::Where_and_clauseContext* SQLParser::Select_tableContext::where_and_clause() {
  return getRuleContext<SQLParser::Where_and_clauseContext>(0);
}

SQLParser::ColumnContext* SQLParser::Select_tableContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

std::vector<tree::TerminalNode *> SQLParser::Select_tableContext::Integer() {
  return getTokens(SQLParser::Integer);
}

tree::TerminalNode* SQLParser::Select_tableContext::Integer(size_t i) {
  return getToken(SQLParser::Integer, i);
}


size_t SQLParser::Select_tableContext::getRuleIndex() const {
  return SQLParser::RuleSelect_table;
}

void SQLParser::Select_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_table(this);
}

void SQLParser::Select_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_table(this);
}


std::any SQLParser::Select_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitSelect_table(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Select_tableContext* SQLParser::select_table() {
  Select_tableContext *_localctx = _tracker.createInstance<Select_tableContext>(_ctx, getState());
  enterRule(_localctx, 10, SQLParser::RuleSelect_table);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(SQLParser::T__25);
    setState(140);
    selectors();
    setState(141);
    match(SQLParser::T__10);
    setState(142);
    identifiers();
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__22) {
      setState(143);
      match(SQLParser::T__22);
      setState(144);
      where_and_clause();
    }
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__26) {
      setState(147);
      match(SQLParser::T__26);
      setState(148);
      match(SQLParser::T__27);
      setState(149);
      column();
    }
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__28) {
      setState(152);
      match(SQLParser::T__28);
      setState(153);
      match(SQLParser::Integer);
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLParser::T__29) {
        setState(154);
        match(SQLParser::T__29);
        setState(155);
        match(SQLParser::Integer);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alter_statementContext ------------------------------------------------------------------

SQLParser::Alter_statementContext::Alter_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::Alter_statementContext::getRuleIndex() const {
  return SQLParser::RuleAlter_statement;
}

void SQLParser::Alter_statementContext::copyFrom(Alter_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Alter_table_drop_pkContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SQLParser::Alter_table_drop_pkContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::Alter_table_drop_pkContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}

SQLParser::Alter_table_drop_pkContext::Alter_table_drop_pkContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_table_drop_pkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_drop_pk(this);
}
void SQLParser::Alter_table_drop_pkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_drop_pk(this);
}

std::any SQLParser::Alter_table_drop_pkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_table_drop_pk(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Alter_table_add_foreign_keyContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SQLParser::Alter_table_add_foreign_keyContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::Alter_table_add_foreign_keyContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}

std::vector<SQLParser::IdentifiersContext *> SQLParser::Alter_table_add_foreign_keyContext::identifiers() {
  return getRuleContexts<SQLParser::IdentifiersContext>();
}

SQLParser::IdentifiersContext* SQLParser::Alter_table_add_foreign_keyContext::identifiers(size_t i) {
  return getRuleContext<SQLParser::IdentifiersContext>(i);
}

SQLParser::Alter_table_add_foreign_keyContext::Alter_table_add_foreign_keyContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_table_add_foreign_keyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_add_foreign_key(this);
}
void SQLParser::Alter_table_add_foreign_keyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_add_foreign_key(this);
}

std::any SQLParser::Alter_table_add_foreign_keyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_table_add_foreign_key(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Alter_table_add_uniqueContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Alter_table_add_uniqueContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::IdentifiersContext* SQLParser::Alter_table_add_uniqueContext::identifiers() {
  return getRuleContext<SQLParser::IdentifiersContext>(0);
}

SQLParser::Alter_table_add_uniqueContext::Alter_table_add_uniqueContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_table_add_uniqueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_add_unique(this);
}
void SQLParser::Alter_table_add_uniqueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_add_unique(this);
}

std::any SQLParser::Alter_table_add_uniqueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_table_add_unique(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Alter_drop_indexContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Alter_drop_indexContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::IdentifiersContext* SQLParser::Alter_drop_indexContext::identifiers() {
  return getRuleContext<SQLParser::IdentifiersContext>(0);
}

SQLParser::Alter_drop_indexContext::Alter_drop_indexContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_drop_indexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_drop_index(this);
}
void SQLParser::Alter_drop_indexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_drop_index(this);
}

std::any SQLParser::Alter_drop_indexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_drop_index(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Alter_add_indexContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Alter_add_indexContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::IdentifiersContext* SQLParser::Alter_add_indexContext::identifiers() {
  return getRuleContext<SQLParser::IdentifiersContext>(0);
}

SQLParser::Alter_add_indexContext::Alter_add_indexContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_add_indexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_add_index(this);
}
void SQLParser::Alter_add_indexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_add_index(this);
}

std::any SQLParser::Alter_add_indexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_add_index(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Alter_table_drop_foreign_keyContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SQLParser::Alter_table_drop_foreign_keyContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::Alter_table_drop_foreign_keyContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}

SQLParser::Alter_table_drop_foreign_keyContext::Alter_table_drop_foreign_keyContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_table_drop_foreign_keyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_drop_foreign_key(this);
}
void SQLParser::Alter_table_drop_foreign_keyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_drop_foreign_key(this);
}

std::any SQLParser::Alter_table_drop_foreign_keyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_table_drop_foreign_key(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Alter_table_add_pkContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SQLParser::Alter_table_add_pkContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::Alter_table_add_pkContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}

SQLParser::IdentifiersContext* SQLParser::Alter_table_add_pkContext::identifiers() {
  return getRuleContext<SQLParser::IdentifiersContext>(0);
}

SQLParser::Alter_table_add_pkContext::Alter_table_add_pkContext(Alter_statementContext *ctx) { copyFrom(ctx); }

void SQLParser::Alter_table_add_pkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_add_pk(this);
}
void SQLParser::Alter_table_add_pkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_add_pk(this);
}

std::any SQLParser::Alter_table_add_pkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAlter_table_add_pk(this);
  else
    return visitor->visitChildren(this);
}
SQLParser::Alter_statementContext* SQLParser::alter_statement() {
  Alter_statementContext *_localctx = _tracker.createInstance<Alter_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, SQLParser::RuleAlter_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SQLParser::Alter_add_indexContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(160);
      match(SQLParser::T__30);
      setState(161);
      match(SQLParser::T__13);
      setState(162);
      match(SQLParser::Identifier);
      setState(163);
      match(SQLParser::T__31);
      setState(164);
      match(SQLParser::T__32);
      setState(165);
      match(SQLParser::T__15);
      setState(166);
      identifiers();
      setState(167);
      match(SQLParser::T__16);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SQLParser::Alter_drop_indexContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(169);
      match(SQLParser::T__30);
      setState(170);
      match(SQLParser::T__13);
      setState(171);
      match(SQLParser::Identifier);
      setState(172);
      match(SQLParser::T__3);
      setState(173);
      match(SQLParser::T__32);
      setState(174);
      match(SQLParser::T__15);
      setState(175);
      identifiers();
      setState(176);
      match(SQLParser::T__16);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SQLParser::Alter_table_drop_pkContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(178);
      match(SQLParser::T__30);
      setState(179);
      match(SQLParser::T__13);
      setState(180);
      match(SQLParser::Identifier);
      setState(181);
      match(SQLParser::T__3);
      setState(182);
      match(SQLParser::T__33);
      setState(183);
      match(SQLParser::T__34);
      setState(185);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLParser::Identifier) {
        setState(184);
        match(SQLParser::Identifier);
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SQLParser::Alter_table_drop_foreign_keyContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(187);
      match(SQLParser::T__30);
      setState(188);
      match(SQLParser::T__13);
      setState(189);
      match(SQLParser::Identifier);
      setState(190);
      match(SQLParser::T__3);
      setState(191);
      match(SQLParser::T__35);
      setState(192);
      match(SQLParser::T__34);
      setState(193);
      match(SQLParser::Identifier);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SQLParser::Alter_table_add_pkContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(194);
      match(SQLParser::T__30);
      setState(195);
      match(SQLParser::T__13);
      setState(196);
      match(SQLParser::Identifier);
      setState(197);
      match(SQLParser::T__31);
      setState(198);
      match(SQLParser::T__36);
      setState(200);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLParser::Identifier) {
        setState(199);
        match(SQLParser::Identifier);
      }
      setState(202);
      match(SQLParser::T__33);
      setState(203);
      match(SQLParser::T__34);
      setState(204);
      match(SQLParser::T__15);
      setState(205);
      identifiers();
      setState(206);
      match(SQLParser::T__16);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SQLParser::Alter_table_add_foreign_keyContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(208);
      match(SQLParser::T__30);
      setState(209);
      match(SQLParser::T__13);
      setState(210);
      match(SQLParser::Identifier);
      setState(211);
      match(SQLParser::T__31);
      setState(212);
      match(SQLParser::T__36);
      setState(214);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLParser::Identifier) {
        setState(213);
        match(SQLParser::Identifier);
      }
      setState(216);
      match(SQLParser::T__35);
      setState(217);
      match(SQLParser::T__34);
      setState(218);
      match(SQLParser::T__15);
      setState(219);
      identifiers();
      setState(220);
      match(SQLParser::T__16);
      setState(221);
      match(SQLParser::T__37);
      setState(222);
      match(SQLParser::Identifier);
      setState(223);
      match(SQLParser::T__15);
      setState(224);
      identifiers();
      setState(225);
      match(SQLParser::T__16);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SQLParser::Alter_table_add_uniqueContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(227);
      match(SQLParser::T__30);
      setState(228);
      match(SQLParser::T__13);
      setState(229);
      match(SQLParser::Identifier);
      setState(230);
      match(SQLParser::T__31);
      setState(231);
      match(SQLParser::T__38);
      setState(232);
      match(SQLParser::T__15);
      setState(233);
      identifiers();
      setState(234);
      match(SQLParser::T__16);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Field_listContext ------------------------------------------------------------------

SQLParser::Field_listContext::Field_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::FieldContext *> SQLParser::Field_listContext::field() {
  return getRuleContexts<SQLParser::FieldContext>();
}

SQLParser::FieldContext* SQLParser::Field_listContext::field(size_t i) {
  return getRuleContext<SQLParser::FieldContext>(i);
}


size_t SQLParser::Field_listContext::getRuleIndex() const {
  return SQLParser::RuleField_list;
}

void SQLParser::Field_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterField_list(this);
}

void SQLParser::Field_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitField_list(this);
}


std::any SQLParser::Field_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitField_list(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Field_listContext* SQLParser::field_list() {
  Field_listContext *_localctx = _tracker.createInstance<Field_listContext>(_ctx, getState());
  enterRule(_localctx, 14, SQLParser::RuleField_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    field();
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__39) {
      setState(239);
      match(SQLParser::T__39);
      setState(240);
      field();
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

SQLParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::FieldContext::getRuleIndex() const {
  return SQLParser::RuleField;
}

void SQLParser::FieldContext::copyFrom(FieldContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Primary_key_fieldContext ------------------------------------------------------------------

SQLParser::IdentifiersContext* SQLParser::Primary_key_fieldContext::identifiers() {
  return getRuleContext<SQLParser::IdentifiersContext>(0);
}

tree::TerminalNode* SQLParser::Primary_key_fieldContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Primary_key_fieldContext::Primary_key_fieldContext(FieldContext *ctx) { copyFrom(ctx); }

void SQLParser::Primary_key_fieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary_key_field(this);
}
void SQLParser::Primary_key_fieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary_key_field(this);
}

std::any SQLParser::Primary_key_fieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitPrimary_key_field(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Foreign_key_fieldContext ------------------------------------------------------------------

std::vector<SQLParser::IdentifiersContext *> SQLParser::Foreign_key_fieldContext::identifiers() {
  return getRuleContexts<SQLParser::IdentifiersContext>();
}

SQLParser::IdentifiersContext* SQLParser::Foreign_key_fieldContext::identifiers(size_t i) {
  return getRuleContext<SQLParser::IdentifiersContext>(i);
}

std::vector<tree::TerminalNode *> SQLParser::Foreign_key_fieldContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::Foreign_key_fieldContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}

SQLParser::Foreign_key_fieldContext::Foreign_key_fieldContext(FieldContext *ctx) { copyFrom(ctx); }

void SQLParser::Foreign_key_fieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_key_field(this);
}
void SQLParser::Foreign_key_fieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_key_field(this);
}

std::any SQLParser::Foreign_key_fieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitForeign_key_field(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Normal_fieldContext ------------------------------------------------------------------

tree::TerminalNode* SQLParser::Normal_fieldContext::Identifier() {
  return getToken(SQLParser::Identifier, 0);
}

SQLParser::Type_Context* SQLParser::Normal_fieldContext::type_() {
  return getRuleContext<SQLParser::Type_Context>(0);
}

tree::TerminalNode* SQLParser::Normal_fieldContext::Null() {
  return getToken(SQLParser::Null, 0);
}

SQLParser::ValueContext* SQLParser::Normal_fieldContext::value() {
  return getRuleContext<SQLParser::ValueContext>(0);
}

SQLParser::Normal_fieldContext::Normal_fieldContext(FieldContext *ctx) { copyFrom(ctx); }

void SQLParser::Normal_fieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNormal_field(this);
}
void SQLParser::Normal_fieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNormal_field(this);
}

std::any SQLParser::Normal_fieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitNormal_field(this);
  else
    return visitor->visitChildren(this);
}
SQLParser::FieldContext* SQLParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 16, SQLParser::RuleField);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::Identifier: {
        _localctx = _tracker.createInstance<SQLParser::Normal_fieldContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(246);
        match(SQLParser::Identifier);
        setState(247);
        type_();
        setState(250);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLParser::T__40) {
          setState(248);
          match(SQLParser::T__40);
          setState(249);
          match(SQLParser::Null);
        }
        setState(254);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLParser::T__41) {
          setState(252);
          match(SQLParser::T__41);
          setState(253);
          value();
        }
        break;
      }

      case SQLParser::T__33: {
        _localctx = _tracker.createInstance<SQLParser::Primary_key_fieldContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(256);
        match(SQLParser::T__33);
        setState(257);
        match(SQLParser::T__34);
        setState(259);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLParser::Identifier) {
          setState(258);
          match(SQLParser::Identifier);
        }
        setState(261);
        match(SQLParser::T__15);
        setState(262);
        identifiers();
        setState(263);
        match(SQLParser::T__16);
        break;
      }

      case SQLParser::T__35: {
        _localctx = _tracker.createInstance<SQLParser::Foreign_key_fieldContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(265);
        match(SQLParser::T__35);
        setState(266);
        match(SQLParser::T__34);
        setState(268);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLParser::Identifier) {
          setState(267);
          match(SQLParser::Identifier);
        }
        setState(270);
        match(SQLParser::T__15);
        setState(271);
        identifiers();
        setState(272);
        match(SQLParser::T__16);
        setState(273);
        match(SQLParser::T__37);
        setState(274);
        match(SQLParser::Identifier);
        setState(275);
        match(SQLParser::T__15);
        setState(276);
        identifiers();
        setState(277);
        match(SQLParser::T__16);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

SQLParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::Type_Context::Integer() {
  return getToken(SQLParser::Integer, 0);
}


size_t SQLParser::Type_Context::getRuleIndex() const {
  return SQLParser::RuleType_;
}

void SQLParser::Type_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_(this);
}

void SQLParser::Type_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_(this);
}


std::any SQLParser::Type_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitType_(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Type_Context* SQLParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 18, SQLParser::RuleType_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__42: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        match(SQLParser::T__42);
        break;
      }

      case SQLParser::T__43: {
        enterOuterAlt(_localctx, 2);
        setState(282);
        match(SQLParser::T__43);
        setState(283);
        match(SQLParser::T__15);
        setState(284);
        match(SQLParser::Integer);
        setState(285);
        match(SQLParser::T__16);
        break;
      }

      case SQLParser::T__44: {
        enterOuterAlt(_localctx, 3);
        setState(286);
        match(SQLParser::T__44);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_listsContext ------------------------------------------------------------------

SQLParser::Value_listsContext::Value_listsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::Value_listContext *> SQLParser::Value_listsContext::value_list() {
  return getRuleContexts<SQLParser::Value_listContext>();
}

SQLParser::Value_listContext* SQLParser::Value_listsContext::value_list(size_t i) {
  return getRuleContext<SQLParser::Value_listContext>(i);
}


size_t SQLParser::Value_listsContext::getRuleIndex() const {
  return SQLParser::RuleValue_lists;
}

void SQLParser::Value_listsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_lists(this);
}

void SQLParser::Value_listsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_lists(this);
}


std::any SQLParser::Value_listsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitValue_lists(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Value_listsContext* SQLParser::value_lists() {
  Value_listsContext *_localctx = _tracker.createInstance<Value_listsContext>(_ctx, getState());
  enterRule(_localctx, 20, SQLParser::RuleValue_lists);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    value_list();
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__39) {
      setState(290);
      match(SQLParser::T__39);
      setState(291);
      value_list();
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_listContext ------------------------------------------------------------------

SQLParser::Value_listContext::Value_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::ValueContext *> SQLParser::Value_listContext::value() {
  return getRuleContexts<SQLParser::ValueContext>();
}

SQLParser::ValueContext* SQLParser::Value_listContext::value(size_t i) {
  return getRuleContext<SQLParser::ValueContext>(i);
}


size_t SQLParser::Value_listContext::getRuleIndex() const {
  return SQLParser::RuleValue_list;
}

void SQLParser::Value_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_list(this);
}

void SQLParser::Value_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_list(this);
}


std::any SQLParser::Value_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitValue_list(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Value_listContext* SQLParser::value_list() {
  Value_listContext *_localctx = _tracker.createInstance<Value_listContext>(_ctx, getState());
  enterRule(_localctx, 22, SQLParser::RuleValue_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(SQLParser::T__15);
    setState(298);
    value();
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__39) {
      setState(299);
      match(SQLParser::T__39);
      setState(300);
      value();
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(306);
    match(SQLParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

SQLParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::ValueContext::Integer() {
  return getToken(SQLParser::Integer, 0);
}

tree::TerminalNode* SQLParser::ValueContext::String() {
  return getToken(SQLParser::String, 0);
}

tree::TerminalNode* SQLParser::ValueContext::Float() {
  return getToken(SQLParser::Float, 0);
}

tree::TerminalNode* SQLParser::ValueContext::Null() {
  return getToken(SQLParser::Null, 0);
}


size_t SQLParser::ValueContext::getRuleIndex() const {
  return SQLParser::RuleValue;
}

void SQLParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void SQLParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


std::any SQLParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ValueContext* SQLParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 24, SQLParser::RuleValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    _la = _input->LA(1);
    if (!(((((_la - 63) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 63)) & ((1ULL << (SQLParser::Null - 63))
      | (1ULL << (SQLParser::Integer - 63))
      | (1ULL << (SQLParser::String - 63))
      | (1ULL << (SQLParser::Float - 63)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Where_and_clauseContext ------------------------------------------------------------------

SQLParser::Where_and_clauseContext::Where_and_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::Where_clauseContext *> SQLParser::Where_and_clauseContext::where_clause() {
  return getRuleContexts<SQLParser::Where_clauseContext>();
}

SQLParser::Where_clauseContext* SQLParser::Where_and_clauseContext::where_clause(size_t i) {
  return getRuleContext<SQLParser::Where_clauseContext>(i);
}


size_t SQLParser::Where_and_clauseContext::getRuleIndex() const {
  return SQLParser::RuleWhere_and_clause;
}

void SQLParser::Where_and_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_and_clause(this);
}

void SQLParser::Where_and_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_and_clause(this);
}


std::any SQLParser::Where_and_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_and_clause(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Where_and_clauseContext* SQLParser::where_and_clause() {
  Where_and_clauseContext *_localctx = _tracker.createInstance<Where_and_clauseContext>(_ctx, getState());
  enterRule(_localctx, 26, SQLParser::RuleWhere_and_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    where_clause();
    setState(315);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__45) {
      setState(311);
      match(SQLParser::T__45);
      setState(312);
      where_clause();
      setState(317);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Where_clauseContext ------------------------------------------------------------------

SQLParser::Where_clauseContext::Where_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::Where_clauseContext::getRuleIndex() const {
  return SQLParser::RuleWhere_clause;
}

void SQLParser::Where_clauseContext::copyFrom(Where_clauseContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Where_in_listContext ------------------------------------------------------------------

SQLParser::ColumnContext* SQLParser::Where_in_listContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::Value_listContext* SQLParser::Where_in_listContext::value_list() {
  return getRuleContext<SQLParser::Value_listContext>(0);
}

SQLParser::Where_in_listContext::Where_in_listContext(Where_clauseContext *ctx) { copyFrom(ctx); }

void SQLParser::Where_in_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_in_list(this);
}
void SQLParser::Where_in_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_in_list(this);
}

std::any SQLParser::Where_in_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_in_list(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Where_operator_selectContext ------------------------------------------------------------------

SQLParser::ColumnContext* SQLParser::Where_operator_selectContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::Operator_Context* SQLParser::Where_operator_selectContext::operator_() {
  return getRuleContext<SQLParser::Operator_Context>(0);
}

SQLParser::Select_tableContext* SQLParser::Where_operator_selectContext::select_table() {
  return getRuleContext<SQLParser::Select_tableContext>(0);
}

SQLParser::Where_operator_selectContext::Where_operator_selectContext(Where_clauseContext *ctx) { copyFrom(ctx); }

void SQLParser::Where_operator_selectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_operator_select(this);
}
void SQLParser::Where_operator_selectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_operator_select(this);
}

std::any SQLParser::Where_operator_selectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_operator_select(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Where_nullContext ------------------------------------------------------------------

SQLParser::ColumnContext* SQLParser::Where_nullContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

tree::TerminalNode* SQLParser::Where_nullContext::Null() {
  return getToken(SQLParser::Null, 0);
}

SQLParser::Where_nullContext::Where_nullContext(Where_clauseContext *ctx) { copyFrom(ctx); }

void SQLParser::Where_nullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_null(this);
}
void SQLParser::Where_nullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_null(this);
}

std::any SQLParser::Where_nullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_null(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Where_operator_expressionContext ------------------------------------------------------------------

SQLParser::ColumnContext* SQLParser::Where_operator_expressionContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::Operator_Context* SQLParser::Where_operator_expressionContext::operator_() {
  return getRuleContext<SQLParser::Operator_Context>(0);
}

SQLParser::ExpressionContext* SQLParser::Where_operator_expressionContext::expression() {
  return getRuleContext<SQLParser::ExpressionContext>(0);
}

SQLParser::Where_operator_expressionContext::Where_operator_expressionContext(Where_clauseContext *ctx) { copyFrom(ctx); }

void SQLParser::Where_operator_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_operator_expression(this);
}
void SQLParser::Where_operator_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_operator_expression(this);
}

std::any SQLParser::Where_operator_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_operator_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Where_in_selectContext ------------------------------------------------------------------

SQLParser::ColumnContext* SQLParser::Where_in_selectContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::Select_tableContext* SQLParser::Where_in_selectContext::select_table() {
  return getRuleContext<SQLParser::Select_tableContext>(0);
}

SQLParser::Where_in_selectContext::Where_in_selectContext(Where_clauseContext *ctx) { copyFrom(ctx); }

void SQLParser::Where_in_selectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_in_select(this);
}
void SQLParser::Where_in_selectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_in_select(this);
}

std::any SQLParser::Where_in_selectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_in_select(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Where_like_stringContext ------------------------------------------------------------------

SQLParser::ColumnContext* SQLParser::Where_like_stringContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

tree::TerminalNode* SQLParser::Where_like_stringContext::String() {
  return getToken(SQLParser::String, 0);
}

SQLParser::Where_like_stringContext::Where_like_stringContext(Where_clauseContext *ctx) { copyFrom(ctx); }

void SQLParser::Where_like_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_like_string(this);
}
void SQLParser::Where_like_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_like_string(this);
}

std::any SQLParser::Where_like_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhere_like_string(this);
  else
    return visitor->visitChildren(this);
}
SQLParser::Where_clauseContext* SQLParser::where_clause() {
  Where_clauseContext *_localctx = _tracker.createInstance<Where_clauseContext>(_ctx, getState());
  enterRule(_localctx, 28, SQLParser::RuleWhere_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SQLParser::Where_operator_expressionContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(318);
      column();
      setState(319);
      operator_();
      setState(320);
      expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SQLParser::Where_operator_selectContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(322);
      column();
      setState(323);
      operator_();
      setState(324);
      match(SQLParser::T__15);
      setState(325);
      select_table();
      setState(326);
      match(SQLParser::T__16);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SQLParser::Where_nullContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(328);
      column();
      setState(329);
      match(SQLParser::T__46);
      setState(331);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLParser::T__40) {
        setState(330);
        match(SQLParser::T__40);
      }
      setState(333);
      match(SQLParser::Null);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SQLParser::Where_in_listContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(335);
      column();
      setState(336);
      match(SQLParser::T__47);
      setState(337);
      value_list();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SQLParser::Where_in_selectContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(339);
      column();
      setState(340);
      match(SQLParser::T__47);
      setState(341);
      match(SQLParser::T__15);
      setState(342);
      select_table();
      setState(343);
      match(SQLParser::T__16);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SQLParser::Where_like_stringContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(345);
      column();
      setState(346);
      match(SQLParser::T__48);
      setState(347);
      match(SQLParser::String);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnContext ------------------------------------------------------------------

SQLParser::ColumnContext::ColumnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SQLParser::ColumnContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::ColumnContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}


size_t SQLParser::ColumnContext::getRuleIndex() const {
  return SQLParser::RuleColumn;
}

void SQLParser::ColumnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn(this);
}

void SQLParser::ColumnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn(this);
}


std::any SQLParser::ColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitColumn(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ColumnContext* SQLParser::column() {
  ColumnContext *_localctx = _tracker.createInstance<ColumnContext>(_ctx, getState());
  enterRule(_localctx, 30, SQLParser::RuleColumn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(351);
      match(SQLParser::Identifier);
      setState(352);
      match(SQLParser::T__49);
      break;
    }

    default:
      break;
    }
    setState(355);
    match(SQLParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SQLParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ValueContext* SQLParser::ExpressionContext::value() {
  return getRuleContext<SQLParser::ValueContext>(0);
}

SQLParser::ColumnContext* SQLParser::ExpressionContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}


size_t SQLParser::ExpressionContext::getRuleIndex() const {
  return SQLParser::RuleExpression;
}

void SQLParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SQLParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any SQLParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ExpressionContext* SQLParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, SQLParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(359);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::Null:
      case SQLParser::Integer:
      case SQLParser::String:
      case SQLParser::Float: {
        enterOuterAlt(_localctx, 1);
        setState(357);
        value();
        break;
      }

      case SQLParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(358);
        column();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_clauseContext ------------------------------------------------------------------

SQLParser::Set_clauseContext::Set_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SQLParser::Set_clauseContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::Set_clauseContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}

std::vector<tree::TerminalNode *> SQLParser::Set_clauseContext::EqualOrAssign() {
  return getTokens(SQLParser::EqualOrAssign);
}

tree::TerminalNode* SQLParser::Set_clauseContext::EqualOrAssign(size_t i) {
  return getToken(SQLParser::EqualOrAssign, i);
}

std::vector<SQLParser::ValueContext *> SQLParser::Set_clauseContext::value() {
  return getRuleContexts<SQLParser::ValueContext>();
}

SQLParser::ValueContext* SQLParser::Set_clauseContext::value(size_t i) {
  return getRuleContext<SQLParser::ValueContext>(i);
}


size_t SQLParser::Set_clauseContext::getRuleIndex() const {
  return SQLParser::RuleSet_clause;
}

void SQLParser::Set_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet_clause(this);
}

void SQLParser::Set_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet_clause(this);
}


std::any SQLParser::Set_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitSet_clause(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Set_clauseContext* SQLParser::set_clause() {
  Set_clauseContext *_localctx = _tracker.createInstance<Set_clauseContext>(_ctx, getState());
  enterRule(_localctx, 34, SQLParser::RuleSet_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(SQLParser::Identifier);
    setState(362);
    match(SQLParser::EqualOrAssign);
    setState(363);
    value();
    setState(370);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__39) {
      setState(364);
      match(SQLParser::T__39);
      setState(365);
      match(SQLParser::Identifier);
      setState(366);
      match(SQLParser::EqualOrAssign);
      setState(367);
      value();
      setState(372);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectorsContext ------------------------------------------------------------------

SQLParser::SelectorsContext::SelectorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::SelectorContext *> SQLParser::SelectorsContext::selector() {
  return getRuleContexts<SQLParser::SelectorContext>();
}

SQLParser::SelectorContext* SQLParser::SelectorsContext::selector(size_t i) {
  return getRuleContext<SQLParser::SelectorContext>(i);
}


size_t SQLParser::SelectorsContext::getRuleIndex() const {
  return SQLParser::RuleSelectors;
}

void SQLParser::SelectorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectors(this);
}

void SQLParser::SelectorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectors(this);
}


std::any SQLParser::SelectorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitSelectors(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::SelectorsContext* SQLParser::selectors() {
  SelectorsContext *_localctx = _tracker.createInstance<SelectorsContext>(_ctx, getState());
  enterRule(_localctx, 36, SQLParser::RuleSelectors);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__50: {
        enterOuterAlt(_localctx, 1);
        setState(373);
        match(SQLParser::T__50);
        break;
      }

      case SQLParser::Count:
      case SQLParser::Average:
      case SQLParser::Max:
      case SQLParser::Min:
      case SQLParser::Sum:
      case SQLParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(374);
        selector();
        setState(379);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLParser::T__39) {
          setState(375);
          match(SQLParser::T__39);
          setState(376);
          selector();
          setState(381);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectorContext ------------------------------------------------------------------

SQLParser::SelectorContext::SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ColumnContext* SQLParser::SelectorContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::AggregatorContext* SQLParser::SelectorContext::aggregator() {
  return getRuleContext<SQLParser::AggregatorContext>(0);
}

tree::TerminalNode* SQLParser::SelectorContext::Count() {
  return getToken(SQLParser::Count, 0);
}


size_t SQLParser::SelectorContext::getRuleIndex() const {
  return SQLParser::RuleSelector;
}

void SQLParser::SelectorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelector(this);
}

void SQLParser::SelectorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelector(this);
}


std::any SQLParser::SelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitSelector(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::SelectorContext* SQLParser::selector() {
  SelectorContext *_localctx = _tracker.createInstance<SelectorContext>(_ctx, getState());
  enterRule(_localctx, 38, SQLParser::RuleSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(384);
      column();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(385);
      aggregator();
      setState(386);
      match(SQLParser::T__15);
      setState(387);
      column();
      setState(388);
      match(SQLParser::T__16);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(390);
      match(SQLParser::Count);
      setState(391);
      match(SQLParser::T__15);
      setState(392);
      match(SQLParser::T__50);
      setState(393);
      match(SQLParser::T__16);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifiersContext ------------------------------------------------------------------

SQLParser::IdentifiersContext::IdentifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SQLParser::IdentifiersContext::Identifier() {
  return getTokens(SQLParser::Identifier);
}

tree::TerminalNode* SQLParser::IdentifiersContext::Identifier(size_t i) {
  return getToken(SQLParser::Identifier, i);
}


size_t SQLParser::IdentifiersContext::getRuleIndex() const {
  return SQLParser::RuleIdentifiers;
}

void SQLParser::IdentifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifiers(this);
}

void SQLParser::IdentifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifiers(this);
}


std::any SQLParser::IdentifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitIdentifiers(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::IdentifiersContext* SQLParser::identifiers() {
  IdentifiersContext *_localctx = _tracker.createInstance<IdentifiersContext>(_ctx, getState());
  enterRule(_localctx, 40, SQLParser::RuleIdentifiers);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    match(SQLParser::Identifier);
    setState(401);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__39) {
      setState(397);
      match(SQLParser::T__39);
      setState(398);
      match(SQLParser::Identifier);
      setState(403);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_Context ------------------------------------------------------------------

SQLParser::Operator_Context::Operator_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::Operator_Context::EqualOrAssign() {
  return getToken(SQLParser::EqualOrAssign, 0);
}

tree::TerminalNode* SQLParser::Operator_Context::Less() {
  return getToken(SQLParser::Less, 0);
}

tree::TerminalNode* SQLParser::Operator_Context::LessEqual() {
  return getToken(SQLParser::LessEqual, 0);
}

tree::TerminalNode* SQLParser::Operator_Context::Greater() {
  return getToken(SQLParser::Greater, 0);
}

tree::TerminalNode* SQLParser::Operator_Context::GreaterEqual() {
  return getToken(SQLParser::GreaterEqual, 0);
}

tree::TerminalNode* SQLParser::Operator_Context::NotEqual() {
  return getToken(SQLParser::NotEqual, 0);
}


size_t SQLParser::Operator_Context::getRuleIndex() const {
  return SQLParser::RuleOperator_;
}

void SQLParser::Operator_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_(this);
}

void SQLParser::Operator_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_(this);
}


std::any SQLParser::Operator_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitOperator_(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::Operator_Context* SQLParser::operator_() {
  Operator_Context *_localctx = _tracker.createInstance<Operator_Context>(_ctx, getState());
  enterRule(_localctx, 42, SQLParser::RuleOperator_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQLParser::EqualOrAssign)
      | (1ULL << SQLParser::Less)
      | (1ULL << SQLParser::LessEqual)
      | (1ULL << SQLParser::Greater)
      | (1ULL << SQLParser::GreaterEqual)
      | (1ULL << SQLParser::NotEqual))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregatorContext ------------------------------------------------------------------

SQLParser::AggregatorContext::AggregatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::AggregatorContext::Count() {
  return getToken(SQLParser::Count, 0);
}

tree::TerminalNode* SQLParser::AggregatorContext::Average() {
  return getToken(SQLParser::Average, 0);
}

tree::TerminalNode* SQLParser::AggregatorContext::Max() {
  return getToken(SQLParser::Max, 0);
}

tree::TerminalNode* SQLParser::AggregatorContext::Min() {
  return getToken(SQLParser::Min, 0);
}

tree::TerminalNode* SQLParser::AggregatorContext::Sum() {
  return getToken(SQLParser::Sum, 0);
}


size_t SQLParser::AggregatorContext::getRuleIndex() const {
  return SQLParser::RuleAggregator;
}

void SQLParser::AggregatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregator(this);
}

void SQLParser::AggregatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregator(this);
}


std::any SQLParser::AggregatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAggregator(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::AggregatorContext* SQLParser::aggregator() {
  AggregatorContext *_localctx = _tracker.createInstance<AggregatorContext>(_ctx, getState());
  enterRule(_localctx, 44, SQLParser::RuleAggregator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQLParser::Count)
      | (1ULL << SQLParser::Average)
      | (1ULL << SQLParser::Max)
      | (1ULL << SQLParser::Min)
      | (1ULL << SQLParser::Sum))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SQLParser::initialize() {
  std::call_once(sqlParserOnceFlag, sqlParserInitialize);
}
