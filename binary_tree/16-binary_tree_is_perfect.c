#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root of the tree
 * Return: 1 if perfect OTHERWISE 0
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}

while (tree->parent != NULL)
{
if (tree->left != NULL && tree->right != NULL)
{
return (1);
}
else
{
return (0);
}
tree = tree->parent;
}
}
