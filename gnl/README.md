*This project has been created as part of the 42 curriculum by marvin.*

# get_next_line

## Description

**get_next_line** is a C programming project from the 42 curriculum whose goal is to implement a function capable of reading and returning one line at a time from a file descriptor, ending with a newline character (`\n`) when present, or returning `NULL` once the end of file (EOF) is reached or an error occurs.

The primary learning objectives of this project include:
- Understanding and properly managing **static variables** in C so state persists across sequential function calls.
- Performing low-level buffered file I/O using the `read()` system call with an arbitrary compile-time `BUFFER_SIZE`.
- Managing dynamic heap memory cleanly with `malloc()` and `free()` without memory leaks or invalid reads/writes across varying buffer sizes (from `BUFFER_SIZE = 1` up to `BUFFER_SIZE = 10000000+`).

---

## Instructions

### Compilation

Because `get_next_line` is a library function rather than a standalone executable, compile it alongside your own `main.c` test file using `cc` with the required 42 flags and a defined `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

You can test different buffer sizes by changing the `-D BUFFER_SIZE=<n>` flag (for example, `1`, `42`, `9999`, or `10000000`). If `BUFFER_SIZE` is omitted at compile time, it defaults to `42` as defined in `get_next_line.h`.

### Execution & Usage Example

Include `"get_next_line.h"` in your C source file and call `get_next_line(fd)` inside a loop until it returns `NULL`, freeing each returned line after use:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Run the compiled test binary:

```bash
./gnl_test
```

---

## Algorithm & Data Structure Explanation

### Data Structures

This implementation separates persistent read-buffer state from per-call line construction using two structures defined in `get_next_line.h`:

1. **`t_BUFFER` (Persistent Static Buffer):**
   - `char buffer[BUFFER_SIZE + 1]`: Stores raw bytes retrieved directly from `read()`.
   - `size_t remains_num`: Tracks the total number of valid bytes currently stored in `buffer`.
   - `size_t buf_index`: Tracks the current read cursor within `buffer` across consecutive calls to `get_next_line()`.
   - `char consum_f`: Flag indicating whether the active chunk in `buffer` has been fully consumed and requires a new `read()` call.

2. **`t_gnl` (Per-Line Dynamic Builder):**
   - `char *line`: Dynamically allocated character array holding the line being assembled.
   - `size_t current_index`: Tracks the current write length inside `line`.
   - `size_t line_size`: Tracks the current allocated capacity of `line`.
   - `char completed_f`: Flag indicating that a `\n` character has been encountered and the line is ready to return.

### Algorithm Walkthrough

1. **Validation & Initialization:** `get_next_line(int fd)` validates `fd >= 0` and `BUFFER_SIZE > 0`, then initializes a fresh `t_gnl` builder with an initial capacity of `BUFFER_SIZE + 1`.
2. **Buffered Reading (`fill_buffer`):** Whenever the static `t_BUFFER` has no unconsumed bytes left (`consum_f` is set or `remains_num == 0`), `read(fd, buffer->buffer, BUFFER_SIZE)` refills the buffer. If `read()` returns `0` (EOF), the loop terminates and returns any accumulated partial line (or `NULL` if nothing was read). If `read()` returns `-1` (error), all allocated memory is freed and `NULL` is returned.
3. **Incremental Scanning & Growth (`copy_until_nl` & `grow_line`):** Characters are copied from `buffer` into `line` starting at `buf_index` until either a `\n` is encountered or `remains_num` is reached. Whenever `line` approaches capacity (`current_index + 2 >= line_size`), `ft_realloc()` expands `line` by `BUFFER_SIZE + 1` bytes in linear amortized steps, avoiding quadratic $O(n^2)$ string-concatenation overhead on very long lines.
4. **Line Termination & State Preservation (`process_buffer_to_line`):** Once `\n` is reached, it is appended to `line`, `buf_index` advances past the newline so the next call resumes seamlessly from the remaining bytes in `static t_BUFFER`, `line` is null-terminated, and the resulting `char *` is returned to the caller.

---

## Resources

- **Linux Manual Pages:** `man 2 read`, `man 3 malloc`, `man 3 free`, `man 2 open`
- **42 Documentation & Subject PDF:** Official `get_next_line` project specification and Norminette v4 coding standard guidelines.
- **Testing Suites:** [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester) and [xicodomingues/francinette](https://github.com/xicodomingues/francinette) for edge-case validation across varying `BUFFER_SIZE` values.

### AI Usage

AI tools were used during development to review edge-case memory management (handling `read()` error paths and `realloc` failure cleanup), diagnose newline boundary conditions across large buffer sizes, and structure this `README.md` according to 42 documentation standards. All code logic and implementation decisions were written, tested, and verified by the author.