#include "binary_trees.h"
/**
 * binary_tree_uncle: This function will finds the uncle of a node
 * @node: This pointer will point to the node to find the uncle
 * Return: This will return the pointer to the uncle node
 * Author: Mikias Hailu and Yared tsgie
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
/**
 * binary_tree_sibling: This funciton will finds the sibling of a node
 * @node: This pointer will point to the node to find the sibling
 * Author: Mikias Hailu and Yared tsgie
 * Return: This will return the pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right == node)
		return (node->parent->left);
	else
		return (node->parent->right);
}
