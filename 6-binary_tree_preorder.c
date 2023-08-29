#include "binary_trees.h"
/**
 * binary_tree_preorder: This funciton will perform pre order traversal in a binary tree.
 * @tree: This pointer will point to the root node of the tree to traverse.
 * @func: This pointer will point to a function to call for each node.
 * Author: Mikias Hailu and Yared Tsgie
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
