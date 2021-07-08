/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:39 by crondeau          #+#    #+#             */
/*   Updated: 2021/07/06 15:26:17 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		i;
	char	*char_return;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	char_return = malloc(sizeof(char) * (i + 1));
	if (!char_return)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		char_return[i] = str[i];
		i++;
	}
	char_return[i] = 0;
	return (char_return);
}

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

void	send_line(char **str, char **line)
{
	*line = get_line(*str);
	*str = record_line(*str);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[256];
	char		buffer[BUFFER_SIZE + 1];
	int			temp;

	temp = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= 256)
		return (-1);
	bzero(buffer, BUFFER_SIZE);
	while (!return_n(str[fd]) && temp != 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE);
		if (temp == -1)
			return (-1);
		buffer[temp] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	send_line(&(str[fd]), line);
	if (temp == 0)
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}
