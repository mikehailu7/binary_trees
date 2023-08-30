#include "binary_trees.h"

/**
 * heap_insert - function used to insert a heap
 * @root: used to store the root
 * @value: used to store the value
 * Return: 1 success 0 fail
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int t, s, l, sub, bit, level;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	s = binary_tree_size(tree);
	l = s;
	for (level = 0, sub = 1; l >= sub; sub *= 2, level++)
		l -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = l & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	l & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		t = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = t;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - function used to measure the size of the tree
 * @tree: used to store the tree
 * Return: 1 success and 0 failer
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
