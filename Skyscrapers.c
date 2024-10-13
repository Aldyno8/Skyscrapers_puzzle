/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:32:40 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 08:12:06 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h> 
#include<stdio.h>

int	not_in_col(int k, int y, int grid[4][4]);
int	not_in_line(int k, int y, int grid[4][4]);
int	check_visibility(int grid[4][4], int indices[16]);
int	evident_number_vr(int indices[16], int grid[4][4]);
int	evident_number_hr(int indices[16], int grid[4][4]);

int	solve_puzzle(int grid[4][4], int position)
{
	int	i;
	int	j;
	int	nbr;
	int k;

	int	indices [16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	if (position == 16)
		return (1);
	i = (position / 4);
	j = (position % 4);
	evident_number_vr(indices, grid);
	evident_number_hr(indices, grid);
	
	if (grid[i][j] != 0)
		return (solve_puzzle(grid, position + 1));
	
	k = 1;
	while (k <= 4)
	{
		if (not_in_col(k, i, grid) && not_in_line(k, j, grid))
		{
			grid[i][j] = k;
			if (check_visibility(grid, indices))	
			{
				if (solve_puzzle(grid, position + 1))
				{
					return (1);}
			}
			printf("\nposition = %i et %i\n", position, grid[i][j] );
			grid[i][j] = 0;
		}
		k ++;
	}
	return (0);
}

// Display the solution on the terminal
int	print_solution(int grid[4][4])
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			nbr = grid[i][j] + '0';
			write(1, &nbr, 1);
			if (j < 3)
				write(1, "  ", 2);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
	return (1);
}
