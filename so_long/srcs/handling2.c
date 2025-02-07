/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:43:07 by amismail          #+#    #+#             */
/*   Updated: 2025/01/16 15:43:11 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* if flag 1 it will close the fd and exit with error message
if flag not 0 and not 1 it will exit with error message but
without closing fd
if flag 0 will exit sucsess */
void	ft_exit_fd(int flag, char *message, int fd)
{
	if (flag == 1)
		close(fd);
	if (flag != 0)
		ft_printf("Error\n%s\n", message);
	if (flag == 0)
		exit(0);
	exit(1);
}

/*if flag 0 it will free otherwise it will free and exit */
void	ft_free(int flag, char **arr, char *message)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	if (flag != 0)
		ft_exit_fd(2, message, 0);
}

/* if flag 0 it will free map and fmap otherwise it will free and exit*/
void	ft_free_map_struct(int flag, t_map **stru, char *message)
{
	if ((*stru)->fmap != NULL)
		ft_free(0, ((*stru)->fmap), NULL);
	if ((*stru)->map != NULL)
		ft_free(0, ((*stru)->map), NULL);
	if (*stru)
		free(*stru);
	if (flag != 0)
		ft_exit_fd(2, message, 0);
}

/*if flag 0 it will free the struct game pointers & map only
 otherwise it will exit with message error */
void	ft_free_game(int flag, t_game **s_l, char *message)
{
	if ((*s_l)->mlx_ptr != NULL)
		free((*s_l)->mlx_ptr);
	ft_free_map_struct(0, &((*s_l)->tmap[0]), NULL);
	free(*s_l);
	if (flag != 0)
		ft_exit_fd(2, message, 0);
}
