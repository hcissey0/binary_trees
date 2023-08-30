#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child
 * @parent: The parent node
 * @value: the value of the new node
 *
 * Return: A pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

	if (parent->left == NULL)
		parent->left = temp;
	else
	{
		parent->left->parent = temp;
		temp->left = parent->left;
		parent->left = temp;
	}
	return (temp);
}
