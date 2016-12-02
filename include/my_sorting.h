/*
** my_sorting.h for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 12:02:12 2016 Antonin Rapini
** Last update Fri Dec  2 20:40:22 2016 Antonin Rapini
*/

#ifndef MY_SORTING_H_
# define MY_SORTING_H_

#include "my_list.h"
#include "my_fileinfos.h"
#include "my_options.h"

int my_atimecmp(t_fileinfos *, t_fileinfos *);
int my_mtimecmp(t_fileinfos *, t_fileinfos *);
int my_namecmp(t_fileinfos *, t_fileinfos *);
int my_nocmp(t_fileinfos *, t_fileinfos *);
void my_reverse_list(t_list **);

#endif /* !MY_SORTING_H_ */
