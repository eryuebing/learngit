#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "removeNode.h"

struct Linked_Node* creatList(char* str)
{
	assert(str);
	struct Linked_Node *phead = NULL, *ptail = NULL, *pNode ;
	int i;
	int len = strlen(str);

	printf("/n testcase: str = %s ", str);
	for(i=0; i<len; i++)
	{
		pNode = malloc(sizeof(struct Linked_Node));
		assert(pNode);
		pNode->val = str[i] - '0';
		pNode->next = NULL;

		if(NULL == phead)
		{
			phead = pNode;
			ptail = pNode;
		}
		else
		{
			ptail->next = pNode;
			ptail = pNode;
		}
	}
	return phead;

}

void printList(struct Linked_Node* pList)
{
	//assert(pList);
	while(pList)
	{
		printf("%d -->", pList->val);
		pList = pList->next;
	}
	printf(".\n");
	return;
}

void freeList(struct Linked_Node * head)
{
	struct Linked_Node Dummy, *pNode;
	Dummy.next = head;

	while(Dummy.next)
	{
		pNode = Dummy.next;
		Dummy.next = pNode->next;
		free(pNode);
	}
	return;
}

void testcase(char* str, int keyVal)
{

	struct Linked_Node *head = NULL;

        head = creatList(str);
	printList(head);

        removeFromList(&head, keyVal);
        printList(head);
        
	freeList(head);

}	

int main()
{
	testcase("12345", 1);

	testcase("11111", 1);

	testcase("123456", 6);

	testcase("121314", 1);

	testcase("121212", 2);

	testcase("", 2);

	testcase("234567", 1);


	testcase("1", 1);

}
