#pragma once

struct List;

// Check if list is empty.
bool isEmpty(List* list);

// Return new List.
List* create();

// Add new element in list.
void addElementToFront(int value, List* list);

// Add new element in list.
void addElementToBack(int value, List* list);

// Print list.
void displayList(List* list);

// Delete list.
void deleteList(List* list);

// Check if lists match.
bool listComparison(List* list1, List* list2);

// Check if number in list.
bool isInList(List* list, int number);

// Return revolved list. 
List* revolve(List* list);

// Fill by rand from diapazone.
void fillByRand(List* list, int rangeBegin, int rangeEnd, int size);