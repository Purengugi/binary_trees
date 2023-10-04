#include "binary_trees.h"
void level_helper(const binary_tree_t *tree, void (*func)(int), int level);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level;

	if (tree == NULL || func == NULL)
		return;
	for (level = 0; level < binary_tree_height(tree); level++)
	{
		level_helper(tree, func, level);
	}
}
/**
 * level_helper - level order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level in the tree
 * Return: nothing
 */
void level_helper(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL || func == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		level_helper(tree->left, func, level - 1);
		level_helper(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: The height of the binary tree, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
