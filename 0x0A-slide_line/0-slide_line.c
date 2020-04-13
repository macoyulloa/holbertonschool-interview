#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * swap - swaps the position of two number in an array
 * @min_n: minimun number
 * @n: bigger number
 */
void swap(int *min_n, int *n)
{
	int temp = *min_n;
	*min_n = *n;
	*n = temp;
}

/**
 * sort - sorting an array of ints
 * @line: pointer to a first number
 * @size: size of the array
 */
void sort(int *line, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < (size - 1); ++i)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (line[j] < line[min_idx])
				min_idx = j;

		swap(&line[min_idx], &line[i]);
	}
}

/**
 * left - if the case if move to the direction left
 * @line: pointer to a first number
 * @size: size of the array
 */
void left(int *line, size_t size)
{
	size_t i, j;

	if (line[0] == 0)
	{
		for (i = 0, j = 0; i < size;)
		{
			if (line[i] != 0)
			{
				line[j] = line[i];
				line[i] = 0;
				j++;
			}
			i++;
		}
	}
}

/**
 * slide_line - slide & merge it to the left or to the right
 * @line: pointer to an arrray of int conteining size n
 * @size: Number of elements in line
 * @direction: directions
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
		{
			while (line[i] == 0)
				i++;
		}
		if (i == (size - 1))
			break;
		j = i + 1;
		if (line[j] == 0)
		{
			while (line[j] == 0)
				j++;
		}
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}
	sort(line, size);

	if (direction == 0)
		left(line, size);

	return (1);
}
