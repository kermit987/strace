/*
** strace_dump_x.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Sat Apr  9 07:35:38 2016 Victor Le
** Last update Sun Apr 10 18:39:09 2016 Steven Loo Fat
*/

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include "access_reg_arg.h"
#include "strace_dump_x.h"

void	strace_dump_int(const pid_t pid, const t_regs *regs,
			const int arg_nb)
{
  int	vl;

  vl = (int)access_reg_arg(regs, arg_nb);
  if (arg_nb == 0 && vl < 0)
    ++vl;
  printf("%d", vl);
  (void)pid;
}

static void	*dump_str(const pid_t pid, void *addr, int *ret)
{
  char		str[9];
  t_data	data;

  memset(str, 0, 9);
  errno = 0;
  data.data = ptrace(PTRACE_PEEKTEXT, pid, addr, NULL);
  if (data.data != -1 || (data.data == -1 && !errno))
    {
      memcpy(str, data.bit, 8);
      *ret = printf("%s", str);
      addr += *ret;
    }
  return (addr);
}

void		strace_dump_str(const pid_t pid, const t_regs *regs,
				const int arg_nb)
{
  int		i;
  int		ret;
  void		*addr;

  printf("\"");
  addr = (void *)access_reg_arg(regs, arg_nb);
  i = 0;
  ret = 8;
  while (i < 4 && ret == 8)
    {
      ret = 0;
      addr = dump_str(pid, addr, &ret);
      ++i;
    }
  printf("\"");
  if (i == 4)
    printf("...");
}

void		strace_dump_addr(const pid_t pid, const t_regs *regs,
				 const int arg_nb)
{
  t_reg_size	ptr_vl;

  ptr_vl = access_reg_arg(regs, arg_nb);
  if (!ptr_vl)
    printf("NULL");
  else
    printf("%#llx", ptr_vl);
  (void)pid;
}

void	strace_dump_unknow(const pid_t pid, const t_regs *regs,
			   const int arg_nb)
{
  printf("???");
  (void)regs;
  (void)pid;
  (void)arg_nb;
}
