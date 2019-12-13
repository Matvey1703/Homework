#pragma once

// Displaying all content. 
void displayPhoneBook(Note* book, int size);

// Check the similarity of two strings.
bool isSimilar(char* firstString, char* secondString);

// Save all content if file.
void saveChanges(Note* book, int size, FILE* file);

// Load all content from file.
int loadBook(Note* book, FILE* file);


// Search phone using name.
int searchByName(Note* book, char* name, int size);

// Search name using phone.
int searchByPhone(Note* book, char* phone, int size);