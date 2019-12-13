#pragma once

struct Stack;

// Check if stack is empty. 
bool isEmpty(Stack* stack);

// Function return new stack.
Stack* create();

// Add new element in head of stack.
void push(char value, Stack* stack);

// Delete element from head of stack.
char pop(Stack* stack);

//  Value in head of stack.
char top(Stack* stack);

// Delete stack.
void deleteStack(Stack* stack);