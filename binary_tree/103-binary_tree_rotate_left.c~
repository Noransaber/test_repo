#include "binary_trees.h"
/**
 * binary_tree_rotate_left -  performs a left-rotation
 * on a binary tree
 * @tree:  pointer to the root node of the tree
 * Return: pointer to the new root node of the tree once rotated
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *p;

if (tree == NULL || tree-> right == NULL)
{
return (NULL);
}
p = tree->right;
tree->right = p->left;
if (p->left != NULL)
{
p->left->parent = tree;
}
p->left = tree;
p->parent = tree->parent;
tree->parent = p;
return (p);
}
