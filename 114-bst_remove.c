#include "binary_trees.h"

/**
 * minValueNode - Finds the min value in a tree
 * @node: the node
 *
 * Return: a pointer to the min value
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *temp = node;

	while (temp && temp->left)
		temp = temp->left;
	return (temp);
}

/**
 * bst_remove - Removes a node froma binary search tree
 * @root: the root node
 * @value: the value to remove from the tree
 *
 * Return: pointer to the new root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, /* *parent, */ *succ;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		succ = minValueNode(root->right);
		root->n = succ->n;
		root->right = bst_remove(root->right, succ->n);
		/*
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			free(root);
			return (temp);
		}
		else
		{
			succ = root->right;
			while (succ->left)
				succ = succ->left;
			root->n = succ->n;
			parent = succ->parent;
			if (parent->left == succ)
				parent->left = succ->right;
			else
				parent->right = succ->right;
			if (succ->right)
				succ->right->parent = parent;
			free(succ);
		}
		*/
	}
	return (root);
}
