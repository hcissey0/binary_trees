#include "binary_trees.h"

/**
 * tree_height - Measures the tree height
 * @tree: The tree to be measured
 *
 * Return: the height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: The tree to be checked
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left == right)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		if (tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
	}
	return (0);
}
