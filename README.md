<h2 align=center>
  GET_NEXT_LINE
</h2>
<h2 align=center>

  ![GNL Logo](https://github.com/ericlespiana/erpiana-utils/blob/master/get_next_linem.png)
</h2>

The **get_next_line** project is a fundamental project that aims to develop a function capable of reading a line from a file descriptor. It allows you to retrieve the next line from a file, one line at a time, without reading the entire file at once. The function is designed to be memory efficient and work seamlessly with multiple file descriptors.

## Description

**get_next_line** is a function that reads a line from a file descriptor. It allows you to retrieve the next line from a file, one line at a time, without having to read the entire file at once. The function is designed to be memory efficient and to work seamlessly with multiple file descriptors.

This project is part of the curriculum at 42 school and is aimed at enhancing your understanding of file manipulation, memory allocation, and static variables.

---

## Features

- Retrieves the next line from a file descriptor
- Handles multiple file descriptors concurrently
- Memory efficient - reads and stores only the necessary data
- Supports reading from different types of files, including text files and binary files

## How to use
1. Install:
   ```
   git clone git@github.com:ericlespiana/get_next_line.git
2. Inside the project's dir create a file.txt like:
   ```
   GNL is a very nice project.
   In it I learned how to resolve memory leaks
   And how to efficiently handle dynamic allocations
   ```
3. Create a `main.c` file

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd)); // GNL is a very nice project.
	printf("%s", get_next_line(fd)); // In it I learned how to resolve memory leaks
	printf("%s", get_next_line(fd)); // And how to efficiently handle dynamic allocations
	close(fd);
}
```
## Compilation
When compiling `get_next_line` or its **bonus** version, be sure to include the following flags

```sh
$ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx <files>.c
```

<p>Where the `xxx` can be substituted by the number of bytes read at a time into the buffer for the `read` function.</p>
<p></p>If you won't, the buffer will be set to 42 automatically</p>
   
