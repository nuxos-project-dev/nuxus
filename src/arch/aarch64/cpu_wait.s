/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - A unix-like kernel
 *
 * A wrapper for wfi
 */

.section .text
.global cpu_wait

cpu_wait:
  wfi
  ret
