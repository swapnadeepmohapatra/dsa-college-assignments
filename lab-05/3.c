#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
	struct node *prev;
};

void createList(struct node **head)
{
	if (*head == NULL)
	{
		int n;
		printf("\nEnter the number of nodes: ");
		scanf("%d", &n);
		if (n != 0)
		{
			int data;
			struct node *newnode, *temp;
			newnode = malloc(sizeof(struct node));
			(*head) = newnode;
			temp = (*head);
			printf("\nEnter number to be inserted: ");
			scanf("%d", &data);
			newnode->info = data;
			newnode->prev = NULL;

			for (int i = 2; i <= n; i++)
			{
				newnode = malloc(sizeof(struct node));
				temp->next = newnode;
				printf("\nEnter number to be inserted: ");
				scanf("%d", &data);
				newnode->info = data;
				newnode->prev = temp;
				temp = newnode;
			}
			temp->next = NULL;
		}
		printf("\nThe list is created\n");
	}
	else
	{
		printf("\nThe list is already created\n");
	}
}

void traverse(struct node *head)
{
	struct node *temp;

	if (head == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			printf("Data = %d\n", temp->info);
			temp = temp->next;
		}
	}
}

void insertAtFront(struct node **head)
{
	int data;
	struct node *temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;

	if (*head != NULL)
	{
		temp->next = (*head);
		(*head)->prev = temp;
	}
	else
	{
		temp->next = NULL;
	}
	(*head) = temp;
}

void insertAtEnd(struct node **head)
{
	int data;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));

	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	newnode->next = NULL;

	if (*head == NULL)
	{
		newnode->prev = NULL;
		(*head) = newnode;
	}
	else
	{
		temp = (*head);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}

void insertAtPosition(struct node **head)
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	printf("\nEnter position and data: ");
	scanf("%d %d", &pos, &data);

	temp = (*head);
	newnode->info = data;

	if (pos == 1)
	{
		newnode->next = (*head);
		newnode->prev = NULL;
		if (*head != NULL)
		{
			(*head)->prev = newnode;
		}
		(*head) = newnode;
		return;
	}

	while (i < pos - 1 && temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
	{
		printf("\nPosition out of range\n");
		free(newnode);
	}
	else
	{
		newnode->next = temp->next;
		newnode->prev = temp;
		if (temp->next != NULL)
		{
			temp->next->prev = newnode;
		}
		temp->next = newnode;
	}
}

void deleteFirst(struct node **head)
{
	struct node *temp;
	if (*head == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = (*head);
		(*head) = (*head)->next;
		if ((*head) != NULL)
		{
			(*head)->prev = NULL;
		}
		free(temp);
	}
}

void deleteEnd(struct node **head)
{
	struct node *temp;
	if (*head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		temp = (*head);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		if (temp->prev != NULL)
		{
			temp->prev->next = NULL;
		}
		else
		{
			(*head) = NULL;
		}
		free(temp);
	}
}

void deletePosition(struct node **head)
{
	struct node *temp, *position;
	int i = 1, pos;

	if (*head == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter index : ");
		scanf("%d", &pos);
		temp = (*head);

		if (pos == 1)
		{
			(*head) = (*head)->next;
			if ((*head) != NULL)
			{
				(*head)->prev = NULL;
			}
			free(temp);
			return;
		}

		while (i < pos - 1 && temp != NULL)
		{
			temp = temp->next;
			i++;
		}

		if (temp == NULL || temp->next == NULL)
		{
			printf("\nPosition out of range\n");
		}
		else
		{
			position = temp->next;
			temp->next = position->next;
			if (position->next != NULL)
			{
				position->next->prev = temp;
			}
			free(position);
		}
	}
}

void swapAlternateNodes(struct Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return; // Nothing to swap
	}

	struct Node *current = head;
	struct Node *temp;

	while (current != NULL && current->next != NULL)
	{
		// Swap data of current and next nodes
		temp = current->data;
		current->data = current->next->data;
		current->next->data = temp;

		// Move to the next pair of nodes
		current = current->next->next;
	}
}
