#include "binary_trees.h"
/**
 * binary_tree_size: This function will measures the size of a binary tree
 * @tree: This pointer will point to the root node of the tree to measure the size
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return if tree is NULL, must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t s_left, s_right;

		s_left = binary_tree_size(tree->left);
		s_right = binary_tree_size(tree->right);
		return (1 + s_left + s_right);
	}
}
