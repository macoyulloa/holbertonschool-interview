Tasks
-----

#### 2D Menger sponge

Function that draws a 2D Menger Sponge

-   Prototype: `void menger(int level);`
-   Where `level` is the level of the Menger Sponge to draw
-   If `level` is lower than `0`, your function must do nothing
-   You're allowed to use the `math` library. Your program will be compiled using the `ld` flag `-lm`

Format:

-   Here, we will only draw a 2D version of the Menger sponge, but the principle is the same
-   A level `N` sponge is a 3x3 square of level `N-1` sponges, except for the center one, which is left empty
-   A level 0 sponge is represented by the `#` character
-   Examples:
    -   A level 0 sponge is a simple 1x1 square
    -   A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
    -   A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
    -   ...
-   TIP: The size of a level `N` Menger sponge is calculated as follows: `3^N`

### How to run it:

```
alex@~/0x0B-menger$ gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
alex@~/0x0B-menger$ ./0-menger 0
#
alex@~/0x0B-menger$ ./0-menger 1
###
# #
###
alex@~/0x0B-menger$ ./0-menger 2
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
alex@~/0x0B-menger$ ./0-menger 3
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
#########         #########
# ## ## #         # ## ## #
#########         #########
###   ###         ###   ###
# #   # #         # #   # #
###   ###         ###   ###
#########         #########
# ## ## #         # ## ## #
#########         #########
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
```

