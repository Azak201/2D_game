/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:43:21 by amismail          #+#    #+#             */
/*   Updated: 2025/01/25 18:16:36 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

/*this funtion called by mlx_key_hook & it call another function
depened on the pressed key */
int	input_handle(int key, t_game *s_l)
{
	if (key == XK_Escape)
		destroy_win(&(*s_l));
	else if (key == XK_w)
		up(&(*s_l));
	else if (key == XK_s)
		down(&(*s_l));
	else if (key == XK_d)
		right(&(*s_l));
	else if (key == XK_a)
		left(&(*s_l));
	if (s_l->tmap[0]->c == 0)
		put_image(&(*s_l), 'Q', s_l->tmap[0]->col_e, s_l->tmap[0]->row_e);
	return (0);
}

/*this function uplode the images to the programm with protection*/
void	upload_images(t_game *s_l)
{
	int	w;
	int	h;

	s_l->g_img = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/gr.xpm", &w, &h);
	s_l->w_img = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/wall.xpm", &w, &h);
	s_l->c_img = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/coll.xpm", &w, &h);
	s_l->p_img = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/p_st.xpm", &w, &h);
	s_l->c_e_img = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/e_cl.xpm", &w, &h);
	s_l->op_e_img = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/e_op.xpm", &w, &h);
	s_l->p_a = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/p_a.xpm", &w, &h);
	s_l->p_s = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/p_s.xpm", &w, &h);
	s_l->p_d = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/p_d.xpm", &w, &h);
	s_l->p_w = mlx_xpm_file_to_image(s_l->mlx_ptr, "xpm/p_w.xpm", &w, &h);
	if (s_l->g_img == NULL || s_l->w_img == NULL || s_l->c_img == NULL)
		fail_up_img(s_l);
	if (s_l->p_img == NULL || s_l->op_e_img == NULL || s_l->c_e_img == NULL)
		fail_up_img(s_l);
	if (s_l->p_w == NULL || s_l->p_a == NULL || s_l->p_d == NULL
		|| s_l->p_s == NULL)
		fail_up_img(s_l);
}

/*this funcion close the window and its connection & x connection & exit*/
int	destroy_win(t_game *s_l)
{
	img_dest(&(*s_l));
	if (s_l->win_ptr)
		mlx_destroy_window(s_l->mlx_ptr, s_l->win_ptr);
	if (s_l->mlx_ptr)
		mlx_destroy_display(s_l->mlx_ptr);
	ft_free_game(0, &s_l, NULL);
	exit(0);
	return (0);
}

/*this function drow the initial map on the window*/
void	upload_map(t_game *s_l)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_l->tmap[0]->row_num)
	{
		j = 0;
		while (j < s_l->tmap[0]->col_num)
		{
			put_image(&(*s_l), s_l->tmap[0]->map[i][j], j, i);
			j++;
		}
		i++;
	}
}

/*this is a helper function used to define the image needed
and drow it on window with its location*/
void	put_image(t_game *s, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->g_img, x * 50, y * 50);
	else if (c == '1')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->w_img, x * 50, y * 50);
	else if (c == 'P')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->p_img, x * 50, y * 50);
	else if (c == 'C')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->c_img, x * 50, y * 50);
	else if (c == 'E')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->c_e_img, x * 50, y * 50);
	else if (c == 'Q')
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->op_e_img, x * 50, y * 50);
}
