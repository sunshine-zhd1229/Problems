#include  "BinarySearchTree.h"
#include  "Random.h"
#include  <stdlib.h>

/**
 *create a binary search tree
 *args:
 *		array: 	array of the input arguments
 *		length:	the number of the arguments
 */
TreeNode * CreateTree(void *array, int length, size_t memsize, int (*compare)(const void *, const void *))
{
	RandomInPlace(array, length, memsize);
	if (array == NULL)
	  return NULL;
	int i;
	TreeNode *Tree = NULL;
	for (i = 0; i < length; i++) {
		InsertIntoTree(&Tree, array + i * memsize, compare);		
	}
	return Tree;
	
}

void InsertIntoTree(TreeNode **Tree, void *data, int (*compare)(const void *, const void *)) 
{
	TreeNode *parent, *current, *new;
	parent = NULL;
	current = *Tree;

	while (current != NULL) {
		/*find the parent of the new node*/
		parent = current;
		if (compare(data, current->data) >= 0)
		  current = current->right;
		else 
		  current = current->left;
	}

	new = (TreeNode *)malloc(sizeof(TreeNode));
	new->data = data;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	if (parent == NULL) {
		/*the new one is the root of the tree*/
		*Tree = new;
	} else {
		/*insert node*/
		if (compare(new->data, parent->data) < 0)
		  parent->left = new;
		else
		  parent->right = new;
	}
}

void InOrderTreeWalk(TreeNode * Tree, void (*Print)(void *))
{
	if (Tree != NULL) {
		InOrderTreeWalk(Tree->left, Print);
		Print(Tree->data);
		InOrderTreeWalk(Tree->right, Print);
	}
	
}

TreeNode * SearchInTree(TreeNode * Tree, void *key, int (*compare)(const void *, const void *))
{
	TreeNode *p = Tree;
	int x;
	while (p != NULL && (x = compare(key, p->data)) != 0) {
		if (x < 0)
		  p = p->left;
		else
		  p = p->right;
	}
	return p;
}

TreeNode * MaximumOfTree(TreeNode * Tree)
{
	if (Tree == NULL)
	  return NULL;
	TreeNode *p = Tree;
	while(p->right != NULL)
	  p = p->right;
	return p;
}

TreeNode * MinimumOfTree(TreeNode * Tree)
{
	if (Tree == NULL)
	  return NULL;
	TreeNode *p = Tree;
	while(p->left != NULL)
	  p = p->left;
	return p;
}

TreeNode * SuccessorOfTree(TreeNode * Tree, TreeNode * x)
{
	if (x == NULL || Tree == NULL)
	  return NULL;
	if (x->right != NULL)
	  return MinimumOfTree(x->right);
	
	TreeNode *parent = x->parent;
	TreeNode *current = x;
	while (parent != NULL && current == parent->right) {
		current = parent;
		parent = current->parent;
	}
	
	return parent;
}

TreeNode * PredecessorOfTree(TreeNode * Tree, TreeNode *x)
{
	if(x == NULL || Tree == NULL)
	  return NULL;
	if (x->left != NULL)
	  return MaximumOfTree(x->left);
	
	TreeNode *parent = x->parent;
	TreeNode *current = x;
	while (parent != NULL && current == parent->left) {
		current = parent;
		parent = current->parent;
	}
	
	return parent;	
}

TreeNode * DeleteFromTree(TreeNode ** Tree, TreeNode *x)
{
	TreeNode * toDelete;
	void * temp;
	if (Tree == NULL || *Tree == NULL || x == NULL)
	  return NULL;
	if (x->left == NULL || x->right == NULL) {
		/*has zero or one child*/
		toDelete = x;
	} else {
		/*if the node has two children, then replace it with the Minimum node of the right subtree*/
		toDelete = MinimumOfTree(x->right);
		temp = toDelete->data;
		toDelete->data = x->data;
		x->data = temp;
	}

	TreeNode *child, *parent;
	/*find child*/
	if (toDelete->left != NULL)
	  child = toDelete->left;
	else
	  child = toDelete->right;

	if (child != NULL) {
		child->parent = toDelete->parent;
	}
	
	parent = toDelete->parent;
	if(parent == NULL)
	  *Tree = child;
	else if (parent->left == toDelete)
	  parent->left = child;
	else
	  parent->right = child;

	return toDelete;
}

