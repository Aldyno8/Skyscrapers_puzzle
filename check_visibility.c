/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:05:09 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 15:05:07 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_visible(int *line, int size);

void	check_visibility_up(int grid[4][4], int line[4], int indices[16])
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = grid[i][j];
			i ++;
		}
		if (count_visible(line, 4) > indices[j])
			return ;
		j ++;
	}
}

void	check_visibility_down(int grid[4][4], int line[4], int indices[16])
{
	int	j;
	int	i;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = grid[3 - i][j];
			i ++;
		}
		if (count_visible(line, 4) > indices[4 + j])
			return ;
		j ++;
	}
}

void	check_visibility_left(int grid[4][4], int line [4], int indices[16])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[i][j];
			j ++;
		}
		if (count_visible(line, 4) > indices[8 + i])
			return ;
		i ++;
	}
}

void	check_visibility_right(int grid[4][4], int line [4], int indices[16])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[i][3 - j];
			j ++;
		}
		if (count_visible(line, 4) > indices[12 + i])
			return ;
		i ++;
	}
}
