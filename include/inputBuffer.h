#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include <stdlib.h>
#include <stdio.h>

/* * * * * INPUT BUFFER DATA STRUCT AND FUNCTIONS * * * * */
typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();

void read_input(InputBuffer* input_buffer);

void close_input_buffer(InputBuffer* input_buffer);
/* * * * * * * * * */

#endif