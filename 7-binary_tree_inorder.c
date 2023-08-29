#include "binary_trees.h"
/**
 * binary_tree_inorder: This function will go through binary tree using in-order
 * This pointer will point to the root node of the tree to traverse.
 * @func: This pointer will point to a function to call for each node.
 * Author: Mikias Hailu and Yared Tsgie
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
