#ifndef PRINTF_BUFFER_H
#define PRINTF_BUFFER_H

#include <unistd.h>

#define BUFFER_SIZE 1024

/**
* struct Buffer - A buffer for managing characters before writing to output
* @data: The character array to store buffered data
* @index: The current index in the buffer
*/
typedef struct Buffer
{
char data[BUFFER_SIZE];
int index;
} Buffer;

void init_buffer(Buffer *buffer);
void update_buffer(Buffer *buffer, char c);
void flush_buffer(Buffer *buffer);

#endif /* PRINTF_BUFFER_H */

