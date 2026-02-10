/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:46:46 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/20 22:23:09 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_checking_backslast(t_list *list)
{
	int		i;
	t_list	*node;

	if (list == NULL)
		return (0);
	node = ft_lstlast(list);
	i = 0;
	while (node->str[i] && i < BUFFER_SIZE)
	{
		if (node->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

int	ft_len_line(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_free_list(t_list *list)
{
	t_list	*node;
	t_list	*next_node;

	node = list;
	while (node)
	{
		free(node->str);
		next_node = node->next;
		free(node);
		node = next_node;
	}
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
