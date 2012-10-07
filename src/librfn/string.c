/*
 * string.c
 *
 * Part of librfn (a general utility library from redfelineninja.org.uk)
 *
 * Copyright (C) 2012 Daniel Thompson <daniel@redfelineninja.org.uk> 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <stdlib.h>
#include <stdio.h>

#include "librfn.h"

static char *xtest(char *p)
{
	if (!p)
		rf_internal_out_of_memory(p);

	return p;
}

char *strdup_join(const char *head, const char *tail)
{
	return strdup_printf("%s%s", head, tail);
}

char *xstrdup_join(const char *head, const char *tail)
{
	return xtest(strdup_join(head, tail));
}

char *strtolower(char *s)
{
	for (char *p = s; *p != '\0'; p++)
		*p = tolower(*p);

	return s;
}

char *strdup_tolower(const char *s)
{
	char *t = strdup(s);
	return (t ? strtolower(t) : NULL);
}

char *xstrdup_tolower(const char *s)
{
	return xtest(strdup_tolower(s));
}

char *strtoupper(char *s)
{
	for (char *p = s; *p != '\0'; p++)
		*p = toupper(*p);

	return s;
}

char *strdup_toupper(const char *s)
{
	char *t = strdup(s);
	return (t ? strtoupper(t) : NULL);
}

char *xstrdup_toupper(const char *s)
{
	return xtest(strdup_toupper(s));
}
