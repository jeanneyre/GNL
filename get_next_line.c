/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:39 by crondeau          #+#    #+#             */
/*   Updated: 2021/06/24 15:55:11 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	return_n(char *str) // retourne le caractere de la chaine en parametre
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *str) // j'obtiens ma ligne avant '\n'
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

char	*record_line(char *rec_str) // j'enregistre la ligne suivante 
{
	int		i;
	int		j;
	char	*char_return;

	i = 0;
	j = 0;
	while (!rec_str)
		return (0);
	while (rec_str[i] && rec_str[i] != '\n')
		i++;
	char_return = malloc(sizeof(char) * (ft_strlen(rec_str) - i)); // on ne compte pas le '\0'
	if (!char_return)
		return (0);
	if (rec_str[i])
		i++;
	while (rec_str[i])
	{
		char_return[j] = rec_str[i]; // str1[j] = str2[i] ??
		i++;
		j++;
	}
	char_return[j] = '\0';
	free (rec_str);
	return (char_return);
}

int	get_next_line(int fd, char **line)
{
	static char	*str; // variable static qui se souvient de ce qu'il reste du dernier appel de read (pointeur vers un pointeur)
	char		buffer[BUFFER_SIZE + 1]; // buffer de destination
	int			temp; // tampon a ajouter a la ligne de resultat

	temp = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (-1);
	// bzero(buffer, BUFFER_SIZE); // si il existe je mets des '0' = garder cette habitude a chaque fois aue je malloc buffer
	while (!return_n(str) && temp != 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE);
		if (temp == -1)
			return (-1);
		buffer[temp] = '\0';
		str = ft_strjoin(str, buffer);
	}
	*line = get_line(str);
	str = record_line(str);
	if (temp == 0)
	{
		if (str)
			free(str);
		str = NULL;
		return (0);
	}
	return (1);
}		


