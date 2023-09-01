#include "binary_trees.h"

/**
 * tree_height - Measures the height of a tree
 * @tree: the tree
 *
 * Return: the height of @tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * is_avl - Checks if a tree is avl
 * @tree: the tree to check
 * @height: the height of the tree
 *
 * Return: 1 if avl 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int *height)
{
	int left = 0, right = 0;
	int left_avl, right_avl;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}
	left_avl = is_avl(tree->left, &left);
	right_avl = is_avl(tree->right, &right);
	*height = (1 + (left > right ? left : right));
	if (abs(left - right) > 1)
		return (0);
	return (left_avl && right_avl);
}

/**
 * is_bst - Checks if a tree is bst
 * @tree: the tree to be checked
 * @min: the int min
 * @max: the int max
 *
 * Return: 1 if bst, 0 otherwise
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
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: The tree to be checked
 *
 * Return: 1 if AVL and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h;

	if (tree == NULL)
		return (1);
	if (is_bst(tree, INT_MIN, INT_MAX) == 0)
		return (0);
	return (is_avl(tree, &h));
}
