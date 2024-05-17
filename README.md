# get_next_line

## Description
`get_next_line` is a function that reads a line from a file descriptor, returning it as a string. It allows you to read text files one line at a time, which can be useful for processing large files or streams of input.

## Project Structure
- **Function Name:** `get_next_line`
- **Prototype:** `char *get_next_line(int fd);`
- **Turn in Files:** `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
- **Parameters:**
  - `fd`: The file descriptor to read from.
- **Return Value:**
  - Returns the read line on correct behavior.
  - Returns `NULL` if there is nothing else to read or an error occurred.
- **External Functions Used:** `read`, `malloc`, `free`
- **Compiler Option:** Add `-D BUFFER_SIZE=n` to your compiler call to define the buffer size.

## Requirements
- The `get_next_line` function must handle repeated calls (e.g., using a loop) to read from the file descriptor one line at a time.
- The function should return the line that was read, including the terminating `\n` character, except if the end of the file is reached and does not end with a `\n`.
- If there is nothing else to read or if an error occurred, the function should return `NULL`.
- Ensure that the function works as expected both when reading from a file and from the standard input.
- The header file `get_next_line.h` must contain at least the prototype of the `get_next_line` function.
- Add all helper functions in the `get_next_line_utils.c` file.
