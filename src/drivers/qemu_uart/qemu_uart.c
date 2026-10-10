/*
 * SPDX-License-Identifier: GPL-2.0-or-later OR BSD-2-Clause
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Lunix - a unix-like kernel
 * QEMU UART driver for lunix kernel
 */
#include <stdint.h>
#define UART0_BASE 0x09000000UL

#define UART0_DR (*(volatile uint32_t*)(UART0_BASE + 0x00)) //Data register
#define UART0_FR (*(volatile uint32_t*)(UART0_BASE + 0x18)) //Flag register

#define UART_FR_TXFF (1 << 5)
#define UART_FR_RXFE (1 << 4)

void qemu_uart_putc(char c) {
  while (UART0_FR & UART_FR_TXFF);
  UART0_DR = c;
}

void qemu_uart_puts(const char *s) {
  while (*s) {
    if (*s == '\n') qemu_uart_putc('\r');
    qemu_uart_putc(*s++);
  }
}

char qemu_uart_getc(void) {
  while (UART0_FR & UART_FR_RXFE);
  return (char)UART0_DR;
}

int qemu_uart_haschar(void) {
  return !(UART0_FR & UART_FR_RXFE);
}
