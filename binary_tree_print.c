#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * _height - function used to measure the heignt
 * @tree: used tos tore the tree
 * Return: success
 */
static size_t _height(const binary_tree_t *tree)
{
        size_t height_l;
        size_t height_r;

        height_l = tree->left ? 1 + _height(tree->left) : 0;
        height_r = tree->right ? 1 + _height(tree->right) : 0;
        return (height_l > height_r ? height_l : height_r);
}
/**
 * print_t - function used to print recuresively
 * @tree: used to store the tree
 * @offset: used to store the ofesset
 * @depth: used to store the depth
 * @s: used to store the s
 * Return: 1 success
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
        char b[6];
        int width, left, right, is_left, i;

        if (!tree)
                return (0);
        is_left = (tree->parent && tree->parent->left == tree);
        width = sprintf(b, "(%03d)", tree->n);
        left = print_t(tree->left, offset, depth + 1, s);
        right = print_t(tree->right, offset + left + width, depth + 1, s);
        for (i = 0; i < width; i++)
                s[depth][offset + left + i] = b[i];
        if (depth && is_left)
        {
                for (i = 0; i < width + right; i++)
                        s[depth - 1][offset + left + width / 2 + i] = '-';
                s[depth - 1][offset + left + width / 2] = '.';
        }
        else if (depth && !is_left)
        {
                for (i = 0; i < left + width; i++)
                        s[depth - 1][offset - width / 2 + i] = '-';
                s[depth - 1][offset + left + width / 2] = '.';
        }
        return (left + width + right);
}
 /**
 * binary_tree_print - function used to print the tree
 * @tree: used to store the pointer
 */
void binary_tree_print(const binary_tree_t *tree)
{
        char **s;
        size_t height, x, y;

        if (!tree)
                return;
        height = _height(tree);
        s = malloc(sizeof(*s) * (height + 1));
        if (!s)
                return;
        for (x = 0; x < height + 1; x++)
        {
                s[x] = malloc(sizeof(**s) * 255);
                if (!s[x])
                        return;
                memset(s[x], 32, 255);
        }
        print_t(tree, 0, 0, s);
        for (x = 0; x < height + 1; x++)
        {
                for (y = 254; y > 1; --y)
                {
                        if (s[x][y] != ' ')
                                break;
                        s[x][y] = '\0';
                }
                printf("%s\n", s[x]);
                free(s[x]);
        }
        free(s);
}
