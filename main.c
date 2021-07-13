#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>


int		main(void)
{
	char	*ret;
	int		fd;

	fd = open("41_with_nl", O_RDONLY);
	while ((ret = get_next_line(fd)))
	{
		printf("%s\n", ret);
		free(ret);
	}
	printf("%s\n", ret);
}
