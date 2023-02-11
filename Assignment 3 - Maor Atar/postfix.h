/* Assignment: 3
Authors: Maor Atar, ID: 318301231
          Guy Ezra, ID: 207329509
*/
#ifndef _POSTFIX
#define _POSTFIX
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define TRUE (1==1)
#define FALSE (!TRUE)

typedef struct Node node; 
struct Node {   
    char* data;
    node* left;
    node* right;
};
typedef struct stack stack; 
struct stack {                               
    node* data;
    stack* next;
}*top = NULL;
node* Left(node* root);
node* Right(node* root);
node* NewNode(char* value);
void push(node* new_data);
node* pop();
bool isOperator(char token); // <- Assistance function
bool isOperand(char token); // <- Assistance function
node* create_expr_tree_postfix(char* postfix);
void inOrder(node* treeNode);
void preOrder(node* treeNode);
void postOrder(node* treeNode);
int evaluateExpression(node* root);
void deleteTree(node* root);
#endif 