#pragma once

#include <stdio.h>

struct List;

// Check if list is empty.
bool isEmpty(List* list);

// Return new list.
List* create();

// Delete list.
void deleteList(List* list);

// Add element in list regarding a and b.
void addElement(int value, List* list, int a, int b);

// Write elements fron list to file.
void writeFromListToFile(FILE* file, List* list);

// Program test.
bool test();
