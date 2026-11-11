/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * Syscall table for Nuxus kernel
 */

#include <nuxus/syscall.h>
#include <nuxus/types.h>

extern SYSCALL_DEFINE(sys_dummy);

syscall_func_t syscall_table[SYS_MAX] = {
  [SYS_DUMMY] = sys_dummy
};
