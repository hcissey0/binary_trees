#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts a node with at least one child in a binary tree
 * @tree: The pointer to the root of the tree
 *
 * Return: The number of nodes or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
