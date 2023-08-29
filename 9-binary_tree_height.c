#include "binary_trees.h"
/**
 * binary_tree_height: This function will measures the height of a binary tree
 * @tree: This pointer will point to the root node of the tree to measure the height
 * Author: MIkias Hailu and Yared Tsige
 * Return: if tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int right = 0, left = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
