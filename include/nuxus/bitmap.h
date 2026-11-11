/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 *
 * Bitmap manipulation macros
 */

#ifndef NUXUS_BITMAP_H
#define NUXUS_BITMAP_H

#include <nuxus/types.h>

static inline int bitmap_get(const void *bm, size_t num) {
  return (((const uint8_t*)bm)[num / 8] >> (num % 8)) & 1;
}

static inline void bitmap_set(void *bm, size_t num) {
  (((uint8_t*)bm)[num / 8] |= (uint8_t)(1u << (num % 8)));
}

static inline void bitmap_clear(void *bm, size_t num) {
  (((uint8_t*)bm)[num / 8] &= (uint8_t)~(1u << (num % 8)));
}

static inline void bitmap_toggle(void *bm, size_t num) {
  (((uint8_t*)bm)[num / 8] ^= (uint8_t)(1u << (num % 8)));
}

#endif
