#pragma once

struct StackElement;
struct Stack;

// Check if stack is empty.
bool isEmpty(Stack* stack);

// Return new Stack.
Stack* create();

// Add new element in head of stack
void push(int value, Stack* stack);

// Delete element fron head of stack.
int pop(Stack* stack);

// Delete stack.
void deleteStack(Stack* stack);