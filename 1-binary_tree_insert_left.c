#include "binary_trees.h"

/**
 *binary_tree_insert_left - function used to insert to the left
 *@parent: used to store the left child 
 *@value: used to store the value
 *Return: print the binary node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
