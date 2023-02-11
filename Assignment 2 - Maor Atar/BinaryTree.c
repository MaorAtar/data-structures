/* Assignment: 2
Authors: Maor Atar, ID: 318301231
		  Guy Ezra, ID: 207329509
*/
#include"BinaryTree.h"

/*=========================================================*/
node* NewNode(int value) 
/* Function that allocates a new node with the
given data and NULL left and right pointers */
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}
node* Left(node* root) {
	return root->left;
}
node* Right(node* root) {
	return root->right;
}
/*=========================================================*/
node* randomInsertInto(node* root, int value)
/* Assistance function to insert a node in a random spot. */
{
	int flag = rand() % 2;
	if (root == NULL)
		return NewNode(value);
	if (flag == 0)
		root->left = randomInsertInto(root->left, value);
	else if (flag == 1)
		root->right = randomInsertInto(root->right, value);
	return root;
}

/*============================ex1===========================*/
node* randomTree()
/* Function creating random binary tree using the
'randomInsertInto' assistance function. */
{
	int randVal = 0, randSize = rand() % 21;
	node* randTree = NULL;
	for (int i = 0; i < randSize; i++) {
		randVal = rand() % 51;
		randTree = randomInsertInto(randTree, randVal);
	}
	return randTree;
}

/*============================ex2===========================*/
void deleteTree(node* root) 
/* Function to delete allocated data of a given tree. */
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	printf("Deleting Node: %d\n", root->data);
	free(root);
}

/*============================ex3===========================*/
void printNodeAtDistance(node *root , int k)
/*Given a Binary Tree and a positive integer ‘k’, the function 
prints all the nodes which are at distance ‘k’ from the root. */
{
	if (root == NULL)
		return;
	if (k == 0) {
		printf("%d ", root->data);
		return;
	}
	printNodeAtDistance(root->left, k - 1);
	printNodeAtDistance(root->right, k - 1);
}

/*============================ex4===========================*/
void mirrorify(node* root, node** mirror)
/* Function to change the 'mirror' tree to a vice-versa of
 the orginal tree. */
{
	if (root) {
		*mirror = NewNode(root->data);
		mirrorify(root->left, &((*mirror)->right));
		mirrorify(root->right, &((*mirror)->left));
	}
	mirror = root;
}

/*============================ex5===========================*/
void preOrderTraversal(node* root)
/* Function to print the given tree in a pre-order way. */
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(node* root)
/* Function to print the given tree in a in-order way. */
{
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	printf("%d ", root->data);
	inOrderTraversal(root->right);
}
void postOrderTraversal(node* root)
/* Function to print the given tree in a post-order way. */
{
	if (root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d ", root->data);
}

/*============================ex6===========================*/
node* insert(node* root, int val) 
/* Function to insert a new node with a given value to a
given tree. */
{
	if (root == NULL)
		return NewNode(val);
	else {
		if (root->data < val)
			root->right = insert(root->right, val);
		if (root->data > val)
			root->left = insert(root->left, val);
		return root;
	}
}

/*============================ex7===========================*/
bool isFull(node* root) 
/* Function to check if a given tree is a Full Binary Tree. */
{	
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	if (root->left && root->right)
		return isFull(root->left) && isFull(root->right);
	return false;
}

/*============================ex8===========================*/
void printLeaves(node* root)
/* Function to print all the leaves in a given tree. */
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		printf("%d ", root->data);
		return;
	}
	if (root->left)
		printLeaves(root->left);
	if (root->right)
		printLeaves(root->right);
}

/*============================ex9===========================*/
int depth(node *root)
/* Function to calculate the depth of a given tree. */
{
	int leftTreeDepth = 0, RightTreeDepth = 0;

	if (root == NULL)
		return -1;
	leftTreeDepth = depth(root->left);
	RightTreeDepth = depth(root->right);
	if (leftTreeDepth > RightTreeDepth)
		return leftTreeDepth + 1;
	else
		return RightTreeDepth + 1;
}

/*=========================================================*/
void printGivenLevel(node* root, int level)
/* Assistance function to print all nodes values in a
given level. */
{
	if (root == NULL)
		return;
	if (level == 0)
		printf("%d ", root->data);
	printGivenLevel(root->left, level - 1);
	printGivenLevel(root->right, level - 1);
}

/*=========================================================*/
int countNodesOnLevel(node* root, int level)
/* Assistance function to counts the amount of nodes in a
given level. */
{
	if (root == NULL)
		return 0;
	if (level == 0)
		return 1;
	return (countNodesOnLevel(root->left, level - 1) + countNodesOnLevel(root->right, level - 1));
}

/*============================ex10===========================*/
int levelStatistics(node* root, int level) 
/* Function to print all the nodes values in a given level, 
and returns the amount of nodes in a given level using the 
'printGivenLevel' and 'countNodesOnLevel' assistance functions. */
{
	if (level < 0 || level > depth(root)) {
		printf("Not a valid level\n");
		return false;
	}
	printGivenLevel(root, level);
	printf("\nAmount of Nodes: ");
	return countNodesOnLevel(root, level);
}