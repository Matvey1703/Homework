#include <stdio.h>

#include "queue.h"

struct QueueElement
{
	int value;
	int priority;
	QueueElement* next;
};

struct Queue
{
	QueueElement* head = nullptr;
	QueueElement* tail = nullptr;
};

bool isEmpty(Queue* queue)
{
	return queue->head == nullptr;
}

Queue* create()
{
	return new Queue;
}

void enqueue(int newValue, int priority, Queue* queue)
{
	if (isEmpty(queue))
	{
		queue->head = new QueueElement{ newValue, priority, nullptr };
		queue->tail = queue->head;
		return;
	}
	if (priority >= queue->head->priority)
	{
		queue->head = new QueueElement{ newValue, priority, queue->head };
		return;
	}
	if (priority <= queue->tail->priority)
	{
		queue->tail->next = new QueueElement{ newValue, priority, nullptr };
		queue->tail = queue->tail->next;
		return;
	}
	QueueElement* prev = nullptr;
	QueueElement* next = queue->head;
	while (next != nullptr && priority <= next->priority)
	{
		prev = next;
		next = next->next;
	}
	prev->next = new QueueElement{ newValue, priority, next };
}

void deleteQueue(Queue* queue)
{
	if (!isEmpty(queue))
	{
		while (queue->head != queue->tail)
		{
			QueueElement* oldHead = queue->head;
			queue->head = queue->head->next;
			queue->tail->next = queue->head;
			delete oldHead;
		}
		delete queue->head;
	}
	delete queue;
}

int dequeue(Queue* queue)
{
	if (isEmpty(queue))
	{
		return -1;
	}
	QueueElement* oldHead = queue->head;
	queue->head = queue->head->next;
	int deletedValue = oldHead->value;
	delete oldHead;
	return deletedValue;
}

void displayQueue(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("Empty queue\n");
		return;
	}
	QueueElement* helpElement = queue->head;
	while (helpElement != nullptr)
	{
		printf("Value: %i Priority: %i\n", helpElement->value, helpElement->priority);
		helpElement = helpElement->next;
	}
}