/*
** sources.h for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 08:53:50 2016 Antonin Rapini
** Last update Fri Dec  2 15:13:59 2016 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_options.h"
#include "my_list.h"
#include "my_fileinfos.h"

t_options	*my_set_options(int, char **, int *);
t_list		*my_create_list(t_options *, char *);
void		my_display(t_options *, int, int, char **);
void		my_sort_list(t_list **, t_options *);
t_fileinfos	*my_create_fileinfos(char *, char *, t_options *, int);
char		*my_format_line(t_options *, t_fileinfos *);
void		my_display_recursive(t_options *, t_list *);
char		my_get_typespecifier(t_options *, mode_t);
#endif /* !SOURCES_H_ */
