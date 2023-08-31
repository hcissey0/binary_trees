#include "binary_trees.h"

/**
 * tree_height - The height of the tree
 * @tree: The tree to measure
 *
 * Return: the height of the given tree
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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: The tree to be measured
 *
 * Return: The balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return (left - right);
}
