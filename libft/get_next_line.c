/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:22:22 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	line_length(char *str)
{
	long unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*clean(char **array, char *ss)
{
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	if (ss)
		free(ss);
	return (NULL);
}

char	*read_1ine(int fd, char *array)
{
	char	*buf;
	char	*temp;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!array)
		array = ft_strdup("");
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		temp = array;
		array = ft_strjoin(array, buf);
		free(temp);
		if (ft_strchr(array, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (clean(&array, buf));
	free(buf);
	return (array);
}

char	*get_next_line(int fd)
{
	static char	*array = NULL;
	char		*line;
	char		*temp;
	int			len;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	array = read_1ine(fd, array);
	if (!array || array[0] == '\0')
	{
		clean(&array, temp);
		return (NULL);
	}
	len = line_length(array);
	line = ft_substr(array, 0, len + 1);
	if (line_length(array) != ft_strlen(array))
	{
		temp = array;
		array = ft_substr(array, len + 1, ft_strlen(array) - len);
		free(temp);
	}
	else
		clean(&array, temp);
	return (line);
}
