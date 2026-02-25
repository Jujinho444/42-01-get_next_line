*This project has been created as part of the 42 curriculum by <aganz>

# **Description**

Get Next Line
*This project implements a function that returns one line at a time from a file descriptor*
Get Next Line (GNL) is a function that returns **one line at a time** from a file descriptor, without losing the reading position between calls.
It must handle arbitrarily long lines, work for any valid file descriptor, and respect strict memory usage rules.

This project trains:
- static variables
- file descriptors and 'read()' function
- dynamic memory allocation
- handling edge cases and EOF behaviour

# **Instructions**

## Mandatory Part

Allowed files
- 'get_next_line.c'
- 'get_next_line_utils.c'
- 'get_next_line.h'

How to compile
Use: 'cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl'
get_next_line() returns:
- the next line (including the \n if present)
- NULL when EOF is reached or an error occurs or memory allocation fails

## Bonus Part

Allowed additional files
- 'get_next_line_bonus.c'
- 'get_next_line_utils_bonus.c'
- 'get_next_line_bonus.h'

The bonus adds:
- Support multiple file descriptors at once (each FD keeps its own reading state)
- Still only one static variable, now indexed per FD

How to compile
Use: 'cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus'

# **Resources**

These resources were used while studying and implementing the project:
- man pages 'read()', 'open()', 'close()', 'malloc()', 'free()'
- get_next_line project pdf
- various tests created for debugging (Valgrind, multiple BUFFER_SIZE tests, multi FD and edge case tests)

