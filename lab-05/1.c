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

int main()
{
	int choice;
	struct node *head = NULL;

	while (1)
	{
		printf("\n1. To see list\n");
		printf("2. For insertion at starting\n");
		printf("3. For insertion at end\n");
		printf("4. For insertion at any position\n");
		printf("5. For deletion of first element\n");
		printf("6. For deletion of last element\n");
		printf("7. For deletion of any position\n");
		printf("8. To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			traverse(head);
			break;
		case 2:
			insertAtFront(&head);
			break;
		case 3:
			insertAtEnd(&head);
			break;
		case 4:
			insertAtPosition(&head);
			break;
		case 5:
			deleteFirst(&head);
			break;
		case 6:
			deleteEnd(&head);
			break;
		case 7:
			deletePosition(&head);
			break;
		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
