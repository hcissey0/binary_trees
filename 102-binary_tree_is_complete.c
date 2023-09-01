#include "binary_trees.h"

/**
 * enqueue - Adds a node to a queue
 * @queue: The queue to add to
 * @node: The node to add
 */
void enqueue(queue_t *queue, const binary_tree_t *node)
{
	queue_node_t *queue_node = malloc(sizeof(queue_node_t));

	if (queue_node == NULL)
		return;
	queue_node->node = node;
	queue_node->next = NULL;
	if (queue->front == NULL)
		queue->front = queue_node;
	else
		queue->rear->next = queue_node;
	queue->rear = queue_node;
}

/**
 * dequeue - Removes a queue
 * @queue: The queue
 *
 * Return: the pointer to the first node
 */
const binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp;
	const binary_tree_t *node;

	if (queue->front == NULL)
		return (NULL);
	temp = queue->front;
	node = temp->node;
	queue->front = temp->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	return (node);
}

/**
 * queue_delete - Deletes a queue
 * @queue: The queue to delete
 */
void queue_delete(queue_t *queue)
{
	while (queue->front)
		dequeue(queue);
	free(queue);
}

/**
 * queue_size - Finds the size of the queue
 * @queue: The queue
 *
 * Return: the queue size
 */
size_t queue_size(queue_t *queue)
{
	size_t size = 0;
	queue_node_t *temp;

	if (!queue)
		return (0);
	temp = queue->front;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: pointer to the tree to check
 *
 * Return: 1 if complete, 0 if otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue = malloc(sizeof(queue_t));
	const binary_tree_t *temp;
	int f = 0;

	if (tree == NULL)
		return (0);
	if (queue == NULL)
		return (0);
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, tree);
	while (queue->front)
	{
		temp = dequeue(queue);
		if (temp->left)
		{
			if (f)
			{
				queue_delete(queue);
				return (0);
			}
			enqueue(queue, temp->left);
		}
		else
			f = 1;
		if (temp->right)
		{
			if (f)
			{
				queue_delete(queue);
				return (0);
			}
			enqueue(queue, temp->right);
		}
		else
			f = 1;

	}
	queue_delete(queue);
	return (1);
}
