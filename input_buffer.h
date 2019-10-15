#ifndef _INPUT_BUFFER_H_
#define _INPUT_BUFFER_H_

#include <stdlib.h>
#include <string.h>

typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();

void close_input_buffer(InputBuffer* input_buffer);

#endif // _INPUT_BUFFER_H_