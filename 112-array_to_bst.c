#include "binary_trees.h"

/**
 * array_to_bst - Converts an array to a binary search tree
 * @array: The array to covert
 * @size: size of the array
 *
 * Return: a pointer to the root of the created binary search tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *temp = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&temp, array[i]);
	return (temp);
}
