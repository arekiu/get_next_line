/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:11:59 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/14 12:38:25 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
static char	*_set_line(int fd, char *buff, char *temp_line);
static char	*_clean_line(char *temp_line);
static char	*_set_left_over(char *temp_line);

int	main(void)
{
	int	fd;

	fd = open("example.txt", O_RDONLY);

	printf("la linea limpia: %s", get_next_line(fd));
	printf("la linea limpia2: %s", get_next_line(fd));
	//printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*temp_line;

	if (fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	temp_line = _set_line(fd, buff, temp_line);
	printf("la linea sucia: %s\n",temp_line);
	line = _clean_line(temp_line);
	free(buff);
	temp_line = _set_left_over(temp_line);
	printf("el left over: %s\n",temp_line);
	return (line);
}

static char	*_set_line(int fd, char *buff, char *temp_line)
{
	ssize_t nr_bytes;
	char	*temp;

	if (!temp_line)
	{
		nr_bytes = read(fd, buff, BUFFER_SIZE);
		if (nr_bytes < 0)
			return (NULL);
		if (nr_bytes == 0)
		{
			free(buff);
			return (NULL);
		}
		temp_line = ft_strdup(buff);
	}
	while ((nr_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		temp = ft_strjoin(temp_line, buff);
		free (temp_line);
		temp_line = temp;
		if (ft_strchr(buff, '\n'))
            break;
	}
	if (nr_bytes < 0)
	{
		free(temp_line);
		return (NULL);
	}
	return (temp_line);
}

static char	*_clean_line(char *temp_line)
{
	int		i;
	char	*clean_str;

	i = 0;
	while (temp_line[i] != '\0' && temp_line[i] != '\n')
		i++;
	if (temp_line[i] == '\n')
		i++;
	clean_str = ft_substr(temp_line, 0, i);
	return (clean_str);
}

static char	*_set_left_over(char *temp_line)
{
	char	*temp;
	int		i;

	i = 0;
	if (ft_strchr(temp_line, '\n') != 0)
	{
		while (temp_line[i] != '\n')
			i++;
		temp = ft_substr(temp_line, (i + 1), ft_strlen(temp_line));
		return (temp);
	}
	free (temp_line);
	return (NULL);
}

