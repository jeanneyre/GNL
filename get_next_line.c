/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:39 by crondeau          #+#    #+#             */
/*   Updated: 2021/07/13 14:14:42 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	int		j;
	char	*char_return;

	i = 0;
	if (!str)
		return (0);
	if (str[i])
		i++;
	while (str[i] && str[i - 1] != '\n')
		i++;
	char_return = malloc(sizeof(char) * (i + 1));
	if (!char_return)
		return (0);
	j = 0;
	while (j < i)
	{
		char_return[j] = str[j];
		j++;
	}
	char_return[j] = 0;
	return (char_return);
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

char	*send_line(char **str, char **line, int temp)
{
	*line = get_line(*str);
	*str = record_line(*str);
	if (temp == 0)
	{
		if (*str)
			free(*str);
		*str = NULL;
		if (ft_strcmp(*line, "") == 0)
		{
			free(*line);
			return (NULL);
		}
		return (*line);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			temp;
	char		*line;

	temp = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (NULL);
	bzero(buffer, BUFFER_SIZE);
	while (!return_n(str) && temp != 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE);
		if (temp == -1)
			return (NULL);
		buffer[temp] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (send_line(&str, &line, temp));
}
