#include <stdio.h>
#include <stdlib.h>
#include "removeNode.h"


void removeFromList(struct Linked_Node **ppList, int keyVal)
{
	struct Linked_Node *pPre, *pCur, *pNext;
	struct Linked_Node Dummy;

	if(!ppList || !(*ppList)) return;
	
	Dummy.next = *ppList;
	pPre = &Dummy;
	pCur = Dummy.next;

	while(pCur)
	{
		pNext = pCur->next;
		if(pCur->val == keyVal)
		{
			pPre->next = pNext;
			free(pCur);
		}
		else
		{
			pPre = pCur;
		}
		pCur = pNext;
	}

	*ppList = Dummy.next;
	return;
}


