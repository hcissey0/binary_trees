#include "binary_trees.h"

/**
 * is_avl - Checks if a tree is avl
 * @tree: the tree
 * @height: the height of the tree
 *
 * Return: 0 if not avl otherwise 1
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
	*height = left > right ? left + 1 : right + 1;
	if (abs(left - right) > 1)
		return (0);
	return (left_avl && right_avl);
}

/**
 * is_bst - Checks if a tree is bst
 * @tree: the tree to be checked
 * @min: the min
 * @max: the max
 *
 * Return: 1 if bst, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, max));
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
