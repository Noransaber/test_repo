#include "binary_trees.h"
/**
 * binary_trees_ancestor - 
 * finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common
 * ancestor node of the two given nodes
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
if (first == NULL && second == NULL)
{
return (NULL);

if (first == second || first == first->parent || second == second->parent)
{
return ((binary_tree_t *)first);

while (first != NULL)
{
first->visited = 1;
first = first->parent;
}

while (second != NULL)
{
if (second->visited)
{
return (binary_tree_t *)second;
second = second->parent;
}
return (NULL);
}

