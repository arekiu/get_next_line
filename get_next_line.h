/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:57:45 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/13 14:12:04 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *str, int c);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
