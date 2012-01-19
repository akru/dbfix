#include <stdio.h>
#include <stdlib.h>

int main(int ac, char * av[])
{
	unsigned char ch;
	int i;
	if (ac != 2)
	{
		printf("Usage: view [filename]\n");
		exit(EXIT_FAILURE);
	}
        FILE *f = fopen(av[1], "r");
	if (f == NULL)
	{
                printf("Can't open file!\n");
                exit(EXIT_FAILURE);
        }
        for (i = 0; !feof(f); ++i)
        {
                ch = getc(f);
                printf("%c :: %d\n", ch, (unsigned char) ch);
        }
        fclose(f);
}
