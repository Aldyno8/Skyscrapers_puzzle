/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:05:09 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 02:55:11 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	not_in_col(int k, int y, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[y][i] == k)
			return (0);
		i ++;
	}
	return (1);
}

int	not_in_row(int k, int x, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][x] == k)
			return (0);
		i ++;
	}
	return (1);
}

int count_visible(int *line, int size)
{
	int	max_height;
	int	visible_count;
	int	i;
	
	i = 0;
	max_height = 0;
	visible_count = 0;
	while (i < size)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count ++;
		}
		i ++;
	}
	return visible_count;
}

int	check_visibility(int grid[4][4], int indices[16])
{
	int	line[4];
	int	i; 
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while(i < 4)
		{	
			line[i] = grid[i][j];
			i ++; 
		}
		
		if (count_visible(line, 4) != indices[j])
			return (0);
		j ++;
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while(i < 4)
		{
			line[i] = grid[3 - i][j];
			i ++;
		}
		if (count_visible(line, 4) != indices[4 + j])
			return (0);
		j ++; 
	}
	i = 0;
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[i][j];
			j ++;
		}
		if (count_visible(line, 4) != indices[8 + i])
			return (0);
		i ++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			line[j] = grid[i][3 - j];
			j ++;
		}
		if (count_visible(line, 4) != indices[12 + i])
			return (0);
		i ++;
	}

	return (1);
}
