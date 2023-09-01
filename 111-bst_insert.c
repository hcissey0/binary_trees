#include "binary_trees.h"

/**
 * bst_insert - Insets a value in a binary search tree
 * @tree: The tree to insert into
 * @value: The value to be inserted
 *
 * Return: a pointer to the created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *prev;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	temp = *tree;
	while (temp)
	{
		prev = temp;
		if (value == temp->n)
			return (NULL);
		if (value > temp->n)
			temp = temp->right;
		else
			temp = temp->left;
	}
	temp = binary_tree_node(prev, value);
	if (value < prev->n)
		prev->left = temp;
	else
		prev->right = temp;
	return (temp);
}
