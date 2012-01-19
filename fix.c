#include <stdio.h>
#include <stdlib.h>

int main(int ac, char * av[])
{
	if (ac != 4)
	{
		printf("Usage: [filename] [prefix code] [replace code]\n");
		exit(EXIT_FAILURE);
	}
	
	unsigned int prefix = atoi(av[2]), replace = atoi(av[3]);
	if (!prefix || !replace)
	{
                printf("Prefix and replace code must be dec and > 0!\n");
                exit(EXIT_FAILURE);
        }

	FILE *f = fopen(av[1], "r");
	FILE *f2 = fopen("out.sql", "w");
	unsigned char ch, chp = getc(f);
	unsigned int i;
	for (i = 0; !feof(f); ++i)
	{
		ch = getc(f);
		if (chp == prefix && ch == 63)
			ch = replace;
		fprintf(f2, "%c", chp);
		chp = ch;
	}
	fclose(f);
	fclose(f2);
}
