#include "sort.h"

/**
 * CopyArray - copy a list
 *
 * @A: The array to be copied
 * @B: The copy array
 * @iBegin: starting point
 * @iEnd: ending point
 */
void CopyArray(int *A, size_t iBegin, size_t iEnd, int *B)
{
	size_t k;

	for (k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}

/**
 * TopDownMerge - dividing the array half by half and sorting it
 *
 * @A: The array to be copied
 * @B: The copy array
 * @iBegin: starting point
 * @iEnd: ending point
 * @iMiddle: the middle of the array
 */
void TopDownMerge(int *A, size_t iBegin, size_t iMiddle, size_t iEnd, int *B)
{
	size_t i, j, k;

	i = iBegin, j = iMiddle;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(A, (iMiddle - iBegin));
	printf("[right]: ");
	print_array(B, (iEnd - iMiddle));
	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(A, iEnd);
}

/**
 * TopDownSplitMerge - split the list 2 by 2
 *
 * @A: The array to be copied
 * @B: The copy array
 * @iBegin: starting point
 * @iEnd: ending point
 */
void TopDownSplitMerge(int *B, size_t iBegin, size_t iEnd, int *A)
{
	size_t iMiddle;

	if (iEnd - iBegin <= 1)
		return;
	iMiddle = (iEnd + iBegin) / 2;
	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

/**
 * merge_sort - sorts a list
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	size_t n;
	int B[n];

	n = size;
	if (!array)
		return;
	if (size < 2)
		return;

	CopyArray(array, 0, n, B);
	TopDownSplitMerge(B, 0, n, array);
}
