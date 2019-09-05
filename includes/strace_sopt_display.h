/*
** strace_sopt_display.h for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Fri Apr  8 11:52:08 2016 Victor Le
** Last update Sun Apr 10 16:21:44 2016 Victor Le
*/

#ifndef STRACE_SOPT_DISPLAY_H_
# define STRACE_SOPT_DISPLAY_H_

# include "syscall_info.h"
# include "main.h"

void	strace_sopt_display(const t_syscall *, const pid_t,
			    const int, const t_regs *);
void	strace_display_return_value(const t_syscall *, const pid_t,
				    const t_regs *);

#endif /* !STRACE_SOPT_DISPLAY_H_ */
