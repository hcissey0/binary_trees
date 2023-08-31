#include "binary_trees.h"

/**
 * tree_nodes - Counts the number of nodes in a tree
 * @tree: The tree to be counted
 *
 * Return: The number of nodes or 0
 */
size_t tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = tree_nodes(tree->left);
	right = tree_nodes(tree->right);

	return (1 + left + right);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: The tree to check through
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = tree_nodes(tree->left);
	right = tree_nodes(tree->right);

	return (left == right);
}
