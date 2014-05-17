/*
 * rand.c
 *
 * Part of librfn (a general utility library from redfelineninja.org.uk)
 *
 * Copyright (C) 2012 Daniel Thompson <daniel@redfelineninja.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */

#include "librfn/rand.h"

#include <stdint.h>

/* Nth generated number (starting from zero) should be ??? */
uint32_t rand31_r(uint32_t *seedp)
{
	uint32_t hi, lo;

	lo = 16807 * (*seedp & 0xffff);
	hi = 16807 * (*seedp >> 16);

	lo += (hi & 0x7fff) << 16;
	lo += hi >> 15;

	if (lo > 0x7fffffff)
		lo -= 0x7fffffff;

	return (*seedp = lo);
}

