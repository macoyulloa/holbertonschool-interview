#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @init: the start point to be printed
 * @end: end point to print
 */
void print_array(const int *array, size_t init, size_t end)
{
	size_t start;

	start = init;
	if (init == end)
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
 * @l_p:left range of the array to be printed
 * @r_p: right range of the array to be printed
 * Return:  the index where value is located or -1 on failure
 */
int binary_search(int *array, size_t l, size_t r, int value,
		  size_t l_p, size_t r_p)
{
	int mid;

	print_array(array, l_p, r_p);
	if (r >= l)
	{
		mid = (l + (r - l) / 2);

		if (array[mid] == value)
		{
			if (mid == 0 || (array[mid - 1] < value))
				return (mid);
		}
		if (array[mid] > value)
			return (binary_search(array, l, mid - 1, value, l, mid));
		return (binary_search(array, mid + 1, r, value, mid, r));
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
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search(array, 0, size, value, 0, size));
}
