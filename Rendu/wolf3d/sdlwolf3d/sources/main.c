/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/02 20:26:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
 * Il faut retourner le code d'errreur avec key_hook, et le recuperer dans
 * le main afin de gerer l'erreur prorpement et d'exit le programme en ayant
 * free tous ce qui a ete malloc
 * */
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"

t_env	*init(void)
{
	t_env	*e;

	if (!(e = ft_envnew()))
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (NULL);
	if (!(e->screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE)))
		return (NULL);
	SDL_WM_SetCaption(NAME, NULL);
	return (e);
}

void	clean_up(t_env *e)
{
	// ajouter ca dans la fonctin de envdel
	SDL_FreeSurface(e->screen);
	ft_envdel(e);
	// SDL_Quit();
}

void	get_events(t_env *e)
{
	SDL_Event	event;
	int			quit;

	quit = 1;
	while (quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = 0;
			if (event.type == SDL_KEYDOWN)
				key_hook(event.key.keysym.sym, e);
		}
	}
}

int		main(void)
{
	t_env	*e;

	if (!(e = init()))
		return (1);
	get_events(e);
	clean_up(e);
	return (0);
}
/*
		mlx_key_hook(e->win, key_hook, e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_loop_hook(e->mlx, loop_hook, e);
		mlx_loop(e->mlx);*/
