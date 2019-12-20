#pragma once

#include "list.h"

// Sort list by phone if byPhone is true and by name if false.
void mergeSort(List* list, ListElement* head, ListElement* tail, bool byPhone);