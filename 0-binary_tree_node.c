#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: The parent node for the node to be created
 * @value: The value of the new node
 *
 * Return: A pointer to the created node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
		return (NULL);
	temp->n = value;
	if (parent == NULL)
	{
		parent = temp;
		return (temp);
	}
	if (parent->left == NULL)
		parent->left = temp;
	else if (parent->right == NULL)
		parent->right = temp;
	else
		free(temp);
	return (temp);
}

