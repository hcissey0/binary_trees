#include "binary_trees.h"

/**
 * tree_depth - Finds the depth of a tree
 * @tree: The tree to find it's depth
 *
 * Return: the depth of the tree or 0
 */
int tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *temp;
	int d = 0;

	temp = (binary_tree_t *)tree;
	if (tree == NULL)
		return (0);
	while (temp->parent != NULL)
	{
		d++;
		temp = temp->parent;
	}
	return (d);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * @first: the first node
 * @second: The second node
 *
 * Return: a pointer to the common ancestor of the two nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	while (first != NULL)
	{
		if (tree_depth(first) > tree_depth(second))
			first = first->parent;
		else if (tree_depth(second) > tree_depth(first))
			second = second->parent;
		else
		{
			if (first == second)
				return ((binary_tree_t *)first);
			first = first->parent;
			second = second->parent;
		}
	}
	return (NULL);
}
