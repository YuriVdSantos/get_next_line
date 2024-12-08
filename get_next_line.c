/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:13:05 by yvieira-          #+#    #+#             */
/*   Updated: 2024/12/08 19:11:36 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	int bytes_read = 0;
	int file;
	file = open ("/nfs/homes/yvieira-/commun_core/get_next_line/text.txt", O_RDONLY);

	if (file == -1)
	{
		printf("Nao ta abrindo esta poha ");
		return (-1);
	}

	bytes_read = read(file, buffer, BUFFER_SIZE);

	if (bytes_read == -1)
	{
		printf("Nao ta lendo esta poha");
		close(file);
		return (-1);
	}

	buffer[bytes_read] = '\0';
	printf("%s", buffer);
	close(file);
	return (0);
	
}

int main()
{
	int fd = open("/nfs/homes/yvieira-/commun_core/get_next_line/text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo\n");
		return (1);
	}
	get_next_line(fd);
	
	printf("\n");
	get_next_line(fd);
	close(fd);

	return (0);
}