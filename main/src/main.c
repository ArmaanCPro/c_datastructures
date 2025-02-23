#include <stdio.h>

#include "linkedlist.h"

int main(void)
{
	linked_list ll;
	ll_init(&ll, 5);

	ll_push(&ll, 420);

	printf("val 1: %i\n", ll.head->value);
	printf("val 2: %i\n", ll.head->next->value);
	printf("val 3: %i\n", ll_pop(&ll));
	printf("val 4: %i\n", ll.head->next == NULL ? 1 : 0);

	ll_free_nodes(&ll);
	return 0;
}
