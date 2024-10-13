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
#include <stdio.h>

int	not_in_col(int k, int x, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[x][i] == k)
		{
			printf("(%i,%i) et k=%i, n_col\n",x,i, k);
			return (0);
		}
		i ++;
	}
	return (1);
}

int	not_in_line(int k, int y, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][y] == k)
		{
			printf("(%i,%i) et k=%i, n_row\n",i,y, k);
			return (0);
		}
		i ++;
	}
	return (1);
}

void evident_number_hr(int indices[16], int grid[4][4])
{
	int i;
	
	i = 8;
	while (i < 12)
	{
		if (indices[i] == 4)
		{	
			grid[i % 4][0] = 1;
			grid[i % 4][1] = 2;
			grid[i % 4][2] = 3;
			grid[i % 4][3] = 4;
		}
		if (indices[i] == 1)
			grid[i % 4][0] = 4;
		i ++;
	}
	i = 12;
	while (i < 16)
	{
		if (indices[i] == 4)
		{
			grid[i % 4][3] = 1;
			grid[i % 4][2] = 2;
			grid[i % 4][1] = 3;
			grid[i % 4][0] = 4;
		}
		if (indices[i] == 1)
			grid[i % 4][3] = 4;
		i ++;
	} 
}

void evident_number_vr(int indices[16], int grid[4][4])
{
	int i;
	int j;
	
	i = 0;
	while (i < 4)
	{
		if (indices[i] == 4)
		{
			grid[0][i % 4] = 1;
			grid[1][i % 4] = 2;
			grid[2][i % 4] = 3;
			grid[3][i % 4] = 4;
		}
		if (indices[i] == 1)
			grid[0][i % 4] = 4;
		i ++;
	}
	i = 4;
	while (i < 8)
	{
		if (indices[i] == 4)
		{	
			grid[3][i % 4] = 1;
			grid[2][i % 4] = 2;
			grid[1][i % 4] = 3;
			grid[0][i % 4] = 4;
		}	
		if (indices[i] == 1)
			grid[4][i % 4] = 4;
		i ++;
	}
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
		
		if (count_visible(line, 4) > indices[j])
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
		if (count_visible(line, 4) > indices[4 + j])
			{printf("%i et %i", count_visible(line, 4), indices[4 + j]);
			return (0);}
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
		if (count_visible(line, 4) > indices[8 + i])
			{printf("g en d");
			return (0);}
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
		if (count_visible(line, 4) > indices[12 + i])
		{printf("%i et %i", count_visible(line, 4), indices[4 + j]);
			return (0);}
		i ++;
	}

	return (1);
}
