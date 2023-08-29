#include "binary_trees.h"
/**
 * binary_tree_size: this fucntion will measures the size of a binary tree
 * @tree: This pointer will point to the root node of the tree to measure the size
 * AUthor: Mikias Hailu and Yared Tsgie
 * Return: This will return if tree is NULL, must return 0.
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
/**
 * binary_tree_height: This function will measures the height of a binary tree
 * @tree: This pointer will point to the root node of the tree to measure the height
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return if tree is NULL, your function must return 0
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
/**
 * binary_tree_is_perfect: This function will checks if a binary tree is perfect
 * @tree: This pointer will point to the root node of the tree to check
 * Author: MIkias Hailu and Yared Tsgie
 * Return: This will return if tree is NULL, function must return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t m = 0, p_size = 0;

	if (tree == NULL)
		return (0);
	m = binary_tree_height(tree);
	p_size = (1 << (m + 1)) - 1;
	if (p_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}

