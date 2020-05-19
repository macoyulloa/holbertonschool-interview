#include "binary_trees.h"

avl_t *SortedArrayToAVL(int *array, size_t start, size_t end,
			avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	root->parent = parent;
	root->n = array[mid];
	root->left = NULL;
	root->right = NULL;

	// Recursively construct the left subtree and make it left child of root
	root->left = SortedArrayToAVL(array, start, mid - 1, root->left);

	// Recursively construct the right subtree and make it right child root
	root->right = SortedArrayToAVL(array, mid + 1, end, root->right);

	return (root);
}

/**
 * binary_tree_s avl_t - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	avl_t *root;
	root = NULL;
	root = SortedArrayToAVL(array, 0, size - 1, NULL);
	return (root);
}
