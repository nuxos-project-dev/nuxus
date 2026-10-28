/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * Syscall number definitions
 */

#ifndef LUNIX_SYSCALL_H
#define LUNIX_SYSCALL_H
#include <types.h>

typedef int64_t (*syscall_func_t)(
  reg_t arg1, reg_t arg2, reg_t arg3,
  reg_t arg4, reg_t arg5, reg_t arg6
);

#define SYS_MAX 1
#define SYS_DUMMY 0

#define SYSCALL_DEFINE(name) int64_t name(reg_t arg1, reg_t arg2, reg_t arg3, \
                                          reg_t arg4, reg_t arg5, reg_t arg6)

#endif
