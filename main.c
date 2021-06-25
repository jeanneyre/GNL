#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void gnl(int fd)
{
	char *line;

	printf("[%d] ", get_next_line(fd, &line));
	printf("%s\n", line);
	free(line);
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int i = 0;

	(void)ac;
	while (i++ < 10)
		gnl(fd);
	close(fd);
	return (0);
}
