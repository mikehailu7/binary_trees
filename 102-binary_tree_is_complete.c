#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - function used to check whether a tree is complet or not
 * @tree: used to store the value of the tree
 * Return: 1 success and 0 for failer
 * author: yared and mike hailu
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
        levelorder_queue_t *head, *tail;
        unsigned char f = 0;

        if (tree == NULL)
                return (0);

        head = tail = create_node((binary_tree_t *)tree);
        if (head == NULL)
                exit(1);

        while (head != NULL)
        {
                if (head->node->left != NULL)
                {
                        if (f == 1)
                        {
                                free_queue(head);
                                return (0);
                        }
                        push(head->node->left, head, &tail);
                }
                else
                        f = 1;
                if (head->node->right != NULL)
                {
                        if (f == 1)
                        {
                                free_queue(head);
                                return (0);
                        }
                        push(head->node->right, head, &tail);
                }
	 	else
	 		f = 1;
                pop(&head);
        }
        return (1);
}
/**
 * create_node - function used to create a node
 * @node: used to store the node
 * Return: 1 succeful and 0 failer
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - function used to free a level loader
 * @head: used to store the head pointer
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * pop - function used to pop a queue
 * @head: used to store the head
 */
void pop(levelorder_queue_t **head)
{
        levelorder_queue_t *tmp;

        tmp = (*head)->next;
        free(*head);
        *head = tmp;
}

/**
 * push - function used to push a binary node
 * @node: used to store the node
 * @head: used to store the head
 * @tail: used to store the tail
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
