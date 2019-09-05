/*
** strace_dump_x.h for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Sat Apr  9 07:40:29 2016 Victor Le
** Last update Sat Apr  9 07:57:35 2016 Victor Le
*/

#ifndef STRACE_DUMP_X_H_
# define STRACE_DUMP_X_H_

void	strace_dump_int(const pid_t, const t_regs *, const int);
void	strace_dump_str(const pid_t, const t_regs *, const int);
void	strace_dump_addr(const pid_t, const t_regs *, const int);
void	strace_dump_unknow(const pid_t, const t_regs *, const int);

typedef void	(*t_sysdump)(const pid_t, const t_regs *, const int);

typedef union	u_data
{
  long		data;
  char		bit[8];
}		t_data;

#endif /* !STRACE_DUMP_X_H_ */
