#include  <stdio.h>

typedef struct Node {
	void 				*data;
	struct Node			*parent;
	struct Node 		*left;
	struct Node 		*right;
} TreeNode;

TreeNode * CreateTree(void *array, int length, size_t memsize, int (*compare)(const void *, const void *));
void InsertIntoTree(TreeNode **Tree, void *data, int (*compare)(const void *, const void *));
void InOrderTreeWalk(TreeNode * Tree, void (*Print)(void *));
TreeNode * SearchInTree(TreeNode * Tree, void *key, int (*compare)(const void *, const void *));
TreeNode * MaximumOfTree(TreeNode * Tree);
TreeNode * MinimumOfTree(TreeNode * Tree);
TreeNode * SuccessorOfTree(TreeNode * Tree, TreeNode * x);
TreeNode * PredecessorOfTree(TreeNode * Tree, TreeNode *x);
TreeNode * DeleteFromTree(TreeNode ** Tree, TreeNode *x);
