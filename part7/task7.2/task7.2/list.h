#pragma once

#include <stdio.h>

struct ListElement;

struct List;

// Check if list is empty.
bool isEmpty(List* list);

// Return new list.
List* create();

// Delete an element using a pointer to it.
bool deleteElement(ListElement** elementToDelete, List* list);

// Add element in head of list.
void addElement(int newValue, List* list);

// Print list.
void displayList(List* list);

// Delete list.
void deleteList(List* list);

// Pass the pointer on head of list to listElement.
void listHead(ListElement** listElement, List* list);

// Check if element1 and element2 are equel.
bool listElements—omparison(ListElement** element1, ListElement** element2);

// Pass the pointer on next to listElement.
void shiftNext(ListElement** listElement);

// Return value of head.
int top(ListElement** listElement);