#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @init: the start point to be printed
 * @end: end point to print
 */
void print_array(const int *array, size_t init, size_t end, size_t size)
{
	size_t start;

	start = init;

	printf("%zu init, %zu end, %zu size\n", init, end, size);
	if ((init == end) || (init == 0 && end == size - 1))
	{
	}
	else
	{
		printf("Searching in array: ");
		while (array && init < end)
		{
			if (init > 0 && start != init)
				printf(", ");
			printf("%d", array[init]);
			++init;
		}
		printf("\n");
	}
}

/**
 * binary_search - search the value into the array
 *
 * @array: pointer first element of the array to search in
 * @l: left size of the array to search in
 * @r: right size of the array to search in
 * @value: the value to search for
 * @size: size of the array
 * Return:  the index where value is located or -1 on failure
 */
int binary_search(int *array, size_t l, size_t r, int value, size_t size)
{
	int mid;

	if (r >= l)
	{
		mid = (l + (r - l) / 2);

		if (array[mid] == value)
		{
			print_array(array, 0, mid, size);
			return (mid);
		}
		if (array[mid] > value)
		{
			print_array(array, l, mid, size);
			return (binary_search(array, l, mid - 1, value, size));
		}
		print_array(array, mid, r, size);
		return (binary_search(array, mid + 1, r, value, size));
	}
	return (-1);
}

/**
 * advanced_binary - search the value into the array
 *
 * @array: pointer first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return:  the index where value is located or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	print_array(array, 0, size, size);
	return (binary_search(array, 0, size, value, size));
}
