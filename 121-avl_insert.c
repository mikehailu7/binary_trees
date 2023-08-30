#include "binary_trees.h"
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value);
int balance(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
/**
 * avl_insert: This funciton will inserts a value into an AVL tree.
 * @value: This will insert into the AVL tree.
 * @tree: This will a double pointer to the root node of the AVL tree to insert into.
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return a pointer to the inserted node.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
/**
 * height: This fucntion Measures the height of a binary tree.
 * @tree: This pointer points to the root node of the tree to measure the height.
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return If tree is NULL, your function must return 0.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t m = 0, e = 0;

		m = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		e = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((m > e) ? m : e);
	}
	return (0);
}

/**
 * balance: This will Measures the balance factor of a binary tree.
 * @tree: This is a pointer that points to the root node of the tree.
 * Author: Mikias Hailu and Yared Tsgie
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive: This funciton will Inserts a value into an AVL tree recursively.
 * @parent: The parent node of the current working node.
 * @tree: This is a pointer that points to the root node of the AVL tree to insert into
 * Author: Mikias Hailu and Yared Tsgie
 * @new: This is a pointer that points to a double pointer to store the new node
 * @value: This is the value to insert into the AVL tree.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
