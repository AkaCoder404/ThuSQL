
#include "SQLBaseVisitor.h"
#include "../../backend/defs.h"
#include "../database/dbms.h"
#include "../database/table.h"
#include <vector>


// bool parse_table_header(table_header *header, SQLParser::Create_tableContext *ctx);
// bool parser_rows(SQLParser::Insert_into_tableContext *ctx);
 
class MySQLVisitor : public SQLBaseVisitor {
public:
  bool parse_table_header(table_header *header, SQLParser::Create_tableContext *ctx);
  bool parser_rows(SQLParser::Insert_into_tableContext *ctx);
public:
  std::any visitProgram(SQLParser::ProgramContext* ctx) override {
    vprint("visit program");
    return this->visitChildren(ctx);
  }

  std::any visitStatement(SQLParser::StatementContext* ctx) override {
    vprint("visit statement");
    return this->visitChildren(ctx);
  }

  std::any visitCreate_db(SQLParser::Create_dbContext* ctx) override {
    vprint("create db");
    const char *database_name = (ctx->Identifier()->toString()).c_str();
    dbms::get_instance()->create_database(database_name);
    dprint("Created database");
    return this->visitChildren(ctx);
  }

  std::any visitDrop_db(SQLParser::Drop_dbContext *ctx) override {
    vprint("visit drop db");
    const char *database_name = (ctx->Identifier()->toString()).c_str();
    dbms::get_instance()->drop_database(database_name);
    return this->visitChildren(ctx);
  }

  std::any visitShow_db(SQLParser::Show_dbContext *ctx) override {
    vprint("visit show db");
    const char *database_name = (ctx->Identifier()->toString()).c_str();
    dbms::get_instance()->show_database(database_name);
    dprint("Showed database");
    return this->visitChildren(ctx);
  }

  std::any visitShow_dbs(SQLParser::Show_dbsContext *ctx) override {
    vprint("visit show dbs");
    dbms::get_instance()->show_databases();
    dprint("Showed databases");
    return this->visitChildren(ctx);
  }

  std::any visitUse_db(SQLParser::Use_dbContext *ctx) override {
    vprint("visit use db");
    const char *database_name = (ctx->Identifier()->toString()).c_str();
    dbms::get_instance()->open_database(database_name);
    dprint("Using database");
    return this->visitChildren(ctx);
  }

  std::any visitShow_tables(SQLParser::Show_tablesContext *ctx) override {
    vprint("visit show tables");
    dbms::get_instance()->show_tables();
    return this->visitChildren(ctx);
  }

  std::any visitShow_indexes(SQLParser::Show_indexesContext *ctx) override {
    vprint("visit show indexes");
    return this->visitChildren(ctx);
  }

  std::any visitLoad_data(SQLParser::Load_dataContext *ctx) override {
    vprint("visit load data");
    return this->visitChildren(ctx);
  }

  std::any visitDump_data(SQLParser::Dump_dataContext *ctx) override {
    vprint("visit dump data");
    return this->visitChildren(ctx);
  }

  std::any visitCreate_table(SQLParser::Create_tableContext *ctx) override {
    vprint("visit create table");
    // table info
    const char *table_name = (ctx->Identifier()->toString()).c_str();
    table_header *header = new table_header;
    // fill table header, create table
    if (parse_table_header(header, ctx)) {
      dbms::get_instance()->create_table(header);
    } else {
      eprint("error parsing table");
    }
    dprint("Created table");
    return this->visitChildren(ctx);
  }

  std::any visitDrop_table(SQLParser::Drop_tableContext *ctx) override {
    vprint("visit drop table");
    const char *table_name = (ctx->Identifier()->toString()).c_str();
    dbms::get_instance()->drop_table(table_name);
    return this->visitChildren(ctx);
  }

  std::any visitDescribe_table(SQLParser::Describe_tableContext *ctx) override {
    vprint("visit describe table");
    const char *table_name = (ctx->Identifier()->toString()).c_str();
    dbms::get_instance()->show_table(table_name);
    dprint("DESC table finished");
    return this->visitChildren(ctx);
  }

  std::any visitInsert_into_table(SQLParser::Insert_into_tableContext *ctx) override {
    vprint("visit insert into table");
    // table information
    const char *table_name = (ctx->Identifier()->toString()).c_str();







    dbms::get_instance()->insert_rows(ctx);
    // parser_rows(ctx);
    dprint("Inserted rows");
    return this->visitChildren(ctx);
  }

  std::any visitDelete_from_table(SQLParser::Delete_from_tableContext *ctx) override {
    vprint("visit delete from table");  // DELETE FROM table_name WHERE
    // table identifier
    std::string table_name = ctx->Identifier()->getText();

    // handle where clause
    std::vector<struct WhereContext> where_clause_context;
    if (ctx->where_and_clause()) { 
      std::vector<SQLParser::Where_clauseContext *, 
                  std::allocator<SQLParser::Where_clauseContext *>> 
                  where_and_clause = ctx->where_and_clause()->where_clause();
                  

      for (auto e : where_and_clause) {
        struct WhereContext temp;  
        temp.column = e->children.at(0)->getText();
        temp.op =  e->children.at(1)->getText();
        temp.value = e->children.at(2)->getText();
        where_clause_context.push_back(temp);
      }
    }

    dbms::get_instance()->delete_rows(table_name.c_str(), where_clause_context);
    // return NULL;
    return this->visitChildren(ctx);
  }

  std::any visitUpdate_table(SQLParser::Update_tableContext *ctx) override {  
    vprint("visit update table");
    // table identifier
    std::string table_name = ctx->Identifier()->getText();
    // handle set clause

    SQLParser::Set_clauseContext *set_clause = ctx->set_clause();
    std::vector<struct SetContext> set;
    int count = 0;
    for (auto e: set_clause->value()) {
      struct SetContext temp;
      temp.column = set_clause->Identifier().at(count)->getText();
      temp.value = e->getText();
      // std::cout <<  set_clause->Identifier().at(count)->getText() << " ";
      // std::cout << e->getText() << "\n";  

      set.push_back(temp);
      count++;
    }

    // handle where clause
    std::vector<struct WhereContext> where_clause_context;
    if (ctx->where_and_clause()) { 
      std::vector<SQLParser::Where_clauseContext *, 
                  std::allocator<SQLParser::Where_clauseContext *>> 
                  where_and_clause = ctx->where_and_clause()->where_clause();
                  

      for (auto e : where_and_clause) {
        struct WhereContext temp;  
        temp.column = e->children.at(0)->getText();
        temp.op =  e->children.at(1)->getText();
        temp.value = e->children.at(2)->getText();
        where_clause_context.push_back(temp);
      }
    }

    dbms::get_instance()->update_rows(table_name.c_str(), where_clause_context, set);
    return this->visitChildren(ctx);
  }

   std::any visitSelect_table_(SQLParser::Select_table_Context *ctx) override {
    vprint("visit select table_");
    return this->visitChildren(ctx);
  }

  std::any visitSelect_table(SQLParser::Select_tableContext *ctx) override {
    vprint("visit select table");


    // later handle multiple identifiers? (multiple table names?)
    antlr4::tree::TerminalNode * table_name = ctx->identifiers()->Identifier().at(0);
    
    
    // get selectors and put into vector of strings
    SQLParser::SelectorsContext *selectors_context = ctx->selectors();
    std::vector<std::string> selectors;
    for (auto e : selectors_context->selector()) {
      selectors.push_back(e->getText());
    }


    // handle where clause, TODO: support AND, OR, NOT clause relationship
    // vector<column, operator, expression>
    std::vector<struct WhereContext> where_clause_context;
    if (ctx->where_and_clause()) { 
      std::vector<SQLParser::Where_clauseContext *, 
                  std::allocator<SQLParser::Where_clauseContext *>> 
                  where_and_clause = ctx->where_and_clause()->where_clause();
                  

      for (auto e : where_and_clause) {
        struct WhereContext temp;  
        temp.column = e->children.at(0)->getText();
        temp.op =  e->children.at(1)->getText();
        temp.value = e->children.at(2)->getText();
        where_clause_context.push_back(temp);
      }
    }

    dbms::get_instance()->select_rows(selectors, where_clause_context, table_name->getText().c_str());
    return this->visitChildren(ctx);
  }

  std::any visitAlter_add_index(SQLParser::Alter_add_indexContext *ctx) override {
    vprint("visit alter add index");
    return this->visitChildren(ctx);
  }

  std::any visitAlter_drop_index(SQLParser::Alter_drop_indexContext *ctx) override {
    vprint("visit alter drop index");
    return this->visitChildren(ctx);
  }

  std::any visitAlter_table_drop_pk(SQLParser::Alter_table_drop_pkContext *ctx) override {
    vprint("visit alter table drop pk");
    return this->visitChildren(ctx);
  }

  std::any visitAlter_table_drop_foreign_key(SQLParser::Alter_table_drop_foreign_keyContext *ctx) override {
    vprint("visit alter table drop foreign key");
    return this->visitChildren(ctx);
  }

  std::any visitAlter_table_add_pk(SQLParser::Alter_table_add_pkContext *ctx) override {
    vprint("visit alter table add pk");
    return this->visitChildren(ctx);
  }

  std::any visitAlter_table_add_foreign_key(SQLParser::Alter_table_add_foreign_keyContext *ctx) override {
    vprint("visit alter table add foreign key");
    return this->visitChildren(ctx);
  }

  std::any visitAlter_table_add_unique(SQLParser::Alter_table_add_uniqueContext *ctx) override {
    vprint("visit alter table add unique");
    return this->visitChildren(ctx);
  }

  std::any visitField_list(SQLParser::Field_listContext *ctx) override {
    vprint("visit field list");
    return this->visitChildren(ctx);
  }

  std::any visitNormal_field(SQLParser::Normal_fieldContext *ctx) override {
    vprint("visit normal field");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitPrimary_key_field(SQLParser::Primary_key_fieldContext *ctx) override {
    vprint("visit primary key field");
    return this->visitChildren(ctx);
  }

  std::any visitForeign_key_field(SQLParser::Foreign_key_fieldContext *ctx) override {
    vprint("visit foreign key field");
    return this->visitChildren(ctx);
  }

  std::any visitType_(SQLParser::Type_Context *ctx) override {
    vprint("visit type");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitValue_lists(SQLParser::Value_listsContext *ctx) override {
    vprint("visit value lists");
    return this->visitChildren(ctx);
  }

  std::any visitValue_list(SQLParser::Value_listContext *ctx) override {
    vprint("visit value list");
    return this->visitChildren(ctx);
  }

  std::any visitValue(SQLParser::ValueContext *ctx) override {
    vprint("visit value");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitWhere_and_clause(SQLParser::Where_and_clauseContext *ctx) override {
    vprint("visit where and clause");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitWhere_operator_expression(SQLParser::Where_operator_expressionContext *ctx) override {
    vprint("where operator expressions");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitWhere_operator_select(SQLParser::Where_operator_selectContext *ctx) override {
    vprint("visit where operator select");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitWhere_null(SQLParser::Where_nullContext *ctx) override {
    vprint("visit where null");
    return this->visitChildren(ctx);
  }

  std::any visitWhere_in_list(SQLParser::Where_in_listContext *ctx) override {
    vprint("visit where in list");
    return this->visitChildren(ctx);
  }

  std::any visitWhere_in_select(SQLParser::Where_in_selectContext *ctx) override {
    vprint("visit where in select");
    return this->visitChildren(ctx);
  }

  std::any visitWhere_like_string(SQLParser::Where_like_stringContext *ctx) override {
    vprint("visit where like string");
    return this->visitChildren(ctx);
  }

  std::any visitColumn(SQLParser::ColumnContext *ctx) override {
    vprint("visit column");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitExpression(SQLParser::ExpressionContext *ctx) override {
    vprint("visit expression");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitSet_clause(SQLParser::Set_clauseContext *ctx) override {
    vprint("visit set clause");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitSelectors(SQLParser::SelectorsContext *ctx) override {
    vprint("visit selectors");
    return this->visitChildren(ctx);
  }

  std::any visitSelector(SQLParser::SelectorContext *ctx) override {
    vprint("visit selector");
    // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitIdentifiers(SQLParser::IdentifiersContext *ctx) override {
    vprint("visit identifier");
    // // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitOperator_(SQLParser::Operator_Context *ctx) override {
    vprint("visit operator");
    // // std::cout << ctx->getText() << "\n";
    return this->visitChildren(ctx);
  }

  std::any visitAggregator(SQLParser::AggregatorContext *ctx) override {
    vprint("visit aggregator");
    return this->visitChildren(ctx);
  }



};

bool MySQLVisitor::parse_table_header(table_header *header,SQLParser::Create_tableContext *ctx) {
  // copy table name over
  std::strncpy(header->table_name, (ctx->Identifier()->getText()).c_str(), MAX_TABLE_NAME_LEN);
  
  SQLParser::Field_listContext* field_list = ctx->field_list();
  std::vector<SQLParser::FieldContext *, 
    std::allocator<SQLParser::FieldContext *>> field = field_list->field();
  
  // std::cout << "field list: " << field_list->getText() << "\n";

  int col_number = 0;
  int col_offset = 4; // first four bytes of record is saved for rowid;
  
  for (SQLParser::FieldContext *e : field) {
    // std::cout << e->getText() << ": " << e->children.size()  << ": " << "\n";
   
    // TODO: handle primary key
    if (e->getText().find("PRIMARYKEY(") != std::string::npos) {
      SQLParser::Primary_key_fieldContext *pk_context = (SQLParser::Primary_key_fieldContext *) e;
      
      // primary key list of identifiers
      // std::cout << "primary: " << pk_context->identifiers()->Identifier().size() << "\n";
      continue;
    }

    // TODO: handle foreign key
    if (e->getText().find("FOREIGNKEY(") != std::string::npos) {
      SQLParser::Foreign_key_fieldContext *fk_context = (SQLParser::Foreign_key_fieldContext *) e;
      
      // // foreign key col
      // std::cout << "foreign:  " << fk_context->identifiers().size() << "\n";

      // // foreign key reference col (name of other tables cols)
      // std::cout << "foregin:  " << fk_context->Identifier().size() << "\n";
      
      
      // for (auto * p : fk_context->identifiers()) {
      //   std::cout << p->getText() << "\n";
      // }

      continue;
    }
  

    // handle normal field
    SQLParser::Normal_fieldContext *norm_context = (SQLParser::Normal_fieldContext *) e;
    // col name
    std::string col_name = norm_context->Identifier()->getText();
    std::strncpy(header->col_name[col_number], col_name.c_str(), MAX_TABLE_NAME_LEN);
    // std::cout << norm_context->Identifier()->getText() << "\n";
   
    //  col_type and col_offset
    std::string col_type = norm_context->type_()->getText();
    // std::cout << "col_type: " << norm_context->type_()->getText() << "\n";


    if (col_type == "INT") {
      header->col_type[col_number] = FIELD_TYPE_INT;
      header->col_length[col_number] = 4;
    } else if (col_type == "FLOAT") {
      header->col_type[col_number] = FIELD_TYPE_FLOAT;
      header->col_length[col_number] = 4;
    } else {
      header->col_type[col_number] = FIELD_TYPE_VCHAR;
      header->col_length[col_number] = std::stoi(norm_context->type_()->Integer()->getText());
    }

    // NOT NULL
    if (e->getText().find("NOTNULL") != std::string::npos) header->flag_notnull |= 1 << col_number;

    // update offset
    header->col_offset[col_number] = col_offset;
    col_offset += header->col_length[col_number];

    // col value
    SQLParser::ValueContext *v_contex = norm_context->value();
    // NOT NULL
    if (!v_contex) {
      std::cout << "NO DEFAULT\n";
      col_number++;
      continue;
    }

    // handle defualt values
    if (v_contex->Null()) {
      std::strncpy(header->default_values[col_number], "NULL", MAX_DEFAULT_LEN);
    } else if (v_contex->Integer()) {
      // std::cout << "INTEGER: " << v_contex->Integer()->getText() << "\n";
      std::strncpy(header->default_values[col_number], v_contex->Integer()->getText().c_str(), MAX_DEFAULT_LEN);
    } else if (v_contex->Float()) {
      // std::cout << "FLOAT: " << v_contex->Float()->getText() << "\n";
      std::strncpy(header->default_values[col_number], v_contex->Float()->getText().c_str(), MAX_DEFAULT_LEN);
    } else if (v_contex->String()) {
      // std::cout << "VARCHAR(" << norm_context->type_()->Integer()->getText() << "): " << v_contex->String()->getText() << "\n";
      std::strncpy(header->default_values[col_number], v_contex->String()->getText().c_str(), MAX_DEFAULT_LEN);
    } 

    col_number++;
    header->flag_default |= 1 << col_number; // default flag, which cols have default
  }
  header->col_num = col_number;
  header->auto_increment_row_id = 1;
  return true;
}
