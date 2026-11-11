/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Nuxus - a unix-like kernel
 * UEFI types for Nuxus kernel
 */

#ifndef NUXUS_UEFI_TYPES

#include <nuxus/types.h>

typedef struct {
    uint32_t                type;
    uint32_t                pad;
    uint64_t                physical_start;
    uint64_t                virtual_start;
    uint64_t                number_of_pages;
    uint64_t                attribute;
} efi_memory_descriptor_t;

typedef enum {
    efi_eeserved_memory_type,
    efi_loader_code,
    efi_loader_data,
    efi_boot_services_code,
    efi_boot_services_data,
    efi_runtime_services_code,
    efi_runtime_services_data,
    efi_conventional_memory,
    efi_unusable_memory,
    efi_acpi_reclaim_memory,
    efi_acpi_memory_nvs,
    efi_memory_mapped_io,
    efi_memory_mapped_io_port_space,
    efi_pal_code,
    efi_persistent_memory,
    efi_unaccepted_memory_type,
    efi_max_memory_type
} efi_memory_type_t;

#endif
