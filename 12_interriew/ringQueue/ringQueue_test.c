#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringQueue.h"


int main()
{
	int w = 0;
	int r = 0;
	int len = 7;
	
	w = 0;
	r = 0;
	len = 7;
	printf("w: %d  r:%d len:%d \n", w, r, (w-r)%len);
	
	w = 0;
	r = 6;
	len = 7;
	printf("w: %d  r:%d len:%d \n", w, r, (w-r)%len);
	
	/*struct RingQueue * queue = NULL;
	int i = 0;

	queue = newQueue(20);
        if(!queue) return -1;

	while(!isQueueFull(queue))
	{
		printf("add %d to queue\n", i);
		addToQueue(queue, i++);
	}

	while(!isQueueEmpty(queue))
	{
		getFromQueue(queue,&i);
		printf("get %d from queue\n", i);
	}	

	deleteQueue(queue);*/
	
	int size = 0;
	printf("please input size of Queue:\n");
	scanf("%d",&size);

	struct RingQueue * queue = NULL;
	int i = 0, val, ret;
	char input[100];


	queue = newQueue(size);
        if(!queue) return -1;
	
	while(1)
	{
		printf("\n\nusage: please input 'add' to add node to queue\n"\
		       "please input 'get' to get node from queue\n"\
		       "please input 'del' to delete the Queue\n\n"
	      		);
		scanf("%s", input);
		if(0 == strcmp("add", input))
		{
			printf("to add a Node, please input number of Node:\n");
			scanf("%d", &val);

		        ret = addToQueue(queue, val);
			if(ret == -1)
			{
				printf("add node error\n");
			}
		}
		else if(0 == strcmp("get", input))
		{
			
		        ret = getFromQueue(queue,&val);
			if(ret == -1)
			{
				printf("get node error\n");
			}
			else
			{
				printf("get the node %d\n",val);
			}
		}
	        else if(0 == strcmp("del", input))
		{
			break;
		}

		printQueue(queue);
		
	}

	deleteQueue(queue);
	return 0;
}
