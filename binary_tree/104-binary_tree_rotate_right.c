#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on
 *  binary tree
 *  @tree:pointer to the root node of the tree to rotate
 *  Return: pointer to the new root
 *  node of the tree once rotated
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *p;
if (tree == NULL || tree->left == NULL)
{
return (NULL);
}

p = tree->left;
tree->left = p->right;

if (p->right != NULL)
{
p->right->parent = tree;
}
p->right = tree;
p->parent = tree->parent;
tree->parent = p;
return (p);
}


