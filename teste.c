/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:07:32 by yvieira-          #+#    #+#             */
/*   Updated: 2024/12/08 18:07:34 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	static int  bytes_read = 0;
	static int  index = 0;
	char        *line;
	int         i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (-1);
	i = 0;
	while (1)
	{
		if (index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			index = 0;
			if (bytes_read <= 0)
				break ;
		}
		if (buffer[index] == '\n')
		{
			index++;
			break ;
		}
		line[i++] = buffer[index++];
	}
	line[i] = '\0';
	if (i == 0 && bytes_read <= 0)
	{
		free(line);
		return (bytes_read);
	}
	return (line);
}