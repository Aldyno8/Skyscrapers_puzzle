/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:32:40 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 03:21:42 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_in_col(int k, int y, int grid[4][4]);
int	not_in_row(int k, int y, int grid[4][4]);

int	solve_puzzle(int grid[4][4], int position)
{
	int	i;
	int	j;
	int	nbr;
	int k;

	if (position == 16)
		return (1);
	i = (position / 4);
	j = (position % 4);
	if (grid[i][j] != 0)
		solve_puzzle(grid, position + 1);
	k = 1;
	while (k <= 4)
	{
		if (not_in_col(k, j, grid) && not_in_row(k, i, grid))
		{
			grid[i][j] = k;
			if (solve_puzzle(grid, position + 1))
				return (1);
			grid[i][j] = 0;
		}
		k ++;
	
	return (0);
}

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
			if (i < 3)
				write(1, "  ", 2);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
}
