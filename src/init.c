/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:16:58 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/08/22 14:06:46 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sl_init_buffers(t_env *env)
{
	int	i;

	env->buffer = malloc(sizeof(int *) * env->height * BLOC_LEN);
	if (!env->buffer)
		sl_exit_game(env, "Error: memory allocation for buffer failed");
	i = 0;
	while (i < env->height * BLOC_LEN)
	{
		env->buffer[i] = malloc(sizeof(int) * env->width * BLOC_LEN);
		++i;
	}
	env->buffer_bkgd = malloc(sizeof(int *) * env->height * BLOC_LEN);
	if (!env->buffer_bkgd)
		sl_exit_game(env, "Error: memory allocation for buffer failed");
	i = 0;
	while (i < env->height * BLOC_LEN)
	{
		env->buffer_bkgd[i] = malloc(sizeof(int) * env->width * BLOC_LEN);
		++i;
	}
}

void	sl_init_sprite(t_sprite *sprite, int x, int y, int speed)
{
	sprite->alive = true;
	sprite->moves = 0;
	sprite->curr_dir.up = false;
	sprite->curr_dir.down = false;
	sprite->curr_dir.left = false;
	sprite->curr_dir.right = false;
	sprite->curr_state = &sprite->img.down.one;
	sprite->sub_pos.x = 0;
	sprite->sub_pos.y = 0;
	sprite->pos.x = x;
	sprite->pos.y = y;
	sprite->speed = speed;
	sprite->time = 0;
}

void	sl_init_env(t_env *env)
{
	env->width = 0;
	env->height = 0;
	env->map = NULL;
	env->tex.bomb.to_collect = 0;
	env->tex.bomb.collected = 0;
    env->tex.bomb.set_bomb = false;
	env->tex.exit_pipe.appear = false;
	env->tex.ennemies.count = 0;
	sl_init_sprite(&env->p1, 0, 0, 90);
}