#include "binary_trees.h"
/**
 * binary_tree_is_root - function used to check if the node is the root
 * @node: used to store the pointer
 * Return: 1 if successful or 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
