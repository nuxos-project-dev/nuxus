/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * Stack switcher for ExitBootServices
 */

.section .bss
.global stack_top
stack_bottom:
.space 16384
stack_top:

.section .text
.global switch_to_kernel

switch_to_kernel:
  ldr x1, =stack_top
  mov sp, x1

  b kernel_main
