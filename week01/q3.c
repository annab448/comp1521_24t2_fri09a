#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);
	free(num);
}

int *get_num_ptr(void) {
    int *ptr = malloc(sizeof(int));
	*ptr = 42;
    return ptr;
}
