#include "binary_trees.h"
/**
 * binary_tree_is_root - This function is used to check if the node is the root
 * @node: This funciton is used to store the pointer
 * Author: Mikias Hailu and Yared Tsgie
 * Return: 1 if successful or 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
