#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "ray_tracer.h"

static int			check_scene_name(char *s)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	if (i < 4)
		return (0);
	if (s[--i] != 't')
		return (0);
	if (s[--i] != 'r')
		return (0);
	if (s[--i] != '.')
		return (0);
	return (1);
}

static int			count_scene(void)
{
	int				nb_button;
	DIR				*dp;
	struct dirent	*ep;

	nb_button = 0;
	if ((dp = opendir("scenes/")))
	{
		while ((ep = readdir(dp)))
		{
			if (ep->d_name[0] != '.')
			{
				if (check_scene_name(ep->d_name))
				{
					ft_putstr("Read scene : ");
					nb_button++;
				}
				else
					ft_putstr("Invalid scene name : ");
				ft_putstr(ep->d_name);
				write(1, "\n", 1);
			}
		}
		closedir(dp);
	}
	else
		ft_putstr("Couldn't open the directory.\n");
	return (nb_button);
}

int					init_choose_scene(t_env *e)
{
	int				i;
	DIR				*dp;
	struct dirent	*ep;

	i = 0;
	e->screens[CHOOSE].nb_button = count_scene();
	if (!(e->screens[CHOOSE].buttons =
		(t_button *)malloc(sizeof(t_button) * e->screens[CHOOSE].nb_button)))
		return (0);
	e->screens[CHOOSE].background = init_img_xpm(e->mlx, "images/background.xpm"
					, 1440, 1080);
	if ((dp = opendir("scenes/")))
	{
		while ((ep = readdir(dp)))
		{
			if (ep->d_name[0] != '.')
			{
				if (check_scene_name(ep->d_name))
				{
					e->screens[CHOOSE].buttons[i] = init_button(WIDTH / 2 - 100,
						100 + i * 100, &mouse_event_choose_scene,
						init_img_xpm(e->mlx, "images/draw.xpm", 200, 200));
					e->screens[CHOOSE].buttons[i].name = ft_strdup(ep->d_name);
					i++;
				}
			}
		}
		closedir(dp);
	}
	return (1);
}
