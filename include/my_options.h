/*
** my_options.h for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 09:22:44 2016 Antonin Rapini
** Last update Wed Nov 30 19:00:44 2016 Antonin Rapini
*/

#ifndef MY_OPTIONS_H_
# define MY_OPTIONS_H_

#include "my_sorting.h"
#include "my_fileinfos.h"
#include "my_list.h"

typedef struct	s_options
{
  int		(*my_compfnc)(t_fileinfos *, t_fileinfos *);
  int		reversed;
  int		show_filetype;
  void		(*my_display)(struct s_options *, t_list *);
  int		recursive;
  int		hide_owner;
  int		show_self;
  int		show_accesstime;
  int		show_hidden;
}		t_options;

void	my_display_default(t_options *, t_list *);
void	my_display_line(t_options *, t_list *);

#endif /* !MY_OPTIONS_H_ */
