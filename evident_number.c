/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evident_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:05:09 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 15:08:07 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	evident_number_lf(int indices[16], int grid[4][4])
{
	int	i;

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
}

void	evident_number_rg(int indices[16], int grid[4][4])
{
	int	i;

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

void	evident_number_up(int indices[16], int grid[4][4])
{
	int	i;

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
}

void	evident_number_dwn(int indices[16], int grid[4][4])
{
	int	i;

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

void	evident_number(int indices[16], int grid[4][4])
{
	evident_number_lf(indices, grid);
	evident_number_rg(indices, grid);
	evident_number_up(indices, grid);
	evident_number_dwn(indices, grid);
}
