#include "binary_trees.h"
/**
 * binary_tree_postorder: This function will goes through a binary tree using post-order
 * @func: This pointer will point to a function to call for each node.
 * @tree: This pointer will point to the root node of the tree to traverse.
 * Author: Mikias Hailu and Yared Tsgie
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
