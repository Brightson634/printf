#include <stdio.h>
#include "main.h"
#include <limits.h>

int main(void)
{
	int n = _printf("hello world %c", 'H');
        printf("\nn = %d \n", n);
}
