#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    SIMPLE WRAPPER FOR INPUT BUFFER
*/
typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer() 
{
  InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

/*
    INPUT PROMPT FOR USER; WILL OUTPUT 'cdb > '
*/
void print_prompt()
{
    printf("cdb > ");
}

/*
    READ IN USER INPUT
*/
void read_input(InputBuffer* input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    
    input_buffer->input_length = bytes_read - 1; // Ignore trailing newline
    input_buffer->buffer[bytes_read - 1] = 0;
}

/*
    D-STROY INPUT BUFFER!
*/
void close_input_buffer(InputBuffer* input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}


int main(int argc, char* argv[]) {
  InputBuffer* input_buffer = new_input_buffer();
  while (1) {
    print_prompt();
    read_input(input_buffer);

    if (strcmp(input_buffer->buffer, ".exit") == 0) {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s'.\n", input_buffer->buffer);
    }
  }
}