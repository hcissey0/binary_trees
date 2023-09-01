#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree
 * @tree: The tree to search from
 * @value: the value to search for
 *
 * Return: a pointer to the node of the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	if (tree == NULL)
		return (NULL);
	temp = (bst_t *)tree;
	while (temp)
	{
		if (temp->n == value)
			return (temp);
		else if (temp->n > value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return (NULL);
}
