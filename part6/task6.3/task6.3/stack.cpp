#include "stack.h"

struct StackElement
{
	char value = 0;
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

void push(char value, Stack* stack)
{
	stack->head = new StackElement{ value, stack->head };
}

char pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		return 0;
	}
	char deletedValue = stack->head->value;
	StackElement* newHead = stack->head->next;

	delete stack->head;
	stack->head = newHead;
	return deletedValue;
}

char headValue(Stack* stack)
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