#include "Queue.h"

/***************** Queue ADT Implementation *****************/
/*
typedef struct intNode
{
	unsigned int data;
	struct intNode* next;
}intNode;

typedef struct Queue
{
	intNode* head;
	intNode* tail;
}Queue;
*/
void initQueue(Queue* q)
{
	q->head = q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* pCurIntNode = q->head;
	while (pCurIntNode != NULL)
	{
		intNode* pCurIntNodeToDel = pCurIntNode;
		pCurIntNode = pCurIntNode->next;
		free(pCurIntNode);
	}
	q->head = q->tail = NULL;
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* pNewIntNode = (intNode*)malloc(sizeof(intNode));
	pNewIntNode->data = data;
	pNewIntNode->next = NULL;
	if (q->tail == NULL)
	{
		q->head = q->tail = pNewIntNode;
	}
	else
	{
		q->tail->next = pNewIntNode;
		q->tail = pNewIntNode;
	}
}

unsigned int dequeue(Queue* q)
{
	char retNum = q->head->data;
	intNode* pSecondNode = q->head->next;
	free(q->head);
	q->head = pSecondNode;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	return retNum;
}

int isEmptyQueue(const Queue* q)
{
	return q->head == NULL ? 1 : 0;
}

/***************** Functions using Queues - Implementation/definition **************************/
void rotateQueue(Queue* q)
{
	Queue helperQ;
	initQueue(&helperQ);
	int inQSize = 0;
	while (isEmptyQueue(q) == 0)
	{
		inQSize++;
		enqueue(&helperQ, dequeue(q));
	}
	while (isEmptyQueue(&helperQ) == 0)
	{
		enqueue(q, dequeue(&helperQ));
	}
	for (int i = 0; i < inQSize - 1; i++)
	{
		enqueue(q, dequeue(q));
	}
}

void cutAndReplace(Queue* q)
{
	if (q == NULL || q->head == NULL)
	{
		return;
	}
	Queue helperQ;
	initQueue(&helperQ);
	int inQSize = 0;
	while (isEmptyQueue(q) == 0)
	{
		inQSize++;
		enqueue(&helperQ, dequeue(q));
	}
	if (inQSize % 2 == 1)
	{
		int inQSum = 0;
		while (isEmptyQueue(&helperQ) == 0)
		{
			int curNum = dequeue(&helperQ);
			inQSum += curNum;
			enqueue(q, curNum);
		}
		enqueue(q, inQSum / inQSize);
		inQSize++;
	}
	else
	{
		while (isEmptyQueue(&helperQ) == 0)
		{
			enqueue(q, dequeue(&helperQ));
		}
	}

	int inQSizeDiv2 = inQSize / 2;
	for (int i = 0; i < inQSizeDiv2; i++)
	{
		enqueue(&helperQ, dequeue(q));
	}
	Queue revTailHalfQ;
	initQueue(&revTailHalfQ);
	while (isEmptyQueue(q) == 0)
	{
		rotateQueue(q);
		enqueue(&revTailHalfQ, dequeue(q));
	}
	while (isEmptyQueue(&revTailHalfQ) == 0)
	{
		enqueue(q, dequeue(&revTailHalfQ));
	}
	while (isEmptyQueue(&helperQ) == 0)
	{
		enqueue(q, dequeue(&helperQ));
	}
}

// ->643152 changes queue to: ->123456
// ->643152->64352 (1)
// ->64352->6435 (12)
// ->6435->645 (123)
// ->645->65 (1234)
// ->65->6 (12345)
// ->6-> (123456)
void sortKidsFirst(Queue* q)
{
	if (q == NULL || q->head == NULL)
	{
		return;
	}
	Queue helperQ;
	initQueue(&helperQ);
	Queue sortedQ;
	initQueue(&sortedQ);
	while (isEmptyQueue(q) == 0)
	{
		int minNum = dequeue(q);
		int isSortDone = 0;
		if (isEmptyQueue(q) == 1)
		{
			isSortDone = 1;
		}
		else
		{
			enqueue(q, minNum);
		}
		while (isEmptyQueue(q) == 0)
		{
			int curNum = dequeue(q);
			if (curNum < minNum)
			{
				minNum = curNum;
			}
			enqueue(&helperQ, curNum);
		}
		enqueue(&sortedQ, minNum);

		if (isSortDone == 0)
		{
			while (isEmptyQueue(&helperQ) == 0)
			{
				int curNum = dequeue(&helperQ);
				if (curNum != minNum)
				{
					enqueue(q, curNum);
				}
			}
		}
	}
	while (isEmptyQueue(&sortedQ) == 0)
	{
		enqueue(q, dequeue(&sortedQ));
	}
}