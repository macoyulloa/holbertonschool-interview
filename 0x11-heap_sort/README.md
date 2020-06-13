0x11. Heap Sort
===============

Tasks
-----

#### 0\. Heap sort

Write a function that sorts an array of integers in ascending ordr

-   Prototype: `void heap_sort(int *array, size_t size);`
-   You must implement the `sift-down` heap sort algorithm
-   You're expected to print the `array` after each time you swap two elements

```
to execute it:

alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
alex@/tmp/sort$ ./0-heap

```
