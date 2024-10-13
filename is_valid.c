/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:05:09 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 14:50:08 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_visibility_left(int grid[4][4], int line [4], int indices[16]);
void	check_visibility_right(int grid[4][4], int line [4], int indices[16]);
void	check_visibility_down(int grid[4][4], int line[4], int indices[16]);
void	check_visibility_up(int grid[4][4], int line[4], int indices[16]);

int	count_visible(int *line, int size)
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
	return (visible_count);
}

int	not_in_col(int k, int x, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[x][i] == k)
			return (0);
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
			return (0);
		i ++;
	}
	return (1);
}

int	check_visibility(int grid[4][4], int indices[16])
{
	int	line[4];

	check_visibility_up(grid, line, indices);
	check_visibility_down(grid, line, indices);
	check_visibility_left(grid, line, indices);
	check_visibility_right(grid, line, indices);
	return (1);
}
