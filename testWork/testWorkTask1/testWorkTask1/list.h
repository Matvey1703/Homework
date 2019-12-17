#pragma once

struct List;

// Check if list is empty. 
bool isEmpty(List* list);

// Return new List.
List* create();

// Add new elemeent in sorted list (if element is already in list, increase count by 1).
void addElement(int newValue, List* list);

//  Print list.
void displayList(List* list);

// Delete list.
void deleteList(List* list);

// Check if list is sorted.
bool checkSort(List* list);

// Check if number in list.
bool isInList(List* list, int number);