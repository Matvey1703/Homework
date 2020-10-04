#include <stdio.h>

#include "queue.h"

 int main()
{
	Queue* queue = create();
	bool run = true;
	int value = 0;
	int priority = 0;

	while (run)
	{
		printf("0 - exit\n"
			"1 - add element\n"
			"2 - delete element with the most hight priority\n"
			"3 - display list\n"
			"  select an action...\n");

		
		while (getchar() != '\n')
		{
		}
		const char selection = getchar();

		switch (selection)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("input new value: ");
			scanf("%i", &value);
			printf("input new priority: ");
			while (getchar() != '\n')
			{
			}
			scanf("%i", &priority);
			enqueue(value, priority, queue);
			break;
		case '2':
			printf("Deleted element: %i\n", dequeue(queue));
			break;
		case '3':
			displayQueue(queue);
			break;
		default:
			break;
		}
	}

	deleteQueue(queue);
	return 0;
} 