/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:39 by crondeau          #+#    #+#             */
/*   Updated: 2021/07/13 12:04:11 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*record_line(char *rec_str)
{
	int		i;
	int		j;
	char	*char_return;

	init(&i, &j);
	while (!rec_str)
		return (0);
	while (rec_str[i] && rec_str[i] != '\n')
		i++;
	char_return = malloc(sizeof(char) * (ft_strlen(rec_str) - i));
	if (!char_return)
		return (0);
	if (rec_str[i])
		i++;
	while (rec_str[i])
	{
		char_return[j] = rec_str[i];
		i++;
		j++;
	}
	char_return[j] = '\0';
	free (rec_str);
	return (char_return);
}

char	*send_line(char **str)
{
	char	*line;

	line = get_line(*str);
	*str = record_line(*str);
	return (line);
}

int	temp_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*read_line;
	char		buffer[BUFFER_SIZE + 1];
	int			temp;

	temp = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) != 0)
		return (NULL);
	bzero(buffer, BUFFER_SIZE);
	while (!return_n(str) && temp != 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE);
		if (temp == 0)
		{
			free(str);	
			return (NULL);
		}
		buffer[temp] = '\0';
		str = ft_strjoin(str, buffer);
	}
	read_line = send_line(&str);
	//if (temp == 0)
	//	temp_free(str);
	return (read_line);
}

/*#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main()
{
    int		fd;
	char *str;

    fd = open("textfile.txt", O_RDONLY);

	str = get_next_line(fd);
	printf("%s, %d\n", str, fd);
	while (str != NULL)
	{
		printf ("fd :%s\n", str);
		str = get_next_line(fd);
	}
	printf ("fd :%s\n", str);

    printf ("fd : %s", get_next_line(fd));
	printf ("fd : %s", get_next_line(fd));
    printf ("fd : %s", get_next_line(fd));
    printf ("fd : %s", get_next_line(fd));
    printf ("fd : %s", get_next_line(fd));
    printf ("fd : %s", get_next_line(fd));
    printf ("fd : %s", get_next_line(fd));
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s", get_next_line(fd));    
	printf ("fd : %s\n", get_next_line(fd));    
	printf ("fd : %s\n", get_next_line(fd));
	close(fd);
    return (0);
}*/
