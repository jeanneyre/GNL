#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int		fd;
	int		i;
	char	*line;

	fd = open("textfile.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line %i : %s", i, line);
		i++;
		line = get_next_line(fd);
	}
	printf("line %i : %s", i, line);
	close(fd);
	free(line);
	return (0);
}