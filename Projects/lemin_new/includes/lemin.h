/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:15:15 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/14 17:02:16 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_HPP
# define LEMIN_HPP

# include <stdio.h>
# include <stdlib.h>
# include <limits.h> //TODO remove
# include "lemin_struct.h"

t_graph			*create_graph(void);
void			destroy_graph(t_graph *graph);
void			add_edge(t_graph* graph, int src, int dest, int weight);
void			dijkstra(t_graph* graph);

t_adj_list_node	*new_adj_list_node(int dest, int weight);
t_min_heap_node	*new_min_heap_node(int v, int dist);
t_min_heap		*create_min_heap(int capacity);
void			swap_min_heap_node(t_min_heap_node **a, t_min_heap_node **b);
void			min_heapify(t_min_heap *minHeap, int idx);
int				is_in_min_heap(t_min_heap *minHeap, int v);

t_graph			*read_map(char const * filename);
char			**ft_splitwhite(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen_tab(char **tab);
void			free_split(char **s);
int				ft_atoi(char *str);
int				ft_isdigit(int c);
int				ft_strlen(char const *s);
int				parse_room(t_room **rooms, char **tmp);
int				return_free(char *line, int ret, char *message);
int				return_free_tab(char *line, char **tab, int ret, char *message);
int				return_print(int ret, char *message);
int				is_number(char *line);
int				create_rooms(t_graph *graph, t_room *rooms);
int				parse_edge(t_graph *graph, char *line);
int				read_num_ant(int fd);
int				read_rooms(t_graph *graph, t_room **rooms, int fd);
int				read_edges(t_graph *graph, int fd, char **tmp);
char			*ft_strdup(char const *s1);
int				contains_bad_char(char *line);
char			**check_commands(t_graph *graph, int fd, char **line, int *error_flag);
int				find_name(t_graph *graph, char *name);

void			ant_stuff(t_graph *graph, int *parents, int src, int dest);

#endif
