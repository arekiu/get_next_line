/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:11:59 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/15 13:19:36 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_set_line(int fd, char *buff, char *left_over);
static char	*_clean_line(char *temp_line);
static char	*_set_left_over(char *left_over);
/*
int	main(void)
{
	int	fd;

	fd = open("example.txt", O_RDONLY);
	printf("la linea: %s$\n", get_next_line(fd));
	printf("la linea2: %s$", get_next_line(fd));
	//printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}*/

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*left_over;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		return (NULL);
	}
	line = _set_line(fd, buff, left_over);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	left_over = ft_strdup(line);
	line = _clean_line(line);
	left_over = _set_left_over(left_over);
	return (line);
}

static char	*_set_line(int fd, char *buff, char *left_over)
{
	ssize_t	nr_bytes;
	char	*temp;

	nr_bytes = 1;
	while (nr_bytes > 0)
	{
		nr_bytes = read (fd, buff, BUFFER_SIZE);
		if (nr_bytes < 0)
		{
			free(left_over);
			return (NULL);
		}
		if (nr_bytes == 0)
			break ;
		buff[nr_bytes] = '\0';
		if (!left_over)
			left_over = ft_strdup("");
		temp = left_over;
		left_over = ft_strjoin(temp, buff);
		free (temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (left_over);
}

static char	*_clean_line(char *temp_line)
{
	int		i;
	char	*temp;

	i = 0;
	if(!temp_line || temp_line[i] == '\0')
		return (NULL);
	while (temp_line[i] != '\0' && temp_line[i] != '\n')
		i++;
	if (temp_line[i] == '\n')
		i++;
	temp = temp_line;
	temp_line = ft_substr(temp, 0, i);
	free (temp);
	temp = NULL;
	return (temp_line);
}

static char	*_set_left_over(char *left_over)
{
	char	*temp;
	int		i;

	i = 0;
	if (!left_over || left_over[i] == '\0' || ft_strchr(left_over, '\n') == 0)
	{
		free (left_over);
		left_over = NULL;
		return (NULL);
	}
	if (ft_strchr(left_over, '\n') != 0)
	{
		while (left_over[i] != '\n')
			i++;
		temp = left_over;
		left_over = ft_substr(temp, (i + 1), ft_strlen(temp));
		if (*left_over == 0 || !left_over)
		{
			free (left_over);
			free(temp);
			temp = NULL;
			return (NULL);
		}
		free (temp);
		temp = NULL;
		return (left_over);
	}
	return (left_over);
}
