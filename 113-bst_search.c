#include "binary_trees.h"
/**
 * bst_search - This function used to search on a binary tree
 * @tree: used to store the tree
 * Author: Mikias Hailu and yared Tsgie
 * @value: used to store the value
 * Return: success
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
