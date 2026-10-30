/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 */

// Type definitions for lunix

#ifndef NUXUS_TYPES_H
#define NUXUS_TYPES_H

// Unsigned types
typedef unsigned long long  uint64_t;
typedef unsigned int        uint32_t;
typedef unsigned short      uint16_t;
typedef unsigned char       uint8_t;
typedef unsigned long long  uintptr_t;
typedef unsigned long long  size_t;

// Signed types
typedef signed long long  int64_t;
typedef signed int        int32_t;
typedef signed short      int16_t;
typedef signed char       int8_t;
typedef signed long long  intptr_t;
typedef signed long long  ssize_t;

// Register types
typedef uint64_t reg_t;
typedef uint32_t low_reg_t;

#endif
