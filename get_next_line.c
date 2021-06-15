/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:39 by crondeau          #+#    #+#             */
/*   Updated: 2021/06/07 10:49:05 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checkerror(int fd, char **str, char **line)
{
	if (fd == -1 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*get_line(char *str)
{
	int	i;
	char	*ret;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);


int	get_next_line(int fd, char **line)
{
	static char	*str;
	int		i;

	if (checkerror(fd, &str, line) == -1)
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
}
