/*
** strace_cmd.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Wed Apr  6 15:37:35 2016 Victor Le
** Last update Sun Apr 10 18:37:36 2016 Steven Loo Fat
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <errno.h>
#include "parse_cmd_line.h"
#include "main.h"
#include "syscall_info.h"
#include "strace_cmd_child.h"
#include "strace_sopt_display.h"
#include "my_wait.h"

static void	strace_dump_param(t_regs *regs, const pid_t pid,
				  const t_opt opt)
{
  t_syscall	*line;
  int		i;
  t_reg_size	*regs_ptr;
  int		offsets[] = {REG_IDX(rdi), REG_IDX(rsi), REG_IDX(rdx),
			     REG_IDX(rcx), REG_IDX(r8), REG_IDX(r9)};

  printf("(");
  line = &g_syscall_array[regs->rax];
  regs_ptr = (t_reg_size *)regs;
  i = 0;
  while (i < line->nb_args)
    {
      printf("%s", (i ? ", " : ""));
      if (opt & S_OPT)
	strace_sopt_display(line, pid, i, regs);
      else
	printf("%#llx", regs_ptr[offsets[i]]);
      ++i;
    }
  printf(")");
}

static int	strace_search_syscall(const pid_t pid, const t_opt opt,
				      t_regs *regs, char *sys)
{
  long		opcode;

  opcode = 0;
  opcode = ptrace(PTRACE_PEEKDATA, pid, regs->rip, NULL);
  if (opcode == -1 && errno)
    {
      perror("ptrace");
      return (0);
    }
  if ((opcode & OPCODE_MASK) == SYSCALL_OPCODE)
    {
      *sys = 1;
      printf("%s", g_syscall_array[regs->rax].name);
      strace_dump_param(regs, pid, opt);
      fflush(stdout);
    }
  return (1);
}

static int	strace_syscall_display(const pid_t pid, const t_opt opt)
{
  t_regs	regs;
  static char	syscall_found = 0;

  if (!ptrace(PTRACE_GETREGS, pid, NULL, &regs))
    {
      if (!syscall_found)
	return (strace_search_syscall(pid, opt, &regs, &syscall_found));
      if (opt & S_OPT)
	strace_display_return_value(g_syscall_array + regs.orig_rax, pid, &regs);
      else
	printf(" = %#llx\n", regs.rax);
      syscall_found = 0;
      return (1);
    }
  syscall_found = 0;
  printf(" = ?\n");
  return (1);
}

int	strace_father(const t_opt opt, const pid_t pid)
{
  int	status;

  if (!my_wait(&status))
    return (0);
  while (WIFSTOPPED(status))
    {
      if (!strace_syscall_display(pid, opt))
	return (0);
      if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
	{
	  perror("ptrace");
	  return (0);
	}
      if (!my_wait(&status))
	return (0);
    }
  if (!strace_syscall_display(pid, opt))
    return (0);
  printf("+++ exited with %d +++\n", status);
  return (1);
}

int	strace_cmd(const t_opt opt, char **av)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      perror("fork");
      return (0);
    }
  if (!pid)
    return (strace_child(av));
  return (strace_father(opt, pid));
}
