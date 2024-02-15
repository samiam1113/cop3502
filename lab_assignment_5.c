#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	node* tmp = head;
	//every traversal is counted until NULL is reached
	while(tmp != NULL) {
		count++;
		tmp = tmp -> next;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int strLength, i=0;
	//length function run and value is returned
	strLength = length(head);
	//allocated memory size of length +1 for null character
	char* cStr = (char*)malloc((strLength+1)*sizeof(char)); 
	
	//array created with each letter 
	node* tmp = head;
	while(tmp != NULL) {
		cStr[i++] = tmp->letter;
		tmp = tmp-> next;
	}
	cStr[i]= '\0';
	return cStr;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	//allocates memory to new node, initializes it and inserts to list
	node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->letter = c;
	newNode->next = NULL;

	if(*pHead == NULL) {
		*pHead = newNode;
	}
	else {
		node* tmp = *pHead;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	//memory deallocated
	node* tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}