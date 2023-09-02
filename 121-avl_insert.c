#include "binary_trees.h"

/**
 * avl_inserts = Inserts a node into an AVL tree
 * @tree: the tree
 * @value: the value to insert
 *
 * Return: a pointer to the inserted avl node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *temp, *parent, *tmp;
	int balance;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	temp = *tree;
	while (temp)
	{
		parent = temp;
		if (value == temp->n)
			return (NULL);
		if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	tmp = binary_tree_node(parent, value);
	if (value < parent->n)
		parent->left = tmp;
	else
		parent->right = tmp;
	while (parent)
	{
		balance = binary_tree_balance(parent);
		if (balance > 1 && value < parent->left->n)
			parent = binary_tree_rotate_right(parent);
		else if (balance > 1 && value > parent->left->n)
		{
			parent->left = binary_tree_rotate_left(parent->left);
			parent = binary_tree_rotate_right(parent);
		}
		else if (balance < -1 && value > parent->right->n)
			parent = binary_tree_rotate_left(parent);
		else if (balance < -1 && value < parent->right->n)
		{
			parent->right = binary_tree_rotate_right(parent->right);
			parent = binary_tree_rotate_left(parent);
		}
		else
			parent = parent->parent;
	}
	return (tmp);
}
