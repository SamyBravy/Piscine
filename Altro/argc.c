#include <unistd.h>

void putstr(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i += 1;
	}
}



int main(int argc, char **argv)
{
	int i = argc + '0';
	write(1, &i, 1);
	/*
	while(argv[i])
	{
		putstr(argv[i]);
		write(1, &i, 4);
		i += 1;
	}*/
}
