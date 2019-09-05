/*
** syscall_info.h for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Thu Apr  7 14:12:26 2016 Victor Le
** Last update Sat Apr  9 22:49:38 2016 Steven Loo Fat
*/

#ifndef SYSCALL_INFO_H_
# define SYSCALL_INFO_H_

typedef struct	s_syscall
{
  char		*name;
  int		nb_args;
  char		*type_info;
}		t_syscall;

# define TYPE_VOID	'0'
# define TYPE_INT	'1'
# define TYPE_PTR	'2'
# define TYPE_STRUCT	'3'
# define TYPE_STR	'4'

extern t_syscall	g_syscall_array[];

#endif /* !SYSCALL_INFO_H_ */
