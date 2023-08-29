#include "binary_trees.h"
/**
 * binary_tree_is_leaf - This function used to ckeck if the node is leaf
 * @node: used to store the node 
 * Author: Mikias Hailu and yared tsgie
 * Return: This will return 1 if successful or 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{

	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
