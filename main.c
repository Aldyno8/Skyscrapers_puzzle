/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:28:29 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/13 08:05:01 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int solve_puzzle(int grid[4][4], int position);
int print_solution(int grid[4][4]);

int main(void)
{

	int	grid[4][4] = {{0,0,0,0}, {0,0,0,0,}, {0,0,0,0,}, {0,0,0,0}};
	if (solve_puzzle(grid, 0))
		print_solution(grid);
	return (0);
}
