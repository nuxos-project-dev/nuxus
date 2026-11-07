#ifndef NUXUS_BITMAP_H
#define NUXUS_BITMAP_H

#include <types.h>

#define BITMAP_GET(bm, num)     ((((uint8_t*)(bm))[(num) / 8] >> ((num) % 8)) & 1)
#define BITMAP_SET(bm, num)     (((uint8_t*)(bm))[(num) / 8] |= (uint8_t)(1u << ((num) % 8)))
#define BITMAP_CLEAR(bm, num)   (((uint8_t*)(bm))[(num) / 8] &= (uint8_t)(1u << ((num) % 8)))
#define BITMAP_TOGGLE(bm, num)  (((uint8_t*)(bm))[(num) / 8] ^= (uint8_t)(1u << ((num) % 8)))

#endif
