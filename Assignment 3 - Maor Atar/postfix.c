/* Assignment: 3
Authors: Maor Atar, ID: 318301231
		  Guy Ezra, ID: 207329509
*/
#include "postfix.h"

/*=========================================================*/
node* Left(node* root)
/* Function to get the left node */
{
	return root->left;
}
/*=========================================================*/
node* Right(node* root)
/* Function to get the right node */
{
	return root->right;
}
/*=========================================================*/
node* NewNode(char* value)
/* Function to create a new node */
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
/*=========================================================*/
void deleteTree(node* root)
/* Fucntion to delete a tree using postorder transversal
 before deleting the parent node, function delete child nodes first */
{
	if (NULL == root)
		return;
	deleteTree(Left(root));
	deleteTree(Right(root));
	free(root);
}
/*=========================================================*/
void push(node* new_data)
/* Function to push a node into the stack */
{
	stack* temp = (stack*)malloc(sizeof(stack));
	if (!temp) { // Condition for wrong temp stack allocating memory
		printf("--Stack Overflow--\n");
		exit(1);
	}
	temp->data = new_data;
	temp->next = top;
	top = temp;
}
/*=========================================================*/
node* pop()
/* Function to pop the last node from the stack */
{
	stack* tempStack = NULL; // Using a temp stack
	node* tempNode = NULL; // Using a temp node
	if (!top) { // Condition for an empty stack
		printf("--Stack Underflow--\n");
		exit(1);
	}
	tempStack = top;
	tempNode = tempStack->data;
	top = tempStack->next;
	free(tempStack);
	return tempNode;
}
/*=========================================================*/
bool isOperator(char token)
/* Assistance function to check if a token enterd is an operator */
{
	return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}
/*=========================================================*/
bool isOperand(char token)
/* Assistance function to check if a token enterd is an operand */
{
	return token >= '0' && token <= '9';
}
/*============================ex1===========================*/
node* create_expr_tree_postfix(char* postfix)
/* Function to create a expression tree from a given string, in a postfix form */
{
	stack* tempStack = (stack*)malloc(sizeof(stack));
	node* tempNode = NULL, * treeRoot = NULL;
	int digit_value;
	for (int i = 0; i < strlen(postfix); i++) {
		tempNode = (node*)malloc(sizeof(node));
		if (isOperand(postfix[i])) { // Condition for char operand
			digit_value = 0;
			while (postfix[i] != ' ') {
				digit_value = digit_value * 10 + postfix[i] - 48; // Converting the string expression into an integer expression
				i++;
			}
			tempNode = NewNode(digit_value); // Storing a new operand node in temp
			tempStack = tempNode; // Temp stack points to the temp node
			push(tempStack); // Pushing the temp node to the stack
			tempNode = NULL; // Initlizing the tempNode with null value 
		}
		else if (isOperator(postfix[i])) { // Condition for char operator 
			//Creating new node and popping children to it
			tempNode = NewNode(postfix[i]); // Storing a new operator node in temp
			tempNode->right = pop(); // Poping to the right child the last stack element
			tempNode->left = pop(); // Poping to the left child the before-last stack element
			tempStack = tempNode; // Temp stack points to the temp node
			push(tempStack); // Pushing the temp node to the stack
			tempNode = NULL; // Initlizing the tempNode with null value 
			i++;
		}
	}
	treeRoot = pop(); // Poping to the new expression tree root the last stack element 
	return treeRoot; // Returns the new expression tree
}
/*============================ex2===========================*/
void inOrder(node* treeNode)
/* Function that prints the expression tree in the infix form */
{
	if (!treeNode) {
		return;
	}
	else if (isOperator(treeNode->data)) {
		printf("( ");
		inOrder(treeNode->left);
		printf("%c ", treeNode->data);
		inOrder(treeNode->right);
		printf(") ");
	}
	else {
		printf("%d ", treeNode->data);
	}
}
/*============================ex2===========================*/
void preOrder(node* treeNode)
/* Function that prints the expression tree in the prefix form */
{
	if (!treeNode) {
		return;
	}
	else if (isOperator(treeNode->data)) {
		printf("%c ", treeNode->data);
		preOrder(treeNode->left);
		preOrder(treeNode->right);
	}
	else {
		printf("%d ", treeNode->data);
	}
}
/*============================ex2===========================*/
void postOrder(node* treeNode)
/* Function that prints the expression tree in the postsfix form */
{
	if (!treeNode) {
		return;
	}
	else if (isOperator(treeNode->data)) {
		postOrder(treeNode->left);
		postOrder(treeNode->right);
		printf("%c ", treeNode->data);
	}
	else {
		printf("%d ", treeNode->data);
	}
}
/*============================ex3===========================*/
int evaluateExpression(node* root)
/* Function that evaluates the expression tree */
{
	if (!isOperator(root->data)) {
		return root->data;
	}
	else if (root->data == '+') {
		return evaluateExpression(root->left) + evaluateExpression(root->right);
	}
	else if (root->data == '-') {
		return evaluateExpression(root->left) - evaluateExpression(root->right);
	}
	else if (root->data == '*') {
		return evaluateExpression(root->left) * evaluateExpression(root->right);
	}
	else if (root->data == '/') {
		return evaluateExpression(root->left) / evaluateExpression(root->right);
	}
	else if (root->data == '^') {
		return pow(evaluateExpression(root->left), evaluateExpression(root->right));
	}
}
/*=========================================================*/