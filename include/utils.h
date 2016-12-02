/*
** Utils.h for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 23:43:23 2016 Antonin Rapini
** Last update Fri Dec  2 11:08:48 2016 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

#include "my_list.h"

char	*my_strdup(char *);
int	my_strlen(char *);
void	my_putstr(char *);
char	*my_nstrcat(int, ...);
void	my_put_nbr(int);
void	my_putchar(char);
char	*my_int_tostr(int);
void	my_showblocks(t_list *);
#endif /* !UTILS_H_ */
