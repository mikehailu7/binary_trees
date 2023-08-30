#include "binary_trees.h"
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);
avl_t *sorted_array_to_avl(int *array, size_t size);
/**
 * sorted_array_to_avl: This funciton will create a alv tree from sorted array
 * @array: This represent the sorted array
 * Author: Mikias Hailu and Yared Tsgie
 * @size: This is the size of the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
/**
 * aux_sort: This funciton will create the tree using the half element
 * @array: sorted array
 * Author: Mikias Hailu and Yared Tsgie
 * @parent: This is the parent of the node to create
 * @last: This is the position where the array ends
 * Return: This will return the tree created
 * @begin: position where the array starts
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	int center = 0;
	binary_tree_t *aux;
	avl_t *root;
	if (begin <= last)
	{
		center = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[center]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, center - 1);
		root->right = aux_sort(root, array, center + 1, last);
		return (root);
	}
	return (NULL);
}
