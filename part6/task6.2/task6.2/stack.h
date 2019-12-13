#pragma once

struct Stack;


bool isEmpty(Stack* stack);
Stack* create();
void push(int value, Stack* stack);
int pop(Stack* stack);
void deleteStack(Stack* stack);