#ifndef _SQL_COMPILER_H_
#define _SQL_COMPILER_H_

#include <stdint.h>

#include "input_buffer.h"

typedef enum {
  EXECUTE_SUCCESS,
  EXECUTE_TABLE_FULL
} ExecuteResult;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_SYNTAX_ERROR,
  PREPARE_UNRECOGNISED_STATEMENT
} PrepareResult;

typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
typedef struct {
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE];
  char email[COLUMN_USERNAME_SIZE];
} Row;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

const uint32_t ID_SIZE;
const uint32_t USERNAME_SIZE;
const uint32_t EMAIL_SIZE;
const uint32_t ID_OFFSET;
const uint32_t USERNAME_OFFSET;
const uint32_t EMAIL_OFFSET;
const uint32_t ROW_SIZE;

const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100
const uint32_t ROWS_PER_PAGE;
const uint32_t TABLE_MAX_ROWS;

typedef struct {
  uint32_t num_rows;
  void* pages[TABLE_MAX_PAGES];
} Table;


PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

void print_row(Row* row);

void serialize_row(Row* source, void* destination);

void deserialize_row(void* source, Row* destination);

void row_slot(Table* table, uint32_t row_num);

ExecuteResult execute_insert(Statement* statement, Table* table);

ExecuteResult execute_select(Statement* statement, Table* table);

ExecuteResult execute_statement(Statement* statement, Table* table);

Table* new_table();

void free_table(Table* table);

#endif // _SQL_COMPILER_H_