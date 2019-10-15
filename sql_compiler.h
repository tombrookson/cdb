#ifndef _SQL_COMPILER_H_
#define _SQL_COMPILER_H_

#include "input_buffer.h"

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNISED_STATEMENT
} PrepareResult;

typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

typedef struct {
  StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

void execute_statement(Statement* statement);

#endif // _SQL_COMPILER_H_