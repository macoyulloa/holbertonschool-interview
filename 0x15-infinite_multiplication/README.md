0x15. Infinite Multiplication
=============================

Tasks
-----


#### 0\. Infinite Multiplication

Program that multiplies two positive numbers:

-   Usage: `mul num1 num2`
-   `num1` and `num2` will be passed in base 10
-   Print the result, followed by a new line
-   If the number of arguments is incorrect, print `Error`, followed by a new line, and exit with a status of `98`
-   `num1` and `num2` should only be composed of digits. If not, print `Error`, followed by a new line, and exit with a status of `98`
-   You are allowed to use more than 5 functions in your file

You can use `bc` (`man bc`) to check your results.

```
alexa@ubuntu:~/0x15-infinite_multiplication$ gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
alexa@ubuntu:~/0x15-infinite_multiplication$ ./mul 10 98
980
```
