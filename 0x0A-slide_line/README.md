0x0A. 2048 (single line)
========================

To execute the game need to run as the next example:

```
alex@~/0x0A-slide_line$ gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
alex@~/0x0A-slide_line$ ./0-slide_line L 2 2 0 0
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
alex@~/0x0A-slide_line$ ./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
Line: 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4
Slide to the left
Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
alex@~/0x0A-slide_line$ ./0-slide_line R 2 2 2 2
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4
alex@~/0x0A-slide_line$ ./0-slide_line R 2 2 2 2 2
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4
```


Tasks
-----

#### 0\. Slide line

Reproduce the 2048 game mechanics on a single horizontal line.

Given an array of integers, we want to be able to slide & merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeros, should be merged (See example)

-   Function that slides and merges an array of integers
-   Prototype: `int slide_line(int *line, size_t size, int direction);`
-   Where `line` points to an array of integers containing `size` elements, that must be slided & merged to the direction represented by `direction`. `direction` can be either:
    -   `SLIDE_LEFT`
    -   `SLIDE_RIGHT`
-   If it is something else, the function must fail
-   Both macros `SLIDE_LEFT` and `SLIDE_RIGHT` must be defined in `slide_line.h`
-   Function return `1` upon success, or `0` upon failure