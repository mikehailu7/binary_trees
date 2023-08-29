#include "binary_trees.h"
/**
 * binary_tree_insert_right - This function used to store the right child node
 * @parent: This is used to store the pointer to the right
 * @value: This is used to store the value
 * Author: mikias hailu and yared tsgie
 * Return: This will return the node or null
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *ne;

	if (parent == NULL)
		return (NULL);

	ne = binary_tree_node(parent, value);
	if (ne == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		ne->right = parent->right;
		parent->right->parent = ne;
	}
	parent->right = ne;
	return (ne);
}
