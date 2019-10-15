#ifndef _META_COMMAND_H_
#define _META_COMMAND_H_

#include "input_buffer.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNISED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif // _META_COMMAND_H_