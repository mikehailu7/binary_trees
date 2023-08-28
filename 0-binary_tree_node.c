#include "binary_trees.h"
/**
 * binary_tree_node - it is used to print the binary tree node 
 * @parent: used to point the parent node
 * @value: used to store the value of the node
 * Return: the pointer 
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *ne;

	ne = malloc(sizeof(binary_tree_t));
	if (ne == NULL)
		return (NULL);
	ne->n = value;
	ne->parent = parent;
	ne->left = NULL;
	ne->right = NULL;

	return (ne);
}
