/*
 * siggen.h
 *
 * Part of libtt (the integer amplifier library)
 *
 * Copyright (C) 2012 Daniel Thompson <daniel@redfelineninja.org.uk> 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef TT_SIGGEN_H_
#define TT_SIGGEN_H_

#include "sample.h"

/*! Signal generator based on periodic mathematical functions.
 */
typedef struct {
	ttspl_t phase;
	ttspl_t step;
	ttspl_t limit;
	ttspl_t amplitude;
	ttspl_t (*fn)(ttspl_t phase);
} tt_siggen_t;

typedef enum {
	TT_SIGGEN_DC,
	TT_SIGGEN_SIN
} tt_siggen_fn_t;

tt_siggen_t *tt_siggen_new();
void tt_siggen_delete(tt_siggen_t *sg);

ttspl_t tt_siggen_step(tt_siggen_t *sg);
void tt_siggen_process(tt_siggen_t *sg, tt_sbuf_t *outbuf);
void tt_siggen_reset(tt_siggen_t *sg);

void tt_siggen_setup(
		tt_siggen_t *sg,
		int sfreq, int gfreq, ttspl_t amplitude, tt_siggen_fn_t fn);

#endif // TT_SIGGEN_H_