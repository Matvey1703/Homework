#pragma once

struct StackElement;
struct Stack;

bool isEmpty(Stack* stack);
Stack* create();
void push(char value, Stack* stack);
char pop(Stack* stack);
char headValue(Stack* stack);
void deleteStack(Stack* stack);