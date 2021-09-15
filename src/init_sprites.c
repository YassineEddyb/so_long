/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:40:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/13 04:35:02 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sl_init_set_bomb(t_items *bomb, bool draw, int x, int y, int size)
{
	bomb->draw = draw;
	bomb->pos = sl_assign_pos(x, y);
	bomb->explode_size = size;
	bomb->time1 = 0;
	bomb->time2 = 0;
	bomb->time3 = 0;
}

void	sl_init_sprite(t_sprite *sprite, int x, int y, int speed)
{
	sprite->alive = true;
	sprite->time_death = 0;
	sprite->moves = 0;
	sprite->curr_dir = 0;
	sprite->curr_state = &sprite->img.down.one;
	sprite->sub_pos = sl_assign_pos(0, 0);
	sprite->pos = sl_assign_pos(x, y);
	sprite->stop = false;
	sprite->speed = speed;
	sprite->time = 0;
}
