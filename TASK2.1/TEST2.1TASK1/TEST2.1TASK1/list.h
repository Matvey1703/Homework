#pragma once

#include <stdio.h>

struct ListElement;
struct List;
bool isEmpty(List* list);
List* create();
void addToFront(int newValue, List* list);
void displayList(List* list);
void deleteList(List* list);

void listRevol(FILE* file, List* revList); //list flipping function

bool test(); //test of list flipping function