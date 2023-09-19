#include <stdio.h>

int main() {
	int a[] = {1, 2, 3};
	printf("%p %p %p\n", a, (void *) a + sizeof(a), a + sizeof(a)/sizeof(*a));
}
