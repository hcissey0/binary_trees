#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: The pointer to the node
 *
 * Return: The depth or zero if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;
	binary_tree_t *temp;

	temp = (binary_tree_t *)tree;
	if (tree == NULL)
		return (0);
	while (temp->parent != NULL)
	{
		d++;
		temp = temp->parent;
	}

	return (d);
}
