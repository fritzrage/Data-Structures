#include <stdio.h>
#include <malloc.h>

typedef struct CLLNode {
	int data;
	CLLNode * next;
};

void InsertAtFrontCLL(CLLNode **head, int data)
{
	CLLNode * current = *head;
	CLLNode * newNode = (CLLNode*)malloc(sizeof(CLLNode));

	if (!newNode)
		printf("Memory error");
	newNode->data = data;
	newNode->next = newNode;

	while (current->next != *head)
		current = current->next;

	if (head == NULL)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		current->next = newNode;
		*head = newNode;
	}
}


void InsertAtEndCLL(CLLNode **head, int data)
{
	CLLNode * current = *head;
	CLLNode * newNode = (CLLNode*)malloc(sizeof(CLLNode));
	
	if (!newNode)
		printf("Memory error");
	newNode->data = data;
	newNode->next = newNode;

	while (current->next != *head)
		current = current->next;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		current->next = newNode;
	}
}

void printCLLData(CLLNode *head)
{
	CLLNode * current = head;
	if (head == NULL)
	{
		printf("List is empty");
		return;
	}

	do {

		printf("%d\n", current->data);
		current = current->next;
	} while (current != head);
}

int CLLLength(CLLNode **head)
{
	CLLNode *current = *head;
	if (!head)
		return 0;
	int count = 0;

	do
	{
		current = current->next;
		count++;
	} while (current != *head);
	return count;
}

//Main program for testing
//
//int main()
//{
//	CLLNode *head = (CLLNode*)malloc((sizeof(CLLNode)));
//	head->data = 20;
//	head->next = (CLLNode*)malloc((sizeof(CLLNode)));
//
//	head->next->data = 30;
//	head->next->next = (CLLNode*)malloc((sizeof(CLLNode)));
//
//	head->next->next->data = 40;
//	head->next->next->next = head;
//
//	printf("Length of the list = %d\n", CLLLength(&head));
//
//	return 0;
//}
