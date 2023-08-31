#include "binary_trees.h"
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}
return (bal_avl(tree, INT_MIN, INT_MAX));
}
/**
 * binary_tree_height - measures the height of BT
 * @tree: tree
 * Return: the height
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t l = 0;
size_t r = 0;

if (tree == NULL)
{
return (0);
}
else
{
if (tree)
{
l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
}
return ((l > r) ? l : r);
}
}
/**
 * bal_avl - comapre subtrees if they are avl
 * @tree: pointer to tree to be checked
 * @heigh: pointer to hieghest node
 * @lower: pointer to lowest node
 * Return: 1 if the tree is AVL, 0 if not
 **/
int bal_avl (const binary_tree_t *tree, int lower, int heigh)
{
size_t height_l, height_r, balancer;

if (tree != NULL)
{
if (tree->n > heigh || tree->n < lower)
{
return (0);
}
height_l = binary_tree_height(tree->left);
height_r = binary_tree_height(tree->right);
balancer = height_l > height_r ? height_l - height_r : height_r - height_l;

if (balancer > 1)
{
return (0);
}
return (bal_avl(tree->left, lower, tree->n -1) && bal_avl(tree->right, tree->n + 1, heigh));
}
return (1);
}

