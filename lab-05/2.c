#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node to store a non-zero element
struct Node
{
	int row;
	int col;
	int value;
	struct Node *next;
};

// Structure for the header node to store dimensions and row pointers
struct HeaderNode
{
	int rows;
	int cols;
	struct Node **rowPtrs;
};

// Function to create a new node with given values
struct Node *createNode(int row, int col, int value)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newNode->row = row;
	newNode->col = col;
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

// Function to insert a non-zero element into the linked list
void insertElement(struct HeaderNode *header, int row, int col, int value)
{
	if (row < 0 || row >= header->rows || col < 0 || col >= header->cols)
	{
		printf("Invalid input element (%d, %d, %d).\n", row, col, value);
		return;
	}

	struct Node *newNode = createNode(row, col, value);
	int index = row;
	if (header->rowPtrs[index] == NULL)
	{
		header->rowPtrs[index] = newNode;
	}
	else
	{
		struct Node *current = header->rowPtrs[index];
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

// Function to display the sparse matrix
void displaySparseMatrix(struct HeaderNode *header)
{
	printf("Sparse Matrix:\n");
	for (int i = 0; i < header->rows; i++)
	{
		struct Node *current = header->rowPtrs[i];
		for (int j = 0; j < header->cols; j++)
		{
			if (current != NULL && current->col == j)
			{
				printf("%d ", current->value);
				current = current->next;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main()
{
	int rows, cols;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d", &rows, &cols);

	struct HeaderNode *header = (struct HeaderNode *)malloc(sizeof(struct HeaderNode));
	if (header == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
	header->rows = rows;
	header->cols = cols;

	// Initialize row pointers to NULL
	header->rowPtrs = (struct Node **)malloc(rows * sizeof(struct Node *));
	for (int i = 0; i < rows; i++)
	{
		header->rowPtrs[i] = NULL;
	}

	int row, col, value;
	printf("Enter the elements of the sparse matrix (row, col, value):\n");
	while (1)
	{
		scanf("%d %d %d", &row, &col, &value);
		if (row < 0 || col < 0 || row >= rows || col >= cols)
		{
			break;
		}
		insertElement(header, row, col, value);
	}

	displaySparseMatrix(header);

	// Free allocated memory
	for (int i = 0; i < rows; i++)
	{
		struct Node *current = header->rowPtrs[i];
		while (current != NULL)
		{
			struct Node *temp = current;
			current = current->next;
			free(temp);
		}
	}
	free(header->rowPtrs);
	free(header);

	return 0;
}
