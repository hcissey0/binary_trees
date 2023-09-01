#include "binary_trees.h"

/**
 * is_bst - Checks if a tree is a binary search tree
 * @tree: Pointer to the tree node
 * @min: the min value
 * @max: the max value
 *
 * Return: 1 if bst 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a bst
 * @tree: The tree to be checked
 *
 * Return: 1 if a bst 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
