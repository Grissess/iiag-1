#include <stdio.h>
#include <stdlib.h>
#include "util/list.h"

#define expect(C) \
	if (!(C)) { \
		fprintf(stderr, "test failed: " #C); \
		return EXIT_FAILURE; \
	}

int sum = 0;

void sumify(int * x)
{
	sum += *x;
}

void push_all(list_t * ls, int * ints, int cnt)
{
	int i;

	for (i = 0; i < cnt; i++) {
		list_push(ls, ints + i);
	}
}

int main()
{
	list_t * l = list_new();

	int stuff[] = {1, 2, 4, 100, 101};
	int stuff2[] = {8, 16};

	push_all(l, stuff, 5);

	expect(*(int *)list_pop(l) == 101);
	expect(*(int *)list_pop(l) == 100);

	push_all(l, stuff2, 2);

	list_foreach(l, (list_foreach_func)sumify);

	expect(sum == 1 + 2 + 4 + 8 + 16);

	return 0;
}
