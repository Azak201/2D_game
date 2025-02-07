/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:43:33 by amismail          #+#    #+#             */
/*   Updated: 2025/01/16 15:43:35 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	put_player(t_game *s, char c, int x, int y);

void	up(t_game *s)
{
	int	i;
	int	j;

	i = s->tmap[0]->row_p;
	j = s->tmap[0]->col_p;
	if (i - 1 >= 0 && s->tmap[0]->map[i - 1][j] != '1')
	{
		put_image(&(*s), '0', j, i);
		if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c > 0)
			put_image(&(*s), 'E', j, i);
		s->tmap[0]->row_p = s->tmap[0]->row_p - 1;
		s->count = s->count + 1;
		i = s->tmap[0]->row_p;
		if (s->tmap[0]->map[i][j] == 'C')
		{
			s->tmap[0]->map[i][j] = '0';
			s->tmap[0]->c = s->tmap[0]->c - 1;
		}
		ft_printf("counter=%d\n", s->count);
		put_player(&(*s), 'w', j, i);
	}
	if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c == 0)
		destroy_win(&(*s));
}

void	down(t_game *s)
{
	int	i;
	int	j;

	i = s->tmap[0]->row_p;
	j = s->tmap[0]->col_p;
	if (i + 1 < s->tmap[0]->row_num && s->tmap[0]->map[i + 1][j] != '1')
	{
		put_image(&(*s), '0', j, i);
		if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c > 0)
			put_image(&(*s), 'E', j, i);
		s->tmap[0]->row_p = s->tmap[0]->row_p + 1;
		s->count = s->count + 1;
		i = s->tmap[0]->row_p;
		if (s->tmap[0]->map[i][j] == 'C')
		{
			s->tmap[0]->map[i][j] = '0';
			s->tmap[0]->c = s->tmap[0]->c - 1;
		}
		ft_printf("counter=%d\n", s->count);
		put_player(&(*s), 's', j, i);
	}
	if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c == 0)
		destroy_win(&(*s));
}

void	right(t_game *s)
{
	int	i;
	int	j;

	i = s->tmap[0]->row_p;
	j = s->tmap[0]->col_p;
	if (j + 1 < s->tmap[0]->col_num && s->tmap[0]->map[i][j + 1] != '1')
	{
		put_image(&(*s), '0', j, i);
		if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c > 0)
			put_image(&(*s), 'E', j, i);
		s->tmap[0]->col_p = s->tmap[0]->col_p + 1;
		s->count = s->count + 1;
		j = s->tmap[0]->col_p;
		if (s->tmap[0]->map[i][j] == 'C')
		{
			s->tmap[0]->map[i][j] = '0';
			s->tmap[0]->c = s->tmap[0]->c - 1;
		}
		ft_printf("counter=%d\n", s->count);
		put_player(&(*s), 'd', j, i);
	}
	if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c == 0)
		destroy_win(&(*s));
}

void	left(t_game *s)
{
	int	i;
	int	j;

	i = s->tmap[0]->row_p;
	j = s->tmap[0]->col_p;
	if (j - 1 >= 0 && s->tmap[0]->map[i][j - 1] != '1')
	{
		put_image(&(*s), '0', j, i);
		if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c != 0)
			put_image(&(*s), 'E', j, i);
		s->tmap[0]->col_p = s->tmap[0]->col_p - 1;
		s->count = s->count + 1;
		j = s->tmap[0]->col_p;
		if (s->tmap[0]->map[i][j] == 'C')
		{
			s->tmap[0]->map[i][j] = '0';
			s->tmap[0]->c = s->tmap[0]->c - 1;
		}
		ft_printf("counter=%d\n", s->count);
		put_player(&(*s), 'a', j, i);
	}
	if (s->tmap[0]->map[i][j] == 'E' && s->tmap[0]->c == 0)
		destroy_win(&(*s));
}

static void	put_player(t_game *s, char c, int x, int y)
{
	if (c == 'w')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->p_w, x * 50, y * 50);
	else if (c == 's')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->p_s, x * 50, y * 50);
	else if (c == 'd')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->p_d, x * 50, y * 50);
	else if (c == 'a')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->p_a, x * 50, y * 50);
}
