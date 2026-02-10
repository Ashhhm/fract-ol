/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:42:12 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/20 22:22:45 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("harry_potter.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &ret, 0) < 0)
	{
		ft_free_list(list);
		list = NULL;
		return (NULL);
	}
	ret = NULL;
	ft_create_str(fd, &list);
	if (!list)
		return (NULL);
	ft_return_line(list, &ret);
	ft_next_ret(&list);
	if (ret[0] == '\0')
	{
		ft_free_list(list);
		list = NULL;
		free(ret);
		return (NULL);
	}
	return (ret);
}

// we are reading from our fd we check if we already have a \n in the 
// linked-list. 
// We then pass the buffer with the BUFFER_SIZE char,
//	the int value of the read function and the pointer to the linked list

void	ft_create_str(int fd, t_list **list)
{
	char	*buffer;
	int		byte_read;

	byte_read = 1;
	while (!ft_checking_backslast(*list) && byte_read != 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[byte_read] = '\0';
		ft_add_to_list(buffer, list, byte_read);
		free(buffer);
	}
}
// on are allocating mem to store the line reader in our linked-list,

void	ft_add_to_list(char *buffer, t_list **list, int byte_read)
{
	int		i;
	t_list	*lt_node;
	t_list	*n_node;

	n_node = malloc(sizeof(t_list));
	if (!n_node)
		return ;
	n_node->next = NULL;
	n_node->str = malloc(sizeof(char) * (byte_read + 1));
	if (!n_node->str)
		return ;
	i = 0;
	while (buffer[i] && i < byte_read)
	{
		n_node->str[i] = buffer[i];
		i++;
	}
	n_node->str[i] = '\0';
	lt_node = ft_lstlast(*list);
	if (lt_node == NULL)
	{
		*list = n_node;
		return ;
	}
	lt_node->next = n_node;
}

void	ft_return_line(t_list *list, char **ret)
{
	int	i;
	int	j;

	if (!list)
		return ;
	*ret = malloc(sizeof(char) * (ft_len_line(list) + 1));
	if (*ret == NULL || !list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				(*ret)[j++] = '\n';
				(*ret)[j] = '\0';
				return ;
			}
			(*ret)[j++] = list->str[i++];
		}
		list = list->next;
	}
	(*ret)[j] = '\0';
}

void	ft_next_ret(t_list **list)
{
	t_list	*lt_node;
	t_list	*n_node;
	int		i;
	int		j;

	lt_node = ft_lstlast(*list);
	n_node = malloc(sizeof(t_list));
	if (!list || !n_node)
		return ;
	i = ((j = 0));
	while (lt_node->str[i] && lt_node->str[i] != '\n')
		i++;
	if (lt_node->str && lt_node->str[i] == '\n')
		i++;
	n_node->str = malloc(sizeof(char) * ((ft_strlen2(lt_node->str) - i) + 1));
	if (!n_node->str)
		return ;
	while (lt_node->str[i])
		n_node->str[j++] = lt_node->str[i++];
	n_node->str[j] = '\0';
	n_node->next = NULL;
	ft_free_list(*list);
	*list = n_node;
}
