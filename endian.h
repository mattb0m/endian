#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h>

#if !defined(UINT8_MAX) || !defined(UINT16_MAX) || !defined(UINT32_MAX) || !defined(UINT64_MAX)
#error "This header requires 8, 16, 32 and 64-bit unsigned integers to be defined."
#endif

static inline uint32_t is_le(void) {
	uint32_t i = 1;
	return (uint32_t)*((uint8_t*)&i);
}

static inline uint16_t bswap_16(uint16_t i) {
    return ((i & 0xff00U) >> 8) | ((i & 0x00ffU) << 8);
}

static inline uint32_t bswap_32(uint32_t i) {
    return ((i & 0x000000FF) << 24)|
	       ((i & 0x0000FF00) <<  8)|
	       ((i & 0x00FF0000) >>  8)|
	       ((i & 0xFF000000) >> 24);
}

static inline uint64_t bswap_64(uint64_t i) {
    return ((i & 0x00000000000000FFULL) << 56)|
	       ((i & 0x000000000000FF00ULL) << 40)|
		   ((i & 0x0000000000FF0000ULL) << 24)|
	       ((i & 0x00000000FF000000ULL) <<  8)|
	       ((i & 0x000000FF00000000ULL) >>  8)|
	       ((i & 0x0000FF0000000000ULL) >> 24)|
		   ((i & 0x00FF000000000000ULL) >> 40)|
	       ((i & 0xFF00000000000000ULL) >> 56);
}

#endif