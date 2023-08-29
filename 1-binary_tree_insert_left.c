#include "binary_trees.h"
/**
 * binary_tree_insert_left - This function is used to insert values to the left
 * @parent: This is used to store the left child 
 * @value: This is used to store the value
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return the binary node
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
