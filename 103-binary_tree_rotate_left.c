#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: The tree to rotate
 *
 * Return: a pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	temp = tree->right;
	tree->right = temp->left;
	if (temp->left != NULL)
		temp->left->parent = tree;
	temp->left = tree;
	temp->parent = tree->parent;
	tree->parent = temp;
	return (temp);
}
