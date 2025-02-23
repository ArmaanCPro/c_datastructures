#include <stdio.h>

#include "linkedlist.h"

int main(void)
{
	linked_list ll;
	ll_init(&ll, 5);

	printf("val 1: %i\n", ll.head->value);
	return 0;
}
