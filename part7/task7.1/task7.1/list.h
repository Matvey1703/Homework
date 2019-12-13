#pragma once

#include <stdio.h>

struct ListElement;
struct List;

// Check if list is empty. 
bool isEmpty(List* list);

// Return new List.
List* create();

// Delete element from list by value.
bool deleteElement(int value, List* list);

// Add new elemeent in sorted list.
void addElement(int newValue, List* list);

//  Print list.
void displayList(List* list);

// Delete list.
void deleteList(List* list);