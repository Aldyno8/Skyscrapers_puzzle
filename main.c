/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:28:29 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 14:53:22 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	solve_puzzle(int grid[4][4], int position, int indices[16]);
int	print_solution(int grid[4][4]);

void	primitive_grid(int i, int j, int grid[4][4])
{
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j ++;
		}
		i ++;
	}
}

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	i;
	int	j;
	int	indices[16];

	if (argc != 2)
		write(1, "Error\n", 6);
	i = 0;
	j = 0;
	while (i < 16)
	{
		indices[i] = (argv[1][i * 2] - '0');
		i += 1;
	}
	primitive_grid(i, j, grid);
	if (solve_puzzle(grid, 0, indices))
		print_solution(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
