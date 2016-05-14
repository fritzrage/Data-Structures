#include <stdio.h>
#include <malloc.h>

typedef struct CLLNode {
	int data;
	CLLNode * next;
};

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

int main()
{
	CLLNode *head = (CLLNode*)malloc((sizeof(CLLNode)));
	head->data = 20;
	head->next = (CLLNode*)malloc((sizeof(CLLNode)));

	head->next->data = 30;
	head->next->next = (CLLNode*)malloc((sizeof(CLLNode)));

	head->next->next->data = 40;
	head->next->next->next = head;

	printf("Length of the list = %d\n", CLLLength(&head));

	return 0;
}
