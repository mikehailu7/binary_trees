#include "binary_trees.h"
/**
 * binary_tree_node - This fucntion is used to print the binary tree node 
 * @parent: is a pointer that is used to point the parent node
 * @value: is a pointer that is used to store the value of the node
 * Author: mikias hailu and yared tsgie.
 * Return: This will return to the pointer. 
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
