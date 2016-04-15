/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:20:34 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 12:01:32 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIDEO_H
# define VIDEO_H

# include "ray_tracer.h"

void	draw_pics(t_env *e, t_img *vid);
void	change_cam_pos(t_env *e, int i);
void	create_pics(t_env *e);

#endif
