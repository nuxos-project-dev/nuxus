/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * A header defines boot information
 */

#ifndef NUXUS_BOOT_INFO_H
#define NUXUS_BOOT_INFO_H

#ifndef EFIAPI
#include <types.h>
#endif

typedef struct {
  uint64_t mem_map;
  uint64_t mem_map_size;
  uint64_t mem_desc_size;
} mem_info_t;

typedef struct {
  uint64_t fb_base;
  uint64_t fb_size;
  uint32_t fb_width;
  uint32_t fb_height;
  uint32_t fb_pitch;
} fb_info_t;

typedef struct {
  fb_info_t fb_info;
  mem_info_t mem_info;
} boot_info_t;

#endif
