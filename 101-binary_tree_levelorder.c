#include "binary_trees.h"

/**
 * queue_create - Creates a queue node
 *
 * Return: a pointer to the newly created node
 */
queue_t queue_create(void)
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

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
There's something to add here
/**
 * binary_tree_levelorder - Traverse a tree using level order
 * @tree: The pointer to the root node of the tree
 * @func: The function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp;
	size_t h, i;
	queue_t *queue;

	if (tree == NULL || func == NULL)
		return;
	queue = queue_create
