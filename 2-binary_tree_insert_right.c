#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child
 * @parent: The parent node to insert to
 * @value: value of the new node
 *
 * Return: A pointer to the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);
	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
		return (NULL);
	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = parent;

	if (parent->right == NULL)
		parent->right = temp;
	else
	{
		parent->right->parent = temp;
		temp->right = parent->right;
		parent->right = temp;
	}
	return (temp);
}
