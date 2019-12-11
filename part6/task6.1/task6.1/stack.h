#pragma once

struct StackElement;
struct Stack;
bool isEmpty(Stack* stack);
Stack* create();
void push(int value, Stack* stack);
int pop(Stack* stack);
int headValue(Stack* stack);
void deleteStack(Stack* stack);