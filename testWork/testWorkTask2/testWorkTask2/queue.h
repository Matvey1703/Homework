#pragma once

struct Queue;

// Check if queue is empty.
bool isEmpty(Queue* queue);

// Return new queue.
Queue* create();

// Add new element in queue (if an element with this priority already exists, add a new element next to the elements with this priority).
void enqueue(int newValue, int priority, Queue* queue);

// Delete queue.
void deleteQueue(Queue* queue);

// Delete queue with the most hight priority.
int dequeue(Queue* queue);

// Display queue.
void displayQueue(Queue* queue);