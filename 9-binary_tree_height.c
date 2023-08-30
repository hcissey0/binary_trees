#include "binary_trees.h"

/**
 * tree_height - Recursively find the tree height
 * @tree: The tree
 *
 * Return: The height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: The binary tree to be measured
 *
 * Return: The height of tree or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree) - 1);
}
