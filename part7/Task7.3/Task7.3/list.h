#pragma once

struct List;
struct ListElement;

// Check if list is empty.
bool isEmpty(List* list);

// Return new List.
List* create();

// Add new element in list.
void addElement(char* name, char* phone, List* list);

// Print list.
void displayList(List* list);

// Delete list.
void deleteList(List* list);

// Return pointer on head of list. 
ListElement* headPointer(List* list);

// Return pointer on tail of list.
ListElement* tailPointer(List* list);

// Check if lists match.
bool listComparison(List* list1, List* list2);

// Return pointer on listElement->next
ListElement* shiftNext(ListElement* listElement);

// Return pointer on listElement->next
ListElement* shiftPrev(ListElement* listElement);

// Return listElement->phone.
char* fieldPhone(ListElement* listElement);

// Return listElement->name.
char* fieldName(ListElement* listElement);

// Copy fields of element2 to element1.
void copyFields(ListElement** element1, ListElement** element2);