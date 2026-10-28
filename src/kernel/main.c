/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - A unix-like kernel
 *
 * Kernel main function
 */

#include <boot_info.h>
#include <stdint.h>

void kernel_main(boot_info_t *boot_info) {
  volatile uint32_t *fb = (volatile uint32_t*)(uintptr_t)boot_info->fb_base;

  fb[20] = 0xffffffff;
}
