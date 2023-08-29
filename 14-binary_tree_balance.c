#include "binary_trees.h"
/**
 * binary_tree_height: This fucntion will measure the height of a binary tree
 * @tree: This pointer to the root node of the tree to measure the height.
 * Auhtor: Mikias hailu and Yared tsgie
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int right = 1, left = 1;

		if (tree->right)
			right = right + binary_tree_height(tree->right);
		if (tree->left)
			left = left + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
/**
 * binary_tree_balance: This function will measures the balance factor of a binary tree
 * @tree: This funciton will point to the root node of the tree to measure the balance factor
 * Auhtor: Mikias hailu and Yared Tsgie
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
