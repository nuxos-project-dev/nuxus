/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * Syscall diagnose mechanism for Nuxus kernel
 */

#include <types.h>
#include <syscall.h>
#include <errno.h>

extern syscall_func_t syscall_table[];

int64_t syscall_diagnose(
  reg_t arg1, reg_t arg2, reg_t arg3,
  reg_t arg4, reg_t arg5, reg_t arg6,
  reg_t sys_num
) {
  if (sys_num >= SYS_MAX)
    return -ENOSYS;

  syscall_func_t handler = syscall_table[sys_num];

  if (!handler)
    return -ENOSYS;

  return handler(arg1, arg2, arg3, arg4, arg5, arg6);
}
