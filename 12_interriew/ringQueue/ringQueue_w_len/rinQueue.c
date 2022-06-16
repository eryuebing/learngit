#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringQueue.h"

struct RingQueue *newQueue(int size)
{
	struct RingQueue* q = NULL;
	q = (struct RingQueue*)calloc(1, sizeof(struct RingQueue));
	if(NULL == q)
	{
		printf("Error: memory allocate!");
		return NULL;
	}

        q->arr = (int*)malloc(sizeof(int) * (size + 1));
	if(NULL == q)
	{
		printf("Error: memory allocate!");
		free(q);
		return NULL;
	}

	q->rear = 0;
	q->size = size + 1;
	q->len = 0;
	return q;
}

void deleteQueue(struct RingQueue* queue)
{
	if(queue)
	{
		if(queue->arr) free(queue->arr);
		free(queue);
	}
}

int addToQueue(struct RingQueue*queue, int val)
{
	if(isQueueFull(queue))
	{
		printf("Waring: add failed, queue is full\n");
		return -1;
	}
	queue->arr[queue->rear] = val;
	++queue->len;
	queue->rear = (queue->rear + 1)%(queue->size);
	return 0;
}

int getFromQueue(struct RingQueue* queue, int *pval)
{
	if(NULL == queue || NULL == pval) return -1;

	if(isQueueEmpty(queue))
	{
		printf("Waring: get failed, queue is emtpy\n");
		return -1;
	}
	int head = (queue->rear + queue->size - queue->len)% queue->size;
	*pval = queue->arr[head];
	--(queue->len);
	return 0;
}

int isQueueEmpty(struct RingQueue* queue)
{
	return 0 == queue->len;
}
int isQueueFull(struct RingQueue* queue)
{
	return queue->len == (queue->size - 1);
}
void printQueue(struct RingQueue* queue)
{
	int i = 0;

	int head = (queue->rear + queue->size - queue->len)% queue->size;
	printf("queue: len:%d, head:%d ---------------rear:%d\n",
			queue->len, head, queue->rear);

	for(i = 0; i < queue->size; i++)
	{
		printf("[%d]: %d\t", i, queue->arr[i]);
	}
	return;
}
