/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:04:35 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/13 14:12:38 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int	i;
	size_t	size;
	char	*buffer;

	size = ft_strlen(s1);
	buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buffer == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		buffer[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		buffer[i] = s2[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ce;

	i = 0;
	ce = c;
	while (str[i] != '\0')
	{
		if (str[i] == ce)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == ce)
		return ((char *)(str + i));
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
	{
		len = 0;
	}
	if (len != 0 && len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && str)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
