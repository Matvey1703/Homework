#include "list.h"

int main()
{
	List* list = create();
	bool run = true;
	int value = 0;

	while (run)
	{
		printf("0 - exit\n"
			"1 - add element\n"
			"2 - delete element\n"
			"3 - display list\n"
			"  select an action...\n");

		char selection = getchar();

		while (getchar() != '\n')
		{
		}

		switch (selection)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("input new value: ");
			scanf_s("%i", &value);
			addElement(value, list);
			break;
		case '2':
			printf("input value to delete: ");
			scanf_s("%i", &value);
			if (!deleteElement(value, list))
			{
				printf("no element for deletion\n");
			}
			break;
		case '3':
			displayList(list);
			break;
		default:
			break;
		}
	}
	deleteList(list);
	return 0;
}