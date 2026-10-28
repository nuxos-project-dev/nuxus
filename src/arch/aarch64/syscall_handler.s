/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * Syscall handler mechanism
 */

.section .text

.balign 0x800
.global vector_table
vector_table:
  // SP_EL0
  .balign 0x80
  b .
  .balign 0x80
  b .
  .balign 0x80
  b .
  .balign 0x80
  b .

  // SP_ELx
  .balign 0x80
  b syscall_handler
  .balign 0x80
  b .
  .balign 0x80
  b .
  .balign 0x80
  b .

  // Aarch64 - Low EL
  .balign 0x80
  b syscall_handler
  .balign 0x80
  b .
  .balign 0x80
  b .
  .balign 0x80
  b .

  // Arm32 - Low EL
  .balign 0x80
  b .
  .balign 0x80
  b .
  .balign 0x80
  b .
  .balign 0x80
  b .

.global syscall_handler
syscall_handler:
  sub sp, sp, #272

  stp x0, x1,   [sp, #0]
  stp x2, x3,   [sp, #16]
  stp x4, x5,   [sp, #32]
  stp x6, x7,   [sp, #48]
  stp x8, x9,   [sp, #64]
  stp x10, x11, [sp, #80]
  stp x12, x13, [sp, #96]
  stp x14, x15, [sp, #112]
  stp x16, x17, [sp, #128]
  stp x18, x19, [sp, #144]
  stp x20, x21, [sp, #160]
  stp x22, x23, [sp, #176]
  stp x24, x25, [sp, #192]
  stp x26, x27, [sp, #208]
  stp x28, x29, [sp, #224]
  mrs x0, elr_el1
  mrs x1, spsr_el1
  stp x30, x0, [sp, #240]
  str x1, [sp, #256]

  bl syscall_diagnose

  ldr x1, [sp, #256]
  ldp x30, x0, [sp, #240]
  msr spsr_el1, x1
  msr elr_el1, x0
  ldp x0, x1,   [sp, #0]
  ldp x2, x3,   [sp, #16]
  ldp x4, x5,   [sp, #32]
  ldp x6, x7,   [sp, #48]
  ldp x8, x9,   [sp, #64]
  ldp x10, x11, [sp, #80]
  ldp x12, x13, [sp, #96]
  ldp x14, x15, [sp, #112]
  ldp x16, x17, [sp, #128]
  ldp x18, x19, [sp, #144]
  ldp x20, x21, [sp, #160]
  ldp x22, x23, [sp, #176]
  ldp x24, x25, [sp, #192]
  ldp x26, x27, [sp, #208]
  ldp x28, x29, [sp, #224]

  add sp, sp, #272
