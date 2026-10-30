# SPDX-License-Identifier: GPL-2.0-or-later
# Copyright (c) 2026 Omer PALA

ARCH := $(shell uname -m)

ifeq ($(ARCH),arm64)
	ARCH := aarch64
endif

ifeq ($(ARCH),x86_64)
	$(info x86_64 is unsupported for now, Cross-compiling...)
	ARCH := aarch64
endif

ifeq ($(ARCH),riscv64)
	$(info riscv64 is unsupported for now, Cross-compiling...)
	ARCH := aarch64
endif

DEFAULTS := src/kernel \
					 src/mm \
					 src/uefi \
					 src/drivers/qemu_uart \
					 src/kernel/syscalls \
					 src/arch/$(ARCH)

CC := clang
AS := clang
LD := lld-link
C_SRC := $(foreach module, $(DEFAULTS), $(wildcard $(module)/*.c))
AS_SRC := $(wildcard src/arch/$(ARCH)/*.s)
C_OBJ := ${C_SRC:.c=.o}
AS_OBJ := $(AS_SRC:.s=.o)
CFLAGS := --target=$(ARCH)-unknown-windows -ffreestanding -nostdlib -c -Iinclude
ASFLAGS := -c --target=$(ARCH)-unknown-windows
LDFLAGS := -subsystem:efi_application -entry:uefi_init
TARGET := build/nuxus.efi
OBJ := $(AS_OBJ) $(C_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

$(TARGET): $(OBJ)
	mkdir -p build
	$(LD) $(LDFLAGS) $^ -out:$@

clean:
	@echo "Cleaning object files and build output"
	rm -f $(TARGET)
	rm -f $(OBJ)

.PHONY: clean
