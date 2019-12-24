#pragma once

struct List;

// Check if list is empty.
bool isEmpty(List* list);

// Return new List.
List* create();

// Add new element in list.
void addElement(int value, int position, List* list);

// Print list.
void displayList(List* list);

// Delete list.
void deleteList(List* list);

// Check if lists match.
bool listComparison(List* list1, List* list2);

// Delet element indicated position;
bool deleteByPosition(List* list, int position);

// Check if number in list.
bool isInList(List* list, int number);