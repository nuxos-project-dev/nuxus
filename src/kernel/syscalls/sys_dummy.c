/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Lunix - a unix-like kernel
 *
 * Decleration of sys_dummy syscall
 */

#include <nuxus/compiler.h>
#include <nuxus/types.h>
#include <nuxus/syscall.h>
#include <nuxus/errno.h>

SYSCALL_DEFINE(sys_dummy) {
  UNUSED(arg1); UNUSED(arg2); UNUSED(arg3);
  UNUSED(arg4); UNUSED(arg5); UNUSED(arg6);

  return -ENOSYS;
}
