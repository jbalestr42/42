/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_data_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:51:20 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/11 10:36:40 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			destroy_obj_data(t_obj_data *obj_data)
{
	if (obj_data->obj_vertices)
		free(obj_data->obj_vertices);
	if (obj_data->vertices)
		free(obj_data->vertices);
	if (obj_data->obj_uvs)
		free(obj_data->obj_uvs);
	if (obj_data->indices)
		free(obj_data->indices);
}
