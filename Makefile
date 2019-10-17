CC=gcc
CFLAGS=-I.
DEPS = input_buffer.h meta_command.h sql_compiler.h
OBJ = cdb.o input_buffer.o meta_command.o sql_compiler.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cdb: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)