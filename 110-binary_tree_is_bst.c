#include "binary_trees.h"

int find_node(binary_tree_t *root, binary_tree_t *node);
int binary_tree_is_bst(const binary_tree_t *tree);
int croos_tree(binary_tree_t *root, binary_tree_t *node);

/**
 * binary_tree_is_bst - This funciton will check if is bst tree in a correct form
 * @tree: This will tre to check
 * Author: Mikias hailu and Yared tsgie
 * Return: This will return if 1 if is bst 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}
/**
 * croos_tree: This funciton will cross the tree checking
 * @root: This is root node of the tree
 * @node: This current node to evaluate
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return 1 if is BST0 if no
 */
int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int mu = 0;
		mu = find_node(root, node);
		if (node->left)
			mu &= croos_tree(root, node->left);
		if (node->right)
			mu &= croos_tree(root, node->right);
		return (mu);
	}
	return (0);
}
/**
 * find_node: This function will find node in a tree
 * @root: This is a root of the tre to evaluate
 * @node: This is a node to find
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return 1 if exits 0 if no
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{
	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}

