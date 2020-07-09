Heap Insert

Tasks
-----

#### 0\. Heap - Extract

Funtion that extracts the root node of a Max Binary Heap:

-   Prototype: `int heap_extract(heap_t **root);`
-   `root` is a double pointer to the root node of the heap
-   Your function must return the value stored in the root node
-   The root node must be freed and replace with the last `level-order` node of the heap
-   Once replaced, the heap must be rebuilt if necessary
-   If your function fails, return `0`


```
lex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
alex@/tmp/binary_trees$ valgrind ./0-heap_extract
==29133== Memcheck, a memory error detector
```

