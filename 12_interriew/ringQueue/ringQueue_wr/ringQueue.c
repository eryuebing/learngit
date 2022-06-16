#include <stdio.h>
#include <stdlib.h>
#include "ringQueue.h"

struct RingQueue *newQueue(int size)
{
	struct RingQueue *queue = NULL;
	queue = (struct RingQueue*) calloc(1, sizeof(struct RingQueue));
	if(NULL == queue)
	{
		printf("Fatal error: no memory\n");
		return NULL;
	}

	queue->arr = (int*)malloc(sizeof(int)*(size+1)); //ringqueue: there is one element waist
	if(NULL == queue->arr)
	{
		printf("Fatal error: no memory\n");
		free(queue);
		return NULL;
	}
	
	queue->size = size + 1;
	queue->head = 0;
	queue->rear = 0;
	//queue->length = 0;
	return queue;
}

void deleteQueue(struct RingQueue* queue)
{
	if(NULL == queue) return;

	if(queue->arr) free(queue->arr);
	free(queue);
	return;

}

int addToQueue(struct RingQueue*queue, int val)
{
	if(isQueueFull(queue))
	{
		printf("Warning: add to Queue failed: full\n");
		return -1;	
	}

	queue->arr[queue->rear] = val;
	queue->rear = (queue->rear + 1)% (queue->size);
	return 0;
}

int getFromQueue(struct RingQueue* queue, int *val)
{
	if(isQueueEmpty(queue))
	{
		printf("Warning: get from Queue failed: empty Queue\n");
		return -1;
	}

	*val = queue->arr[queue->head];
       queue->head = (queue->head + 1)% (queue->size);
       return 0;       
}

int isQueueEmpty(struct RingQueue* queue)
{
	return queue->head == queue->rear;
}

int isQueueFull(struct RingQueue* queue)
{
	return (queue->rear + 1)%(queue->size) == queue->head; 
}


int queueLength(struct RingQueue* queue)
{
	return (queue->rear - queue->head + queue->size)%(queue->size);
}

void printQueue(struct RingQueue* queue)
{
	int i = 0;
	printf("\n");

	printf("%d elem: head: %d -----------------rear %d\n",queueLength(queue), queue->head, queue->rear);
	for(i = 0; i<queue->size; i++)
	{
		printf("[%d]:%d\t",i, queue->arr[i]);
	}
	printf("\n");
}

