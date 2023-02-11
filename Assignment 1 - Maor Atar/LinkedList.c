/* Assignment: 1
Authors: Maor Atar, ID: 318301231
		  Guy Ezra, ID: 207329509
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;
struct Node {
	int data;
	node* next;
};

node* BuildNode(int num1)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = num1;
	new_node->next = NULL;
	return new_node;
}
node* BuildList()
{
	node* head = NULL, * temp = head;
	int num;
	printf("Enter nmbers for list, enter -1 for end: ");
	scanf("%d", &num);
	while (num != -1)
	{
		if (head == NULL)
		{
			head = BuildNode(num);
			temp = head;
		}
		else
		{
			temp->next = BuildNode(num);
			temp = temp->next;
		}
		scanf("%d", &num);
	}
	return head;
}
void PrintList(node* head)
{
	node* temp = head;
	printf("\nThe list is: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node* addToSortList(node* head, node* node_new)
{
	node* temp;
	if (head == NULL)
		return node_new;
	if (node_new->data < head->data)
	{
		node_new->next = head;
		return node_new;
	}
	for (temp = head; temp->next != NULL && node_new->data >= temp->next->data; temp = temp->next);
	node_new->next = temp->next;
	temp->next = node_new;
	return head;
}

node* SortList(node* head)
{
	node* temp, * new_head = NULL;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		temp->next = NULL;
		new_head = addToSortList(new_head, temp);
	}
	return new_head;
}
// ------------------Assignment Methods--------------------
// --------------------------------------------------------
int SumOddIndex(node* head)
{ // Function to sum the values in the odd indexs of the list
	int sum = 0, i = 1;
	node* temp = head;

	while (temp != NULL)
	{
		if (i % 2 != 0) // Condition to check for an odd index
		{
			sum = sum + temp->data; // If the condition is true we add the value to the sum
		}
		i++;
		temp = temp->next;
	}

	return sum; // Returns the sum of values in the odd indexs
}
// --------------------------------------------------------
int MinNode(node* head)
{ // Function to find the minimum value in a list
	node* temp = head;
	int min = temp->data; // Start value for the minimum
	temp = temp->next;

	while (temp != NULL)
	{
		if (temp->data < min) // Condition to search in the list for a smaller value than the minimum
		{
			min = temp->data; // If executes stores the new minimum value in 'min'
		}
		temp = temp->next;
	}

	return min; // Returns the minimum value of the list
}
// --------------------------------------------------------
void ReverseList(node** head)
{ // Function to reverse the values in the list
	node *prev = NULL, *curr = *head, *next = NULL;

	while (curr != NULL)
	{
		next = curr->next; // Stores in 'next' the next value
		curr->next = prev; // Stores in 'curr->next' the previous value
		prev = curr; // Stores in 'prev' the current value
		curr = next; // Stores in 'curr' the next value
	}
	*head = prev; // The tail becomes the head of the list

}
// --------------------------------------------------------
int MiddleList(node* head)
{ // Function to find the middle index in a list
	int i = 0, listSize = 0;
	node* temp = head;

	while (temp != NULL) // Loop to find the size values in the list
	{
		listSize++;
		temp = temp->next;
	}

	temp = head; // Points back to the head of the list

	while (temp != NULL)
	{
		if (listSize % 2 == 0 &&  i == (listSize / 2) - 1) // Condition for an even size of a list
		{
			return temp->data;
		}
		else if (listSize % 2 != 0 && i == listSize / 2) // Condition for an odd size of a list
		{
			return temp->data;
		}
		temp = temp->next;
		i++;
	}
}
// --------------------------------------------------------
int MultHeadTail(node* head)
{ // Function to multiply the head and tail values of a list
	node* temp = head;
	int headVal = temp->data, tailVal = 0; // Stores in 'headVal' the value from the first index in the list

	while (temp != NULL)
	{
		tailVal = temp->data; // Stores in 'tailVal' the value from the last index of the list
		temp = temp->next;
	}

	return headVal * tailVal; // Returns the result of the multiplication of the head and tail
}
// --------------------------------------------------------
void ifSorted(node* head)
{ // Function to check if a list is sorted
	int flag = 0; // Using the 'flag' to check if the list is sorted or not
	node* temp = head;

	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data) // Condition to check if the current value is bigger than the next value in the list
		{
			flag++; // If executes increment 'flag' (The list is not sorted)
		}
		temp = temp->next;
	}

	if (flag == 0)
	{
		printf("The List is sorted\n");
	}
	else
	{
		printf("The List is not sorted\n");
	}
}
// --------------------------------------------------------
node* FreeList(node* head)
{
	node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}
