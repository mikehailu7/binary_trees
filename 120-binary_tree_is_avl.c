#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * is_avl_helper: This fucntion will checks if a binary tree is a valid AVL tree
 * @tree: This is a pointer that points to the root node of the tree to check
 * @hi: The is the value of the largest node visited this far
 * @lo: The is the value of the smallest node visited thus far
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return if the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t mheight, eheight, dif;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		mheight = height(tree->left);
		eheight = height(tree->right);
		dif = mheight > eheight ? mheight - eheight : eheight - mheight;
		if (dif > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl: This function will Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Author: Mikias Hailu and Yared Tsgie
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * height: This function measures the height of a binary tree.
 * @tree: This is a pointer that points to the root node of the tree to measure the height.
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return If tree is NULL, your function must return 0,
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t m = 0, e = 0;

		m = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((m > e) ? m : e);
	}
	return (0);
}

