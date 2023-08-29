#include "binary_trees.h"
/**
 * binary_tree_is_full: This function will check if a binary tree is full
 * @tree: This pointer will point to the root node of the tree to check
 * Author: Mikias hailu and yared Tsgie
 * Return: This will return if tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (0);
}
