/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2026 Omer PALA
 *
 * Lunix - A unix-like kernel
 *
 * Efi start point and exiting BootServices
 */

#include <uefi.h>
#include <boot_info.h>

static boot_info_t boot_info;
static uint8_t static_map_buffer[8192];

extern void cpu_wait(void);
extern void switch_to_kernel(boot_info_t *boot_info);

int main(int argc, char *argv[]) {
  efi_status_t status;

  printf("Welcome to Lunix!\n");
  printf("Started in BootServices\n");

  //GOP
  printf("Acquiring GOP framebuffer...\n");

  efi_gop_t *gop = NULL;
  efi_guid_t gop_guid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;

  status = BS->LocateProtocol(&gop_guid, NULL, (void**)&gop);
  if (EFI_ERROR(status) || !gop) {
    printf("Cannot find GOP!\n");
    return 1;
  }

  printf("GOP Acquired!\n");

  status = gop->SetMode(gop, 0);
  if (EFI_ERROR(status)) {
    printf("Failed to change GOP mode setting");
    return 1;
  }

  boot_info.fb_base       = gop->Mode->FrameBufferBase;
  boot_info.fb_size       = gop->Mode->FrameBufferSize;
  boot_info.fb_width      = gop->Mode->Information->HorizontalResolution;
  boot_info.fb_height     = gop->Mode->Information->VerticalResolution;
  boot_info.fb_pitch      = gop->Mode->Information->PixelsPerScanLine * 4;

  uintn_t map_key;
  uint32_t desc_version;
  boot_info.mem_map_size = sizeof(static_map_buffer);
  boot_info.mem_map = (uint64_t)(uintptr_t)static_map_buffer;

  status = BS->GetMemoryMap(
    &boot_info.mem_map_size,
    (efi_memory_descriptor_t*)(uintptr_t)boot_info.mem_map,
    &map_key, &boot_info.mem_desc_size,
    &desc_version
  );
  if (EFI_ERROR(status)) {
    printf("GetMemoryMap failed!\n");
    return 1;
  }

  status = BS->ExitBootServices(IM, map_key);
  if (EFI_ERROR(status)) {
    printf("Failed to exit BootServices\n! Retrying...");

    boot_info.mem_map_size = sizeof(static_map_buffer);
    status = BS->GetMemoryMap(
      &boot_info.mem_map_size,
      (efi_memory_descriptor_t*)(uintptr_t)boot_info.mem_map,
      &map_key, &boot_info.mem_desc_size,
      &desc_version
    );
    if (EFI_ERROR(status)) {
      printf("GetMemoryMap failed!\n");
      return 1;
    }

    status = BS->ExitBootServices(IM, map_key);
    if (EFI_ERROR(status)) {
      printf("ExitBootServices failed two times!\n");
      return 1;
    }
  }

  switch_to_kernel(&boot_info);

  while (1) {
    cpu_wait();
  }
}
