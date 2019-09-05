/*
** strace_sopt_display.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Fri Apr  8 11:50:47 2016 Victor Le
** Last update Sun Apr 10 16:25:05 2016 Victor Le
*/

#include <stdio.h>
#include <unistd.h>
#include "syscall_info.h"
#include "main.h"
#include "strace_dump_x.h"

void			strace_sopt_display(const t_syscall *syscall,
					    const pid_t pid,
					    const int arg_nb,
					    const t_regs *regs)
{
  static char		type[] = {TYPE_INT, TYPE_PTR,
				  TYPE_STRUCT, TYPE_STR, 0};
  static t_sysdump	fptr[] = {&strace_dump_int, &strace_dump_addr,
				  &strace_dump_addr, &strace_dump_str,
				  &strace_dump_unknow};
  int			i;

  if (syscall->type_info)
    {
      i = 0;
      while (type[i] && type[i] != syscall->type_info[arg_nb + 1])
	++i;
      if (type[i] == syscall->type_info[arg_nb + 1])
	fptr[i](pid, regs, arg_nb + 1);
      else
	printf("???");
    }
  else
    printf("???");
}

void			strace_display_return_value(const t_syscall *syscall,
						    const pid_t pid,
						    const t_regs *regs)
{
  static char		type[] = {TYPE_INT, TYPE_PTR,
				  TYPE_STRUCT, TYPE_STR, 0};
  static t_sysdump	fptr[] = {&strace_dump_int, &strace_dump_addr,
				  &strace_dump_addr, &strace_dump_str,
				  &strace_dump_unknow};
  int			i;

  printf(" = ");
  i = 0;
  while (type[i] && type[i] != syscall->type_info[0])
    ++i;
  if (type[i] == syscall->type_info[0])
    fptr[i](pid, regs, 0);
  else if (type[i] == 0)
    printf("?");
  printf("\n");
}
