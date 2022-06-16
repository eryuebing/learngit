#ifndef __RING_QUEUE__
#define __RING_QUEUE__

struct RingQueue
{
	int *arr;
	int size; //arr size
	int rear;  //rear of queue (write ptr)
	int head;  //head of queue (read ptr);
	int len; //element length
};

struct RingQueue *newQueue(int size);
void deleteQueue(struct RingQueue* queue);
int addToQueue(struct RingQueue*queue, int val);
int getFromQueue(struct RingQueue* queue, int *val);
int isQueueEmpty(struct RingQueue* queue);
int isQueueFull(struct RingQueue* queue);
void printQueue(struct RingQueue* queue);
#endif
