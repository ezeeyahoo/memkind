/*
 * Copyright (C) 2014 Intel Corperation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice(s),
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice(s),
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef numakind_default_include_h
#define numakind_default_include_h
#ifdef __cplusplus
extern "C" {
#endif

#include "numakind.h"

int numakind_default_create(struct numakind *kind, const struct numakind_ops *ops, const char *name);
int numakind_default_destroy(struct numakind *kind);
void *numakind_default_malloc(struct numakind *kind, size_t size);
void *numakind_default_calloc(struct numakind *kind, size_t num, size_t size);
int numakind_default_posix_memalign(struct numakind *kind, void **memptr, size_t alignment, size_t size);
void *numakind_default_realloc(struct numakind *kind, void *ptr, size_t size);
void numakind_default_free(struct numakind *kind, void *ptr);
int numakind_default_is_available(struct numakind *kind);
int numakind_default_mbind(struct numakind *kind, void *ptr, size_t len);
int numakind_noop_mbind(struct numakind *kind, void *ptr, size_t len);
int numakind_default_get_mmap_flags(struct numakind *kind, int *flags);
int numakind_default_get_mbind_mode(struct numakind *kind, int *mode);
int numakind_default_get_mbind_nodemask(struct numakind *kind, unsigned long *nodemask, unsigned long maxnode);
int numakind_default_get_size(struct numakind *kind, size_t *total, size_t *free);

static const struct numakind_ops NUMAKIND_DEFAULT_OPS = {
    .create = numakind_default_create,
    .destroy = numakind_default_destroy,
    .malloc = numakind_default_malloc,
    .calloc = numakind_default_calloc,
    .posix_memalign = numakind_default_posix_memalign,
    .realloc = numakind_default_realloc,
    .free = numakind_default_free,
    .is_available = numakind_default_is_available,
    .mbind = numakind_default_mbind,
    .get_mmap_flags = numakind_default_get_mmap_flags,
    .get_mbind_mode = numakind_default_get_mbind_mode,
    .get_mbind_nodemask = numakind_default_get_mbind_nodemask,
    .get_arena = NULL,
    .get_size = numakind_default_get_size
};

#ifdef __cplusplus
}
#endif
#endif
