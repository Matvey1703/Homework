#include "stack.h"

struct StackElement
{
	int value = 0;
	StackElement* next = nullptr;
};

struct Stack
{
	StackElement* head = nullptr;
};

bool isEmpty(Stack* stack)
{
	return stack->head == nullptr;
}

Stack* create()
{
	return new Stack;
}

void push(int value, Stack* stack)
{
	stack->head = new StackElement{ value, stack->head };
}

int pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		return -1;
	}
	int deletedValue = stack->head->value;
	StackElement* newHead = stack->head->next;

	delete stack->head;
	stack->head = newHead;
	return deletedValue;
}

int headValue(Stack* stack)
{
	return stack->head->value;
}

void deleteStack(Stack* stack)
{
	while (!isEmpty(stack))
	{
		StackElement* newHead = stack->head->next;

		delete stack->head;
		stack->head = newHead;
	}
	delete stack;
}