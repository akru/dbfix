#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	unsigned char *c = av[1];
	if (ac != 2)
        {
                printf("Usage: code [symbol]\n");
                exit(EXIT_FAILURE);
        }
	printf("UTF8 :: %d : %d\n", c[0], c[1]);
}
