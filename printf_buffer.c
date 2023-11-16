#include "printf_buffer.h"

/**
* init_buffer - Initialize the buffer
* @buffer: The buffer to initialize
*/
void init_buffer(Buffer *buffer)
{
buffer->index = 0;
}

/**
* update_buffer - Update the buffer with a character
* @buffer: The buffer to update
* @c: The character to add to the buffer
*/
void update_buffer(Buffer *buffer, char c)
{
if (buffer->index >= BUFFER_SIZE)
flush_buffer(buffer);

buffer->data[buffer->index++] = c;
}

/**
* flush_buffer - Flush the buffer to the standard output
* @buffer: The buffer to flush
*/
void flush_buffer(Buffer *buffer)
{
if (buffer->index > 0)
{
write(1, buffer->data, buffer->index);
buffer->index = 0;
}
}

