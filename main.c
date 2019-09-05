/*
** main.c for strace in /home/le_l/Workspace/PSU_2015_strace/tmp
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Wed Apr  6 15:01:13 2016 Victor Le
** Last update Sun Apr 10 18:34:02 2016 Steven Loo Fat
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include "parse_cmd_line.h"
#include "strace_cmd.h"
#include "main.h"
#include "p_init.h"

static int	check_arg(const int ac)
{
  if (ac == 1)
    {
      printf(STRACE_USAGE);
      return (0);
    }
  return (1);
}

int	main(int ac, char **av)
{
  pid_t	pid;
  t_opt	opt;
  int	idx;

  opt = NO_OPT;
  pid = 0;
  if (!check_arg(ac))
    return (1);
  if (!(idx = parse_cmd_line(ac, av, &opt, &pid)))
    return (1);
  if (opt & P_OPT)
    init(opt, (pid_t)atoi(av[2]));
  else
    {
      if (!check_arg(ac - idx + 1))
	return (1);
      if (!strace_cmd(opt, av + idx))
	return (1);
    }
  return (0);
}
