#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

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
 * slide_line - slide & merge it to the left or to the right
 * @line: pointer to an arrray of int conteining size n
 * @size: Number of elements in line
 * @direction: directions
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction != 0)
		if (direction != 1)
			return (0);

	for (i=0, j=0; i < size;)
	{
		if (line[i] == 0)
		{
			while (line[i] == 0)
				i++;
		}
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
	}

	sort(line, size);

	if (direction == 0)
	{
		if (line[0] == 0)
		{
			for (i=0, j=0; i < size;)
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
	return (1);
}
