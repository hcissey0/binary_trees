#include "binary_trees.h"

/**
 * array_to_avl - Converts an array to avl
 * @array: the array to convert
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
