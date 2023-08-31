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
 * binary_tree_levelorder - Traverse a tree using level order
 * @tree: The pointer to the root node of the tree
 * @func: The function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp;
	size_t h = 0, i;
	/* queue_node_t *tmp; */
	queue_t *queue;

	if (tree == NULL || func == NULL)
		return;
	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return;
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, tree);
	while (queue->front)
	{
		h = queue_size(queue);

		for (i = 0; i < h; i++)
		{
			temp = dequeue(queue);
			func(temp->n);
			if (temp->left)
				enqueue(queue, temp->left);
			if (temp->left)
				enqueue(queue, temp->right);
		}
	}
	queue_delete(queue);
}
