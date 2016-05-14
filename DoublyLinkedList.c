#include <stdio.h>
#include <malloc.h>

struct DLLNode {
	int data;
	DLLNode * next;
	DLLNode * prev;
};


///Function to delete node from a doubly linked list at any position
void DLLDelete(struct DLLNode ** head, int position)
{
	struct DLLNode *temp, *temp2;
	temp = *head;
	int k = 1;
	if (*head == NULL) {
		printf("List is empty");
		return;
	}
	if (position == 1)
	{
		*head = (*head)->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
			free(temp);
		}
		return;
	}

	while (k < position && (temp->next != NULL))
	{
		temp = temp->next;
		k++;
	}
	if (k != position)
	{
		printf("Desired position does not exist");
	}

	//Now we are at the node to be deleted viz temp

	temp2 = temp->prev;
	temp2->next = temp->next;
	if (temp->next)
		temp->next->prev = temp2;
	free(temp);
	return;
}

///Function to insert node into a doubly linked list at any position
void DLLInsert(struct DLLNode ** head, int data, int position)
{
	int k = 1;
	struct DLLNode *temp, *newNode;
	newNode = (DLLNode*)malloc(sizeof(DLLNode));
	if (!newNode)
	{
		printf("Memory Error\n");return;
	}

	newNode->data = data; // Insertion of Node at the beginning of the list.
	if (position == 1) {
		newNode->next = *head;
		newNode->prev = NULL;
		if (*head)
			(*head)->prev = newNode;
		*head = newNode;
		return;
	}

	//If position is not beginning of the list
	temp = *head;
	while ((k < position - 1) && temp->next != NULL)
	{
		temp = temp->next;
		k++;
	}
	//the above loop brings us to one position less than where we have to insert.

	if (k != position - 1)
	{
		printf("Desired position does not exist");
	}

	if (temp->next)//if not null
		temp->next->prev = newNode;
	newNode->prev = temp;
	newNode->next = temp->next;
	temp->next = newNode;
}


int main()
{
	//Creating a sample doubly linked list with two items
	DLLNode * head = (DLLNode*)malloc(sizeof(DLLNode));

	head->prev = NULL;
	head->next = (DLLNode*)malloc(sizeof(DLLNode));
	head->data = 20;

	head->next->prev = head;
	head->next->next = NULL;
	head->next->data = 30;

	DLLInsert(&head, 35, 2); //testing insertion into list at position = 2

	return 0;
}
