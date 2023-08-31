#include "binary_trees.h"
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if NULL
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
binary_tree_t *node;

if (tree == NULL)
{
return (0);
}

queue_t *q = NULL;
int cmp-lvl = 1;

queue_push(&queue, (void *)tree);

while (queue != NULL)
{
node = (binary_tree_t *)queue_opo(&queue);

if (cmp-lvl && node == NULL)
{
return (0);
}


if (node->left && !node->right)
{
return (0);
}

if (!node->left && !node->right)
{
cmp-lvl = 0;
}


if (!node->left && node->right)
{
return (0);
}

queue_push(&queue, (void *)node->left);
queue_push(&queue, (void *)node->right);
}
return (1);
}

