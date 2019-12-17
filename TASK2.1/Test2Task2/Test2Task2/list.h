#pragma once

struct List;

bool isEmpty(List* list);
List* create();
void addToFront(List* list, int value);
void addToBack(List* list, int value);
void displayList(List* list);
void deleteFromFront(List* list);
void deleteList(List* list);
int listSize(List* list);
bool listCompaisor(List* firstList, List* secondList);
bool symmetryCheck(List* list);