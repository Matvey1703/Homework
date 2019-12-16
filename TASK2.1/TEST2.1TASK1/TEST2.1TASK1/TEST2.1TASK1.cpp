#include <stdio.h>

#include "list.h"

int main()
{
	if (!test())
	{
		printf("error");
		return -1;
	}

	FILE* file = fopen("file.txt", "r");
	List* revList = create();

	listRevol(file, revList);
	fclose(file);
	displayList(revList);

	deleteList(revList);
	return 0;
}