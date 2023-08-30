#include "binary_trees.h"
/**
 * binary_tree_height - calculate the height of the tree
 * @tree: pointer to the root
 * Return: height
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
{
return (0);
}

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_balance - measures the balance
 * factor of a binary tree
 * @tree: The pointer to the root
 * Return: The balance factor | ZERO
 **/

int binary_tree_balance(const binary_tree_t *tree)
{
size_t leftH, rightH;
int balance_factor;
if (tree == NULL)
{
return (0);
}

leftH = binary_tree_height(tree->left);
rightH = binary_tree_height(tree->right);

balance_factor = leftH - rightH;

return (balance_factor);
}

